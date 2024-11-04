#pragma once
#include "SDL.h"
#include "SDL_ttf.h"

class DebugText {
public:
    DebugText();
    ~DebugText();
    
    virtual void init(SDL_Renderer* r);
    virtual void draw(SDL_Renderer* r);
private:
    SDL_Surface* surfaceMessage = NULL;
    TTF_Font* Sans = NULL;
    SDL_Rect Message_rect = {0, 0, 0, 0};
    SDL_Texture* Message = NULL;
    bool debugEnabled = true;
};
