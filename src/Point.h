#include<Arduino.h>
struct Point {

    double_t x;
    double_t y;

    Point(double_t x, double_t y):x(x),y(y){};

    Point rotatePoint(Point origin, double_t angle) {
      double_t newX=(x-origin.x)*cos(angle)-(y-origin.y)*sin(angle) + origin.x;
      double_t newY=(x-origin.x)*sin(angle)+(y-origin.y)*cos(angle) + origin.y;
      return Point(newX, newY);
    }

    const String toString(){
      return String(x) + " "+ String(y);
    }

};
