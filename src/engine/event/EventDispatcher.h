#ifndef EVENTDISPATCHER_H
#define EVENTDISPATCHER_H

#include <unordered_map>
#include <vector>
#include <functional>
#include <utility>

#include "Event.h"

template <typename EventT, typename std::enable_if<std::is_base_of<Event, EventT>::value>::type* = nullptr>
using EventListener = std::function<void(EventT&)>;

template <typename EventT, typename std::enable_if<std::is_base_of<Event, EventT>::value>::type* = nullptr>
using EventListenerMap = std::unordered_map<std::string, std::vector<EventListener<EventT>>>;

class EventDispatcher
{
private:

    EventListenerMap<Event> listeners;

public:
    EventDispatcher();

    template <typename EventT, typename std::enable_if<std::is_base_of<Event, EventT>::value>::type* = nullptr, typename... ArgT>
    void operator<<(EventT &event) {
        post(event);
    }

    template <typename EventT, typename std::enable_if<std::is_base_of<Event, EventT>::value>::type* = nullptr, typename... ArgT>
    void operator>>(EventListener<EventT> &listener) {

    }

    template <typename EventT, typename std::enable_if<std::is_base_of<Event, EventT>::value>::type* = nullptr, typename... ArgT>
    void post(ArgT&&... args) {
        EventT &event = EventT(args...);
        post(event);
    }

    template <typename EventT, typename std::enable_if<std::is_base_of<Event, EventT>::value>::type* = nullptr, typename... ArgT>
    void post(EventT &event) {
        for ( auto &handler : listeners[event.getId()] ) {
            handler(event);
        }
    }

    template <typename EventT, typename std::enable_if<std::is_base_of<Event, EventT>::value>::type* = nullptr>
    void listen(std::string eventId, EventListener<EventT> listener) {
        auto &handlers = listeners[eventId];
        handlers.push_back(listener);
    }

    ~EventDispatcher();
};

#endif