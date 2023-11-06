#include "ComponentBase.h"
#include "DisplayEngine.h"

void ComponentBase::begin() {}
void ComponentBase::end() {}
void ComponentBase::loop() {}

void ComponentBase::setDisplayEngine(DrawPrimitiveShape* display)
{
    this->display = display;
}