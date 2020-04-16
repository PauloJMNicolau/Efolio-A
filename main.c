#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "ui/menu.h"
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
    //Carregar programa (Carregar Dados)
    SGBD * sgbd = criarBaseDados();
    carregarFicheiros(sgbd);
    //Mostrar Menu
    menuPrincipal(sgbd);
    //Terminar Programa (Libertar memoria)
}


int main(int argc, char ** argv){
    setlocale(LC_ALL,"pt_PT.UTF-8");
    setlocale(LC_CTYPE, " ");
    executarPrograma();




    
    INSCRICAO * i1 = criarInscricao(1,2,L"2012/2013");
    INSCRICAO * i2 = criarInscricao(1,4,L"2011/2012");
    INSCRICAO * i3 = criarInscricao(1,6,L"2013/2014");
    INSCRICAO * i4 = criarInscricao(1,7,L"2012/2013");
    INSCRICAO * i5 = criarInscricao(1,8,L"2013/2014");
    INSCRICAO * i6 = criarInscricao(1,5,L"2012/2013");
    LISTA_PASTA * inscricoes = criarListaPastas();
    adicionarInscricao(i1,inscricoes);
    adicionarInscricao(i2,inscricoes);
    adicionarInscricao(i3,inscricoes);
    adicionarInscricao(i4,inscricoes);
    adicionarInscricao(i5,inscricoes);
    adicionarInscricao(i6,inscricoes);
    
    INSCRICAO* no = procuraInscricao(inscricoes, L"2012/2013",2,1);
    INSCRICAO* no1 = procuraInscricao(inscricoes, L"2013/2014",8,1);
    INSCRICAO* no2 = procuraInscricao(inscricoes, L"2012/2013",5,1);

    removerInscricao(i6,inscricoes);
    //removerElementoInscricao(no,arvore);

    return 0;
}