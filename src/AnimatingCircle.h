#ifndef CIRCLE_COMPONENT_HEADER
#define CIRCLE_COMPONENT_HEADER


#include "ComponentBase.h"
#include "DisplayEngine.h"

class AnimatingCircle : public ComponentBase
{
    double_t radius;
    double_t min_radius;
    double_t max_radius;
    Point origin;

    public:
    AnimatingCircle(Point origin, double_t min_radius, double_t max_radius)
        :origin(origin),radius(min_radius), min_radius(min_radius), max_radius(max_radius) {}

    virtual void loop(DisplayEngine* display)
    {
        radius = radius + 5;

        if(radius>=max_radius)
            radius=min_radius;
        display->drawCircle(origin, radius, DisplayEngine::COLOR_BLACK);
        display->drawCircle(origin, max_radius-radius, DisplayEngine::COLOR_BLACK);
    }
};


#endif