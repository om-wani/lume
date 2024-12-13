#include "core.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

Core::Core(){
  std::cout << "Core Class Constructor called!" << std::endl;
  isRunning = false;

}

Core::~Core(){
  std::cout << "Core Class Destructor called!" << std::endl;

}

void Core::Init(){
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
    std::cout << "Error Initializing SDL \n Error:" << SDL_GetError() << std::endl;
    return;
  }

  if (TTF_Init() < 0){
    std::cout << "Error Initializing TTF\nError:" << SDL_GetError() << std::endl;
    return;
  }

  window = SDL_CreateWindow("Lume Engine Test Window",
                                         SDL_WINDOWPOS_CENTERED,
                                         SDL_WINDOWPOS_CENTERED,
                                         RESW,RESH,0);

  if (!window){
    std::cout << "Error Creating Window\nError:" << SDL_GetError() << std::endl;
    return;
  }

  renderer = SDL_CreateRenderer(window, -1, 0);

  if (!renderer){
    std::cout << "Error Creating Renderer\nError:" << SDL_GetError() << std::endl;
    return;
  }
  
  //create for every font
  sans = TTF_OpenFont("assets/fonts/hlsimple.ttf", 72);
  if (!sans){std::cout<<"Error opening font\nError:"<<SDL_GetError()<<std::endl;return;}
  
  // for Text1
  surfaceMessage = TTF_RenderText_Blended(sans, "this is test text.,?![]{}()", white);
  if (!surfaceMessage){std::cout<<"Error creating surface\nError:"<<SDL_GetError()<<std::endl;return;}

  message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
  if (!message){std::cout<<"Error creating texture\nError:"<<SDL_GetError()<<std::endl;return;}
  
  messageRect.x = (RESW-(surfaceMessage->w))/2;
  messageRect.y = (RESH-(surfaceMessage->h))/2;
  messageRect.w = surfaceMessage->w;
  messageRect.h = surfaceMessage->h;
  // till here

  
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
        if (sdlEvent.key.keysym.sym == SDLK_LSHIFT && sdlEvent.key.keysym.sym == SDLK_w){
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
  SDL_SetRenderDrawColor(renderer, 128, 0, 0, 255);
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, message, NULL, &messageRect);
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
  if (surfaceMessage) SDL_FreeSurface(surfaceMessage);
  if (message) SDL_DestroyTexture(message);
  if (sans) TTF_CloseFont(sans);
  if (renderer) SDL_DestroyRenderer(renderer);
  if (window) SDL_DestroyWindow(window);
  TTF_Quit();
  SDL_Quit();
}


  //TODO: 1.display text in the window in different pos
  //TODO: 2.display shapes
  //TODO: 3.display images
  //TODO: 4.display images in background, animate the images

