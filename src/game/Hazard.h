#ifndef HAZARD_H
#define HAZARD_H

#include <engine/Game.h>
#include <engine/Config.h>
#include <engine/event/GameStartEvent.h>

#include <game/state/IdleGameState.h>

class Hazard : public Game
{
private:

    Config config;

public:
    Hazard();
    
    ~Hazard();
};


#endif // !HAZARD_H