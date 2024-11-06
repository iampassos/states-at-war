#ifndef OBJECTIVES_C
#define OBJECTIVES_C

struct Objective {
  int id;
  char *description;
} objectives[] = {
    {.id = 0, .description = "Conquer 24 territories"},
    {.id = 1, .description = "Eliminate the yellow army"},
    {.id = 2, .description = "Eliminate the blue army"},
    {.id = 3, .description = "Eliminate the green army"},
    {.id = 4, .description = "Eliminate the black army"},
    {.id = 5, .description = "Eliminate the red army"},
    {.id = 6, .description = "Eliminate the white army"},
    {.id = 7, .description = "Conquer North America and Africa"},
    {.id = 8, .description = "Conquer North America and Oceania"},
    {.id = 9, .description = "Conquer Europe and South America"},
    {.id = 10, .description = "Conquer Europe and Oceania"},
    {.id = 11, .description = "Conquer Asia and South America"},
    {.id = 12, .description = "Conquer Asia and Africa"},
    {.id = 13,
     .description = "Conquer 18 territories with at least two armies in each"},
    {.id = 14, .description = "Conquer 30 territories"},
    {.id = 15, .description = "Conquer South America and Africa"},
    {.id = 16, .description = "Conquer North America and Asia"},
    {.id = 17, .description = "Conquer Europe and Asia"},
    {.id = 18, .description = "Conquer Asia and Oceania"},
    {.id = 19, .description = "Conquer North America and Europe"}};

#endif
