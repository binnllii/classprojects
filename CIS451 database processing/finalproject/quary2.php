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
  
$order_no = $_POST['order_no'];

$order_no = mysqli_real_escape_string($conn, $order_no);
// this is a small attempt to avoid SQL injection
// better to use prepared statements

// $query = "SELECT s.description, CONCAT('$', IFNULL(SUM(i.total_price), 0)) AS totalSpent
// FROM stores7.manufact m
// 			JOIN stores7.stock s using(manu_code)
// 			LEFT JOIN stores7.items i USING(stock_num, manu_code)
//             WHERE manu_name =  ";
// $query = $query.'"'.$manufacturer.'" group by stock_num, manu_code;';

$query = "SELECT i.product_name as name, i.generation as generation, as storage, 
(o.order_cost) - (i.source_price) - (s.shipping_cost) - (se.fee) as profit
 FROM onlineStore.selling_fees se
      JOIN onlineStore.inventory i USING (product_id)
      JOIN onlineStore.orders o using (product_id)
      JOIN onlineStore.shipping_costs s USING (order_no)
    WHERE o.order_no =  ";
$query = $query."$order_no";


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
    print "$row[name] $row[generation] $row[profit]";
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