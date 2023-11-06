#ifndef ANIMATING_ARROW_HEADER
#define ANIMATING_ARROW_HEADER

#include "ComponentBase.h"
#include "DisplayEngine.h"

class AnimatingArrow : public ComponentBase
{
    Point origin;
    int16_t size;
    int16_t thickness;
    int16_t angle;

    void drawArrow(Point origin, int16_t size, int16_t thickness, uint16_t color, double_t degrees) {
        // Calculate arrowhead points
        double_t angle = (degrees * 71) / 4068;

        double_t offset = sqrt(pow(thickness,2)*2)/4;
        display->drawThickLine(origin.rotatePoint(origin, angle), Point(origin.x, origin.y-size).rotatePoint(origin,angle), thickness, color);
        display->drawThickLine(Point(origin.x, origin.y-size+offset).rotatePoint(origin,angle), Point(origin.x-size/2, origin.y-size/2+offset).rotatePoint(origin,angle), thickness, color);
        display->drawThickLine(Point(origin.x, origin.y-size+offset).rotatePoint(origin,angle),Point(origin.x+size/2, origin.y-size/2+offset).rotatePoint(origin,angle),thickness,color);

    }

    public:
    AnimatingArrow(Point origin, int16_t size, int16_t thickness, int16_t initialAngle):
        origin(origin), size(size), thickness(thickness), angle(initialAngle){}

    virtual void loop(){
        drawArrow(origin, size, thickness, DisplayEngine::COLOR_BLACK, angle);
        angle = angle+10>=360 ? 0 : angle+10;
    }

};

#endif