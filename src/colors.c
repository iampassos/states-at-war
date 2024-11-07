#ifndef COLORS_C
#define COLORS_C

struct Colors {
  char *name;
  int rgb[3];
} colors[] = {{.name = "blue", .rgb = {69, 170, 242}},
              {.name = "yellow", .rgb = {254, 211, 48}},
              {.name = "purple", .rgb = {165, 94, 234}},
              {.name = "red", .rgb = {229, 80, 57}},
              {.name = "orange", .rgb = {253, 150, 68}},
              {.name = "green", .rgb = {46, 204, 113}}};
#endif
