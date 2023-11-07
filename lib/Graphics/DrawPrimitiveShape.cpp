#include "DrawPrimitiveShape.h"

DrawPrimitiveShape::DrawPrimitiveShape(EpdDisplay* display):display(display) {}

void DrawPrimitiveShape::setFont(const char name[], const uint8_t *font)
{
    display->setRotation(1);
    textDisplay.setFontMode(1);                   // use u8g2 transparent mode (this is default)
    textDisplay.setFontDirection(0);              // left to right (this is default)
    textDisplay.setForegroundColor(GxEPD_BLACK);  // apply Adafruit GFX color
    textDisplay.setBackgroundColor(GxEPD_WHITE);  // apply Adafruit GFX color
    textDisplay.setFont(font); // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
}

void DrawPrimitiveShape::drawCircle(Point origin, double_t radius, uint16_t color)
{
    display->drawCircle((int16_t) origin.x, (int16_t) origin.y, (int16_t)radius, color);
}

void DrawPrimitiveShape::drawThickLine(Point first, Point second, int16_t size, uint16_t color)
{
    Point vector = Point(second.x - first.x, second.y - first.y);
    Point normal = Point(-(vector.y), vector.x);
    double_t magnitude = sqrt(pow(normal.x, 2) + pow(normal.y, 2));
    Point normalized = Point(normal.x / magnitude, normal.y / magnitude);
    Serial.println(normalized.toString());
    for (int16_t lambda = -(size / 2)*100; lambda <= (size / 2)*100; lambda++)
    {
      Point offset = Point(normalized.x * lambda/100, normalized.y * lambda/100);
      display->drawLine(first.x + offset.x, first.y + offset.y, second.x + offset.x, second.y + offset.y, color);
    }
}

void DrawPrimitiveShape::drawThickRectangle(Point first, Point second, uint16_t color)
{
    display->drawRect(first.x, first.y,second.x, second.y, color);
}