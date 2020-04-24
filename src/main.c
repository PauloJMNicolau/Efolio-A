#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "ui/ui.h"
#include "sgbd/sgbd.h"

/********************************
 *          Headers             *
 ********************************/

//Executar o Programa Completo
void executarPrograma();


/********************************
 *          Programa            *
 ********************************/

//Executar o Programa Completo
void executarPrograma(){
    //Criar Base de Dados
    SGBD * sgbd = criarBaseDados();
    //Carregar programa (Carregar Dados dos ficheiros)
    carregarFicheiros(sgbd);
    //Mostrar Menu Principal
    menuPrincipal(sgbd);
    //Gravar dados do programa no ficheiro
    gravarDados(sgbd);
    //Terminar Programa (Libertar memoria)
    libertarBD(sgbd);
}


int main(int argc, char ** argv){
    setlocale(LC_ALL,"pt_PT.UTF-8");
    setlocale(LC_CTYPE, " ");
    executarPrograma();
    return 0;
}