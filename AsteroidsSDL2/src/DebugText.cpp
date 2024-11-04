#include "DebugText.h"
#include <iostream>

DebugText::DebugText() {
    if (TTF_Init() == 0) {
        std::cout << "TTF lib initialized " << TTF_GetError() << std::endl;
    }
    else {
        std::cout << "Couldn't initialize TTF lib: " << TTF_GetError() << std::endl;
    }
}

DebugText::~DebugText() {
}

void DebugText::init(SDL_Renderer* r) {
    std::cout << "DebugText initialized" << std::endl;

    Sans = TTF_OpenFont("pixel.ttf", 24);
    if (!Sans) {
        std::cout << "Open Font FAILED" << std::endl;
        std::cout << TTF_GetError() << std::endl; 
    }
    SDL_Color color = { 255, 255, 255 }; //White 
    surfaceMessage = TTF_RenderText_Solid(Sans, "TEST TEXT", color);
    if (!surfaceMessage) {
        std::cout << "surfaceMessage FAILED" << std::endl;
        std::cout << TTF_GetError() << std::endl;
    }

    Message_rect.x = 0;  //controls the rect's x coordinate
    Message_rect.y = 0; // controls the rect's y coordinte
    Message_rect.w = 300; // controls the width of the rect
    Message_rect.h = 50; // controls the height of the rect

    Message = SDL_CreateTextureFromSurface(r, surfaceMessage);
    if (!Message) {
        std::cout << "Message texture FAILED" << std::endl;
        std::cout << TTF_GetError() << std::endl;
    }

    SDL_FreeSurface(surfaceMessage);
    TTF_CloseFont(Sans);
}

void DebugText::draw(SDL_Renderer* r) {
    if (debugEnabled) {
        SDL_RenderCopy(r, Message, NULL, &Message_rect);
    }
}
