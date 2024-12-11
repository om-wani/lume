#include "core.h"
#include <iostream>
#include <SDL2/SDL.h>

Core::Core(){
  std::cout << "Core Class Constructor called!" << std::endl;
  isRunning = false;

}

Core::~Core(){
  std::cout << "Core Class Destructor called!" << std::endl;

}

void Core::Init(){
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
    std::cout << "Error Initializing SDL \n Error:" << SDL_GetError() << std::endl;
    return;
  }

  window = SDL_CreateWindow("Lume Engine Test Window",
                                         SDL_WINDOWPOS_CENTERED,
                                         SDL_WINDOWPOS_CENTERED,
                                         640,480,0);

  if (!window){
    std::cout << "Error Creating Window\nError:" << SDL_GetError() << std::endl;
    return;
  }

  renderer = SDL_CreateRenderer(window, -1, 0);

  if (!renderer){
    std::cout << "Error Creating Renderer\nError:" << SDL_GetError() << std::endl;
    return;
  }

  isRunning = true;

}

void Core::ProcessInput(){
  SDL_Event sdlEvent;
  while(SDL_PollEvent(&sdlEvent)) {
    switch (sdlEvent.type) {
      case SDL_QUIT:
        isRunning = false;
        break;
      case SDL_KEYDOWN:
        if (sdlEvent.key.keysym.sym == SDLK_ESCAPE){
          isRunning = false;
        }
        break;
    }
  }
}

void Core::Update(){
  // updates game objects
}

void Core::Render(){
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
}

void Core::Run(){
  while(isRunning){
    ProcessInput();
    Update();
    Render();
  }
}

void Core::Destroy(){
  if (renderer) SDL_DestroyRenderer(renderer);
  if (window) SDL_DestroyWindow(window);
  SDL_Quit();
}


  //TODO: 1.display text in the window in different pos
  //TODO: 2.display shapes
  //TODO: 3.display images
  //TODO: 4.display images in background, animate the images

