int Value=0;
#include <SoftwareSerial.h>
SoftwareSerial sim800l(6,5);
void setup(){
pinMode(9,OUTPUT);
digitalWrite(9,LOW);
delay(1000);
digitalWrite(9,HIGH);
delay(2000);
digitalWrite(9, LOW);
delay(3000);
Serial.begin(9600);   //Module baude rate, this is on max, it depends on the version
sim800l.begin(9600);  
  delay(1000);
  Value=1;}

  
void loop(){


  if(Value==1)
  {
Serial.print("AT+CMGF=1\r");
 Serial.print("AT+CMGF=1\r");                   //Set the module to SMS mode
  delay(100);
  if (Serial.available()){            //Displays on the serial monitor if there's a communication from the module
 sim800l.write(Serial.read()); }
  Serial.print("AT+CMGS=\"0021620121908\"\r");  //Your phone number don't forget to include your country code, example +212123456789"
  delay(500);
  if (Serial.available()){            //Displays on the serial monitor if there's a communication from the module
 sim800l.write(Serial.read());
}
 Serial.print("1");       //This is the text to send to the phone number, don't make it too long or you have to modify the SoftwareSerial buffer
  delay(500);
 if (Serial.available()){            //Displays on the serial monitor if there's a communication from the module
 sim800l.write(Serial.read());
}
  Serial.print((char)26);// (required according to the datasheet)
  delay(500);
 
  if (Serial.available()){            //Displays on the serial monitor if there's a communication from the module
 sim800l.write(Serial.read());
}
Serial.println();
  sim800l.println("Text Sent.");
  delay(500);
if (Serial.available()){            //Displays on the serial monitor if there's a communication from the module
 sim800l.write(Serial.read());
} }

}
