#pragma once

#include <SDL2/SDL.h>

class Core{
  private:
    bool isRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;
  
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
