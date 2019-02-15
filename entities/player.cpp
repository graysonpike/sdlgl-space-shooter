#include <sdlgl/graphics/resources.h>

#include "player.h"
#include "laser.h"


#define KEY_P1_MOVE_UP      SDL_SCANCODE_W
#define KEY_P1_MOVE_DOWN    SDL_SCANCODE_S
#define KEY_P1_MOVE_LEFT    SDL_SCANCODE_A
#define KEY_P1_MOVE_RIGHT   SDL_SCANCODE_D
#define KEY_P1_FIRE_MISSILE SDL_SCANCODE_PERIOD
#define KEY_P1_FIRE_LASER   SDL_SCANCODE_COMMA


// Time between firing missiles
#define MISSILE_DELAY (2.0f)
// Time between firing lasers
#define LASER_DELAY (0.2f)
// How many particles are spawned when the ship explodes
#define NUM_PARTICLES (40)
// Duration between blinks while invincible
#define BLINK_INTERVAL (0.2f)
// Maximum speed (in px/sec)
#define MAX_SPEED (300.0f)
// Acceleration in px/sec^2
#define LINEAR_ACCEL (300.0f)
// Turning speed in rad/sec
#define TURN_SPEED (3.0f)


Player::Player(Scene *scene, float x, float y, float angle, SDL_Color color) :
    PhysicalEntity(scene, x, y, 0, 0) {

    Resources *resources = scene->get_graphics()->get_resources();

    this->texture = resources->get_texture("ship");
    this->vx = 0;
    this->vy = 0;
    this->angle = angle;
    this->color = color;
    this->w = texture.get_width();
    this->h = texture.get_height();

}


void Player::shoot_laser() {
    scene->add_entity(new Laser(scene, x, y, angle, (SDL_Color){255, 255, 255, 255}));
    printf("Entity added\n");
}


void Player::handle_inputs(Inputs *inputs) {

    float delta = scene->get_delta();

    if (inputs->is_key_down(KEY_P1_MOVE_UP)) {
        vx += delta * LINEAR_ACCEL * cos(angle);
        vy += delta * LINEAR_ACCEL * sin(angle);
    } else if (inputs->is_key_down(KEY_P1_MOVE_DOWN)) {
        vx -= delta * LINEAR_ACCEL * cos(angle);
        vy -= delta * LINEAR_ACCEL * sin(angle);
    }

    if (inputs->is_key_down(KEY_P1_MOVE_LEFT)) {
        angle -= delta * TURN_SPEED;
    } else if (inputs->is_key_down(KEY_P1_MOVE_RIGHT)) {
        angle += delta * TURN_SPEED;
    }

    if (inputs->is_key_down_event(KEY_P1_FIRE_LASER)) {
        shoot_laser();
        printf("Shoot\n");
    }

}


void Player::enforce_max_speed() {

    if(vx > MAX_SPEED) {
        vx = MAX_SPEED;
    }
    if(vy > MAX_SPEED) {
        vy = MAX_SPEED;
    }
    if(vx < -MAX_SPEED) {
        vx = -MAX_SPEED;
    }
    if(vy < -MAX_SPEED) {
        vy = -MAX_SPEED;
    }

}


void Player::update() {

    handle_inputs(scene->get_inputs());
    enforce_max_speed();

    // Apply change in x and y directions
    float delta = scene->get_delta();
    x += delta * vx;
    y += delta * vy;

    wrap_bounds();

}

void Player::render() {
    texture.draw(scene->get_graphics()->get_renderer(), this->x, this->y, this->angle);
}