char* lines[] = {
  "Out of kindness     ",
  "comes redness and   ",
  "out of rudeness     ",
  "comes rapid same    ",
  "question out of an  ",
  "eye comes research  ",
  "out of selection    ",
  "comes painful cattle",
  "So then the order is",
  "that a white way of ",
  "being round is      ",
  "something suggesting",
  "a pin and is it     ",
  "disappointing it is ",
  "not it is so        ",
  "rudimentary to be   ",
  "analysed and see a  ",
  "fine substance      ",
  "strangely it is so  ",
  "earnest to have a   ",
  "green point not to  ",
  "red but to point    ",
  "again A large box is",
  "handily made of what",
  "is necessary to     ",
  "replace any         ",
  "substance Suppose an",
  "example is necessary",
  "the plainer it is   ",
  "made the more reason",
  "there is for some   ",
  "outward recognition ",
  "that there is a     ",
  "result A box is made",
  "sometimes and them  ",
  "to see to see to it ",
  "neatly and to have  ",
  "the holes stopped up",
  "makes it necessary  ",
  "to use paper A      ",
  "custom which is     ",
  "necessary when a box",
  "is used and taken is",
  "that a large part of",
  "the time there are  ",
  "three which have    ",
  "different           ",
  "connections The one ",
  "is on the table The ",
  "two are on the table",
  "The three are on the",
  "table The one one is",
  "the same length as  ",
  "is shown by the     ",
  "cover being longer  ",
  "different there is  ",
  "more cover that     ",
  "shows it The other  ",
  "is different and    ",
  "corners have the    ",
  "same shade the eight",
  "are in singular     ",
  "arrangement to make ",
  "four necessary Lax  ",
  "to have corners to  ",
  "be lighter than some",
  "weight to indicate a",
  "wedding journey to  ",
  "last brown and not  ",
  "wealthy cigarettes  ",
  "are established by  ",
  "doubling Left open  ",
  "to be left pounded  ",
  "to be left closed to",
  "be circulating in   ",
  "summer and winter   ",
  "and sick color that ",
  "is grey that is not ",
  "dusty and red shows "
};
const int lineSize = 80;
const int touchPin = 10;

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#include <Servo.h>
Servo myservo;

void setup() {
  // put your setup code here, to run once:
  randomSeed(analogRead(0));
  lcd.begin(20, 4);
  myservo.attach(9);
  pinMode(touchPin, INPUT);
  myservo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(touchPin) == HIGH) {
    for(int i=0;i<=90;i++) {
      myservo.write(i);
      delay(30);
    }
    lcd.display();
    lcd.setCursor(0, 0);
    lcd.print(lines[random(lineSize)]);
    lcd.setCursor(0, 1);
    lcd.print(lines[random(lineSize)]);
    lcd.setCursor(0, 2);
    lcd.print(lines[random(lineSize)]); 
    lcd.setCursor(0, 3);
    lcd.print(lines[random(lineSize)]);
    do {
      delay(5);
    } while(digitalRead(touchPin) == HIGH);
    
    for(int i=90;i>=0;i--) {
      myservo.write(i);
      delay(30);
    }
    lcd.noDisplay();
  }
  
  
}
