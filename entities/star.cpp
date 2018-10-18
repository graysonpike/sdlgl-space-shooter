#include "star.h"

Star::Star(float x, float y, int w, int h) :
    PhysicalEntity(x, y, w, h),
    color(SDL_Color({255, 255, 0, 255})) {};

void Star::update() {
   float delta = scene->get_delta();
   time += delta;
}

void Star::render() {
    SDL_Renderer *renderer = scene->get_graphics()->get_renderer();

	// Draw rectangle 
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_Rect box_rect = {(int)x, (int)y, w, h};
	SDL_RenderDrawRect(renderer, &box_rect);
}


