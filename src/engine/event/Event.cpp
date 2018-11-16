#include "Event.h"

Event::Event(const std::string &id) 
    : id(id)
{

}

const std::string &Event::getId() const {
    return id;
}

Event::~Event()
{
}