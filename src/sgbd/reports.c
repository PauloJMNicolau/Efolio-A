/*
 * Ficheiro que possui todas as funções que gerem os reports
 */
#include "reports.h"
/************************
 *      Report A       *
 * **********************/

/************************
 *      Report B        *
 * **********************/

//Crar lista de Report B
REP_B * criarListaReportB(){
    REP_B * nova = calloc(1, sizeof(REP_B));
    if(!nova){
        wprintf(L"Erro %d: nâo foi possivel alocar memoria do report\n",_ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    nova->cauda = NULL;
    nova->quantidade =0;
    return nova;
}

//Criar elemento da lista ReportB
REP_B_ELEM * criarElementoReportB(int id, int nota){
    REP_B_ELEM * nova = calloc(1, sizeof(REP_B_ELEM));
    if(!nova){
        wprintf(L"Erro %d: nâo foi possivel alocar memoria do report\n",_ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    nova->chave = id;
    modificarEstado(nova,nota);
    nova->proximo = nova; //Aponta para ele mesmo, util no caso de ser o unico elemento da lista
    return nova;
}

//Libertar memoria do Elemento Report B
void libertarElementoReportB(REP_B_ELEM * elemento){
    if(!elemento){
        wprintf(L"Erro %d: Não é possivel eliminar o elemento", _ERR_MEMORYFREE);
    }
    elemento->chave = 0;
    elemento->estado= 0;
    elemento->proximo = NULL;
    free(elemento);
    elemento = NULL;
}

//Remover no inicio da lista
int removerElementoRepBInicio(REP_B * lista){
    if(!lista){
        wprintf(L"Erro %d: Não foi possivel remover elemento da lista", _ERR_IMPOSSIBLE);
        return _ERR_IMPOSSIBLE;
    }
    if(lista->cauda){
        lista->quantidade--;
        if(lista->quantidade == 0){
            libertarElementoReportB(lista->cauda);
            lista->cauda = NULL;
        } else{
            REP_B_ELEM * temp = lista->cauda->proximo;
            lista->cauda->proximo = temp->proximo;
            libertarElementoReportB(temp);
        }
        return _SUCESSO;
    }
    return _ERR_IMPOSSIBLE;
}

//Adiciona elemento no final da lista
int adicionarElementoRepBFim(REP_B * lista, REP_B_ELEM * elemento){
    if(!lista || !elemento){
        wprintf(L"Erro %d: Não foi possivel adicionar elemento da lista", _ERR_IMPOSSIBLE);
        return _ERR_IMPOSSIBLE;
    }
    if(lista->quantidade > 0){
        elemento->proximo = lista->cauda->proximo;
        lista->cauda->proximo = elemento;
    }
    lista->cauda = elemento;
    lista->quantidade++;
    return _SUCESSO;
}

//Modifica estado do elemento
void modificarEstado(REP_B_ELEM * elemento, int nota){
    if(nota<10){
        elemento->estado = 0;   //Reprovado
    } else {
        elemento->estado =1;    //Aprovado
    }
}

//Liberta Memoria da Lista Report B
void libertarListaReportB(REP_B * lista){
    if(!lista)
        wprintf(L"Erro %d: Não é possivel eliminar o elemento", _ERR_MEMORYFREE);
    while(lista->quantidade !=0)
        removerElementoRepBInicio(lista);
    lista->cauda = NULL;
    free(lista);
    lista = NULL;
    
}

//Obter Elemento com chave igual a id
REP_B_ELEM * obterElementoReportBNum(int id, REP_B * lista){
    if(!lista)
        return NULL;
    int i =0;
    REP_B_ELEM * temp = lista->cauda;
    while(i<lista->quantidade){
        temp = temp->proximo;
        if(temp->chave == id)
            return temp;
        i++;
    }
    return NULL;
}

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

/************************
 *      Report C        *
 * **********************/

/************************
 *      Report D        *
 * **********************/
