<?php

/*$name=$_POST['username'];
$password=$_POST['password'];
$email=$_POST['email'];
$address=$_POST['Address'];
$city=$_POST['city'];
if($name && $password && $email && $address && $city)
{
   $con= mysqli_connect("localhost","root","") or die("can't connect to mysql server");
    mysqli_select_db($con,"book_store");
    mysqli_query($con,"INSERT INTO users(username,password,email,Address,city) VALUES('$name',$password','$email','$address','$city')");
    
    $registered=mysqli_affected_rows($con);
    echo "$registered was inserted";

}
else
{
    echo "entered detailed are incomplete please fill the form again";
}*/
?>
<?php

$name=$_POST['username'];
$pass=$_POST['password'];
$email=$_POST['email'];

$address=$_POST['Address'];
$city=$_POST['city'];
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "book_store";
echo "password is".$pass."<br>";
echo $address."<br>";
// Create connection
$conn = mysqli_connect($servername, $username, $password, $dbname);
$email = mysqli_real_escape_string($conn,$_POST['email']);
// Check connection
if (!$conn) {
    
    die("Connection failed: " . mysqli_connect_error());
}


$sql = "INSERT INTO `book_store_table`(username, passwd, email,addr,city)
VALUES ('$name','$pass','$email','$address','$city')"; 

if (mysqli_query($conn, $sql)) {
    echo "New record created successfully";
} else {
    echo "Error: " . $sql . "<br>" . mysqli_error($conn);
    echo "<br>"."here";
}

mysqli_close($conn);
?>


<?php
/*$servername = "localhost";
$username = "username";
$password = "password";
$dbname = "myDB";

// Create connection
$conn = mysqli_connect($servername, $username, $password, $dbname);
// Check connection
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

$sql = "INSERT INTO MyGuests (firstname, lastname, email)
VALUES ('John', 'Doe', 'john@example.com')";

if (mysqli_query($conn, $sql)) {
    echo "New record created successfully";
} else {
    echo "Error: " . $sql . "<br>" . mysqli_error($conn);
}

mysqli_close($conn);*/
?>