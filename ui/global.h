#include <stdlib.h>

//verificar tipo de sistema operativo para aplicar o comando correcto para limpar ecrã.
//Windows - "cls"
//Unix - "clear"
#ifdef _WIN32
#define clearScreen() system("cls")
#else
#define clearScreen() system("clear")
#endif


//cabeçalho dos menus, recebe string da designação do menu
void cabecalho(char *str);
//função verifica largura da tela
int largTela();
//função para imprimir no centro da tela
void imprimirMeio(char *str);