#include <Arduino.h>
#include <DisplayEngine.h>
#include <AnimatingCircle.h>
#include <AnimatingArrow.h>

DisplayEngine engine = DisplayEngine();
Point origin = engine.getCenterScreen();
Point left = Point(60,190);
Point right = Point(60, 60);

int16_t angle = 0;
void setup() {  
  Serial.begin(115200);
  engine.addComponent(new AnimatingCircle(origin, 0, 60)); //TODO: FREE MEMORY
  engine.addComponent(new AnimatingArrow(origin, 45, 6, 0));
  engine.addComponent(new AnimatingCircle(Point(60, 190), 0, 60));
  engine.addComponent(new AnimatingCircle(Point(60, 60), 0, 60));
  engine.addComponent(new AnimatingArrow(left,30, 4, 0));
  engine.addComponent(new AnimatingArrow(right, 30, 4, 0));

  Serial.println(origin.toString());

  engine.init();
  engine.clear();
  engine.end();
}

void loop() {
  engine.init();
  
  engine.loop();

  engine.end();
  delay(50);  
}

