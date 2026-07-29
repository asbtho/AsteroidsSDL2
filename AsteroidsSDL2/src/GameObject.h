#pragma once

#include "SDL2/SDL.h"
#include "Drawable.h"

class GameObject : public Drawable
{
public:
    inline float* getVelocity() { return velocity; }
    inline SDL_FPoint getPosition() { return position; }
    inline float getAngle() { return angle; }
protected:
    SDL_FPoint prevPosition;
    SDL_FPoint position;

    float angle = 0.0;
    float velocity[2];

    float cosA = 0.0;
    float sinA = 0.0;
};
