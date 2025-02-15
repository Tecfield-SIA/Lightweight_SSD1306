/* Lightweight_SSD1306.cpp
  this file is part of Lightweight_SSD1306 library

  written by Siavash alizadeh (TECFIELD)
  https://github.com/Tecfield-SIA
  www.linkedin.com/in/siavash-alizadeh-tecfield

  The Lightweight_SSD1306 library is inspired by 
  the Adafruit_SSD1306 library but is not a direct copy or modification of it.
  https://github.com/adafruit/Adafruit_SSD1306
*/

#include "Lightweight_SSD1306.h"
#include <Arduino.h>

const uint8_t Lightweight_SSD1306::font[] PROGMEM = {
    0x00, 0x00, 0x00, 0x00, 0x00, // (space)
    0x00, 0x00, 0x5F, 0x00, 0x00, // !
    0x00, 0x07, 0x00, 0x07, 0x00, // "
    0x14, 0x7F, 0x14, 0x7F, 0x14, // #
    0x24, 0x2A, 0x7F, 0x2A, 0x12, // $
    0x23, 0x13, 0x08, 0x64, 0x62, // %
    0x36, 0x49, 0x55, 0x22, 0x50, // &
    0x00, 0x05, 0x03, 0x00, 0x00, // '
    0x00, 0x1C, 0x22, 0x41, 0x00, // (
    0x00, 0x41, 0x22, 0x1C, 0x00, // )
    0x08, 0x2A, 0x1C, 0x2A, 0x08, // *
    0x08, 0x08, 0x3E, 0x08, 0x08, // +
    0x00, 0x50, 0x30, 0x00, 0x00, // ,
    0x08, 0x08, 0x08, 0x08, 0x08, // -
    0x00, 0x60, 0x60, 0x00, 0x00, // .
    0x20, 0x10, 0x08, 0x04, 0x02, // /
    0x3E, 0x51, 0x49, 0x45, 0x3E, // 0
    0x00, 0x42, 0x7F, 0x40, 0x00, // 1
    0x42, 0x61, 0x51, 0x49, 0x46, // 2
    0x21, 0x41, 0x45, 0x4B, 0x31, // 3
    0x18, 0x14, 0x12, 0x7F, 0x10, // 4
    0x27, 0x45, 0x45, 0x45, 0x39, // 5
    0x3C, 0x4A, 0x49, 0x49, 0x30, // 6
    0x01, 0x71, 0x09, 0x05, 0x03, // 7
    0x36, 0x49, 0x49, 0x49, 0x36, // 8
    0x06, 0x49, 0x49, 0x29, 0x1E, // 9
    0x00, 0x36, 0x36, 0x00, 0x00, // :
    0x00, 0x56, 0x36, 0x00, 0x00, // ;
    0x00, 0x08, 0x14, 0x22, 0x41, // <
    0x14, 0x14, 0x14, 0x14, 0x14, // =
    0x41, 0x22, 0x14, 0x08, 0x00, // >
    0x02, 0x01, 0x51, 0x09, 0x06, // ?
    0x32, 0x49, 0x79, 0x41, 0x3E, // @
    0x7E, 0x11, 0x11, 0x11, 0x7E, // A
    0x7F, 0x49, 0x49, 0x49, 0x36, // B
    0x3E, 0x41, 0x41, 0x41, 0x22, // C
    0x7F, 0x41, 0x41, 0x22, 0x1C, // D
    0x7F, 0x49, 0x49, 0x49, 0x41, // E
    0x7F, 0x09, 0x09, 0x09, 0x01, // F
    0x3E, 0x41, 0x49, 0x49, 0x7A, // G
    0x7F, 0x08, 0x08, 0x08, 0x7F, // H
    0x00, 0x41, 0x7F, 0x41, 0x00, // I
    0x20, 0x40, 0x41, 0x3F, 0x01, // J
    0x7F, 0x08, 0x14, 0x22, 0x41, // K
    0x7F, 0x40, 0x40, 0x40, 0x40, // L
    0x7F, 0x02, 0x04, 0x02, 0x7F, // M
    0x7F, 0x04, 0x08, 0x10, 0x7F, // N
    0x3E, 0x41, 0x41, 0x41, 0x3E, // O
    0x7F, 0x09, 0x09, 0x09, 0x06, // P
    0x3E, 0x41, 0x51, 0x21, 0x5E, // Q
    0x7F, 0x09, 0x19, 0x29, 0x46, // R
    0x46, 0x49, 0x49, 0x49, 0x31, // S
    0x01, 0x01, 0x7F, 0x01, 0x01, // T
    0x3F, 0x40, 0x40, 0x40, 0x3F, // U
    0x1F, 0x20, 0x40, 0x20, 0x1F, // V
    0x7F, 0x20, 0x18, 0x20, 0x7F, // W
    0x63, 0x14, 0x08, 0x14, 0x63, // X
    0x03, 0x04, 0x78, 0x04, 0x03, // Y
    0x61, 0x51, 0x49, 0x45, 0x43, // Z
    0x00, 0x7F, 0x41, 0x41, 0x00, // [
    0x02, 0x04, 0x08, 0x10, 0x20, // backslash
    0x00, 0x41, 0x41, 0x7F, 0x00, // ]
    0x04, 0x02, 0x01, 0x02, 0x04, // ^
    0x40, 0x40, 0x40, 0x40, 0x40, // _
    0x00, 0x01, 0x02, 0x04, 0x00, // `
    0x20, 0x54, 0x54, 0x54, 0x78, // a
    0x7F, 0x48, 0x44, 0x44, 0x38, // b
    0x38, 0x44, 0x44, 0x44, 0x20, // c
    0x38, 0x44, 0x44, 0x48, 0x7F, // d
    0x38, 0x54, 0x54, 0x54, 0x18, // e
    0x08, 0x7E, 0x09, 0x01, 0x02, // f
    0x08, 0x14, 0x54, 0x54, 0x3C, // g
    0x7F, 0x08, 0x04, 0x04, 0x78, // h
    0x00, 0x44, 0x7D, 0x40, 0x00, // i
    0x20, 0x40, 0x44, 0x3D, 0x00, // j
    0x7F, 0x10, 0x28, 0x44, 0x00, // k
    0x00, 0x41, 0x7F, 0x40, 0x00, // l
    0x7C, 0x04, 0x18, 0x04, 0x78, // m
    0x7C, 0x08, 0x04, 0x04, 0x78, // n
    0x38, 0x44, 0x44, 0x44, 0x38, // o
    0x7C, 0x14, 0x14, 0x14, 0x08, // p
    0x08, 0x14, 0x14, 0x18, 0x7C, // q
    0x7C, 0x08, 0x04, 0x04, 0x08, // r
    0x48, 0x54, 0x54, 0x54, 0x20, // s
    0x04, 0x3F, 0x44, 0x40, 0x20, // t
    0x3C, 0x40, 0x40, 0x20, 0x7C, // u
    0x1C, 0x20, 0x40, 0x20, 0x1C, // v
    0x3C, 0x40, 0x30, 0x40, 0x3C, // w
    0x44, 0x28, 0x10, 0x28, 0x44, // x
    0x0C, 0x50, 0x50, 0x50, 0x3C, // y
    0x44, 0x64, 0x54, 0x4C, 0x44, // z
    0x00, 0x08, 0x36, 0x41, 0x00, // {
    0x00, 0x00, 0x7F, 0x00, 0x00, // |
    0x00, 0x41, 0x36, 0x08, 0x00, // }
    0x08, 0x04, 0x08, 0x10, 0x08, // ~
};

Lightweight_SSD1306::Lightweight_SSD1306(uint8_t width, uint8_t height)
    : _width(width), _height(height), _i2c_addr(SSD1306_I2C_ADDRESS), _wire(&Wire),
      _textSize(1), _textColor(1), _cursorX(0), _cursorY(0) {
    memset(_buffer, 0, sizeof(_buffer));
}

bool Lightweight_SSD1306::begin(uint8_t i2c_addr, TwoWire *wire) {
    _i2c_addr = i2c_addr;
    _wire = wire;

    _wire->begin();
    _wire->beginTransmission(_i2c_addr);
    if (_wire->endTransmission() != 0) {
        return false; 
    }

    sendCommand(0xAE); 
    sendCommand(0xD5); 
    sendCommand(0x80);
    sendCommand(0xA8); 
    sendCommand(_height - 1);
    sendCommand(0xD3); 
    sendCommand(0x00);
    sendCommand(0x40 | 0x00); 
    sendCommand(0x8D); 
    sendCommand(0x14);
    sendCommand(0x20); 
    sendCommand(0x00);
    sendCommand(0xA1);
    sendCommand(0xC8);
    sendCommand(0xDA);
    sendCommand(0x12);
    sendCommand(0x81);
    sendCommand(0xCF);
    sendCommand(0xD9);
    sendCommand(0xF1);
    sendCommand(0xDB);
    sendCommand(0x40);
    sendCommand(0xA4);
    sendCommand(0xA6);
    sendCommand(0xAF);

    clearDisplay();
    display();
    return true;
}

void Lightweight_SSD1306::clearDisplay() {
    memset(_buffer, 0, sizeof(_buffer));
}

void Lightweight_SSD1306::display() {
    for (uint8_t page = 0; page < 8; page++) {
        sendCommand(0xB0 + page); 
        sendCommand(0x00); 
        sendCommand(0x10); 

        _wire->beginTransmission(_i2c_addr);
        _wire->write(0x40); 
        for (uint16_t i = 0; i < 128; i++) {
            _wire->write(_buffer[i + page * 128]);
        }
        _wire->endTransmission();
    }
}

void Lightweight_SSD1306::setTextSize(uint8_t size) {
    _textSize = size;
}

void Lightweight_SSD1306::setTextColor(uint16_t color) {
    _textColor = color;
}

void Lightweight_SSD1306::setCursor(int16_t x, int16_t y) {
    _cursorX = x;
    _cursorY = y;
}

void Lightweight_SSD1306::print(const char *text) {
    while (*text) {
        drawChar(_cursorX, _cursorY, *text, _textColor, _textSize);
        _cursorX += 6 * _textSize;
        text++;
    }
}

void Lightweight_SSD1306::drawChar(int16_t x, int16_t y, char c, uint16_t color, uint8_t size) {
    if (c < 32 || c > 126) {
        return;
    }

    uint8_t charIndex = c - 32;

    for (int8_t i = 0; i < 5; i++) {
        uint8_t line = pgm_read_byte(&font[charIndex * 5 + i]);
        for (int8_t j = 0; j < 8; j++) {
            if (line & 0x1) {
                if (size == 1) {
                    drawPixel(x + i, y + j, color);
                } else {
                    fillRect(x + i * size, y + j * size, size, size, color);
                }
            }
            line >>= 1;
        }
    }
}

void Lightweight_SSD1306::drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color) {
    for (int16_t j = 0; j < h; j++) {
        for (int16_t i = 0; i < w; i++) {
            if (bitmap[i + (j / 8) * w] & (1 << (j % 8))) {
                drawPixel(x + i, y + j, color);
            }
        }
    }
}

void Lightweight_SSD1306::fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) {
    for (int16_t i = x; i < x + w; i++) {
        for (int16_t j = y; j < y + h; j++) {
            drawPixel(i, j, color);
        }
    }
}

void Lightweight_SSD1306::drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color) {
    int16_t dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int16_t dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int16_t err = dx + dy, e2;

    while (true) {
        drawPixel(x0, y0, color);
        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
}

void Lightweight_SSD1306::drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) {
    drawLine(x, y, x + w, y, color);
    drawLine(x + w, y, x + w, y + h, color);
    drawLine(x + w, y + h, x, y + h, color);
    drawLine(x, y + h, x, y, color);
}

void Lightweight_SSD1306::drawPixel(int16_t x, int16_t y, uint16_t color) {
    if (x >= 0 && x < _width && y >= 0 && y < _height) {
        if (color) {
            _buffer[x + (y / 8) * _width] |= (1 << (y % 8));
        } else {
            _buffer[x + (y / 8) * _width] &= ~(1 << (y % 8));
        }
    }
}

void Lightweight_SSD1306::sendCommand(uint8_t command) {
    _wire->beginTransmission(_i2c_addr);
    _wire->write(0x00); 
    _wire->write(command);
    _wire->endTransmission();
}

void Lightweight_SSD1306::sendData(uint8_t *data, size_t size) {
    _wire->beginTransmission(_i2c_addr);
    _wire->write(0x40); 
    for (size_t i = 0; i < size; i++) {
        _wire->write(data[i]);
    }
    _wire->endTransmission();
}
