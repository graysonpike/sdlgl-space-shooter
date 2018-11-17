#include "laser.h"
#include <math.h>
#include <sdlgl/graphics/resources.h>


#define SPEED (300.0f)


Laser::Laser(Scene *scene, float x, float y, float angle, SDL_Color color) :
    PhysicalEntity(scene, x, y, w, h),
    angle(angle),
    color(color) {

    Resources *resources = scene->get_graphics()->get_resources();
    texture = resources->get_texture("laser");

}

void Laser::update() {

    float delta = scene->get_delta();
    x += delta * SPEED * cos(angle);
    y += delta * SPEED * sin(angle);
    wrap_bounds();

}


void Laser::render() {

    texture.draw(scene->get_graphics()->get_renderer(), this->x, this->y, this->angle);

}