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

/************************
 *      Report C        *
 * **********************/

/************************
 *      Report D        *
 * **********************/