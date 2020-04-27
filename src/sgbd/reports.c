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

//Libertar Memoria do elemento 
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

//Criar nó da lista
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

//Libertar nó da lista
int  libertarNoReportA(No_REP_A * no){
    if(!no)
        return _ERR_MEMORYFREE;
    no->elemento = libertarElementoReportA(no->elemento);
    no->proximo = NULL;
    free(no);
    no = NULL;
    return _SUCESSO;
}

//Criar lista de Report A vazia
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

//Eliminar Lista de Report A
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

//Adicionar elemento na lista
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

//Adicionar dados no elemento epecifico
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

//Criar lista de Report B
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


//Criar lista de Report C
PROB_ABANDONO * criarListaReportC(){
    PROB_ABANDONO * nova = calloc(1, sizeof(PROB_ABANDONO));
    
    if(!nova){
        wprintf(L"Erro %d: nâo foi possivel alocar memoria do report\n",_ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    nova->contador_semestre_1 = 0;
    nova->contador_semestre_1 = 0;
    return nova;
}

//Libertar memoria do Elemento Report c
void libertarElementoReportC( PROB_ABANDONO * elemento){
    if(!elemento){
        wprintf(L"Erro %d: Não é possivel eliminar o elemento", _ERR_MEMORYFREE);
    }
    elemento->contador_semestre_1 = 0;
    elemento->contador_semestre_2 = 0;
    free(elemento);
    elemento = NULL;
}

/************************
 *      Report D        *
 * **********************/

//Crar lista de Report D
REP_D * criarListaReportD(){
    REP_D * nova = calloc(1, sizeof(REP_D));
    if(!nova){
        wprintf(L"Erro %d: nâo foi possivel alocar memoria do report\n",_ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    nova->cauda = NULL;
    nova->elementos = 0;
    return nova;
}

//Criar elemento da lista ReportD
REP_D_ELEM * criarElementoReportD(wchar_t * ano, int total){
    REP_D_ELEM * nova = calloc(1, sizeof(REP_D_ELEM));
    if(!nova){
        wprintf(L"Erro %d: nâo foi possivel alocar memoria do report\n",_ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    nova->ano = calloc(_TAMDATAS, sizeof(wchar_t));
    if(!nova->ano){
        wprintf(L"Erro %d: nâo foi possivel alocar memoria do report\n",_ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    wcsncpy(nova->ano,ano,wcslen(ano));
    nova->totalAlunos= total;
    nova->proximo = nova; //Aponta para ele mesmo, util no caso de ser o unico elemento da lista
    return nova;
}

//Crar lista de Anos letivos de Report D
REP_D_LISTA * criarListaAnoReportD(){
    REP_D_LISTA * nova = calloc(1, sizeof(REP_D_LISTA));
    if(!nova){
        wprintf(L"Erro %d: nâo foi possivel alocar memoria do report\n",_ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    nova->cauda = NULL;
    nova->elementos = 0;
    return nova;
}

//Criar elemento da lista de anos letivos ReportD
REP_D_LISTA_ELEM * criarElementoAnoReportD(int id){
    REP_D_LISTA_ELEM * nova = calloc(1, sizeof(REP_D_LISTA_ELEM));
    if(!nova){
        wprintf(L"Erro %d: nâo foi possivel alocar memoria do report\n",_ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    nova->idAluno = id;
    nova->proximo = nova; //Aponta para ele mesmo, util no caso de ser o unico elemento da lista
    return nova;
}

//Libertar memoria do Elemento Report D
void libertarElementoReportD(REP_D_ELEM * elemento){
    if(!elemento){
        wprintf(L"Erro %d: Não é possivel eliminar o elemento", _ERR_MEMORYFREE);
    }
    free(elemento->ano);
    elemento->ano = NULL;
    elemento->totalAlunos = 0;
    elemento->proximo = NULL;
    free(elemento);
    elemento = NULL;
}

//Libertar memoria do Elemento da lista de ano letivo de Report D
void libertarElementoAnoReportD(REP_D_LISTA_ELEM * elemento){
    if(!elemento){
        wprintf(L"Erro %d: Não é possivel eliminar o elemento", _ERR_MEMORYFREE);
    }
    elemento->idAluno =0;
    elemento->proximo = NULL;
    free(elemento);
    elemento = NULL;
}

//Remover no inicio da lista
int removerElementoRepDInicio(REP_D * lista){
    if(!lista){
        wprintf(L"Erro %d: Não foi possivel remover elemento da lista", _ERR_IMPOSSIBLE);
        return _ERR_IMPOSSIBLE;
    }
    if(lista->cauda){
        lista->elementos--;
        if(lista->elementos == 0){
            libertarElementoReportD(lista->cauda);
            lista->cauda = NULL;
        } else{
            REP_D_ELEM * temp = lista->cauda->proximo;
            lista->cauda->proximo = temp->proximo;
            libertarElementoReportD(temp);
        }
        return _SUCESSO;
    }
    return _ERR_IMPOSSIBLE;
}

//Remover no inicio da lista de anos letivos
int removerElementoRepDAnoInicio(REP_D_LISTA * lista){
    if(!lista){
        wprintf(L"Erro %d: Não foi possivel remover elemento da lista", _ERR_IMPOSSIBLE);
        return _ERR_IMPOSSIBLE;
    }
    if(lista->cauda){
        lista->elementos--;
        if(lista->elementos == 0){
            libertarElementoAnoReportD(lista->cauda);
            lista->cauda = NULL;
        } else{
            REP_D_LISTA_ELEM * temp = lista->cauda->proximo;
            lista->cauda->proximo = temp->proximo;
            libertarElementoAnoReportD(temp);
        }
        return _SUCESSO;
    }
    return _ERR_IMPOSSIBLE;
}

//Adiciona elemento no final da lista
int adicionarElementoRepDFim(REP_D * lista, REP_D_ELEM * elemento){
    if(!lista || !elemento){
        wprintf(L"Erro %d: Não foi possivel adicionar elemento da lista", _ERR_IMPOSSIBLE);
        return _ERR_IMPOSSIBLE;
    }
    if(lista->elementos > 0){
        elemento->proximo = lista->cauda->proximo;
        lista->cauda->proximo = elemento;
    }
    lista->cauda = elemento;
    lista->elementos++;
    return _SUCESSO;
}

//Adiciona elemento no final da lista de Anos Letivos
int adicionarElementoAnoRepDFim(REP_D_LISTA * lista, REP_D_LISTA_ELEM * elemento){
    if(!lista || !elemento){
        wprintf(L"Erro %d: Não foi possivel adicionar elemento da lista", _ERR_IMPOSSIBLE);
        return _ERR_IMPOSSIBLE;
    }
    if(lista->elementos > 0){
        elemento->proximo = lista->cauda->proximo;
        lista->cauda->proximo = elemento;
    }
    lista->cauda = elemento;
    lista->elementos++;
    return _SUCESSO;
}

//Liberta Memoria da Lista Report D
void libertarListaReportD(REP_D * lista){
    if(!lista)
        wprintf(L"Erro %d: Não é possivel eliminar o elemento", _ERR_MEMORYFREE);
    while(lista->elementos !=0)
        removerElementoRepDInicio(lista);
    lista->cauda = NULL;
    free(lista);
    lista = NULL;
    
}

//Liberta Memoria da Lista de Anos letivos Report D
void libertarListaAnoReportD(REP_D_LISTA * lista){
    if(!lista)
        wprintf(L"Erro %d: Não é possivel eliminar o elemento", _ERR_MEMORYFREE);
    while(lista->elementos !=0)
        removerElementoRepDAnoInicio(lista);
    lista->cauda = NULL;
    free(lista);
    lista = NULL;
}

//Obter Elemento da lista de anos letivos com idAluno igual a id
REP_D_LISTA_ELEM * obterElementoReportDNum(int id, REP_D_LISTA * lista){
    if(!lista)
        return NULL;
    int i =0;
    REP_D_LISTA_ELEM * temp = lista->cauda;
    while(i<lista->elementos){
        temp = temp->proximo;
        if(temp->idAluno == id)
            return temp;
        i++;
    }
    return NULL;
}