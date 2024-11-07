#ifndef PLAYERS_C
#define PLAYERS_C

#include "./objectives.c"

struct Player {
  char *username;
  char *color;
  struct Objective objective;
} players[6];

#endif
