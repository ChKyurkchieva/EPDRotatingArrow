#ifndef COMPONENT_BASE_HEADER
#define COMPONENT_BASE_HEADER

#include <Arduino.h>
#include "Point.h"
#include "DrawPrimitiveShape.h"

class ComponentBase{
    protected:
    DrawPrimitiveShape* display;
    public:
    virtual void begin();
    virtual void end();
    virtual void loop();
    void setDisplayEngine(DrawPrimitiveShape* display);
    
};

#endif
