import processing.serial.*; // imports library for serial communication
import java.awt.Robot; // imports library for key press or release simulation
import java.awt.event.KeyEvent; // imports library for reading the data from the serial port
import java.io.IOException;
Serial port; // defines Object Serial
Robot robot; // defines Object Robot
//defining variables
String X= "";

String data= "";
int index=0;
int index2=0;
int index3=0;
int index4=0;
int index5=0;
int index6=0;
int index7=0;
int iX=0;

// creates new robot object
void setup()
{
try 
{
robot = new Robot();
}
catch (Exception e) {
e.printStackTrace();
exit();
}
delay(2000);
size (800, 800);
port = new Serial(this,"COM3", 9600); // starts the serial communication
port.bufferUntil(';'); // reads the data from the serial port up to the character '.'. So actually it reads this: 215,214/141;315:314<316!314?315.
}
void draw()
{
background(0,0,0);
fill(255, 255, 255);
//Simulating key press or release
// turn left
if(iX==70)
{ 
delay(40);
robot.keyPress(KeyEvent.VK_UP); // Simulates "I" key press if the value from the accelerometer for the X axis is greater than 320 

}
if(iX==66){
delay(40);
robot.keyPress(KeyEvent.VK_DOWN); // Simulates "I" key release if the value from the accelerometer for the X axis is less than 320 

}
if(iX==76){
delay(40);
robot.keyPress(KeyEvent.VK_LEFT); // Simulates "I" key release if the value from the accelerometer for the X axis is less than 320 

}
if(iX==82){
delay(40);
robot.keyPress(KeyEvent.VK_RIGHT); // Simulates "I" key release if the value from the accelerometer for the X axis is less than 320 

}
if(iX==49)
{ 
delay(40);
robot.keyPress(KeyEvent.VK_UP); // Simulates "I" key press if the value from the accelerometer for the X axis is greater than 320 
iX=0;
}
if(iX==50){
delay(40);
robot.keyPress(KeyEvent.VK_DOWN); // Simulates "I" key release if the value from the accelerometer for the X axis is less than 320 
iX=0;
}
if(iX==51){
delay(40);
robot.keyPress(KeyEvent.VK_ENTER); // Simulates "I" key release if the value from the accelerometer for the X axis is less than 320 
iX=0;
}
if(iX==52){
delay(40);
robot.keyPress(KeyEvent.VK_BACK_SPACE); // Simulates "I" key release if the value from the accelerometer for the X axis is less than 320 
iX=0;
}
if(iX==83){
delay(40);
robot.keyRelease(KeyEvent.VK_ENTER);
robot.keyRelease(KeyEvent.VK_BACK_SPACE); 
robot.keyRelease(KeyEvent.VK_UP); 
robot.keyRelease(KeyEvent.VK_DOWN); 
robot.keyRelease(KeyEvent.VK_LEFT);
robot.keyRelease(KeyEvent.VK_RIGHT);
}

// turn right
// turn up

}
// Reading data from the Serial Port
void serialEvent (Serial port) // starts reading data from the Serial Port
{
data = port.readStringUntil(';'); // reads the data from the serial port up to the character '.' and it sets that into the String variable "data". So actually it reads this: 215,214/141;315:314<316!314?315.
data = data.substring(0,data.length()-1); // it removes the '.' from the previous read. So this will be the String "data" variable: 215,214/141;315:314<316!314?315
// Finding the indexes in the data and setting the variables from the sensors by taking from the String "data" the appropriate values that are between the characters in the "data" String
index = data.indexOf(","); // finds the index of the character "," from the String "data" variable
X= data.substring(0, index); // sets into the variable X the string from position 0 of the hole string to where the index was. That would mean that read will be : 215

// Converting the String variables values into Integer values needed for the if statements above
iX= int(X);

}
