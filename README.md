# Lightweight_SSD1306

The Lightweight_SSD1306 library is a minimal, fast, and easy-to-use library for SSD1306 OLED displays, designed for basic text, shapes, and bitmap rendering. It is optimized for small code size and simplicity, making it ideal for projects with limited resources.

![Lightweight_SSD1306](https://github.com/Tecfield-SIA/Lightweight_SSD1306-/blob/main/Images/2.jpg)

## Introduction

- The Lightweight_SSD1306 library is inspired by the Adafruit_SSD1306 library but is not a direct copy or modification of it. Here’s the breakdown:
  - Inspiration: The functionality and structure of the library are inspired by the Adafruit library, as both libraries are designed to work with SSD1306-based OLED displays.
  - Codebase: The code in Lightweight_SSD1306 is written from scratch with a focus on simplicity and minimalism. It does not reuse any code directly from the Adafruit library.
  - Purpose: The goal of Lightweight_SSD1306 is to provide a smaller, faster, and more focused library for basic use cases, whereas the Adafruit library is more feature-rich and supports a wider range of functionalities.
- If you need a small, fast, and easy-to-use library for basic SSD1306 display operations, Lightweight_SSD1306 is a great choice. However, if you require advanced features like hardware scrolling, custom fonts, or complex graphics, the Adafruit_SSD1306 library is more suitable.
- [adafruit/Adafruit_SSD1306: Arduino library for SSD1306 monochrome 128x64 and 128x32 OLEDs](https://github.com/adafruit/Adafruit_SSD1306)

## Why Create a New Library?
- The Lightweight_SSD1306 library was created to address specific needs:
  - Reduced Code Size: Ideal for projects with limited flash memory (e.g., STM32F030K6T6 or small Arduino boards).
  - Simplicity: Easier to understand and modify for beginners.
  - Focused Functionality: Only includes the features needed for basic display operations, avoiding unnecessary bloat.

## Key Features
  - Supports I2C communication.
  - Compatible with 128x64 and 128x32 resolutions.
  - Simple and practical functions for displaying text, shapes, and bitmaps.
  - Reduced code size and memory usage.

## Installation
1.	Place the Lightweight_SSD1306.h and Lightweight_SSD1306.cpp files in the Arduino libraries folder.
2.	Include the library in your code:
```cpp
#include <Lightweight_SSD1306.h>
```

## Library Functions
- Refer to the Functions.md file for information about functions.

## Conclusion
- This library allows you to easily work with SSD1306-based OLED displays and display text, shapes, and bitmaps. With this documentation, you can quickly get started and use the library in your projects.
For questions or discussions, feel free to open an issue or reach out via Linkedin or email me at Tecfield@live.com
www.linkedin.com/in/siavash-alizadeh-tecfield
