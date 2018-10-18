#ifndef STAR_H
#define STAR_H

#include <sdlgl/game/physical_entity.h>

class Star : public PhysicalEntity {

    float time;
    SDL_Color color;

public:

    static void create_starfield(Scene *scene);

    Star(float x, float y, int w, int h);
    void update();
    void render();

};


#endif
