#include "arvore.h"
#include "macro.h"

/************************************
 *      Arvore de Inscrições        *
 ************************************/

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



//Criar Arvore de Inscrições
//Retorna arvore criada
TREE_INSCRICAO * criarArvore(){
    TREE_INSCRICAO * novo = calloc(1,sizeof(TREE_INSCRICAO));
    if(!novo){
        wprintf(L"Erro %d: Não foi possivel alocar memória", _ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    novo->elementos =0;
    novo->raiz = NULL;
    return novo;
}

//Criar No da Arvore
//Retorna No criado
NoINSCRICAO * criarNoArvore(INSCRICAO * elemento){
    NoINSCRICAO * novo = calloc(1, sizeof(NoINSCRICAO));
    if(!novo){
        wprintf(L"Erro %d: Não foi possivel alocar memória", _ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    novo->elemento = elemento;
    novo->anterior = NULL;
    novo->proximo = NULL;
    novo->ramo = NULL;
    return novo;
}

//Inserir No na arvore
//Retorna o no adicionado
NoINSCRICAO * inserirNoArvore(NoINSCRICAO * noPai, NoINSCRICAO * no){
    if(!noPai)
        return no;
    else{
        int res = wcscmp(noPai->elemento->anoLetivo, no->elemento->anoLetivo);
        if(res ==0)
            noPai->ramo = inserirNoArvore(noPai->ramo, no);
        else if(res > 0)
            noPai->anterior = inserirNoArvore(noPai->anterior, no);
        else
            noPai->proximo = inserirNoArvore(no->proximo, no);
    }
    return noPai;
}

//Inserir elementos na arvore
int inserirArvore(TREE_INSCRICAO * arvore, INSCRICAO * elemento){
    if(!arvore)
        return _ERR_EMPTYLIST;
    NoINSCRICAO * novo = criarNoArvore(elemento);
    if(arvore->elementos==0){
        arvore->raiz = inserirNoArvore(arvore->raiz, novo);
    } else{
        int res = wcscmp(arvore->raiz->elemento->anoLetivo, novo->elemento->anoLetivo);
         if(res == 0){ //Inserir no ramo
            arvore->raiz->ramo = inserirNoArvore(arvore->raiz->ramo, novo);
        } else if(res > 0){ //Inserir no anterior
            arvore->raiz->anterior = inserirNoArvore(arvore->raiz->anterior, novo);
        } else{ //Inserir no seguinte
            arvore->raiz->proximo = inserirNoArvore(arvore->raiz->proximo, novo);;
        }
    }
    arvore->elementos++;
    return _SUCESSO;
}

//Procura elemento na arvore
//Retorna No Encontrado
NoINSCRICAO * procuraInscricao(int numeroUC, int numeroAluno, wchar_t * ano, NoINSCRICAO * no){
    if(!no)
        return NULL; //Não encontrou elemento
    int res = wcscmp(no->elemento->anoLetivo, ano);
    if(no->elemento->numeroUC == numeroUC 
    && no->elemento->numeroAluno == numeroAluno
    && res==0){
        return no;
    } else{
        if(res ==0) //Procura no mesmo ramo
            return procuraInscricao(numeroUC, numeroAluno,ano,no->ramo);
        else if(res <1) //Procura nos elementos maiores
            return procuraInscricao(numeroUC, numeroAluno,ano,no->proximo);
        else
            return procuraInscricao(numeroUC, numeroAluno,ano,no->anterior);
    }
}