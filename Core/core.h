#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Core{
  private:
    bool isRunning;
    int RESW = 1280, RESH = 720;
    SDL_Window* window;
    SDL_Renderer* renderer;
    TTF_Font* sans;
    SDL_Color white = {255,255,255};
    SDL_Surface* surfaceMessage;
    SDL_Texture* message;
    SDL_Rect messageRect;
  
  public:
    Core();
    ~Core();
    void Init();
    void Run();
    void ProcessInput();
    void Update();
    void Render();
    void Destroy();
};
