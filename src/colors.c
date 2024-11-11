#ifndef COLORS_C
#define COLORS_C

struct Colors {
  char *name;
  int rgb[3];
} colors[] = {{.name = "Blue", .rgb = {69, 170, 242}},
              {.name = "Yellow", .rgb = {254, 211, 48}},
              {.name = "Purple", .rgb = {165, 94, 234}},
              {.name = "Red", .rgb = {229, 80, 57}},
              {.name = "Orange", .rgb = {253, 150, 68}},
              {.name = "Green", .rgb = {46, 204, 113}}};
#endif
