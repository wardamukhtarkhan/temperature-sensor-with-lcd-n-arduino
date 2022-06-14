#include <LiquidCrystal.h>

LiquidCrystal lcd(2,3,4,5,6,7);
#define temp A0

void setup() {
  pinMode(temp, INPUT);
  lcd.begin(16,2);
  Serial.begin(9600);
}
void loop(){
  int RawValue = analogRead(temp);
 
  float Volatage = (RawValue/ 1023.0) * 5000; //to get millis
  float tempC = (Volatage-500) * 0.1;  // 500 is the offset
  Serial.print("Temperature in C =");
  Serial.println(tempC,1);
 
  int humidity = analogRead(temp);
  Serial.print("Humidity:");
  Serial.print(map(humidity, 0, 1023, 10, 70));
  Serial.println("%");
 
  Serial.println("----------------");
  
  lcd.setCursor(0, 0);
  lcd.print("Temp");
  lcd.print(tempC);
  lcd.print("C");
    
  lcd.setCursor(0, 1);
  lcd.print("Hum");
  lcd.print(humidity);
  lcd.print("%");  
  
}