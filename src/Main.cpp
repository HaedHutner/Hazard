#include <game/Hazard.h>

int main(int argc, char const *argv[])
{
    Hazard* hazard = new Hazard();
    
    if ( hazard->init() ) {
        hazard->run();
    }

    delete hazard;

    return 0;
}
