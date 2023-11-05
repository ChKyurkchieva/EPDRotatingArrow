#include <Arduino.h>
#include "DisplayEngine.h"

DisplayEngine engine = DisplayEngine();

void setup() {  
  Serial.begin(115200);
  engine.init();
  engine.clear();
  engine.end();
}

void loop() {
  engine.init();
  engine.printArrow();
  delay(50);  
  engine.end();
}