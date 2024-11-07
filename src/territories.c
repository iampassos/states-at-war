#ifndef TERRITORIES_C
#define TERRITORIES_C

#include "colors.c"

struct Territory {
  char *name;
  char *uf;
  char *path;
  int coords[2];
  int dimensions[2];
  int troops;
  struct Colors color;
} territories[] = {{.name = "Acre",
                    .uf = "AC",
                    .path = "assets/map/BR-AC.svg",
                    .coords = {334, 233},
                    .dimensions = {115, 64}},
                   {
                       .name = "Alagoas",
                       .uf = "AL",
                       .path = "assets/map/BR-AL.svg",
                       .coords = {892, 260},
                       .dimensions = {49, 27},
                   },
                   {
                       .name = "Amapá",
                       .uf = "AP",
                       .path = "assets/map/BR-AP.svg",
                       .coords = {634, 54},
                       .dimensions = {77, 88},
                   },
                   {.name = "Amazonas",
                    .uf = "AM",
                    .path = "assets/map/BR-AM.svg",
                    .coords = {337, 88},
                    .dimensions = {273, 189}},
                   {
                       .name = "Bahia",
                       .uf = "BA",
                       .path = "assets/map/BR-BA.svg",
                       .coords = {762, 255},
                       .dimensions = {143, 157},
                   },
                   {
                       .name = "Ceará",
                       .uf = "CE",
                       .path = "assets/map/BR-CE.svg",
                       .coords = {842, 166},
                       .dimensions = {66, 80},
                   },
                   {
                       .name = "Espírito Santo",
                       .uf = "ES",
                       .path = "assets/map/BR-ES.svg",
                       .coords = {835, 404},
                       .dimensions = {35, 57},
                   },
                   {
                       .name = "Goiás",
                       .uf = "GO",
                       .path = "assets/map/BR-GO.svg",
                       .coords = {658, 317},
                       .dimensions = {115, 114},
                   },
                   {
                       .name = "Maranhão",
                       .uf = "MA",
                       .path = "assets/map/BR-MA.svg",
                       .coords = {728, 139},
                       .dimensions = {109, 145},
                   },
                   {
                       .name = "Mato Grosso",
                       .uf = "MT",
                       .path = "assets/map/BR-MT.svg",
                       .coords = {527, 236},
                       .dimensions = {179, 171},
                   },
                   {
                       .name = "Mato Grosso do Sul",
                       .uf = "MS",
                       .path = "assets/map/BR-MS.svg",
                       .coords = {581, 393},
                       .dimensions = {114, 115},
                   },
                   {
                       .name = "Minas Gerais",
                       .uf = "MG",
                       .path = "assets/map/BR-MG.svg",
                       .coords = {692, 346},
                       .dimensions = {175, 142},
                   },
                   {
                       .name = "Pará",
                       .uf = "PA",
                       .path = "assets/map/BR-PA.svg",
                       .coords = {568, 83},
                       .dimensions = {202, 194},
                   },
                   {
                       .name = "Paraíba",
                       .uf = "PB",
                       .path = "assets/map/BR-PB.svg",
                       .coords = {884, 216},
                       .dimensions = {62, 36},
                   },
                   {
                       .name = "Paraná",
                       .uf = "PR",
                       .path = "assets/map/BR-PR.svg",
                       .coords = {636, 481},
                       .dimensions = {103, 72},
                   },
                   {
                       .name = "Pernambuco",
                       .uf = "PE",
                       .path = "assets/map/BR-PE.svg",
                       .coords = {843, 235},
                       .dimensions = {103, 36},
                   },
                   {
                       .name = "Piauí",
                       .uf = "PI",
                       .path = "assets/map/BR-PI.svg",
                       .coords = {771, 165},
                       .dimensions = {88, 128},
                   },
                   {
                       .name = "Rio de Janeiro",
                       .uf = "RJ",
                       .path = "assets/map/BR-RJ.svg",
                       .coords = {788, 452},
                       .dimensions = {62, 44},
                   },
                   {
                       .name = "Rio Grande do Norte",
                       .uf = "RN",
                       .path = "assets/map/BR-RN.svg",
                       .coords = {886, 197},
                       .dimensions = {58, 35},
                   },
                   {
                       .name = "Rio Grande do Sul",
                       .uf = "RS",
                       .path = "assets/map/BR-RS.svg",
                       .coords = {589, 559},
                       .dimensions = {125, 121},
                   },
                   {
                       .name = "Rondônia",
                       .uf = "RO",
                       .path = "assets/map/BR-RO.svg",
                       .coords = {445, 247},
                       .dimensions = {110, 91},
                   },
                   {
                       .name = "Roraima",
                       .uf = "RR",
                       .path = "assets/map/BR-RR.svg",
                       .coords = {477, 41},
                       .dimensions = {94, 104},
                   },
                   {
                       .name = "Santa Catarina",
                       .uf = "SC",
                       .path = "assets/map/BR-SC.svg",
                       .coords = {648, 540},
                       .dimensions = {87, 60},
                   },
                   {
                       .name = "São Paulo",
                       .uf = "SP",
                       .path = "assets/map/BR-SP.svg",
                       .coords = {659, 435},
                       .dimensions = {141, 94},
                   },
                   {
                       .name = "Sergipe",
                       .uf = "SE",
                       .path = "assets/map/BR-SE.svg",
                       .coords = {892, 271},
                       .dimensions = {29, 33},
                   },
                   {
                       .name = "Tocantins",
                       .uf = "TO",
                       .path = "assets/map/BR-TO.svg",
                       .coords = {697, 203},
                       .dimensions = {78, 129},
                   }};

#define TERRITORIES_COUNT (sizeof(territories) / sizeof(territories[0]))

#endif
