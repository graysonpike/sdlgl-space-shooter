#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include <sdlgl/game/scene.h>
#include <sdlgl/graphics/texture.h>
#include "physical_entity.h"

class Player : public PhysicalEntity {

    float vx, vy;
    float angle;
    SDL_Color color;

    Texture texture;
    void handle_inputs(Inputs *inputs);
    void enforce_max_speed();

public:

    Player(Scene *scene, float x, float y, float angle, SDL_Color color);
    void update();
    void render();

};

#endif