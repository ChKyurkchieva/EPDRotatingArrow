#ifndef CIRCLE_COMPONENT_HEADER
#define CIRCLE_COMPONENT_HEADERR


#include "ComponentBase.h"

class AnimatingCircle : public ComponentBase
{
    double_t radius;
    double_t min_radius;
    double_t max_radius;
    Point origin;

    public:
    AnimatingCircle(Point origin, double_t min_radius = 0, double_t max_radius = 0);
    virtual void begin(DisplayEngine* display);
    virtual void end(DisplayEngine* display);
    virtual void loop(DisplayEngine* display);
};

#endif