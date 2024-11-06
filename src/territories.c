#ifndef TERRITORIES_C
#define TERRITORIES_C

char *territory_names[] = {"Alaska",
                           "Northwest Territory",
                           "Greenland",
                           "Alberta",
                           "Ontario",
                           "Quebec",
                           "Western United States",
                           "Eastern United States",
                           "Central America",
                           "Venezuela",
                           "Peru",
                           "Brazil",
                           "Argentina",
                           "Iceland",
                           "Scandinavia",
                           "Ukraine",
                           "Great Britain",
                           "Northern Europe",
                           "Western Europe",
                           "Southern Europe",
                           "North Africa",
                           "Egypt",
                           "East Africa",
                           "Congo",
                           "South Africa",
                           "Madagascar",
                           "Ural",
                           "Siberia",
                           "Yakutsk",
                           "Kamchatka",
                           "Irkutsk",
                           "Mongolia",
                           "Japan",
                           "Afghanistan",
                           "China",
                           "Middle East",
                           "India",
                           "Siam",
                           "Indonesia",
                           "New Guinea",
                           "Western Australia",
                           "Eastern Australia"};

#define TERRITORIES_COUNT (sizeof(territory_names) / sizeof(territory_names[0]))

struct Territory {
  char *name;
  char *owner;
  int troops;
} territories[TERRITORIES_COUNT];

#endif
