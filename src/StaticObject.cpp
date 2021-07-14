#include "StaticObject.h"
#include <iostream>
//--------------------------------------------------------------------------------------------
//c-tor
StaticObject::StaticObject(const sf::Vector2f &location,int index):Object(location, index)
{
}
StaticObject::~StaticObject() {}