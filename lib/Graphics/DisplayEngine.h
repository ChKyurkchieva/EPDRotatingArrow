#ifndef DISPLAY_ENGINE_HEADER
#define DISPLAY_ENGINE_HEADER

// #define USE_HSPI_FOR_EPD
// #define ENABLE_GxEPD2_GFX 0
// #include <GxEPD2_BW.h>
// #include <GxEPD2_3C.h>
// #include <Fonts/FreeMonoOblique24pt7b.h>
// #include <U8g2_for_Adafruit_GFX.h>

// #define GxEPD_BLACK     0x0000
// #define GxEPD_WHITE     0xFFFF

// #define GxEPD2_DISPLAY_CLASS GxEPD2_BW
// #define GxEPD2_DRIVER_CLASS GxEPD2_213_BN // DEPG0213BN  128x250, SSD1680, (FPC-7528B), TTGO T5 V2.4.1, V2.3.1
// #define MAX_DISPLAY_BUFFER_SIZE 65536ul // e.g.
// #define MAX_HEIGHT(EPD) (EPD::HEIGHT <= MAX_DISPLAY_BUFFER_SIZE / (EPD::WIDTH / 8) ? EPD::HEIGHT : MAX_DISPLAY_BUFFER_SIZE / (EPD::WIDTH / 8))
// //GxEPD2_DISPLAY_CLASS<GxEPD2_DRIVER_CLASS, MAX_HEIGHT(GxEPD2_DRIVER_CLASS)> display(GxEPD2_DRIVER_CLASS(/*CS=*/ 15, /*DC=*/ 27, /*RST=*/ 26, /*BUSY=*/ 25));

// #include "bitmaps/Bitmaps128x250.h" // 2.13" b/w

#include "DrawPrimitiveShape.h"
#include "Point.h"
#include "ArrayList.h"

class ComponentBase;

class DisplayEngine {
private:
    EpdDisplay* display;
    SPIClass hspi;
    // U8G2_FOR_ADAFRUIT_GFX textDisplay;
    DrawPrimitiveShape* geometry;
    ArrayList<ComponentBase*> components;

public:

    static const uint64_t COLOR_BLACK = 0x0000;
    static const uint64_t COLOR_WHITE = 0xFFFF;

    DisplayEngine();

    void init(bool firstCall = false);

    Point getCenterScreen();

    void end();

    void addComponent(ComponentBase* component);

    void loop();

    void clear();    
};
#endif