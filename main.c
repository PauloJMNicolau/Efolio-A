#include <stdio.h>
#include <stdlib.h>
#include "ui/menu.h"
#include "sgbd/sgbd.h"
#include "sgbd/arvore.h"
#include "sgbd/alunos.h"
#include "sgbd/ucs.h"

int main(int argc, char ** argv){

    INSCRICAO * i1 = criarInscricao(1,2,L"2012/2013");
    INSCRICAO * i2 = criarInscricao(1,4,L"2011/2012");
    INSCRICAO * i3 = criarInscricao(1,6,L"2013/2014");
    INSCRICAO * i4 = criarInscricao(1,7,L"2012/2013");
    INSCRICAO * i5 = criarInscricao(1,8,L"2013/2014");
    INSCRICAO * i6 = criarInscricao(1,5,L"2012/2013");
    
    TREE_INSCRICAO * arvore = criarArvore();
    inserirArvore(arvore,i1);
    inserirArvore(arvore,i2);
    inserirArvore(arvore,i3);
    inserirArvore(arvore,i4);
    inserirArvore(arvore,i5);
    inserirArvore(arvore,i6);
    
    NoINSCRICAO * no = procuraInscricao(1,2,L"2012/2013", arvore->raiz);
    NoINSCRICAO * no1 = procuraInscricao(1,8,L"2013/2014", arvore->raiz);
    NoINSCRICAO * no2 = procuraInscricao(1,5,L"2012/2013", arvore->raiz);

    //removerElementoInscricao(no,arvore);

    return 0;
}