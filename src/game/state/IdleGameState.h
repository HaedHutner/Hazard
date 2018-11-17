#ifndef IDLEGAMESTATE_H
#define IDLEGAMESTATE_H

#include <engine/GameState.h>
#include <engine/Log.h>

class IdleGameState : public GameState
{
    private:
    public:
        IdleGameState();

        void processInputs(GLFWwindow* window) override;

        bool update() override;

        void render(GLFWwindow* window) override;

        ~IdleGameState();
};

#endif // IDLEGAMESTATE_H