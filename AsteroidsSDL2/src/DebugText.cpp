#include "DebugText.h"
#include <iostream>
#include <string>

DebugText::DebugText() {
    if (TTF_Init() == 0) {
        std::cout << "TTF lib initialized " << TTF_GetError() << std::endl;
    }
    else {
        std::cout << "Couldn't initialize TTF lib: " << TTF_GetError() << std::endl;
    }
}

DebugText::~DebugText() {
    TTF_CloseFont(Sans);
}

void DebugText::init(SDL_Renderer* r) {
    std::cout << "DebugText initialized" << std::endl;

    Sans = TTF_OpenFont("pixel.ttf", 24);
    if (!Sans) {
        std::cout << "Open Font FAILED" << std::endl;
        std::cout << TTF_GetError() << std::endl; 
    }

    angleMessage = TTF_RenderText_Solid(Sans, "Init Angle", color);
    speedMessage = TTF_RenderText_Solid(Sans, "Init Speed", color);
    velocityMessage = TTF_RenderText_Solid(Sans, "Velocity", color);
    if (!angleMessage) {
        std::cout << "surfaceMessage FAILED" << std::endl;
        std::cout << TTF_GetError() << std::endl;
    }

    angleTexture = SDL_CreateTextureFromSurface(r, angleMessage);
    speedTexture = SDL_CreateTextureFromSurface(r, speedMessage);
    velocityTexture = SDL_CreateTextureFromSurface(r, velocityMessage);
    if (!angleTexture) {
        std::cout << "Message texture FAILED" << std::endl;
        std::cout << TTF_GetError() << std::endl;
    }

    SDL_FreeSurface(angleMessage);
    SDL_FreeSurface(speedMessage);
    SDL_FreeSurface(velocityMessage);
}

void DebugText::updateText(SDL_Renderer* r, float angle, float speed, float* velocity) {
    if (debugEnabled) {
        std::string angleString = std::string("Angle: ") + std::to_string(angle);
        std::string speedString = std::string("Speed: ") + std::to_string(speed);
        std::string velocityString = std::string("Velocity X: ") + std::to_string(velocity[0]) + std::string(" Y: ") + std::to_string(velocity[1]);
        angleMessage = TTF_RenderText_Solid(Sans, angleString.c_str(), color);
        speedMessage = TTF_RenderText_Solid(Sans, speedString.c_str(), color);
        velocityMessage = TTF_RenderText_Solid(Sans, velocityString.c_str(), color);
        angleTexture = SDL_CreateTextureFromSurface(r, angleMessage);
        speedTexture = SDL_CreateTextureFromSurface(r, speedMessage);
        velocityTexture = SDL_CreateTextureFromSurface(r, velocityMessage);
        SDL_FreeSurface(angleMessage);
        SDL_FreeSurface(speedMessage);
        SDL_FreeSurface(velocityMessage);
    }
}

void DebugText::draw(SDL_Renderer* r) {
    if (debugEnabled) {
        SDL_RenderCopy(r, angleTexture, NULL, &angle_rect);
        SDL_RenderCopy(r, speedTexture, NULL, &speed_rect);
        SDL_RenderCopy(r, velocityTexture, NULL, &velocity_rect);
    }
}
