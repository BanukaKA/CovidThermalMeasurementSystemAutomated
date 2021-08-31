/* MLX90614 IR(Non Contact) Temperature Sensor with Arduino
   By Banuka Ambegoda , DRCK Robetics Club
   Download Sensor Library: https://github.com/adafruit/Adafruit-MLX90614-Library
*/

//Including the necessary libraries
#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <LiquidCrystal.h>

//Defining the object for mlx
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

//Defining the LCD
int Contrast=75;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  

//Defining the variable
float tempC;
float tempF;

void setup() {
  Serial.begin(9600);         //Initializing the Serial Port to Baud rate 9600
  Serial.println("Start the Temperature Alarming");
  mlx.begin();     //Initializing the MLX90614 sensor
  analogWrite(3,Contrast); 
  lcd.begin(16, 2);          // Initializing the LCD
  pinMode(2,OUTPUT);        //Initializing the LED 
  pinMode(3,OUTPUT);       //Initializing the Buz
}

void loop() {

  //Reading the data from the sensor and printing it on Serial terminal

  tempC = mlx.readAmbientTempC();
  tempF = mlx.readObjectTempF();
  
  Serial.print("Temperature = "); Serial.print(mlx.readAmbientTempC());
  Serial.print("*C\tObject = "); Serial.print(mlx.readObjectTempC()); Serial.println("*C");
  Serial.print("Temperature = "); Serial.print(mlx.readAmbientTempF());
  Serial.print("*F\tObject = "); Serial.print(mlx.readObjectTempF()); Serial.println("*F");
  Serial.println();

  if(tempF>97)
    {
      lcd.setCursor(0, 0);
      lcd.autoscroll();
      lcd.print(tempC + "C" + " or " + tempF + "F" + "A Human Detected");
      delay(50);
      
      
      if(tempF>100.4)
      {

       //If fever
      digitalWrite(1,HIGH);
      delay(20);
      digitalWrite(8,HIGH);
      delay(20);
      digitalWrite(8,LOW);
      delay(20);
      digitalWrite(1,LOW);
      delay(20);

      digitalWrite(1,HIGH);
      delay(20);
      digitalWrite(8,HIGH);
      delay(20);
      digitalWrite(8,LOW);
      delay(20);
      digitalWrite(1,LOW);
      delay(20);

      digitalWrite(1,HIGH);
      delay(20);
      digitalWrite(8,HIGH);
      delay(20);
      digitalWrite(8,LOW);
      delay(20);
      digitalWrite(1,LOW);
      delay(20);
      }
    }
    
  
  
  delay(500);

  
}
