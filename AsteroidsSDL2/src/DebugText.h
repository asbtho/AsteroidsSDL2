#pragma once
#include "SDL.h"
#include "SDL_ttf.h"

class DebugText {
public:
    DebugText();
    ~DebugText();
    
    virtual void init(SDL_Renderer* r);
    virtual void updateText(SDL_Renderer* r, float angle, float speed, float* velocity);
    virtual void draw(SDL_Renderer* r);
private:
    SDL_Surface* angleMessage = NULL;
    SDL_Surface* speedMessage = NULL;
    SDL_Surface* velocityMessage = NULL;
    TTF_Font* Sans = NULL;
    SDL_Color color = { 255, 255, 255 }; //White 
    SDL_Rect angle_rect = { 0, 0, 300, 50 }; // x, y, w, h
    SDL_Rect speed_rect = { 0, 50, 300, 50 };
    SDL_Rect velocity_rect = { 0, 100, 500, 50 };
    SDL_Texture* angleTexture = NULL;
    SDL_Texture* speedTexture = NULL;
    SDL_Texture* velocityTexture = NULL;
    bool debugEnabled = true;
};
