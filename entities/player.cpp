#include <sdlgl/graphics/resources.h>

#include "player.h"


Player::Player(Scene *scene, float x, float y, float angle, SDL_Color color) {

	Resources *resources = scene->get_graphics()->get_resources();
	this->texture = resources->get_texture("ship");
	
	this->scene = scene;
	this->x = x;
	this->y = x;
	this->angle = angle;
	this->color = color;
}


void Player::update() {
	
}

void Player::render() {
	this->texture.draw(this->scene->get_graphics()->get_renderer(), this->x, this->y);
}