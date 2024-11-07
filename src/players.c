#ifndef PLAYERS_C
#define PLAYERS_C

#include "./colors.c"
#include "./objectives.c"

struct Player {
  char *username;
  struct Colors color;
  struct Objective objective;
} players[6];

#endif
