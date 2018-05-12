#include <dht.h>

#include <PCD8544.h>

#define DHT11_PIN 8

dht DHT;

// A custom glyph (a smiley)...
static const byte glyph[] = { B00010000, B00110100, B00110000, B00110100, B00010000 };


static PCD8544 lcd;


void setup() {
  // PCD8544-compatible displays may have a different resolution...
  lcd.begin(84, 48);

  // Add the smiley to position "0" of the ASCII table...
  lcd.createChar(0, glyph);
}


void loop() {

  //delay(500);
  //counter++;

  // SENSOR

  int chk = DHT.read11(DHT11_PIN);
  lcd.setCursor(1,1);
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,4);
  lcd.print("Hum:  ");
  lcd.print(DHT.humidity);
  lcd.print("%");
  lcd.setCursor(40,2);
  lcd.write(0);  // write the smiley
  delay(500);

}


/* EOF - HelloWorld.ino */
