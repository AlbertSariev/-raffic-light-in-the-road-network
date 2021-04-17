#include <LiquidCrystal.h>
//Declaring LCD.
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
double clock=2;//Еnter a real time!

void setup()
{
  lcd.begin(16, 2);
  lcd.print("");
  //Declaring LED.
   pinMode(8, OUTPUT);
   pinMode(9, OUTPUT);
   pinMode(10, OUTPUT);
  pinMode(A0, INPUT); 
  Serial.begin(9600);
}

void loop() 
{
  //Check condition on time.
  if(clock>=23.00||clock<=5.00)
  {
   // Set the value of LCD.
     lcd.print("BE CAREFULLY!");
   
    //Potentiometre.
    int state = analogRead(A0); 
    Serial.println(state);
     //Flashing control LED.
    digitalWrite(9, HIGH); 
    delay(state);
    digitalWrite(9, LOW); 
    delay(state);
    lcd.clear();//Clear information from LCD.
    delay(1000);//The time between flashing.
  }
  else
  {
    while (true)
    {
      //Potentiometre.
      int state = analogRead(A0);
      Serial.println(state);
      delay(10);
      
     // Changing the voltage in the LCD.
    analogWrite(10, map(state, 0, 1023, 0, 255));
    lcd.print("STOP!");// Set the value of LCD.
    delay(1000);//The time when the LED is lit.
    analogWrite(10,LOW);
    lcd.clear();//Clear information from LCD.
      
      // Changing the voltage in the LCD.
    analogWrite(9,map(state, 0, 1023, 0, 255));
    lcd.print("BE CAREFULLY!");// Set the value of LCD.
    delay(1000);//The time when the LED is lit.
    analogWrite(9,LOW);
    lcd.clear();//Clear information from LCD.
      
      // Changing the voltage in the LCD.
    analogWrite(8,map(state, 0, 1023, 0, 255));
    lcd.print("GO!");// Set the value of LCD.
    delay(1000);//The time when the LED is lit.
    analogWrite(8,LOW);
    lcd.clear();//Clear information from LCD.
      
      // Changing the voltage in the LCD.
    analogWrite(9,map(state, 0, 1023, 0, 255));
    lcd.print("BE CAREFULLY!");// Set the value of LCD.
    delay(1000);//The time when the LED is lit.
    analogWrite(9,LOW);
    lcd.clear();//Clear information from LCD.
    }
  }
}