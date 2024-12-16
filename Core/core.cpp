#include "core.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

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
                                         winWidth,
                                         winHeight,
                                         SDL_WINDOW_METAL);

  if (!window){
    std::cout << "Error Creating Window\nError:" << SDL_GetError() << std::endl;
    return;
  }

  renderer = SDL_CreateRenderer(window, 
                                -1, 
                                SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if (!renderer){
    std::cout << "Error Creating Renderer\nError:" << SDL_GetError() << std::endl;
    return;
  }
  
  //create for every font
  sans = TTF_OpenFont("assets/fonts/hlsimple.ttf", 72);
  if (!sans){
    std::cout<<"Error opening font\nError:"<<SDL_GetError()<<std::endl;
    return;
  }
  
  // for Text1
  surfaceMessage = TTF_RenderText_Blended_Wrapped(sans, "press 'f' to toggle fullscreen. press 'esc' to close window", white, 800);
  if (!surfaceMessage){
    std::cout<<"Error creating surface\nError:"<<SDL_GetError()<<std::endl;
    return;
  }

  message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
  if (!message){
    std::cout<<"Error creating texture\nError:"<<SDL_GetError()<<std::endl;
    return;
  }
  
  messageRect.x = (winWidth-(surfaceMessage->w))/2;
  messageRect.y = (winHeight-(surfaceMessage->h))/2;
  messageRect.w = surfaceMessage->w;
  messageRect.h = surfaceMessage->h;
  // till here

  
  isRunning = true;

}

void Core::Setup(){
  // Initializing game objects
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
        if (sdlEvent.key.keysym.sym == SDLK_LALT){
          toggleFullscreen(window);
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

  SDL_Surface* fullscreen_surf = IMG_Load("./assets/images/fullscreen-btn.png");
  SDL_Surface* escape_surf = IMG_Load("./assets/images/buttons.svg");
  
  SDL_Texture* fullscreen_tex = SDL_CreateTextureFromSurface(renderer, fullscreen_surf);
  SDL_FreeSurface(fullscreen_surf);
  
  SDL_Texture* escape_tex = SDL_CreateTextureFromSurface(renderer, escape_surf);
  SDL_FreeSurface(escape_surf);

  SDL_Rect rect1 = {10,10,128,62};
  SDL_Rect rect2 = {10,70,300,146};

  SDL_RenderCopy(renderer, fullscreen_tex, NULL, &rect1);
  SDL_DestroyTexture(fullscreen_tex);

  SDL_RenderCopy(renderer, escape_tex, NULL, &rect2);
  SDL_DestroyTexture(escape_tex);

  SDL_RenderPresent(renderer);
}

void Core::Run(){
  Setup();
  while(isRunning){
    ProcessInput();
    Update();
    Render();
  }
}

void Core::Destroy(){
  if (surfaceMessage) SDL_FreeSurface(surfaceMessage);
  if (message)        SDL_DestroyTexture(message);
  if (sans)           TTF_CloseFont(sans);
  if (renderer)       SDL_DestroyRenderer(renderer);
  if (window)         SDL_DestroyWindow(window);
  TTF_Quit();
  SDL_Quit();
}


  //TODO: 1.display text in the window in different pos
  //TODO: 2.display shapes
  //TODO: 3.display images
  //TODO: 4.display images in background, animate the images

