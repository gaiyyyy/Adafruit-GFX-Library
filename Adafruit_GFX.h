#ifndef _ADAFRUIT_GFX_H
#define _ADAFRUIT_GFX_H

#if ARDUINO >= 100
#include "Arduino.h"
#include "Print.h"
#else
#include "WProgram.h"
#endif

#include "gfxfont.h"

class Adafruit_GFX : public Print {

public:
    Adafruit_GFX(int16_t w, int16_t h);

    // Subclass MUST implement
    virtual void drawPixel(int16_t x, int16_t y, uint16_t color) = 0;

    // Transaction API
    virtual void startWrite(void);
    virtual void writePixel(int16_t x, int16_t y, uint16_t color);
    virtual void writeFillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
    virtual void writeFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
    virtual void writeFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color);
    virtual void writeLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
    virtual void endWrite(void);

    // Control API
    virtual void setRotation(uint8_t r);
    virtual void invertDisplay(boolean i);

    // Basic draw API
    virtual void drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
    virtual void drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color);
    virtual void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
    virtual void fillScreen(uint16_t color);
    virtual void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
    virtual void drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);

    // GFX primitives
    void drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
    void drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint16_t color);
    void fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
    void fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername,
        int16_t delta, uint16_t color);

    // ⭐ 你新增的函数（实验核心）
    void drawPentagram(int16_t x0, int16_t y0, int16_t r, uint16_t color);
    void drawEllipse(int16_t x0, int16_t y0, int16_t rx, int16_t ry, uint16_t color);

    // Other primitives
    void drawTriangle(int16_t x0, int16_t y0,
        int16_t x1, int16_t y1,
        int16_t x2, int16_t y2, uint16_t color);
    void fillTriangle(int16_t x0, int16_t y0,
        int16_t x1, int16_t y1,
        int16_t x2, int16_t y2, uint16_t color);
    void drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h,
        int16_t radius, uint16_t color);
    void fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h,
        int16_t radius, uint16_t color);

    void drawBitmap(int16_t x, int16_t y, const uint8_t bitmap[],
        int16_t w, int16_t h, uint16_t color);
    void drawBitmap(int16_t x, int16_t y, const uint8_t bitmap[],
        int16_t w, int16_t h, uint16_t color, uint16_t bg);

    void drawChar(int16_t x, int16_t y, unsigned char c,
        uint16_t color, uint16_t bg, uint8_t size);

    // Text API
    void setCursor(int16_t x, int16_t y);
    void setTextColor(uint16_t c);
    void setTextColor(uint16_t c, uint16_t bg);
    void setTextSize(uint8_t s);
    void setTextWrap(boolean w);
    void cp437(boolean x = true);
    void setFont(const GFXfont* f = NULL);

#if ARDUINO >= 100
    virtual size_t write(uint8_t);
#else
    virtual void write(uint8_t);
#endif

    int16_t height(void) const;
    int16_t width(void) const;
    uint8_t getRotation(void) const;

    int16_t getCursorX(void) const;
    int16_t getCursorY(void) const;

protected:
    void charBounds(char c, int16_t* x, int16_t* y,
        int16_t* minx, int16_t* miny,
        int16_t* maxx, int16_t* maxy);

    const int16_t WIDTH, HEIGHT;
    int16_t _width, _height;
    int16_t cursor_x, cursor_y;
    uint16_t textcolor, textbgcolor;
    uint8_t textsize, rotation;
    boolean wrap, _cp437;
    GFXfont* gfxFont;
};

#endif
