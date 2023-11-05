#ifndef COMPONENT_BASE_HEADER
#define COMPONENT_BASE_HEADER

#include <Arduino.h>
#include "Point.h"

class DisplayEngine;

class ComponentBase{

    public:
    virtual void begin(DisplayEngine* display);
    virtual void end(DisplayEngine* display);
    virtual void loop(DisplayEngine* display);
};

#endif
