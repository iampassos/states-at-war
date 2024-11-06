#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>

#define WINDOW_HEIGHT 810
#define WINDOW_WIDTH 600

#define FPS 60
#define FRAME_TARGET_TIME 1000 / FPS

int game_is_runnning = 0;

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

void setup(void) {}

void process_input(void) {
  SDL_Event event;
  SDL_PollEvent(&event);

  switch (event.type) {
  case SDL_QUIT:
    game_is_runnning = 0;
    break;
  case SDL_KEYDOWN:
    switch (event.key.keysym.sym) {
    case SDLK_ESCAPE:
      game_is_runnning = 0;
      break;
    }
  }
}

void update(void) { SDL_Delay(FRAME_TARGET_TIME); }

void render(void) {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
}

int main(void) {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    printf("Error initializing SDL\n");
    return 0;
  }

  window = SDL_CreateWindow("War Game", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, WINDOW_HEIGHT, WINDOW_WIDTH,
                            SDL_WINDOW_SHOWN);

  if (!window) {
    printf("Error creating SDL window\n");
    return 0;
  }

  renderer = SDL_CreateRenderer(window, -1, 0);

  if (!renderer) {
    printf("Error creating SDL render\n");
    return 0;
  }

  game_is_runnning = 1;

  setup();

  while (game_is_runnning) {
    process_input();
    update();
    render();
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

  return 0;
}
