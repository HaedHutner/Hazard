#include "Hazard.h"

Hazard::Hazard()
    : Game(), config("res/config/config.json")
{
    name = "Hazard";

    printf("Width: %d, Height: %d, Test: %f\n", 
        config.getInt({"window", "width"}), 
        config.getInt({"window", "height"}),
        config.getDouble({"window", "test"})
    );

    glm::vec3 color = config.getVec3({"window", "bgcolor"});

    printf("x: %f, y: %f, z: %f\n",
        color.x,
        color.y,
        color.z
    );

    eventDispatcher.listen<GameStartEvent>("GameStartEvent", [=](GameStartEvent &event){
        printf("Hello, Game start!");
    });

    eventDispatcher.post<GameStartEvent>(this);

    background = color;

    state = std::make_unique<IdleGameState>();
}

Hazard::~Hazard()
{
}