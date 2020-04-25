/*
 * Ficheiro que possui todas as funções globais da UI (User Interface)
 */

#include "global.h"


//cabeçalho dos menus, recebe string da designação do menu
void cabecalho(char *str) {
    imprimirMeio("Sistema de Gestão de Inscrições");
   	imprimirMeio("     Universidade Aberta       ");
	imprimirMeio(str);
}

//função verifica largura da tela
int largTela() {
	struct winsize ws;
    int x, fd;
	if (ioctl(0, TIOCGWINSZ, &ws) < 0)	//Dimensão da tela
	    err(1, "/dev/tty");

	x = ws.ws_col;	//largura da tela em colunas
    return x;
}

//função para imprimir no centro da tela
void imprimirMeio(char *str){
	int x = largTela();
	int len = strlen(str);
	int cursor = (x-len)/2;
	wprintf(L"\033[%dC%s\n", cursor, str);
}

//Função aguarda que utilizador pressione ENTER
void pressioneENTER(){
	wchar_t tecla = L' ';
	wprintf(L"\nPara continuar pressione ENTER");
    getwchar();
    do{
        wscanf(L"%c", &tecla);
    } while(tecla != L'\n');	
}





