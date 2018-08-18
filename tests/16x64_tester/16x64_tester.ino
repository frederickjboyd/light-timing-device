// testshapes demo for Adafruit RGBmatrixPanel library.
// Demonstrates the drawing abilities of the RGBmatrixPanel library.
// For 16x32 RGB LED matrix:
// http://www.adafruit.com/products/420

// Written by Limor Fried/Ladyada & Phil Burgess/PaintYourDragon
// for Adafruit Industries.
// BSD license, all text above must be included in any redistribution.

#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

#define CLK 11  // MUST be on PORTB! (Use pin 11 on Mega)
#define LAT A15
#define OE  9
#define A   A12
#define B   A13
#define C   A14
RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false, 64);

void setup() {

  matrix.begin();
  
  // draw a pixel in solid white
  matrix.drawPixel(0, 0, matrix.Color333(7, 7, 7)); 
  delay(500);

  // fix the screen with green
  matrix.fillRect(0, 0, 16, 16, matrix.Color333(7, 7, 0));
  matrix.fillRect(16, 0, 16, 16, matrix.Color333(0, 7, 7));
  matrix.fillRect(32, 0, 16, 16, matrix.Color333(7, 0, 7));
  matrix.fillRect(48, 0, 16, 16, matrix.Color333(0, 0, 7));
  delay(500);

  // whew!
}

void loop() {
  // do nothing
}
