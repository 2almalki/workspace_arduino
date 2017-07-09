//LM35 output voltage has a linear relation with the Celsius temperature, output of 0 v when 0 ℃, 
//every increase 1 ℃, the output voltage increase 10 mv
#define lmPin A0  //LM35 attach to
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

float tem = 0;
long lmVal = 0;
long previousMillis = 0;
long interval = 1000;

void setup()
{
  lcd.begin();  //initialize the lcd
  lcd.backlight();  //open the backlight 
}

void loop()
{
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis > interval){
    lmVal = analogRead(lmPin);
    tem = (lmVal * 0.0048828125 * 100);//to get temp
    lcd.setCursor(5,0);
    lcd.print("LM35");
    lcd.setCursor(0,1);
    lcd.print("Tem= ");
    lcd.setCursor(5,1);
    lcd.print(tem);
    lcd.print(" C");
  } 
}
