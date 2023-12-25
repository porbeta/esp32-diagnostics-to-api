<?php
header("Content-Type:application/json");

if (isValid($_GET['chip_id']) && isValid($_GET['voltage'])) {
	include('db.php');
	$chip_id = $_GET['chip_id'];
    $voltage = $_GET['voltage'];

    $result = mysqli_query($con,"INSERT INTO `diagnostics` (chip_id, voltage) VALUES ('$chip_id', '$voltage')");

    if($result === TRUE) {
        response(200, "Store Success");
	} else {
		response(500, "Store Failure");
	}

    mysqli_close($con);

} else {
	response(400, "Invalid Request");
}

function response($response_code,$response_desc){
	$response['response_code'] = $response_code;
	$response['response_desc'] = $response_desc;
	
	$json_response = json_encode($response);
	echo $json_response;
}

function isValid($arg) {
    return isset($arg) && $arg != "";
}

?>