#include<iostream>
#include<SDL2/SDL.h>

int main(int argc, char *argv[]){
  std::cout << "Test" << std::endl;
  bool isRunning = false;

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
    std::cout << "Error Initializing SDL \n Error:" << SDL_GetError() << std::endl;
    return 1;
  }

  SDL_Window* window = SDL_CreateWindow("Lume Engine Test Window",
                                         SDL_WINDOWPOS_CENTERED,
                                         SDL_WINDOWPOS_CENTERED,
                                         640,480,0);

  if (!window){
    std::cout << "Error Creating Window\nError:" << SDL_GetError() << std::endl;
    return 1;
  }

  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

  if (!renderer){
    std::cout << "Error Creating Renderer\nError:" << SDL_GetError() << std::endl;
    return 1;
  }

  isRunning = true;

  while (isRunning){
    SDL_Event e;
    while(SDL_PollEvent(&e) != 0){
      if(e.type == SDL_QUIT){
        isRunning = false;
        break;
      }
    }
  }
  
  /*while(isRunning){
    SDL_RenderDrawLine(renderer,
                       10,10,
                       60,60);

  }*/

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  //TODO: 1.display text in the window in different pos
  //TODO: 2.display shapes
  //TODO: 3.display images
  //TODO: 4.display images in background, animate the images

  return 0;
}
