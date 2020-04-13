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
