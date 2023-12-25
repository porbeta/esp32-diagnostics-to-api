<?php
if (isset($_GET['chip_id']) && $_GET['chip_id']!="") {
	include('db.php');
	$chip_id = $_GET['chip_id'];
	$result = mysqli_query($con, "SELECT * FROM `diagnostics` WHERE chip_id='$chip_id' ORDER BY datetime desc;");

    echo "<table border=1>";
    echo "<tr><th>date/time</th><th>voltage</th></tr>";

    if (mysqli_num_rows($result)>0) {
        while($row = $result->fetch_assoc()) {
            $datetime = $row["datetime"];
            $voltage = $row["voltage"];

            echo "<tr>";
            echo "<td style='padding-right: 40px'>$datetime</td>";
            echo "<td style='padding-right: 40px'>$voltage</td>";
            echo "</tr>";
        }
	}

    echo "</table>";
} else {
    echo "No Chip ID provided";
}
?>
