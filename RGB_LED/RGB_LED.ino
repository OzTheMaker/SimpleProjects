#include <LiquidCrystal.h>

#define RED_PIN 6
#define GREEN_PIN 10
#define BLUE_PIN 9 
#define potRed A0
#define potGreen A1
#define potBlue A2 

const int rs = 11, en = 12, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

int redLevel = 0;
int greenLevel = 0;
int blueLevel = 0;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  //LCD Setup
  lcd.begin(16, 2);
}

void loop() {

  redLevel = analogRead(potRed)/4;
  greenLevel = analogRead(potGreen)/4;
  blueLevel = analogRead(potBlue)/4;

  lcd.clear();
  lcd.home();
  lcd.print("R: ");
  lcd.print(redLevel);
  lcd.print("    ");
  lcd.print("G: ");
  lcd.print(greenLevel);
  lcd.setCursor(0,1);
  lcd.leftToRight();
  lcd.print("B: ");
  lcd.print(blueLevel);

  setColor(redLevel, greenLevel, blueLevel);
  delay(100);
}

//Function that changes the color of the RGB_LED
void setColor(int R, int G, int B){
  analogWrite(RED_PIN, R);
  analogWrite(GREEN_PIN, G);
  analogWrite(BLUE_PIN, B);
}
