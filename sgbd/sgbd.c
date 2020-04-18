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
    lerlistalunos(bd->alunos);
    //Carregar ficheiro de inscrições
    return _SUCESSO;
}

int libertarBD(SGBD * bd){
    if(!bd){
        wprintf(L"Erro %d: Não foi possivel libertar memória!", _ERR_MEMORYFREE);
        return _ERR_MEMORYFREE;
    }
    if(bd->alunos){
        libertarListaAluno(bd->alunos);
        bd->alunos = NULL;
    }
    if(bd->ucs){
        libertarListaUC(bd->ucs);
        bd->ucs = NULL;
    }
    if(bd->inscricoes){
        libertarListaPasta(bd->inscricoes);
        bd->inscricoes = NULL;
    }
    free(bd);
    bd=NULL;
    return _SUCESSO;
}

int gravarDados(SGBD * bd){
    if(!bd){
        wprintf(L"Erro %d: Base de Dados não existe\n");
        return _ERR_RESOURCENOTFOUND;
    }
    //Gravar ficheiro de UCS
    gravarUCTexto(bd->ucs);
    //Gravar ficheiro de Alunos
    
    //Gravar ficheiro de inscrições
    return _SUCESSO;
}