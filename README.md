<h1>ESP32 Diagnostics to API</h1>
<p>
This repository is a simple project to demonstrate API communication from an ESP32 to a basic REST API
</p>

<h2>Considerations for setting up the project</h2>

<h3><u>Set up PHP</u></h3>
<h4>1. Install a thread-safe version of the PHP</h4>
<h4>2. Configure the php.ini file</h4>
<p>
Add extension<br/>
<code>extension=mysqli</code>
</p>

<h3><u>Set up Apache</u></h3>

<h4>1. Update the httpd.conf file</h4>
<p>
Turn on .htaccess<br/>
<code>
AllowOverride All
</code>

Add LoadModule for PHP<br/>
<code>
LoadModule php_module "C:\PHP8.3.1\php8apache2_4.dll"  
AddHandler application/x-httpd-php  .php
PHPIniDir "C:\PHP8.3.1"
</code>
</p>

<h3><u>Create MySQL test database, table, and test user</u></h3>
Use the <code>sql/CreateTestData.sql</code> file

<h3><u>Set up PHP API files</u></h3>
Move all files in the <code>php</code> directory into the main directory of your server (e.g., <code>htdocs</code> for Apache)

<h3><u>Flash ESP32 with code to send status</u></h3>
Use <code>arduino-cplusplus/SendStatus.ino</code>