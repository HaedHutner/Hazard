#ifndef EVENTDISPATCHER_H
#define EVENTDISPATCHER_H

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