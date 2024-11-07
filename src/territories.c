#ifndef TERRITORIES_C
#define TERRITORIES_C

struct Territory {
  char *name;
  char *uf;
  char *path;
  char *owner;
  int troops;
} territories[] = {
    {.name = "Acre", .uf = "AC", .path = "assets/map/BR-AC.svg"},
    {.name = "Alagoas", .uf = "AL", .path = "assets/map/BR-AL.svg"},
    {.name = "Amapá", .uf = "AP", .path = "assets/map/BR-AP.svg"},
    {.name = "Amazonas", .uf = "AM", .path = "assets/map/BR-AM.svg"},
    {.name = "Bahia", .uf = "BA", .path = "assets/map/BR-BA.svg"},
    {.name = "Ceará", .uf = "CE", .path = "assets/map/BR-CE.svg"},
    {.name = "Espírito Santo", .uf = "ES", .path = "assets/map/BR-ES.svg"},
    {.name = "Goiás", .uf = "GO", .path = "assets/map/BR-GO.svg"},
    {.name = "Maranhão", .uf = "MA", .path = "assets/map/BR-MA.svg"},
    {.name = "Mato Grosso", .uf = "MT", .path = "assets/map/BR-MT.svg"},
    {.name = "Mato Grosso do Sul", .uf = "MS", .path = "assets/map/BR-MS.svg"},
    {.name = "Minas Gerais", .uf = "MG", .path = "assets/map/BR-MG.svg"},
    {.name = "Pará", .uf = "PA", .path = "assets/map/BR-PA.svg"},
    {.name = "Paraíba", .uf = "PB", .path = "assets/map/BR-PB.svg"},
    {.name = "Paraná", .uf = "PR", .path = "assets/map/BR-PR.svg"},
    {.name = "Pernambuco", .uf = "PE", .path = "assets/map/BR-PE.svg"},
    {.name = "Piauí", .uf = "PI", .path = "assets/map/BR-PI.svg"},
    {.name = "Rio de Janeiro", .uf = "RJ", .path = "assets/map/BR-RJ.svg"},
    {.name = "Rio Grande do Norte", .uf = "RN", .path = "assets/map/BR-RN.svg"},
    {.name = "Rio Grande do Sul", .uf = "RS", .path = "assets/map/BR-RS.svg"},
    {.name = "Rondônia", .uf = "RO", .path = "assets/map/BR-RO.svg"},
    {.name = "Roraima", .uf = "RR", .path = "assets/map/BR-RR.svg"},
    {.name = "Santa Catarina", .uf = "SC", .path = "assets/map/BR-SC.svg"},
    {.name = "São Paulo", .uf = "SP", .path = "assets/map/BR-SP.svg"},
    {.name = "Sergipe", .uf = "SE", .path = "assets/map/BR-SE.svg"},
    {.name = "Tocantins", .uf = "TO", .path = "assets/map/BR-TO.svg"}};

#define TERRITORIES_COUNT (sizeof(territories) / sizeof(territories[0]))

#endif
