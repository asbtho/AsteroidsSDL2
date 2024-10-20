#pragma once
#include <cmath>
#include "GameObject.h"
#include "SDL.h"

class Player : public GameObject {
public:
    Player();
    ~Player();

    virtual void trace();
    virtual void draw(SDL_Renderer* r);
private:
    SDL_Point baseFormula(const int& a, const int& b, const int& c, const int& d);

    int shipPoints[5][4] = {
        { -10, 1, -10, 1 },
        { 10, -10, 10, -10 },
        { 5, 1, 5, 1 },
        { 10, 10, 10, 10 },
        {  -10, 1, -10, 1 }
    };

    SDL_Point* ship = NULL;
};
