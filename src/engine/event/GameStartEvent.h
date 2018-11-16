#ifndef GAMESTARTEVENT_H
#define GAMESTARTEVENT_H

#include <engine/Game.h>

#include "Event.h"

class GameStartEvent : public Event {
private:

    Game *game;

public:
    GameStartEvent(Game *game);

    ~GameStartEvent();
};

#endif