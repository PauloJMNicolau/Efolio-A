
#include "reports.h"

//Criar elemento
ECTS * criarElementoECTS(int numeroAluno, wchar_t * nomeAluno, int ects, wchar_t * observacao){
    ECTS * unidade = calloc(1, sizeof(ECTS));
    if (!unidade){
        wprintf(L"Erro %d: Impossível alocar memória para Elemento do Report ECTS", _ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    unidade->numero = numeroAluno;
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
NoRepECTS * criarNoECTS(ECTS * elemento){
    NoRepECTS * novo = calloc(1,sizeof(NoRepECTS));
    if(!novo){
        wprintf(L"Erro %d: Impossível alocar memória para elemento do Report ECTS", _ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
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

//Adicionar elemento ECTS na lista
int adicionarRepECTS(ECTS * unidade, ListRepECTS * lista, int pos){
    if(!lista || !unidade){
        wprintf(L"Erro %d: Impossível adicionar elemento na lista\n", _ERR_EMPTYLIST);
        return _ERR_EMPTYLIST;
    }
    if(pos<0 || pos > lista->elementos){
        wprintf(L"Erro %d: Posição inválida na lista\n", _ERR_IMPOSSIBLE);
        return _ERR_IMPOSSIBLE;
    }
    NoRepECTS * no = criarNoECTS(unidade);
    if(lista->elementos==0){ //Lista vazia adiciona no inicio
        lista->cauda = no;
        lista->elementos++;
    } else if(pos == lista->elementos){// Adiciona no final
        no->proximo = lista->cauda->proximo;    //Aponta novo elemento para o inicio da lista
        lista->cauda->proximo = no;             //Aponta ultimo elemento atual da lista para o novo elemento
        lista->cauda = no;                      //Atualiza o ultimo elemento
        lista->elementos++;
    } else{ //Adiciona na posição;
        NoRepECTS * temp = lista->cauda->proximo;
        for(int i =0;i<pos; i++)
            temp = temp->proximo;
        no->proximo = temp->proximo;    //Aponta novo elemento para o elemento seguinte da posição da lista
        temp->proximo = no;             //Aponta posicao anterior para o novo elemento
        lista->elementos++;
    }
    return _SUCESSO;
}

//Remover elemento da lista
int removerElementoECTS(int pos, ListRepECTS * lista){
    if(!lista){
        wprintf(L"Erro %d: Impossível remover elemento na lista", _ERR_EMPTYLIST);
        return _ERR_EMPTYLIST;
    }
    if(pos < 0 || pos >= lista->elementos){
        wprintf(L"Erro %d: Posição inválida na lista", _ERR_IMPOSSIBLE);
        return _ERR_IMPOSSIBLE;
    }
    if(pos==0){ //Remover na cabeça da lista
        NoRepECTS * temp = lista->cauda->proximo;
        lista->cauda->proximo = temp->proximo;      //Aponta final da lista para segundo elemento da lista
        lista->elementos--;
        libertarNoECTS(temp);
    } else {    //Remove na posição
        NoRepECTS *temp = lista->cauda->proximo;
        for (int i = 0; i < pos-1; i++)
            temp = temp->proximo;
        NoRepECTS * aux = temp->proximo;
        temp->proximo = aux->proximo; //Aponta elemento atual para o segundo elemento seguinte da posição da lista
        if (pos == lista->elementos - 1)
            lista->cauda = temp; //Atualiza cauda caso seja o ultimo elemento a remover
        lista->elementos--;
        libertarNoECTS(aux);
    }
    return _SUCESSO;
}
//Adicionar dados no elemento 
void adicionarECTS(ECTS * elemento, int ects, wchar_t * observacao){
    elemento->ects = ects;
    elemento->observacao = calloc(_TAMSTRING, sizeof(wchar_t));
    if (!elemento->observacao){
        wprintf(L"Erro %d: Impossível alocar memória para nome de Aluno do Report ECTS", _ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    swprintf(elemento->observacao,wcslen(observacao)+1,L"%S",observacao);
}


