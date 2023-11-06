#include "DisplayEngine.h"
#include "ComponentBase.h"


DisplayEngine::DisplayEngine()
  : hspi(HSPI)
    {
    display = new EpdDisplay(GxEPD2_DRIVER_CLASS(/*CS=*/ 15, /*DC=*/ 27, /*RST=*/ 26, /*BUSY=*/ 25));
      hspi.begin(13, 12, 14, 15);  // remap hspi for EPD (swap pins)
      display->epd2.selectSPI(hspi, SPISettings(4000000, MSBFIRST, SPI_MODE0));
      geometry = new DrawPrimitiveShape(display);
    }

void DisplayEngine::init(bool firstCall) {
  //textDisplay.begin(display);
    display->init(115200, firstCall);
  for(ComponentBase* element : components)
    element->begin();//foreach component.init()

  //setFont("u8g2_font_fub49_t_symbols", u8g2_font_fub49_t_symbol); //init of TextComponent
}

void DisplayEngine::end(){
  for(ComponentBase* element : components)
    element->end();//foreach component.end()

  display->hibernate();
}

void DisplayEngine::addComponent(ComponentBase* component)
{
  components.add(component);
  component->setDisplayEngine(geometry);
}

Point DisplayEngine::getCenterScreen(){
  return Point(display->width()/2, display->height()/2);
}

void DisplayEngine::loop() {
  uint16_t backgroundColor = GxEPD_WHITE;

  display->setPartialWindow(0, 0, display->width(), display->height());

  display->firstPage();
  do
  {
    display->fillScreen(backgroundColor);
    
    for(ComponentBase* element : components)
      element->loop();

  }
  while (display->nextPage());
}

void DisplayEngine::clear() {
  display->clearScreen();
}