/* Micro SD TF Card Memory Module [S059] : http://rdiot.tistory.com/109 [RDIoT Demo] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <SD.h> // include the SD library

LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004

File myFile;

void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");

  delay(1000);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("S059:microSD Adapter");

  lcd.setCursor(0,1);
  lcd.print("Initializing SD Card");

  if (!SD.begin(4)) {
    lcd.setCursor(0,1);
    lcd.print("Initialize Failed   ");
    return;
  }

  lcd.setCursor(0,1);
  lcd.print("Initialization done");

  myFile = SD.open("test5.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {

    lcd.setCursor(0,1);
    lcd.print("Writing to test.txt ");
    myFile.println("text");
    
    // close the file:
    myFile.close();
    lcd.setCursor(0,2);
    lcd.print("writing done.");
  } else {

    lcd.setCursor(0,2);
    lcd.print("error opening test.txt");
  }

  // re-open the file for reading:
  myFile = SD.open("test5.txt");
  if (myFile) {
    lcd.setCursor(0,3);
    lcd.print("Read test.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      lcd.write(myFile.read());

    } 
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    lcd.setCursor(0,2);
    lcd.print("error opening test.txt");
  }

}
