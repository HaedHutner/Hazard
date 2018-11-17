#ifndef EVENTDISPATCHER_H
#define EVENTDISPATCHER_H

#include <functional>
#include <map>
#include <typeinfo>

#include <engine/Log.h>

#include "Event.h"

using EventHandler = const std::function<void(Event&)>;

using EventMap = std::multimap<const std::string,EventHandler>;

class EventDispatcher
{
private:

    EventMap eventMap;

public:
    EventDispatcher();

    template <typename E, typename... ArgT>
    void post(ArgT&&... args) {
        Event event = E(args...);

        #ifdef HAZARD_DEBUG
            log_info("Triggered %s", typeid(E).name());
        #endif

        auto handlers = eventMap.equal_range(typeid(E).name());
        for ( auto handler = handlers.first; handler != handlers.second; ++handler ) {
            handler->second(event);
        }
    }

    template <typename E>
    void listen(EventHandler &fn) {

        #ifdef HAZARD_DEBUG
            log_info("Registered Listener for %s", typeid(E).name());
        #endif

        eventMap.emplace(typeid(E).name(), fn);
    }

    ~EventDispatcher();
};

#endif