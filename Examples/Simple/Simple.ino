/* A simple example to better understand how this library works
  and how its elements are used.

  Note that this example is for a microMicrocontroller STM32
  and you should modify it for your case if needed.

  This code is written by Siavash Alizadeh
  Saturday, February 15, 2025
  Tecfield@live.com
  https://github.com/Tecfield-SIA
  www.linkedin.com/in/siavash-alizadeh-tecfield
*/


#include <Lightweight_SSD1306.h>

// Define the display with 128x64 resolution
Lightweight_SSD1306 display(128, 64);

void setup() {
  // Set I2C pins (PB7 for SDA, PB6 for SCL)
  Wire.setSDA(PB7);
  Wire.setSCL(PB6);
  Wire.begin();

  Serial.begin(9600);
  // Initialize the display with I2C address 0x3C
  if (!display.begin()) {  // I2C address of the display
    Serial.println("Display not found!");
    while (1);  // Halt if the display is not found
  }

  display.clearDisplay();  // Clear the display

  // Display text
  display.setTextSize(1);    // Set text size (1 for small)
  display.setTextColor(1);   // Set text color (1 for white, 0 for black)
  display.setCursor(0, 0);   // Set text cursor position
  display.print("Tecfield-SIA");  // Display text

  // Display larger text
  display.setTextSize(2);    // Set text size (2 for large)
  display.setCursor(10, 50); // Set text cursor position
  display.print("TECFIELD"); // Display text

  // Draw shapes
  display.drawLine(0, 10, 127, 10, 1);  // Draw a horizontal line
  display.drawRect(10, 15, 50, 20, 1);  // Draw an outlined rectangle
  display.fillRect(70, 15, 50, 20, 1);  // Draw a filled rectangle
  display.drawPixel(64, 40, 1);         // Draw a single pixel

  // Display a simple bitmap
  const uint8_t bitmap[] = {
    0b00111100,
    0b01000010,
    0b10100101,
    0b10000001,
    0b10100101,
    0b10011001,
    0b01000010,
    0b00111100
  };
  display.drawBitmap(40, 38, bitmap, 8, 8, 1);  // Display the bitmap

  // Update the display to show the content
  display.display();
}

void loop() {
  // Do nothing in the loop
}
