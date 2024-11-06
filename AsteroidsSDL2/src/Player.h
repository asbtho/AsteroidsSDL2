#pragma once
#include <cmath>
#include "GameObject.h"
#include "SDL.h"

class Player : public GameObject {
public:
    enum rotateDir { 
        LEFT = 1,
        RIGHT = 2,
        NONE = 0 
    };

    Player();
    ~Player();

    virtual void trace();
    virtual void updatePosition();
    virtual void draw(SDL_Renderer* r);

    void rotate(const int& val) { rot = val; }
    void thrusting(const bool& val) { thrust = val; }

    inline bool isAlive() { return alive; }
    inline float getSpeed() { return speed; }
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

    int rot = NONE;
    float speed = 0.0;

    bool thrust = false;
    bool alive = true;
};
