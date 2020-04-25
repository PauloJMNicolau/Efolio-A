
#include "reports.h"

//Criar elemento
ECTS * criarElementoECTS(wchar_t * nomeAluno, int ects, wchar_t observacao){
    ECTS * unidade = calloc(1, sizeof(UC));
    if (!unidade){
        wprintf(L"Erro %d: Impossível alocar memória para Elemento do Report ECTS", _ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    unidade->ects = ects;
    unidade->nome = calloc(_TAMSTRING, sizeof(wchar_t));
    if (!unidade->nome){
        wprintf(L"Erro %d: Impossível alocar memória para nome de Aluno do Report ECTS", _ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    swprintf(unidade->nome,wcslen(nomeAluno)+1,L"%S",nomeAluno);
    unidade->observacao = calloc(_TAMSTRING, sizeof(wchar_t));
        if (!unidade->observacao){
            wprintf(L"Erro %d: Impossível alocar memória para observacao do Report ECTS", _ERR_MEMORYALLOC);
            exit(_ERR_MEMORYALLOC);
        }
        swprintf(unidade->observacao,wcslen(observacao)+1,L"%S",observacao);
    return unidade;
}

//Libertar Memoria do elemento Report ECTS
ECTS * libertarElementoECTS(ECTS * elemento){
    if (elemento){
        if (elemento->nome)
            free(elemento->nome);
        elemento->nome = NULL;
        if (elemento->observacao)
            free(elemento->observacao);
        free(elemento);
        elemento = NULL;
    }
    return elemento;
}

//Criar nó da lista tendo como chave número de aluno
NoRepECTS * criarNoECTS(ECTS * elemento, int numeroAluno){
    NoRepECTS * novo = calloc(1,sizeof(NoRepECTS));
    if(!novo){
        wprintf(L"Erro %d: Impossível alocar memória para elemento do Report ECTS", _ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    novo->numero = numeroAluno;
    novo->elemento = elemento;
    novo->proximo = novo;
    return novo;
}

//Libertar nó Report ECTS
int  libertarNoECTS(NoRepECTS * no){
    if(!no)
        return _ERR_MEMORYFREE;
    no->elemento = libertarElementoECTS(no->elemento);
    no->proximo = NULL;
    free(no);
    no = NULL;
    return _SUCESSO;
}

//Criar lista de Report ECTS vazia
ListRepECTS * criarListaECTS(){
    ListRepECTS * lista = calloc(1, sizeof(ListRepECTS));
    if(!lista){
        wprintf(L"Erro %d: Impossível alocar memória para Report ECTS", _ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    lista->elementos =0;
    lista->cauda = NULL;
    return lista;
}

//Eliminar Lista de UC
int libertarListaECTS(ListRepECTS * lista){
    if(!lista)
        return _ERR_MEMORYFREE;
    while(lista->elementos != 0){
        removerElementoECTS(0,lista);
    }
    lista->cauda = NULL;
    free(lista);
    lista= NULL;
    return _SUCESSO;
}



