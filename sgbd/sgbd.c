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

/************************************
 *          Lista de UC             *
 ************************************/

/* Criar Unidade Curricular */
UC * criarUC(int numero, wchar_t *nome, int ano, int semestre){
    UC *unidade = calloc(1, sizeof(unidade));
    if (!unidade)
    {
        wprintf(L"Erro %d: Impossível alocar memória para Unidade Curricular", _ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    unidade->numero = numero;
    unidade->nome = calloc(_TAMSTRING + 1, sizeof(wchar_t));
    if (!unidade->nome)
    {
        wprintf(L"Erro %d: Impossível alocar memória para Unidade Curricular", _ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    swprintf(unidade->nome, wcslen(nome), L"%ls", nome);
    if ((ano <= 0 || ano > 3) && (semestre <= 0 || semestre > 2))
    {
        return unidade;
    }
    unidade->ano = ano;
    unidade->semestre = semestre;
    return unidade;
}

//Libertar Memoria da Unidade Curricular
int libertarUC(UC *unidade){
    if (unidade)
    {
        if (unidade->nome)
            free(unidade->nome);
        unidade->nome = NULL;
        free(unidade);
        unidade = NULL;
        return _SUCESSO;
    }
    return _ERR_MEMORYFREE;
}

//Criar lista vazia
LIST_UC * criarListaUC(){
    LIST_UC * lista = calloc(1, sizeof(LIST_UC));
    if(!lista){
        wprintf(L"Erro %d: Impossível alocar memória para Unidade Curricular", _ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    lista->elementos =0;
    lista->cauda = NULL;
    return lista;
}

//Eliminar Lista
int libertarListaUC(LIST_UC * lista){
    if(!lista)
        return _ERR_MEMORYFREE;
    while(lista->elementos != 0){
        removerUC(0,lista);
    }
    lista->cauda = NULL;
    free(lista);
    lista= NULL;
    return _SUCESSO;
}

//Criar No Lista UC
NoUC * criarNoUC(UC * unidade){
    NoUC * novo = calloc(1,sizeof(NoUC));
    if(!novo){
        wprintf(L"Erro %d: Impossível alocar memória para Unidade Curricular", _ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    novo->elemento = unidade;
    novo->proximo = novo;
    return novo;
}

//Libertar No UC
int libertarNoUC(NoUC * no){
    if(!no)
        return _ERR_MEMORYFREE;
    libertarUC(no->elemento);
    no->proximo = NULL;
    free(no);
    no = NULL;
    return _SUCESSO;
}

//Adicionar elemento na lista
int adicionarUC(UC * unidade, LIST_UC * lista, int pos){
    if(!lista || !unidade){
        wprintf(L"Erro %d: Impossível adicionar elemento na lista", _ERR_EMPTYLIST);
        return _ERR_EMPTYLIST;
    }
    if(pos<0 || pos >= lista->elementos){
        wprintf(L"Erro %d: Possição inválida na lista", _ERR_IMPOSSIBLE);
        return _ERR_IMPOSSIBLE;
    }
    NoUC * no = criarNoUC(unidade);
    if(lista->elementos==0){ //Lista vazia adiciona no inicio
        lista->cauda = no;
        lista->elementos++;
    } else if(pos == lista->elementos-1){// Adiciona no final
        no->proximo = lista->cauda->proximo;    //Aponta novo elemento para o inicio da lista
        lista->cauda->proximo = no;             //Aponta ultimo elemento atual da lista para o novo elemento
        lista->cauda = no;                      //Atualiza o ultimo elemento
        lista->elementos++;
    } else{ //Adiciona na posição;
        NoUC * temp = lista->cauda->proximo;
        for(int i =0;i<pos; i++)
            temp = temp->proximo;
        no->proximo = temp->proximo;    //Aponta novo elemento para o elemento seguinte da posição da lista
        temp->proximo = no;             //Aponta posicao anterior para o novo elemento
        lista->elementos++;
    }
    return _SUCESSO;
}

//Remover elemento da lista
int removerUC(int pos, LIST_UC * lista){
    if(!lista){
        wprintf(L"Erro %d: Impossível adicionar elemento na lista", _ERR_EMPTYLIST);
        return _ERR_EMPTYLIST;
    }
    if(pos < 0 || pos >= lista->elementos){
        wprintf(L"Erro %d: Possição inválida na lista", _ERR_IMPOSSIBLE);
        return _ERR_IMPOSSIBLE;
    }
    if(pos ==0){ //Remover na cabeça da lista
        NoUC * temp = lista->cauda->proximo;
        lista->cauda->proximo = temp->proximo;      //Aponta final da lista para segundo elemento da lista
        lista->elementos--;
        libertarNoUC(temp);
    } else {    //Remove na posição
        NoUC *temp = lista->cauda->proximo;
        for (int i = 0; i < pos; i++)
            temp = temp->proximo;
        NoUC * aux = temp->proximo;
        temp->proximo = aux->proximo; //Aponta elemento atual para o segundo elemento seguinte da posição da lista
        if (pos == lista->elementos - 1)
            lista->cauda = temp; //Atualiza cauda caso seja o ultimo elemento a remover
        lista->elementos--;
        libertarNoUC(aux);
    }
    return _SUCESSO;
}


/************************************
 *         Lista de Alunos          *
 ************************************/

//Criar Aluno com dados
//Retorna Aluno
ALUNO *criarAluno(int numero, wchar_t *nome, wchar_t *pais){
    ALUNO *aluno = calloc(1, sizeof(ALUNO));
    if (!aluno)
    {
        wprintf(L"Erro %d: Impossível alocar memória para Aluno", _ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    aluno->numero = numero;
    aluno->nome = calloc(_TAMSTRING + 1, sizeof(wchar_t));
    if (!aluno->nome)
    {
        wprintf(L"Erro %d: Impossível alocar memória para Aluno", _ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    swprintf(aluno->nome, wcslen(nome) + 1, L"%ls", nome);
    aluno->pais = calloc(_TAMSTRING + 1, sizeof(wchar_t));
    if (!aluno->pais)
    {
        wprintf(L"Erro %d: Impossível alocar memória para Aluno", _ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    swprintf(aluno->pais, wcslen(pais) + 1, L"%ls", pais);
    return aluno;
}

//Criar lista vazia
LIST_ALUNO * criarListaAluno(){
    LIST_ALUNO *lista = calloc(1, sizeof(LIST_ALUNO));
    if (!lista){
        wprintf(L"Erro %d: Impossível alocar memória para Aluno", _ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    lista->elementos = 0;
    lista->cauda = NULL;
    return lista;
}

//Libertar Memoria Aluno
int libertarAluno(ALUNO *aluno){
    if (aluno){
        if (aluno->nome)
            free(aluno->nome);
        aluno->nome = NULL;
        if (aluno->pais)
            aluno->pais = NULL;
        free(aluno);
        aluno = NULL;
        return _SUCESSO;
    }
    return _ERR_MEMORYFREE;
}

//Eliminar Lista
int libertarListaAluno(LIST_ALUNO *lista){
    if (!lista)
        return _ERR_MEMORYFREE;
    while (lista->elementos != 0){
        removerAluno(0, lista);
    }
    lista->cauda = NULL;
    free(lista);
    lista = NULL;
    return _SUCESSO;
}

//Criar No Lista Aluno
NoALUNO *criarNoAluno(ALUNO *aluno){
    NoALUNO *novo = calloc(1, sizeof(NoALUNO));
    if (!novo){
        wprintf(L"Erro %d: Impossível alocar memória para Aluno", _ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    novo->elemento = aluno;
    novo->proximo = novo;
    return novo;
}

//Libertar No Aluno
int libertarNoAluno(NoALUNO *no){
    if (!no)
        return _ERR_MEMORYFREE;
    libertarAluno(no->elemento);
    no->proximo = NULL;
    free(no);
    no = NULL;
    return _SUCESSO;
}

//Adicionar elemento na lista
int adicionarAluno(ALUNO * aluno, LIST_ALUNO *lista, int pos){
    if (!lista || !aluno)
    {
        wprintf(L"Erro %d: Impossível adicionar elemento na lista", _ERR_EMPTYLIST);
        return _ERR_EMPTYLIST;
    }
    if (pos < 0 || pos >= lista->elementos){
        wprintf(L"Erro %d: Possição inválida na lista", _ERR_IMPOSSIBLE);
        return _ERR_IMPOSSIBLE;
    }
    NoALUNO *no = criarNoAluno(aluno);
    if (lista->elementos == 0){ //Lista vazia adiciona no inicio
        lista->cauda = no;
        lista->elementos++;
    } else if (pos == lista->elementos - 1){   // Adiciona no final
        no->proximo = lista->cauda->proximo; //Aponta novo elemento para o inicio da lista
        lista->cauda->proximo = no;          //Aponta ultimo elemento atual da lista para o novo elemento
        lista->cauda = no;                   //Atualiza o ultimo elemento
        lista->elementos++;
    } else{ //Adiciona na posição;
        NoALUNO *temp = lista->cauda->proximo;
        for (int i = 0; i < pos; i++)
            temp = temp->proximo;
        no->proximo = temp->proximo; //Aponta novo elemento para o elemento seguinte da posição da lista
        temp->proximo = no;          //Aponta posicao anterior para o novo elemento
        lista->elementos++;
    }
    return _SUCESSO;
}

//Remover elemento da lista
int removerAluno(int pos, LIST_ALUNO *lista){
    if (!lista){
        wprintf(L"Erro %d: Impossível adicionar elemento na lista", _ERR_EMPTYLIST);
        return _ERR_EMPTYLIST;
    }
    if (pos < 0 || pos >= lista->elementos){
        wprintf(L"Erro %d: Possição inválida na lista", _ERR_IMPOSSIBLE);
        return _ERR_IMPOSSIBLE;
    }
    if (pos == 0){ //Remover na cabeça da lista
        NoALUNO *temp = lista->cauda->proximo;
        lista->cauda->proximo = temp->proximo; //Aponta final da lista para segundo elemento da lista
        lista->elementos--;
        libertarNoAluno(temp);
    } else { //Remove na posição
        NoALUNO *temp = lista->cauda->proximo;
        for (int i = 0; i < pos; i++)
            temp = temp->proximo;
        NoALUNO *aux = temp->proximo;
        temp->proximo = aux->proximo; //Aponta elemento atual para o segundo elemento seguinte da posição da lista
        if (pos == lista->elementos - 1)
            lista->cauda = temp; //Atualiza cauda caso seja o ultimo elemento a remover
        lista->elementos--;
        libertarNoAluno(aux);
    }
    return _SUCESSO;
}


/************************************
 *      Arvore de Inscrições        *
 ************************************/

//Cria a arvore vazia
TREE_INSCRICAO * criarArvore(){
    TREE_INSCRICAO * arvore = calloc(1,sizeof(TREE_INSCRICAO));
    if(!arvore){
        wprintf(L"Erro %d: Não foi possivel alocar memoria para a arvore", _ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    arvore->elementos = 0;
    arvore->raiz = NULL;
    return arvore;
}

//Liberta a memoria da arvore
int libertarArvore(TREE_INSCRICAO * arvore){
    if(!arvore)
        return _ERR_EMPTYLIST;
    return _SUCESSO;
}

//Criar Inscricao
INSCRICAO * criarInscricao(int numeroUC, int numeroAluno, wchar_t* ano){
    INSCRICAO * novo = calloc(1,sizeof(INSCRICAO));
    if(!novo){
        wprintf(L"Erro %d: Não foi possivel alocar memoria para a inscriçao", _ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    novo->numeroUC=numeroUC;
    novo->numeroAluno=numeroAluno;
    novo->anoLetivo=calloc(_TAMSTRING + 1, sizeof(wchar_t));
    if (!novo->anoLetivo) {
        wprintf(L"Erro %d: Impossível alocar memória para inscricao", _ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    swprintf(novo->anoLetivo, wcslen(ano) + 1, L"%ls",ano);
    return novo;
}

//Libertar memória da Inscricao
int libertarInscricao(INSCRICAO * inscricao){
    if(!inscricao)
        return _ERR_MEMORYFREE;
    inscricao->numeroUC =0;
    inscricao->numeroAluno =0;
    if(inscricao->anoLetivo){
        free(inscricao->anoLetivo);
        inscricao->anoLetivo = NULL;
    }
    free(inscricao);
    inscricao = NULL;
    return _SUCESSO;
}

//Criar No de inscricao
NoINSCRICAO * criarNoInscricao(INSCRICAO * inscricao){
    NoINSCRICAO * novo = calloc(1,sizeof(NoINSCRICAO));
    novo->elemento = inscricao;
    novo->anterior = NULL;
    novo->proximo = NULL;
    novo->ramo = NULL;
}

//Libertar NoInscricao
int libertarNoInscricao(NoINSCRICAO * no){
    if(!no)
        return _ERR_MEMORYFREE;
    no->ramo=NULL;
    no->proximo=NULL;
    no->anterior=NULL;
    libertarInscricao(no->elemento);
    no->elemento = NULL;
    free(no);
    no = NULL;
}

//Inserir NO na arvore
int inserirNaArvore(INSCRICAO * inscricao, TREE_INSCRICAO* arvore){
    if(arvore->elementos ==0){  //Inserir na Raiz
        arvore->raiz = criarNoInscricao(inscricao);
        arvore->elementos++;
        return _SUCESSO;
    } else{//Inserir nos ramos da arvore
        int res = wcscmp(inscricao->anoLetivo,arvore->raiz->elemento->anoLetivo);
        int aux=0;
        if(res == 0){ //Inserir no ramo
            arvore->raiz->ramo = inserirInscricao(inscricao, arvore->raiz->ramo);
        } else if(res < 0){ //Inserir no anterior
            arvore->raiz->anterior = inserirInscricao(inscricao, arvore->raiz->anterior);
        } else{ //Inserir no seguinte
            arvore->raiz->proximo = inserirInscricao(inscricao, arvore->raiz->proximo);
        }
        arvore->elementos++;
        return _SUCESSO;
    }
}

//Inserir No na subArvore
NoINSCRICAO * inserirInscricao(INSCRICAO * inscricao, NoINSCRICAO * no){
    if(!no){ //Inserir na raiz
        return criarNoInscricao(inscricao);
    } else{
        int res = wcscmp(inscricao->anoLetivo,no->elemento->anoLetivo);
        if(res == 0){ //Inserir no ramo
            no->ramo = inserirInscricao(inscricao, no->ramo);
        } else if(res < 0){ //Inserir no anterior
            no->anterior = inserirInscricao(inscricao, no->anterior);
        } else{ //Inserir no seguinte
            no->proximo = inserirInscricao(inscricao, no->proximo);
        }
    }
    return no;
}

//Procura elemento na arvore
NoINSCRICAO * procuraInscricao(int numeroUC, int numeroAluno, wchar_t * ano){

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
