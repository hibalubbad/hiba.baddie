<html>
<?php
//header("Content-type: text/css; charset: UTF-8");
// $linkColor = "#555555";
// input[type="submit"] {
//     color: <?php echo $linkColor; ;
//   }
echo "<center>";

$firstname= $_POST['firstname'];
$lastname = $_POST['lastname'];
$Title = $_POST['Title'];
$industry= $_POST['industry'];
$phonenumber= $_POST['phonenumber'];
$organization= $_POST['organization'];
$email= $_POST['email'];
if(isset($_POST['submit'])){
            // creating an object for sending SMS
                // Retrieving each selected option 
                echo '<div style="border: 5px solid rgb(10, 12, 109);">';
                foreach ($_POST['material'] as $material)  
                {
                    print "You selected $material<br/></br>"; 
                }
                    echo '</div>';
            
               
            $postUrl = "http://api.nabed.xyz/custom/prescriber-guest-log";
            $postData = array(
                'title' => $Title,
                'full_name' => $firstname+ ' ' + $lastname,
                'company_name' => $organization,
                'email' => $email,
                'mobile_number' => $phonenumber,
                'type'=> 'hcp',
            );
            $postDataJson = json_encode($postData);
            $ch = curl_init($postUrl);
            $header = array("Content-Type:application/json", "Accept:application/json");
            curl_setopt($ch, CURLOPT_POST, 1);
            curl_setopt($ch, CURLOPT_HTTPHEADER, $header);
            curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
            curl_setopt($ch, CURLOPT_POSTFIELDS, $postDataJson);
            curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false);
            $response = curl_exec($ch);
            //var_dump($response);die;
            $httpCode = curl_getinfo($ch, CURLINFO_HTTP_CODE);
            $responseBody = json_decode($response);
            curl_close($ch);
            $messages = $responseBody->messages;
            echo '<br>';
            echo '<br>';
            echo '<font size="5"'." face='Poppins'>";
            echo 'Thank you for completing the form!';
            echo '<br><br>';
        }
        echo '<input type="button" 
        style="width:160px;
        height:35px; 
        font-size:15px;
        color: black;
        background: grey;
        cursor: pointer;
        border-radius: 10px;
        border: none;
        outline: none;
        " value="return to form" onclick="window.location=\'http://localhost:8888/projectN/temp.html\'" />';
        echo '<br><br><br><br>';


    ?>
    </html>