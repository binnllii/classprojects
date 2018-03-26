<?php

include('connectionData.txt');

$conn = mysqli_connect($server, $user, $pass, $dbname, $port)
or die('Error connecting to MySQL server.');

?>

<html>
<head>
  <title>Another Simple PHP-MySQL Program</title>
  </head>
  
  <body bgcolor="white">
  
  
  <hr>
  
  
<?php
  
$product_id = $_POST['product_id'];

$product_id = mysqli_real_escape_string($conn, $product_id);
// this is a small attempt to avoid SQL injection
// better to use prepared statements

// $query = "SELECT s.description, CONCAT('$', IFNULL(SUM(i.total_price), 0)) AS totalSpent
// FROM stores7.manufact m
// 			JOIN stores7.stock s using(manu_code)
// 			LEFT JOIN stores7.items i USING(stock_num, manu_code)
//             WHERE manu_name =  ";
// $query = $query.'"'.$manufacturer.'" group by stock_num, manu_code;';

$query = "SELECT i.product_name as pname, i.generation as generation, i.inventory as inventory
      FROM onlineStore.inventory i
      WHERE i.product_id =  ";
$query = $query."$product_id";


?>

<p>
The query:
<p>
<?php
print $query;
?>

<hr>
<p>
Result of query:
<p>

<?php
$result = mysqli_query($conn, $query)
or die(mysqli_error($conn));

print "<pre>";
while($row = mysqli_fetch_array($result, MYSQLI_BOTH))
  {
    print "\n";
    print "$row[pname] $row[generation] $row[inventory]";
  }
print "</pre>";

mysqli_free_result($result);

mysqli_close($conn);

?>

<p>
<hr>

<p>
<a href="findManuName.php" >Contents</a>
of the PHP program that created this page. 	 
 
</body>
</html>