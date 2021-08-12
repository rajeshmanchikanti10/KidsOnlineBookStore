<!doctype html>
<html>
<head>
<style>

input[type=submit] {
  background-color: #4CAF50;
  color: white;
  padding: 12px 20px;
  border: none;
  border-radius: 4px;
  cursor: pointer;
  
}

input[type=submit]:hover {
  background-color: skyblue;
}
input{
  width:100%;
}

.container {
  border-radius: 5px;
  background-color: #f2f2f2;
  padding: 20px;
  
  left: 50%;
    top: 50%;
    margin-left: -15%;
    position: absolute;
    margin-top: -15%;
  width: 350px;
    height: 450px;
  

}

.col-25 {
  float: left;
  width: 25%;
  margin-top: 6px;
}

.col-75 {
  float: left;
  width: 75%;
  margin-top: 6px;
  height: 40px;
}

/* Clear floats after the columns */
.row:after {
  content: "";
  display: table;
  clear: both;
  height:25%;
}
.row{
  height:33%
}

/*.container{
  -ms-flex-align: center;
    align-items: center;
    -ms-flex-pack: center;
    justify-content: center;
}*/
.body{
  background-color:#0beedb;
}

</style>
</head>
<body style="background-color:#242525;float: scroll;">
<center><div class="container">
<form action="process.php" method="POST" name="registerform">
  <div class="row">
    <h1>Register</h1>
  </div>
<div class="row">
<div class="col-25">
<label>Username</label>
</div>
<div class="col-75">
<input type="text" name="username" placeholder="user name" required=" "/>
</div>
</div>
<div class="row">
<div class="col-25">
<label>Password</label>
</div>
<div class="col-75">
<input type="password" name="password" id="password"  placeholder="password"  required=" "/>
<span id="message"></span>
</div>
</div>
<div class="row">
<div class="col-25">
<label>Confirm Password</label>
</div>
<div class="col-75">
<input type="password" name="confirmpassword" id="confirm_password" placeholder="confirmpassword"   required=" "/>
<span id="message"></span>
</div>
</div>
<div class="row">
<div class="col-25">
<label>Email-id</label>
</div>
<div class="col-75">
 <input type="email" name="email" placeholder="Email-id" required=" "/>
</div>
</div>
<div class="row">
<div class="col-25">
<label>Address</label>
</div>
<div class="col-75">
<textarea  name="Address" placeholder="address" style="height:50px" required=" "></textarea>
</div>
</div>
<br>
<div class="row">
<div class="col-25">
<label>city</label>
</div>
<div class="col-75">
<input type="text" name="city" placeholder="city" required=" "/>
</div>
</div>
<br>
<div class="row">
<input type="submit" name="registernow" value="Register Now"  >
</div>


</form>
</div>
</center>
</body>
<script>
function verify()
{
if(document.getElementById('password')==document.getElementById('confirmpassword'))
{
document.getElementById('message').style.color="green";
document.getElementById('message').innerHTML="matching";
}
else{
  document.getElementById('message').style.color="red";
  document.getElementById('message').innerHTML="not matching";
}
}
</script>
</html>