#include "DisplayEngine.h"

DisplayEngine::DisplayEngine()
  : hspi(HSPI),
    display(GxEPD2_DRIVER_CLASS(/*CS=*/15, /*DC=*/27, /*RST=*/26, /*BUSY=*/25)) {
  hspi.begin(13, 12, 14, 15);  // remap hspi for EPD (swap pins)
  display.epd2.selectSPI(hspi, SPISettings(4000000, MSBFIRST, SPI_MODE0));
}

void DisplayEngine::init(bool firstCall) {
  display.init(115200, firstCall);
  textDisplay.begin(display);

  setFont("u8g2_font_fub49_t_symbols", u8g2_font_fub49_t_symbol);
}

void DisplayEngine::end(){
  display.hibernate();
}

void DisplayEngine::setFont(const char name[], const uint8_t *font)
{
  display.setRotation(1);
  textDisplay.setFontMode(1);                   // use u8g2 transparent mode (this is default)
  textDisplay.setFontDirection(0);              // left to right (this is default)
  textDisplay.setForegroundColor(GxEPD_BLACK);  // apply Adafruit GFX color
  textDisplay.setBackgroundColor(GxEPD_WHITE);  // apply Adafruit GFX color
  textDisplay.setFont(font); // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
}

void DisplayEngine::drawThickLine(Point first, Point second, int16_t size, uint16_t color)
{
  Point vector = Point(second.x - first.x, second.y - first.y);
  Point normal = Point(-(vector.y), vector.x);
  double_t magnitude = sqrt(pow(normal.x, 2) + pow(normal.y, 2));
  Point normalized = Point(normal.x / magnitude, normal.y / magnitude);
Serial.println(normalized.toString());
  for (int16_t lambda = -(size / 2)*100; lambda <= (size / 2)*100; lambda++)
  {
    Point offset = Point(normalized.x * lambda/100, normalized.y * lambda/100);
    display.drawLine(first.x + offset.x, first.y + offset.y, second.x + offset.x, second.y + offset.y, color);
  }
}


void DisplayEngine::drawArrow(Point origin, int16_t size, int16_t thickness, uint16_t color, double_t degrees) {
  // Calculate arrowhead points
  double_t angle = (degrees * 71) / 4068;

  double_t offset = sqrt(pow(thickness,2)*2)/4;
  drawThickLine(origin.rotatePoint(origin, angle), Point(origin.x, origin.y-size).rotatePoint(origin,angle), thickness, color);
  drawThickLine(Point(origin.x, origin.y-size+offset).rotatePoint(origin,angle), Point(origin.x-size/2, origin.y-size/2+offset).rotatePoint(origin,angle), thickness, color);
  drawThickLine(Point(origin.x, origin.y-size+offset).rotatePoint(origin,angle),Point(origin.x+size/2, origin.y-size/2+offset).rotatePoint(origin,angle),thickness,color);

}

Point DisplayEngine::getCenterScreen(){
  return Point(display.width()/2, display.height()/2);
}

void DisplayEngine::printArrow(Point origin, int16_t angle, int16_t thickness, int16_t arrowSize) {
  uint16_t backgroundColor = GxEPD_WHITE;

  display.setPartialWindow(0, 0, display.width(), display.height());

  display.firstPage();
  do
  {
    display.fillScreen(backgroundColor);
    display.drawCircle(origin.x, origin.y, (arrowSize+thickness)*(360-angle)/360, GxEPD_BLACK);
     display.drawCircle(origin.x, origin.y, (arrowSize+thickness)*(angle)/360, GxEPD_BLACK);
    drawArrow(origin, arrowSize, thickness, GxEPD_BLACK, angle);
  }
  while (display.nextPage());
}

void DisplayEngine::clear() {
  display.clearScreen();
}