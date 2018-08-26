#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include <sdlgl/game/entity.h>
#include <sdlgl/game/scene.h>
#include <sdlgl/graphics/texture.h>

class Player : public Entity {

	float x, y;
	float angle;
	SDL_Color color;

	Texture texture;

public:

	Player(Scene *scene, float x, float y, float angle, SDL_Color color);
	void update();
	void render();

};

#endif