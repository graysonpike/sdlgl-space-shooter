#include <iostream>

#include "sdlgl/graphics/graphics.h"
#include "sdlgl/game/clock.h"
#include "sdlgl/game/scene.h"
#include "sdlgl/input/inputs.h"
#include "sdlgl/ui/fps_display.h"


int main() {

    Clock clock;
    Inputs inputs;

    // Load a window
    Graphics graphics(640, 480);

    // Load resources
    graphics.get_resources()->load_resources("resources.json");

    // Create and populate scene
    Scene scene(&inputs, &graphics);

    // Enter a simple update loop
    bool loop = true;
    while (loop) {

        inputs.update();
        clock.tick();
        graphics.clear_screen();
        
        scene.update(clock.get_delta());
        scene.render();

        graphics.present_renderer(clock.get_delta());

        // If ESC or 'X' button is pressed, leave the update loop and exit
        if(inputs.get_quit()) {
            loop = false;
        }

    }

    return 0;
}
