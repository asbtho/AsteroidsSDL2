#include "Player.h"
#include <iostream>

Player::Player(){
    prevPosition = { 400, 400 };
    position = { 400, 400 };
    ship = new SDL_Point[5];

    velocity[0] = 0.0;
    velocity[1] = 0.0;

    this->trace();
}

Player::~Player(){
    delete[] ship;
}

void Player::trace(){
    cosA = cos(angle);
    sinA = sin(angle);

    for (int i = 0; i < 5; i++) {
        ship[i] = baseFormula(shipPoints[i][0], shipPoints[i][1], shipPoints[i][2], shipPoints[i][3]);
    }
}

void Player::updatePosition(){
    if (thrust) {
        speed += 0.1;
        if (speed > 5) {
            speed = 5;
        }
        velocity[0] += speed * cosA;
        velocity[1] += speed * sinA;
    }
    else {
        speed = 0;
    }

    switch (rot) {
        case LEFT: {
            angle -= 0.1;
            break;
        }
        case RIGHT: {
            angle += 0.1;
            break;
        }
        case NONE: {
            break;
        }
    }

    position.x = prevPosition.x - velocity[0];
    position.y = prevPosition.y - velocity[1];

    prevPosition.x = position.x;
    prevPosition.y = position.y;
}

void Player::draw(SDL_Renderer* r) {
    SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
    if (alive) {
        SDL_RenderDrawLines(r, ship, 5);
    }
}

SDL_Point Player::baseFormula(const int& a, const int& b, const int& c, const int& d){
    return { int(cosA * a - sinA * b + position.x), int(sinA * c + cosA * d + position.y) };
}
