#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./colors.c"
#include "./objectives.c"
#include "./players.c"
#include "./territories.c"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#define FPS 60
#define FRAME_TARGET_TIME 1000 / FPS

int game_is_runnning = 0;
int player_count = 0;
int player_turn = 0;

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

void render_text(char *text, TTF_Font *font, SDL_Color color, int x, int y) {
  SDL_Surface *textSurface = TTF_RenderText_Solid(font, text, color);
  SDL_Texture *textTexture =
      SDL_CreateTextureFromSurface(renderer, textSurface);
  SDL_Rect textPosition = {x, y, .w = textSurface->w, .h = textSurface->h};

  SDL_FreeSurface(textSurface);
  SDL_RenderCopy(renderer, textTexture, NULL, &textPosition);
}

void setup() {
  char *names[6] = {"PlayerOne",  "PlayerTwo",  "PlayerThree",
                    "PlayerFour", "PlayerFive", "PlayerSix"};

  for (int i = 0; i < player_count; i++) {
    players[i].color = colors[i];
    players[i].objective = objectives[i];
    players[i].username = names[i];
  }

  for (int i = 0, j = 0; i < TERRITORIES_COUNT; i++, j++) {
    j %= player_count;
    territories[i].color = players[j].color;
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
    if (event.key.keysym.sym == SDLK_ESCAPE) {
      game_is_runnning = 0;
      break;
    }
  }
}

void update(void) { SDL_Delay(FRAME_TARGET_TIME); }

void render(SDL_Texture *backgroundTexture, SDL_Texture *textures[],
            TTF_Font *fonts[]) {
  SDL_RenderClear(renderer);

  SDL_Rect backgroundRect = {
      .x = 0, .y = 0, .w = WINDOW_WIDTH, .h = WINDOW_HEIGHT};

  SDL_RenderCopy(renderer, backgroundTexture, NULL, &backgroundRect);

  for (int i = 0; i < TERRITORIES_COUNT; i++) {
    SDL_Rect rect = {.x = territories[i].coords[0],
                     .y = territories[i].coords[1],
                     .w = territories[i].dimensions[0],
                     .h = territories[i].dimensions[1]};

    SDL_SetTextureColorMod(textures[i], territories[i].color.rgb[0],
                           territories[i].color.rgb[1],
                           territories[i].color.rgb[2]);

    SDL_RenderCopy(renderer, textures[i], NULL, &rect);
  }

  SDL_Color color = {255, 255, 255};

  for (int i = 0; i < player_count; i++) {
    render_text(players[i].username, fonts[1], color, 30, 30 + (90 * i));

    int troopsCount = 0;
    int territoriesCount = 0;

    for (int j = 0; j < TERRITORIES_COUNT; j++) {
      if (strcmp(territories[j].color.name, players[i].color.name) == 0) {
        troopsCount += territories[j].troops;
        territoriesCount++;
      }
    }

    char troopsStr[3];
    char territoriesStr[3];

    sprintf(troopsStr, "%d", troopsCount);
    sprintf(territoriesStr, "%d", territoriesCount);

    char troops[30];
    strcat(strcpy(troops, "Troops: "), troopsStr);
    render_text(troops, fonts[0], color, 40, 65 + (90 * i));

    char territories[30];
    strcat(strcpy(territories, "Territories: "), territoriesStr);
    render_text(territories, fonts[0], color, 40, 90 + (90 * i));
  }

  char turn[20];
  strcat(strcpy(turn, players[player_turn].color.name), "'s Turn");
  render_text(turn, fonts[2], color, 1000, 30);

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

  window = SDL_CreateWindow("States at War", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT,
                            SDL_WINDOW_SHOWN);

  if (!window) {
    printf("Error creating SDL window\n");
    return 1;
  }

  renderer = SDL_CreateRenderer(window, -1, 0);

  if (!renderer) {
    printf("Error creating SDL render\n");
    return 1;
  }

  if (TTF_Init() != 0) {
    printf("Error initializing TTF\n");
    return 1;
  }

  game_is_runnning = 1;
  player_count = atoi(argv[1]);

  setup();

  SDL_Texture *backgroundTexture =
      IMG_LoadTexture(renderer, "assets/background.png");

  SDL_Texture *textures[TERRITORIES_COUNT];

  TTF_Font *fonts[3] = {
      TTF_OpenFont("assets/fonts/fontregular.ttf", 24),
      TTF_OpenFont("assets/fonts/fontregular.ttf", 28),
      TTF_OpenFont("assets/fonts/fontbold.ttf", 48),
  };

  if (!fonts[0] || !fonts[1] || !fonts[2]) {
    printf("Error loading font\n");
    return 1;
  }

  for (int i = 0; i < TERRITORIES_COUNT; i++) {
    textures[i] = IMG_LoadTexture(renderer, territories[i].path);
  }

  while (game_is_runnning) {
    process_input();
    update();
    render(backgroundTexture, textures, fonts);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

  return 0;
}
