#ifndef COLORS_C
#define COLORS_C

struct Colors {
  char *name;
  int rgb[3];
} colors[] = {{.name = "blue", .rgb = {0, 0, 255}},
              {.name = "yellow", .rgb = {255, 255, 0}},
              {.name = "white", .rgb = {255, 255, 255}},
              {.name = "red", .rgb = {255, 0, 0}},
              {.name = "pink", .rgb = {255, 192, 203}},
              {.name = "green", .rgb = {0, 255, 0}}};

#endif
