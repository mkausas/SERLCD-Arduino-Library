/**
 * Messing with the SerLCD Screen.
 * Created many methods that my be 
 * used to display various things...
 * @author Marty Kausas
 */

// Imports
#include <SoftwareSerial.h>
#include <serLCD.h>
 
// The PWM the SerLCD is connected to 
int lcdPWM = 8;
 
// Creating the serLCD object (doesn't need to be initialized)
serLCD lcd(lcdPWM);
 
// Example: Creating a custom character
byte smiley[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};
 
// Setup
void setup() {
  Serial.begin(9600); 
  
  // Setting the brightness (1 - 30)
  lcd.setBrightness(30);
  
  // Adding the custom character
  lcd.createChar(1, smiley);
  
  // Print the custom character
  //lcd.printCustomChar(1);

}
 
void loop() {
  
  // The showAndClear method takes an arguement and prints it all at once
  showAndClear("Fast!");
  
  // The dots method draws the amount of dots requested in the parameter slowly 
  dots(3);
  
  // The print slow method prints the string arguement slowly
  printSlow("Slow");
  
  // Clear screen clears the screen
  clearScreen();
  
  lcd.print("End, 3 second delay till reset");
  delay(3000);
}


/**
 * Prints text letter by letter with a 
 * one second delay in between.
 * @param String text
 */
void printSlow(String text) {
  lcd.clear();  
  for(int i = 0; i < text.length(); i++) {
   char temp = text.charAt(i);
   lcd.print(temp);
   if(temp != ' ')
     delay(1000); 
  }
}

/**
 * Prints text letter by letter with a 
 * time delay of choice.
 * @param String text
 * @param int seconds
 */
 // TODO: Fix the . problem...
void printSlow(String text, int seconds) {
  lcd.clear();  
  for(int i = 0; i < text.length(); i++) {
   char temp = text.charAt(i);
   lcd.print(temp);
   if(temp != ' ')
     delay(seconds * 1000); 
  }
}

// TODO: Finish this...
void setPosition(int pos) {
  if(pos == 2) 
   lcd.selectLine(pos);
}

/**
 * Prints dots with a second 
 * in between each print 
 * @param int amount
 */
void dots(int amount) {
  for(int i = 0; i < amount; i++) {
   lcd.print(".");
   delay(1000); 
  }
  lcd.clear();
}

/**
 * Prints text for a second.
 * @param String text
 */
void showAndClear(String text) {
 int millisDelay = 2;
 lcd.clear();
 delay(1000);
 lcd.print(text);
 delay(1000); 
}

/**
 * Prints text with a
 * for as long you code it to.
 * @param String text
 * @param int seconds
 */
void showAndClear(String text, int seconds) {
 int millisDelay = seconds * 1000;
 lcd.clear();
 delay(millisDelay);
 lcd.print(text);
 delay(millisDelay); 
}

/**
 * Clears the screen...
 */
void clearScreen() { lcd.clear(); }


