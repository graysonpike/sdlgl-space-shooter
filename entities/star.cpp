#include <stdlib.h>
#include <math.h>
#include "star.h"

#define MIN_SPEED (1.0f)
#define MAX_SPEED (2.0f)


void create_random_star(Scene *scene, float angle) {
	Graphics *graphics = scene->get_graphics();
	int x = rand() % graphics->get_width();
	int y = rand() % graphics->get_height();
	float speed = rand() / (float)(RAND_MAX) * (MAX_SPEED - MIN_SPEED) + MIN_SPEED;
	float vx = speed * cos(angle);
	float vy = speed * sin(angle);
	scene->add_entity(new Star(scene, x, y, 2, 2, vx, vy));
}


void Star::create_starfield(Scene *scene, float density, float angle) {
	// Determine how many stars to create, given a density in stars/100px^2
	Graphics *graphics = scene->get_graphics();
	int pixels = graphics->get_width() * graphics->get_height();
	int stars = pixels / 10000 * density;
	for (int i = 0; i < stars; i++) {
		create_random_star(scene, angle);	
	}
}

void Star::create_starfield(Scene *scene, float density) {
	float angle = rand() / (float)(RAND_MAX) * 2 * M_PI;
	Star::create_starfield(scene, density, angle);
}


Star::Star(Scene *scene, float x, float y, int w, int h, float vx, float vy) :
    PhysicalEntity(scene, x, y, w, h),
    color(SDL_Color({255, 255, 0, 255})),
    vx(vx), vy(vy) {};

void Star::update() {
   float delta = scene->get_delta();
   time += delta;
   x += vx;
   y += vy;
   wrap_bounds();
}

void Star::render() {
    SDL_Renderer *renderer = scene->get_graphics()->get_renderer();

	// Draw rectangle 
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_Rect box_rect = {(int)x, (int)y, w, h};
	SDL_RenderDrawRect(renderer, &box_rect);
}
