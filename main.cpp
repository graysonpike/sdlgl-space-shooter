#include <iostream>

#include "sdlgl/graphics/graphics.h"
#include <sdlgl/game/clock.h>
#include <sdlgl/game/scene.h>
#include <sdlgl/input/inputs.h>
#include <stdlib.h>
#include <time.h>

#include <sdlgl/ui/fps_display.h>

#include "entities/player.h"
#include "entities/star.h"


int main() {

    srand(time(NULL));

    Clock clock;
    Inputs inputs;

    // Load a window
    Graphics graphics(640, 480);

    // Load resources
    graphics.get_resources()->load_resources("resources.json");

    // Create and populate scene
    Scene scene(&inputs, &graphics);
    scene.add_entity(new FPS_Display(
        &scene, "base_text", {0, 0, 0, 255}));
    Star::create_starfield(&scene, 2.0f);
    scene.add_entity(new Player(&scene, 100, 100, 0, {0, 0, 0, 0}));

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
