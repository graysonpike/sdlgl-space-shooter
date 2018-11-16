#ifndef LASER_H
#define LASER_H

#include <sdlgl/game/physical_entity.h>
#include <sdlgl/graphics/texture.h>


class Laser : public PhysicalEntity {

	Texture texture;
	float angle;
	SDL_Color color;
	float vx, vy;

public:

	Laser(Scene *scene, float x, float y, float angle, SDL_Color color);

	void update();
	void render();

};

#endif