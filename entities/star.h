#ifndef STAR_H
#define STAR_H

#include <sdlgl/game/physical_entity.h>

class Star : public PhysicalEntity {

    float time;
    SDL_Color color;
    float vx, vy;

public:

	// Create a field of stars as a background
	// Density is # stars per 100 px^2
	// angle (if specified) is in radians
    static void create_starfield(Scene *scene, float density);
    static void create_starfield(Scene *scene, float density, float angle);

    Star(Scene *scene, float x, float y, int w, int h, float vx, float vy);
    void update();
    void render();

};


#endif
