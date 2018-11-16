#include "GameStartEvent.h"

GameStartEvent::GameStartEvent(Game *game) 
    : Event("GameStartEvent"), game(game)
{
}

GameStartEvent::~GameStartEvent()
{
}