#include <runtimer.h>

const int LED = 10; // set pin for led
const int LDR = A5; //set pin for photoresistor
int ambient;
int  brightness;
int inputval = 0; //variable for values to be read from A5
int outval = 0;   //variable for output value from A5


intervalTimer writeOutputTimer(100U);
intervalTimer readInputTimer(25U);
intervalTimer displayValuesTimer(500U);


void setup()
{
  delay(200U);
  Serial.begin(9600);
  //Initialize pinModes
  pinMode(LED, OUTPUT);
  pinMode(LDR, INPUT);
}

void loop()
{
  if (readInputTimer.expired())
  {
    inputval = analogRead(LDR);
    outval = map(inputval, 0, 100, 255, 0); 
  }

  if (writeOutputTimer.expired())
  {
    brightness = constrain(outval, 0, 255); 
    analogWrite(LED,brightness);
  
  }
  
  if(displayValuesTimer.expired()){
  ambient= analogRead(A5);
  Serial.print("ambient = ");
  Serial.print(ambient);
  Serial.print("|brightness = ");
  Serial.println(brightness);
  }


}
