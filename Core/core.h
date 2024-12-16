#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Core{
  private:
    bool isRunning;
    bool isFullscreen;
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
    void Setup();
    void ProcessInput();
    void Update();
    void Render();
    void Destroy();
    
    void toggleFullscreen(SDL_Window* window){
      isFullscreen = !isFullscreen;
      SDL_SetWindowFullscreen(window, isFullscreen ? SDL_WINDOW_FULLSCREEN : 0);
    }

    int winHeight = 720;
    int winWidth  = 1280;
};
