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
    public:
    AnimatingArrow(Point origin, int16_t size, int16_t thickness, int16_t initialAngle):
        origin(origin), size(size), thickness(thickness), angle(initialAngle){}

    virtual void loop(DisplayEngine* display){
        display->drawArrow(origin, size, thickness, DisplayEngine::COLOR_BLACK, angle);
        angle = angle+10>=360 ? 0 : angle+10;
    }

};

#endif