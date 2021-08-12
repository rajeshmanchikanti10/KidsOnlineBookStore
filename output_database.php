<?php
$con=mysqli_connect("localhost","root","");
if(!$con)
die("Connection failed: " . mysqli_connect_error());
mysqli_select_db($con,"book_store");
$result = mysqli_query($con,"SELECT* FROM book_store_table");
if (mysqli_num_rows($result) > 0)
{
    while($row = mysqli_fetch_assoc($result))
    {
        $username = $row["username"];
         $email = $row["email"];
         $address= $row["addr"];
         $passwd=$row["passwd"];
         $city=$row["city"];
         
    }
}
else {
    echo "0 results";
}

mysqli_close($con);
?>