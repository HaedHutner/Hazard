#ifndef EVENTDISPATCHER_H
#define EVENTDISPATCHER_H

#include <map>
#include <algorithm>

class EventDispatcher
{
private:

public:
    EventDispatcher();

    void post() const;

    void listen() const;

    ~EventDispatcher();
};

#endif