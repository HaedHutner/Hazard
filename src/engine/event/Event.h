#ifndef EVENT_H
#define EVENT_H

#include <string>

class Event
{
private:
    std::string id;
protected:
    Event(const std::string &id);
public:
    Event();

    const std::string &getId() const;

    ~Event();
};

#endif