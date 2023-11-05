#include <Arduino.h>
#include "DisplayEngine.h"

DisplayEngine engine = DisplayEngine();

void setup() {  
  Serial.begin(115200);
  engine.init();
  engine.clear();
  engine.end();
}

int16_t angle = 0;
void loop() {
  engine.init();
  engine.printArrow(angle);
  angle = angle+10>=360 ? 0 : angle+10;
  delay(50);  
  engine.end();
}