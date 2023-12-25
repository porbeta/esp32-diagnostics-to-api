#include <WiFi.h>
#include <HTTPClient.h>


// Change to your wi-fi network 
const char* ssid       = "YOUR_SSID";

// Change to your wi-fi network's password
const char* password   = "YOUR_PASS";

// Change to where the API is hosted
const char* serverName = "http://127.0.01:80/api.php";

uint32_t chipId = 0;
char chipName[40];

void setup()
{
  Serial.begin(115200);

  //connect to WiFi
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }
  Serial.println(" CONNECTED");

}

void loop()
{
  char chipName[50];
  char voltageStr[50];

  delay(5000);
  

  for(int i=0; i<17; i=i+8) {
	  chipId |= ((ESP.getEfuseMac() >> (40 - i)) & 0xff) << i;
	}

  sprintf(chipName, "%u", chipId);
  
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  
  sprintf(voltageStr, "%.3f", voltage);
  
  //Check WiFi connection status
  if(WiFi.status()== WL_CONNECTED){
    HTTPClient http;
    char serverPath[100];
    
    sprintf(serverPath, "%s?chip_id=%s&voltage=%s", serverName, chipName, voltageStr);
    Serial.printf("Sending %s\n", serverPath);
    
    // Your Domain name with URL path or IP address with path
    http.begin(serverPath);
    
    // If you need Node-RED/server authentication, insert user and password below
    //http.setAuthorization("REPLACE_WITH_SERVER_USERNAME", "REPLACE_WITH_SERVER_PASSWORD");
    
    // Send HTTP GET request
    int httpResponseCode = http.GET();
    
    if (httpResponseCode>0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      String payload = http.getString();
      Serial.println(payload);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    // Free resources
    http.end();
  }
  else {
    Serial.println("WiFi Disconnected");
  }
}
