#ifndef LASER_H
#define LASER_H

#include <sdlgl/game/physical_entity.h>


class Laser : public PhysicalEntity {

	Texture texture;
	float angle;

public:

	Laser(Scene *scene, float x, float y, float angle);

	void update();
	void render();

}

#endif