#ifndef OBJECTIVE_C
#define OBJECTIVE_C

struct Objective {
  int id;
  char *description;
} objectives[3] = {
    {.id = 0, .description = "Test0"},
    {.id = 1, .description = "Test1"},
    {.id = 2, .description = "Test2"},
};

#endif
