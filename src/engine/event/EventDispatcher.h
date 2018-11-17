#ifndef EVENTDISPATCHER_H
#define EVENTDISPATCHER_H

#include <functional>
#include <map>
#include <typeinfo>

#include "Event.h"

using EventMap = std::multimap<const std::type_info*,const std::function<void(Event&)>&>;

class EventDispatcher
{
private:

    static EventMap eventMap;

public:
    EventDispatcher();

    void operator<<(Event &event) {
        post(event);
    }

    template<typename E>
    void operator>>(const std::function<void(E&)> &listener) {
        listen(listener);
    }

    void post(Event &event) {
        auto handlers = EventDispatcher::eventMap.equal_range(&typeid(event));
        for ( auto handler = handlers.first; handler != handlers.second; ++handler ) {
            handler->second(event);
        }
    }

    template<typename E>
    void listen(const std::function<void(E&)> &fn) {
        EventDispatcher::eventMap.emplace(&typeid(E), fn);
    }

    ~EventDispatcher();
};

EventMap EventDispatcher::eventMap;

#endif