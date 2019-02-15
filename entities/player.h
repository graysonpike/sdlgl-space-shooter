#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include <sdlgl/game/scene.h>
#include <sdlgl/game/physical_entity.h>
#include <sdlgl/graphics/texture.h>
#include <sdlgl/game/timer.h>

class Player : public PhysicalEntity {

    float vx, vy;
    float angle;
    SDL_Color color;
    Texture texture;

    void handle_inputs(Inputs *inputs);
    void enforce_max_speed();
    void fire_laser();

public:

    Player(Scene *scene, float x, float y, float angle, SDL_Color color);
    void update();
    void render();
    void shoot_laser();

};

#endif