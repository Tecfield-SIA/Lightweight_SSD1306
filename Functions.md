# Library Functions

## Constructor
```c++
Lightweight_SSD1306(uint8_t width = 128, uint8_t height = 64);
```

####	Description: 
- Creates an instance of the Lightweight_SSD1306 class.
####	Parameters:
-	width: Display width (default: 128).
-	height: Display height (default: 64).
#### Example:
```C++
Lightweight_SSD1306 display(128, 64);
Lightweight_SSD1306 display(128, 32);
```

---------------------------------------------------------------------------------------------------------
## begin Function
```c++
bool begin(uint8_t i2c_addr = SSD1306_I2C_ADDRESS, TwoWire *wire = &Wire);
```

####	Description: 
- Initializes the display.
####	Parameters:
-	i2c_addr: I2C address of the display (default: 0x3C).
-	wire: Pointer to the Wire object (default: &Wire).
####	Returns:
- true if the display is found, otherwise false.
#### Example:
```c++
display.begin(); // It automatically uses (0x3C) address as default
display.begin(0x3C);
```

---------------------------------------------------------------------------------------------------------
## clearDisplay Function
```c++
void clearDisplay();
```

#### Description: 
- Clears the entire display.
#### Example:
```c++
display.clearDisplay();
```

---------------------------------------------------------------------------------------------------------
## display Function
```c++
void display();
```

#### Description: 
- Updates the display with the contents of the buffer.
#### Example:
```c++
display.display();
```

---------------------------------------------------------------------------------------------------------
## drawBitmap Function
```c++
void drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color = 1);
```

#### Description: 
- Draws a bitmap on the display.
#### Parameters:
-	x: Horizontal starting position of the bitmap.
-	y: Vertical starting position of the bitmap.
-	bitmap: Array containing the bitmap data.
-	w: Width of the bitmap.
-	h: Height of the bitmap.
-	color: Color of the bitmap (1 for white, 0 for black).
#### Example:
```c++
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
  display.drawBitmap(40, 38, bitmap, 8, 8, 1);
```

---------------------------------------------------------------------------------------------------------
## fillRect Function
```c++
void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color = 1);
```

#### Description: 
- Draws a filled rectangle.
#### Parameters:
-	x: Horizontal starting position of the rectangle.
-	y: Vertical starting position of the rectangle.
-	w: Width of the rectangle.
-	h: Height of the rectangle.
-	color: Color of the rectangle (1 for white, 0 for black).
#### Example:
```c++
display.fillRect(70, 15, 50, 20, 1);
display.fillRect(75, 20, 40, 10, 0);
```

---------------------------------------------------------------------------------------------------------
## setTextSize Function
```c++
void setTextSize(uint8_t size);
```

#### Description: 
- Sets the text size.
#### Parameters:
-	size: Text size (1 for small, 2 for large).
#### Example:
```c++
display.setTextSize(1);
display.setTextSize(2);
```

---------------------------------------------------------------------------------------------------------
## setTextColor Function
```c++
void setTextColor(uint16_t color);
```

#### Description: 
- Sets the text color.
#### Parameters:
-	color: Text color (1 for white, 0 for black).
#### Example:
```c++
display.setTextColor(1);
display.setTextColor(0);
```

---------------------------------------------------------------------------------------------------------
## setCursor Function
```c++
void setCursor(int16_t x, int16_t y);
```

#### Description:
- Sets the text cursor position.
#### Parameters:
-	x: Horizontal starting position of the text.
-	y: Vertical starting position of the text.
#### Example:
```c++
display.setCursor(0, 0);
display.setCursor(50, 40);
```

---------------------------------------------------------------------------------------------------------
## print Function
```c++
void print(const char *text);
```

#### Description: 
- Displays text on the screen.
#### Parameters:
-	text: The text to display.
#### Example:
```c++
display.print("Tecfield-SIA");
```

---------------------------------------------------------------------------------------------------------
## drawLine Function
```c++
void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color = 1);
```

#### Description: 
- Draws a line.
#### Parameters:
-	x0: Horizontal starting position of the line.
-	y0: Vertical starting position of the line.
-	x1: Horizontal ending position of the line.
-	y1: Vertical ending position of the line.
-	color: Color of the line (1 for white, 0 for black).
#### Example:
```c++
display.drawLine(0, 10, 127, 20, 1);
display.drawLine(0, 20, 127, 10, 1);

display.fillRect(0, 30, 128, 20, 1);
display.drawLine(10, 40, 118, 40, 0);
```

---------------------------------------------------------------------------------------------------------
## drawRect Function
```c++
void drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color = 1);
```

#### Description: 
- Draws an outlined rectangle.
#### Parameters:
-	x: Horizontal starting position of the rectangle.
-	y: Vertical starting position of the rectangle.
-	w: Width of the rectangle.
-	h: Height of the rectangle.
-	color: Color of the rectangle (1 for white, 0 for black).
#### Example:
```c++
display.drawRect(10, 10, 50, 20, 1);

display.fillRect(0, 40, 60, 20, 1);
display.drawRect(5, 45, 50, 10, 0);
```

---------------------------------------------------------------------------------------------------------
## drawPixel Function
```c++
void drawPixel(int16_t x, int16_t y, uint16_t color = 1);
```

#### Description: 
- Draws a single pixel.
#### Parameters:
-	x: Horizontal position of the pixel.
-	y: Vertical position of the pixel.
-	color: Color of the pixel (1 for white, 0 for black).
#### Example:
```c++
display.drawPixel(64, 40, 1);
```

