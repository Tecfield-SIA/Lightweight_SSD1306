#ifndef LIGHTWEIGHT_SSD1306_H
#define LIGHTWEIGHT_SSD1306_H

#include <Arduino.h>
#include <Wire.h>

#define SSD1306_I2C_ADDRESS 0x3C 

class Lightweight_SSD1306 {
public:
    Lightweight_SSD1306(uint8_t width = 128, uint8_t height = 64);

    bool begin(uint8_t i2c_addr = SSD1306_I2C_ADDRESS, TwoWire *wire = &Wire);
    void clearDisplay();
    void display();
    void drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color = 1);
    void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color = 1);
    void setTextSize(uint8_t size);
    void setTextColor(uint16_t color);
    void setCursor(int16_t x, int16_t y);
    void print(const char *text);
    void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color = 1);
    void drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color = 1);
    void drawPixel(int16_t x, int16_t y, uint16_t color = 1);

private:
    void sendCommand(uint8_t command);
    void sendData(uint8_t *data, size_t size);
    void drawChar(int16_t x, int16_t y, char c, uint16_t color, uint8_t size);

    uint8_t _width;
    uint8_t _height;
    uint8_t _i2c_addr;
    TwoWire *_wire;
    uint8_t _buffer[1024]; 

    uint8_t _textSize;
    uint16_t _textColor;
    int16_t _cursorX;
    int16_t _cursorY;

    static const uint8_t font[];
};

#endif
