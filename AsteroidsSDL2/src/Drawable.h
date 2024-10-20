#pragma once

class Drawable{
public:
    virtual void trace() = 0;
    virtual void draw(SDL_Renderer* r) = 0;
};
