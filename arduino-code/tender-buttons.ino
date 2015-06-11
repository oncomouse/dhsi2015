/*
  Sixth Dimensional Stein
  
  We put Gertrude Stein in a box.
  
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
   * ends to +5V and ground
   * wiper to LCD VO pin
 * servo motor:
   * ends to +5V and gorund
   * connected to digital pin 9
 * touch sensor:
   * ends to +5V and gorund
   * connected to digital pin 10
 */

// Array of 20 character fragments:
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
// Length of the array (may be able to calculate this):
const int lineSize = 80; // sizeof(lines) / (20 * sizeof(char));

// Pin Addresses:
const int touchPin = 10;
const int servoPin = 9;

// How fast to open the box:
const int boxStep = 30;
const int boxPosition[] = {0,90};

// LCD dimensions:
const int lcdSize[] = {20,4};

// Configure the LCD:
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Initialize the servo:
#include <Servo.h>
Servo myservo;

void setup() {
  // Seed the random number generator:
  randomSeed(analogRead(0));

  // Initialize the LCD:
  lcd.begin(lcdSize[0], lcdSize[1]);
  
  // Position the servo:
  myservo.attach(servoPin);
  myservo.write(boxPosition[0]);
  
  // Initialize the touch sensor:
  pinMode(touchPin, INPUT);
  
}

void loop() {

  // If the touch sensor is HIGH:
  if(digitalRead(touchPin) == HIGH) {
    // Open the box:
    for(int i=boxPosition[0];i<=boxPosition[1];i++) {
      myservo.write(i);
      delay(boxStep);
    }
    // Turn on the LCD:
    lcd.display();
    
    // Write the four random lines:
    lcd.setCursor(0, 0);
    lcd.print(lines[random(lineSize)]);
    lcd.setCursor(0, 1);
    lcd.print(lines[random(lineSize)]);
    lcd.setCursor(0, 2);
    lcd.print(lines[random(lineSize)]); 
    lcd.setCursor(0, 3);
    lcd.print(lines[random(lineSize)]);
    
    // Display the poem until the touch sensor goes to LOW:
    do {
      delay(5);
    } while(digitalRead(touchPin) == HIGH);
    
    // Close the box:
    for(int i=boxPosition[1];i>=boxPosition[0];i--) {
      myservo.write(i);
      delay(boxStep);
    }
    lcd.noDisplay();
  }
  
  
}
