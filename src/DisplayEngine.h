#ifndef DISPLAY_ENGINE_HEADER
#define DISPLAY_ENGINE_HEADER

#define USE_HSPI_FOR_EPD
#define ENABLE_GxEPD2_GFX 0
#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h>
#include <Fonts/FreeMonoOblique24pt7b.h>
#include <U8g2_for_Adafruit_GFX.h>

#define GxEPD2_DISPLAY_CLASS GxEPD2_BW
#define GxEPD2_DRIVER_CLASS GxEPD2_213_BN // DEPG0213BN  128x250, SSD1680, (FPC-7528B), TTGO T5 V2.4.1, V2.3.1
#define MAX_DISPLAY_BUFFER_SIZE 65536ul // e.g.
#define MAX_HEIGHT(EPD) (EPD::HEIGHT <= MAX_DISPLAY_BUFFER_SIZE / (EPD::WIDTH / 8) ? EPD::HEIGHT : MAX_DISPLAY_BUFFER_SIZE / (EPD::WIDTH / 8))
//GxEPD2_DISPLAY_CLASS<GxEPD2_DRIVER_CLASS, MAX_HEIGHT(GxEPD2_DRIVER_CLASS)> display(GxEPD2_DRIVER_CLASS(/*CS=*/ 15, /*DC=*/ 27, /*RST=*/ 26, /*BUSY=*/ 25));

#include "bitmaps/Bitmaps128x250.h" // 2.13" b/w
#include "Point.h"

class DisplayEngine {
private:
    GxEPD2_DISPLAY_CLASS<GxEPD2_DRIVER_CLASS, MAX_HEIGHT(GxEPD2_DRIVER_CLASS)> display;
    SPIClass hspi;
    U8G2_FOR_ADAFRUIT_GFX textDisplay;

public:

    DisplayEngine();

    void init(bool firstCall = false);

    void end();

    void setFont(const char name[], const uint8_t *font);

    void drawArrow(Point origin, int16_t size, uint16_t color, double_t angle=0);
    void drawThickLine(Point first, Point second, int16_t size, uint16_t color);

    void printArrow();

    void clear();    
};

#endif