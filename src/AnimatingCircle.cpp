#include "AnimatingCircle.h"
#include "DisplayEngine.h"

AnimatingCircle::AnimatingCircle(Point origin, double_t min_radius, double_t max_radius)
:origin(origin),radius(min_radius), min_radius(min_radius), max_radius(max_radius)
{

}

void AnimatingCircle::loop(DisplayEngine* display)
{
    radius = radius + 5;

    if(radius>=max_radius)
        radius=min_radius;
    display->drawCircle(origin, radius, DisplayEngine::COLOR_BLACK);
    display->drawCircle(origin, max_radius-radius, DisplayEngine::COLOR_BLACK);
}

void AnimatingCircle::begin(DisplayEngine* display)
{

}

void AnimatingCircle::end(DisplayEngine* display)
{
    
}
