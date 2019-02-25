#include "laser.h"
#include <math.h>
#include <sdlgl/graphics/resources.h>


#define SPEED (600.0f)
#define LIFETIME (1.1f)


Laser::Laser(Scene *scene, float x, float y, float angle, SDL_Color color) :
    PhysicalEntity(scene, x, y, 0, 0),
    angle(angle),
    color(color),
    time_alive(0) {

    Resources *resources = scene->get_graphics()->get_resources();
    texture = resources->get_texture("laser");

    w = texture.get_width();
    h = texture.get_height();

}

void Laser::update() {

    float delta = scene->get_delta();
    time_alive += delta;
    x += delta * SPEED * cos(angle);
    y += delta * SPEED * sin(angle);
    wrap_bounds();

    if(time_alive > LIFETIME) {
        kill();
    }

}


void Laser::render() {
    texture.draw(scene->get_graphics()->get_renderer(), this->x, this->y, this->angle);
}