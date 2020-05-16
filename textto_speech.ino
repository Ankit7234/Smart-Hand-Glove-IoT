//this is the final code which is uploaded in the arduino and processing code will run(seperately) at the time of gaming part  
#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,10,11,12,13);
const int mode=6;
int thumb=A4;
int index=A3;
int middle=A2;
int ring=A1;
int little=A0;
const int buzzer=7;
bool flag = true;
bool steadyValue = false;
unsigned long time_old  = 0;
int j = 0;
unsigned int thumb_threshold = 0;
unsigned int index_threshold = 0;
unsigned int middle_threshold = 0;
unsigned int ring_threshold = 0;
unsigned int little_threshold = 0;

int decVal;
char lookupTable[]={97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,65,66,46,67,68,32};
int digiStore[5];
int temp[5];
char words[100];
char string[10];

void calibrate()
{
  lcd.begin(16,2); 
  lcd.setCursor(0,0); 
    lcd.print("GESTURE TO      " );
     lcd.setCursor(0,1); 
    lcd.print("SPEECH CONVERTER" );
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
  lcd.print("Bend fingers");
    Serial.print("Bend fingers");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Starting ");
  lcd.setCursor(0,1);
  lcd.print("calibration... ");
  //Serial.print("Starting ");
  delay(1000);
  //Serial.print("Calibration");
  delay(3000);
   lcd.clear();
  lcd.print("Bend fingers");
  delay(5000);
  int t_low=analogRead(thumb);
  int i_low=analogRead(index);
  int m_low=analogRead(middle);
  int r_low=analogRead(ring);
  int l_low=analogRead(little);
  lcd.clear();
   lcd.setCursor(0,0);
 lcd.print("Un-bend fingers");
 Serial.print("Un-bend fingers");
  delay(5000);
  int t_high=analogRead(thumb);
  int i_high=analogRead(index);
  int m_high=analogRead(middle);
  int r_high=analogRead(ring);
  int l_high=analogRead(little);

  thumb_threshold = (t_low + t_high)/2;
  index_threshold = (i_low + i_high)/2;
  middle_threshold = (m_low + m_high)/2;
  ring_threshold = (r_low + r_high)/2;
  little_threshold = (l_low + l_high)/2;
  delay(1000);

 // Serial.println("Calibrated values are - ");
  //Serial.println(thumb_threshold);
  //Serial.println(index_threshold);
  //Serial.println(middle_threshold);
  //Serial.println(ring_threshold);
  delay(1000);
 lcd.clear(); 
}

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(thumb, INPUT);
 pinMode(index, INPUT);
 pinMode(middle, INPUT);
 pinMode(ring, INPUT);
 pinMode(little, INPUT);
 pinMode(buzzer,OUTPUT);
 digitalWrite(buzzer,LOW);
 pinMode(mode, INPUT);
 calibrate();
}

void loop() {
  // put your main code here, to run repeatedly:
//  char sentence[50];
int s=digitalRead(mode);
if(s==0)
{
  int s=digitalRead(mode);
delay(500);
    int t=analogRead(thumb);
         if(t>=thumb_threshold){
         digiStore[0]=1;
         }
           else{
           digiStore[0]=0;
         };
      int i=analogRead(index);
       if(i>=index_threshold){
         digiStore[1]=1;
       }
           else{
           digiStore[1]=0;
         };
      int m=analogRead(middle);
       if(m>=middle_threshold){
         digiStore[2]=1;
       }
           else{
           digiStore[2]=0;
         };
      int r=analogRead(ring);
         if(r>=ring_threshold){
         digiStore[3]=1;
         }
         else{
         digiStore[3]=0;
         };
     int l=analogRead(little);
       if(l>=little_threshold){
       digiStore[4]=1;
       }
       else{
       digiStore[4]=0;
       };
       if(flag)
       {
        for(int k = 0; k<5; k++)
        {
          temp[k] = digiStore[k];
        }
        flag = false;
        time_old = millis();
       }
       if(!flag)
       {
        if(millis() - time_old > 1100)
        {
          if(temp[0] == digiStore[0] && temp[1] == digiStore[1] && temp[2] == digiStore[2] && temp[3] == digiStore[3] && temp[4] == digiStore[4])
            steadyValue = true;
          else
            steadyValue = false;
          if(steadyValue)
            {
              decVal=16*digiStore[0]+8*digiStore[1]+4*digiStore[2]+2*digiStore[3]+1*digiStore[4];
              //Serial.println(decVal);
              if(j!= 0 && words[j-1] == 32 && decVal == 31)
              {
              }
              else
              {
               // words[j]=lookupTable[decVal];
                //Serial.println(words[j]);
              // lcd.print(words[j]);
               // j++;
           /*     if(decVal == 31)
                {
                  
                for(int k = 0; ;k++)
                {
                  if(words[k]!= 32)
                    Serial.print(words[k]);
                   else
                   {
                    Serial.println("");
                    break;
                   }
                }
               }*/
         /*      if(decVal == 28)
               {
                for(int k = 0; ;k++)
                {
                  if(words[k]!= 46)
                    Serial.print(words[k]);
                   else
                   {
                    Serial.print(words[k]);
                       lcd.clear();
                    words[k+1] = '\0'; 
                    Serial.println("");
                   
                  //  strcpy(string,words);
                   // text2speech.sayText(string);
                    j = 0;
                 
                    break;
                   }
                   
                }
               }  
               */
               //////
               if(decVal ==0)
               {
                lcd.setCursor(0,0);
                lcd.print("hello");
                //delay(100);
                Serial.print("hello");
                delay(1000);
                lcd.clear();
               }  
               if(decVal == 16)
               {
                lcd.setCursor(0,0);
                lcd.print("How are u");
                //delay(100);
                Serial.print("How");
                delay(1000);
                Serial.print("are u");
                delay(1000);
               lcd.clear();
               }  
               if(decVal == 1)
               {
                 lcd.setCursor(0,0);
                lcd.print("i am fine");
               // delay(100);
                Serial.print("i am fine");
                delay(1000);
                lcd.clear();
               }  
               if(decVal == 4)
               {
                 lcd.setCursor(0,0);
                lcd.print("   MY NAME IS   ");
                lcd.setCursor(0,1);
                lcd.print("GLOVE");
                //delay(100);
                Serial.print("MY NAME");
                delay(1000);
                  Serial.print("IS GLOVE");
                   delay(1000);
                lcd.clear();
               } 
                
               if(decVal == 8)
               {
                lcd.setCursor(0,0);
                lcd.print("I need help ");
                //delay(100);
                Serial.print("i need");
                delay(1000);
                Serial.print("help");
                delay(1000);
                digitalWrite(buzzer,HIGH);
                delay(2000);
                digitalWrite(buzzer,LOW);
                lcd.clear();
               }   
               if(decVal == 2)
               {
                lcd.setCursor(0,0);
                lcd.print("  What is your   ");
                lcd.setCursor(0,1);
                lcd.print("name?");
                //delay(100);
                Serial.print("WHAT IS");
                delay(1000);
                Serial.print("YOUR");
                delay(500);
                Serial.print("NAME");
                delay(500);
                
                delay(3000);
                lcd.clear();
               } 
               if(decVal == 6)
               {
                lcd.setCursor(0,0);
                lcd.print("PLEASE DROP ME!!");
                //delay(100);
                lcd.setCursor(0,1);
                lcd.print("TO MY HOME");
                 Serial.print("PLEASE DROP ME");
                    delay(2000);
                 Serial.print("TO MY HOME");
                delay(1000);
                lcd.clear();
               }   
               if(decVal == 3)
               {
                lcd.setCursor(0,0);
                lcd.print("THANK YOU");
               Serial.print("THANK YOU");
                delay(1000);
                lcd.clear();
               }   
               

 if(decVal == 30)
               {
                lcd.setCursor(0,0);
                lcd.print("GOOD NIGHT");
                Serial.print("GOOD NIGHT");
               delay(2000);
                lcd.clear();
               }  
                if(decVal == 12)
               {
                lcd.setCursor(0,0);
                lcd.print("GOOD AFTERNOON");
                Serial.print("GOOD AFTERNOON");
               delay(2000);
                lcd.clear();
               }
                if(decVal == 18)
               {
                lcd.setCursor(0,0);
                lcd.print("I GOT IT...");
                Serial.print("I GOT IT");
               delay(2000);
                lcd.clear();
               }
               /////if we want to add more finger features add it in this part
              }
             }
             time_old = millis();
             steadyValue = false;
             flag = true;
       }
      }
}
/////////////////////////////// here we are switching the mode from text to speech to gamming by the help of toogle switch ,,,,,, &&&&&    here we are combining the processing part and arduino
if(s==1)
{
  int s=digitalRead(mode);
  if(Serial.available()>0)
  {
  int val=Serial.read();     // reads the Analog Input, t.e the value from the X - axis from the accelerometer
  Serial.print(val);     // sends that value into the Serial Port
  Serial.print(",");     // sends addition character right next to the read value needed  later in the Processing IDE for indexing
   Serial.print(";");
  
}
  }
////////////////////////////////
}

