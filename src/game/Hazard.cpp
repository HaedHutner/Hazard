#include "Hazard.h"

Hazard::Hazard()
    : Game(), config("res/config/config.json")
{
    name = "Hazard";

    log_info("Width: %d, Height: %d, Test: %f", 
        config.getInt({"window", "width"}), 
        config.getInt({"window", "height"}),
        config.getDouble({"window", "test"})
    );

    glm::vec3 color = config.getVec3({"window", "bgcolor"});

    log_info("x: %f, y: %f, z: %f",
        color.x,
        color.y,
        color.z
    );

    eventDispatcher.listen<GameStartEvent>([=](Event &event) {
        log_info("Game Started.");
    });

    eventDispatcher.post<GameStartEvent>(this);

    background = color;

    state = std::make_unique<IdleGameState>();
}

Hazard::~Hazard()
{
}