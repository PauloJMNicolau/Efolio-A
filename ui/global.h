#include <stdlib.h>

//verificar tipo de sistema operativo para aplicar o comando correcto para limpar ecrã.
//Windows - "cls"
//Unix - "clear"
#ifdef _WIN32
#define clearScreen() system("cls")
#else
#define clearScreen() system("clear")
#endif