#include "Hazard.h"

Hazard::Hazard()
    : Game(), config("res/config/config.json")
{
    Game::name = "Hazard";
    printf("Width: %d, Height: %d\n", 
        config.getInt({"window", "width"}), 
        config.getInt({"window", "height"})
    );
    Game::state = std::make_unique<IdleGameState>();
}

Hazard::~Hazard()
{
}