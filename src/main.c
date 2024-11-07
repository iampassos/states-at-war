#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./colors.c"
#include "./objectives.c"
#include "./players.c"
#include "./territories.c"

#define WINDOW_HEIGHT 1920
#define WINDOW_WIDTH 1000

#define FPS 60
#define FRAME_TARGET_TIME 1000 / FPS

int game_is_runnning = 0;
int player_count = 0;

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

void setup() {
  char *names[6] = {"One", "Two", "Three", "Four", "Five", "Six"};

  for (int i = 0; i < player_count; i++) {
    players[i].color = colors[i].name;
    players[i].objective = objectives[i];
    players[i].username = names[i];
  }

  for (int i = 0, j = 0; i < TERRITORIES_COUNT; i++, j++) {
    j %= player_count;
    territories[i].owner = players[j].color;
    territories[i].troops = 1;
  }
}

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

void render(SDL_Texture *backgroundTexture) {
  SDL_RenderClear(renderer);

  SDL_Rect backgroundRect = {.x = 0, .y = 0, .w = 1920, .h = 1080};
  SDL_RenderCopy(renderer, backgroundTexture, NULL, &backgroundRect);

  SDL_RenderPresent(renderer);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("You must only specify how many players will there be\n");
    return 1;
  }

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    printf("Error initializing SDL\n");
    return 1;
  }

  window = SDL_CreateWindow("War Game", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, WINDOW_HEIGHT, WINDOW_WIDTH,
                            SDL_WINDOW_MAXIMIZED);

  if (!window) {
    printf("Error creating SDL window\n");
    return 1;
  }

  renderer = SDL_CreateRenderer(window, -1, 0);

  if (!renderer) {
    printf("Error creating SDL render\n");
    return 1;
  }

  game_is_runnning = 1;
  player_count = atoi(argv[1]);

  setup();

  SDL_Texture *backgroundTexture =
      IMG_LoadTexture(renderer, "assets/background.png");

  while (game_is_runnning) {
    process_input();
    update();
    render(backgroundTexture);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

  return 0;
}
