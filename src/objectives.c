#ifndef OBJECTIVES_C
#define OBJECTIVES_C

struct Objective {
  int id;
  char *description;
} objectives[] = {
    {.id = 0, .description = "Conquer all territories"},
    {.id = 1, .description = "Conquer North and Northeast"},
    {.id = 2, .description = "Conquer North and Southeast"},
    {.id = 3, .description = "Conquer North and Central-West"},
    {.id = 4, .description = "Conquer North and South"},
    {.id = 5, .description = "Conquer Northeast and Southeast"},
    {.id = 6, .description = "Conquer Northeast and Central-West"},
    {.id = 7, .description = "Conquer Northeast and South"},
    {.id = 8, .description = "Conquer Southeast and Central-West"},
    {.id = 9, .description = "Conquer Southeast and South"},
    {.id = 10, .description = "Conquer Central-West and South"},
};

#endif
