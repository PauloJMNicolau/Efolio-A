#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>
#include "sgbd.h"


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
    baseDados->inscricoes = criarListaPastas();
    baseDados->ucs = criarListaUC();
    return baseDados;
}

int carregarFicheiros(SGBD * bd){
    if(!bd){
        wprintf(L"Erro %d: Base de Dados não existe\n");
        return _ERR_RESOURCENOTFOUND;
    }
    //Carregar ficheiro de UCS
    lerUCTexto(bd->ucs);
    //Carregar ficheiro de Alunos
    lerlistaluno(bd->alunos);
    //Carregar ficheiro de inscrições
    return _SUCESSO;
}