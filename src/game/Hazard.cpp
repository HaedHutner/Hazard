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

    // const std::function<void(GameStartEvent&)> &handler = [=](GameStartEvent &event) {
    //     printf("Hello, Game start!");
    // };
    // eventDispatcher >> handler;

    // GameStartEvent gameStartEvent = GameStartEvent(this);
    // eventDispatcher << gameStartEvent;

    GameStartEvent gameStartEvent = GameStartEvent(this);
    const std::function<void(Event&)> handler = [=](Event &event) {
        printf("Hello, Game start!");
    };

    eventDispatcher.listen<GameStartEvent>(handler);
    // eventDispatcher.post(gameStartEvent);

    background = color;

    state = std::make_unique<IdleGameState>();
}

Hazard::~Hazard()
{
}