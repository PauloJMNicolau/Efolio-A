#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>
#include "sgbd.h"
#include "macro.h"

/************************************
 *          Motor SGBD              *
 ************************************/

//Criar Base de Dados vazia
SGBD *criarBaseDados(){
    SGBD * baseDados = calloc(1, sizeof(SGBD));
    if (!baseDados)
    {
        wprintf(L"Erro %d: Impossível alocar memória para Base de Dados", _ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    baseDados->alunos = criarListaAluno();
    //baseDados->inscricoes = NULL;
    baseDados->ucs = criarListaUC();
    baseDados->proxIDAluno = 1;
    baseDados->proxIDUC = 1;
    return baseDados;
}






/*
//Remover elementos da arvore
int removerElementoInscricao(NoINSCRICAO * inscricao, TREE_INSCRICAO * arvore){
    if(!arvore){
        return _ERR_EMPTYLIST;
    }
    if(inscricao == arvore->raiz) //Remover na raiz da arvore
        arvore->raiz = removerElementoNaSubArvore(inscricao,arvore->raiz);
    else{
        int res = wcscmp(inscricao->elemento->anoLetivo, arvore->raiz->elemento->anoLetivo);
        if(res ==0)
            arvore->raiz->ramo = removerElementoNaSubArvore(inscricao,arvore->raiz->ramo);
        else if(res < 0)
            arvore->raiz->anterior = removerElementoNaSubArvore(inscricao, arvore->raiz->anterior);
        else
            arvore->raiz->proximo = removerElementoNaSubArvore(inscricao, arvore->raiz->proximo);
    }
    arvore->elementos--;
    libertarNoInscricao(inscricao);
    inscricao= NULL;
    return _SUCESSO;
}

//Remover Elementos na Subarvore
NoINSCRICAO * removerElementoNaSubArvore(NoINSCRICAO * inscricao, NoINSCRICAO * subarvore){
    if(inscricao ==subarvore){
        if(subarvore->ramo){ //Verifica se existem ramo central
            if(subarvore->anterior){
                subarvore->ramo->anterior = inserirElementoArvore(subarvore->anterior, subarvore->ramo);
            }
            if(subarvore->proximo){
                subarvore->ramo->proximo = inserirElementoArvore(subarvore->proximo, subarvore->ramo);
            }
            return subarvore->ramo;
        } else if(subarvore->proximo){ //Verifica se existe ramo seguinte
            if(subarvore->anterior){
                subarvore->proximo->anterior = inserirElementoArvore(subarvore->anterior, subarvore->proximo);
            }
            return subarvore->proximo;
        } else{ //Verifica se existe ramo anterior
            return subarvore->anterior;
        }
    } else{
        int res = wcscmp(inscricao->elemento->anoLetivo, subarvore->elemento->anoLetivo);
        if(res ==0)
            subarvore->ramo = removerElementoNaSubArvore(inscricao,subarvore->ramo);
        else if(res < 0)
            subarvore->anterior = removerElementoNaSubArvore(inscricao, subarvore->anterior);
        else
            subarvore->proximo = removerElementoNaSubArvore(inscricao, subarvore->proximo);
    }
    return subarvore;
}*/

//Incrementar IDAluno
//Retorna ID Atual
int obterIDAluno(SGBD *baseDados)
{
    return baseDados->proxIDAluno++;
}

//Incrementa IDUC
//Retorna ID Atual
int obterIDUC(SGBD *baseDados)
{
    return baseDados->proxIDUC++;
}
