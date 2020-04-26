/*
 * Ficheiro que possui todas as funções que gerem os reports
 */
#include "reports.h"
#include "../ui/global.h"
/************************
 *      Report A       *
 * **********************/
//Criar elemento
REP_A_ELEM * criarElementoReportA(int numeroAluno, wchar_t * nomeAluno, int ects, wchar_t * observacao){
    REP_A_ELEM * unidade = calloc(1, sizeof(REP_A_ELEM));
    if (!unidade){
        wprintf(L"Erro %d: Impossível alocar memória para Elemento do Report REP_A_ELEM", _ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    unidade->numero = numeroAluno;
    unidade->ects = ects;
    unidade->nome = calloc(_TAMSTRING, sizeof(wchar_t));
    if (!unidade->nome){
        wprintf(L"Erro %d: Impossível alocar memória para nome de Aluno do Report REP_A_ELEM", _ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    swprintf(unidade->nome,wcslen(nomeAluno)+1,L"%S",nomeAluno);
    unidade->observacao = calloc(_TAMSTRING, sizeof(wchar_t));
    if (!unidade->observacao){
        wprintf(L"Erro %d: Impossível alocar memória para observacao do Report REP_A_ELEM", _ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    swprintf(unidade->observacao,wcslen(observacao)+1,L"%S",observacao);
    return unidade;
}

//Libertar Memoria do elemento Report REP_A_ELEM
REP_A_ELEM * libertarElementoReportA(REP_A_ELEM * elemento){
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
No_REP_A * criarNoReportA(REP_A_ELEM * elemento){
    No_REP_A * novo = calloc(1,sizeof(No_REP_A));
    if(!novo){
        wprintf(L"Erro %d: Impossível alocar memória para elemento do Report REP_A_ELEM", _ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    novo->elemento = elemento;
    novo->proximo = novo;
    return novo;
}

//Libertar nó Report REP_A_ELEM
int  libertarNoReportA(No_REP_A * no){
    if(!no)
        return _ERR_MEMORYFREE;
    no->elemento = libertarElementoReportA(no->elemento);
    no->proximo = NULL;
    free(no);
    no = NULL;
    return _SUCESSO;
}

//Criar lista de Report REP_A_ELEM vazia
REP_A * criarListaReportA(){
    REP_A * lista = calloc(1, sizeof(REP_A));
    if(!lista){
        wprintf(L"Erro %d: Impossível alocar memória para Report REP_A_ELEM", _ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    lista->elementos =0;
    lista->cauda = NULL;
    return lista;
}

//Eliminar Lista de UC
int libertarListaReportA(REP_A * lista){
    if(!lista)
        return _ERR_MEMORYFREE;
    while(lista->elementos != 0){
        removerElementoRepA(lista);
    }
    lista->cauda = NULL;
    free(lista);
    lista= NULL;
    return _SUCESSO;
}

//Adicionar elemento REP_A_ELEM na lista
int adicionarElementoRepA(REP_A_ELEM * unidade, REP_A * lista){
    if(!lista || !unidade){
        wprintf(L"Erro %d: Impossível adicionar elemento na lista\n", _ERR_EMPTYLIST);
        return _ERR_EMPTYLIST;
    }
    No_REP_A * no = criarNoReportA(unidade);
    if(lista->elementos > 0){
        no->proximo = lista->cauda->proximo;
        lista->cauda->proximo = no;
    }
    lista->cauda = no;
    lista->elementos++;
    return _SUCESSO;
}

//Remover elemento da lista
int removerElementoRepA(REP_A * lista){
    if(!lista){
        wprintf(L"Erro %d: Impossível remover elemento na lista", _ERR_EMPTYLIST);
        return _ERR_EMPTYLIST;
    }
    No_REP_A * temp = lista->cauda->proximo;
    lista->cauda->proximo = temp->proximo;      //Aponta final da lista para segundo elemento da lista
    lista->elementos--;
    libertarNoReportA(temp);        
    return _SUCESSO;
}

//Adicionar dados no elemento 
void adicionarDadoElementoRepA(REP_A_ELEM * elemento, int ects, wchar_t * observacao){
    elemento->ects = ects;
    swprintf(elemento->observacao,wcslen(observacao)+1,L"%S",observacao);
}

//Verificar se o aluno consta da lista do ReportA
int verificaElementoRepA(int numeroAluno, REP_A * reportA){
    if(!reportA){
        wprintf(L"Erro %d: Impossível verificar", _ERR_EMPTYLIST);
        return _ERR_EMPTYLIST;
    }
    No_REP_A * no = reportA->cauda;
    for(int i=0; i<reportA->elementos; i++) {
        if(no->elemento->numero == numeroAluno)
            return 1;
        no = no->proximo;
    }
    return 0;
}

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

/************************
 *      Report C        *
 * **********************/

/************************
 *      Report D        *
 * **********************/
