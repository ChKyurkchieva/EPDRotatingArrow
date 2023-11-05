#include <Arduino.h>
#include "DisplayEngine.h"
#include "AnimatingCircle.h"

DisplayEngine engine = DisplayEngine();
Point origin = engine.getCenterScreen();
void setup() {  
  Serial.begin(115200);
  engine.addComponent(new AnimatingCircle(origin, 0, 60));
  
  //display.add(AnimatingArrow(origin, thickness, size))

  engine.init();
  engine.clear();
  engine.end();
}

int16_t angle = 0;
void loop() {
  engine.init();
  
  engine.printArrow(origin,angle);
  angle = angle+10>=360 ? 0 : angle+10;
  delay(50);  
  engine.end();
}

