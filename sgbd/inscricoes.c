#include "inscricoes.h"
#include "macro.h"

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

//Cria lista para pastas
LISTA_PASTA * criarListaPastas(){
    LISTA_PASTA * novo = calloc(1,sizeof(LISTA_PASTA));
    if(!novo){
        wprintf(L"Erro %d: Não foi possivel alocar memoria para a inscriçao", _ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    novo->pastas =0;
    novo->cauda = NULL;
    return novo;
}

//Criar Pasta Anual
NO_PASTA * criarPasta(wchar_t * chave){
    NO_PASTA * novo = calloc(1, sizeof(NO_PASTA));
    if(!novo){
        wprintf(L"Erro %d: Não foi possivel alocar memoria para a inscriçao", _ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    novo->elementos = 0;
    novo->proximo = novo;
    novo->cauda = NULL;
    novo->chave = calloc(_TAMSTRING, sizeof(wchar_t));
    if(!novo->chave){
        wprintf(L"Erro %d: Não foi possivel alocar memoria para a inscriçao", _ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    wcscpy(novo->chave, chave);
    return novo;
}

//Cria no da lista na pasta
//Retorna no criado
NO * criarNo(INSCRICAO * elemento){
    NO * novo = calloc(1,sizeof(NO));
    if(!novo){
        wprintf(L"Erro %d: Não foi possivel alocar memoria para a inscriçao", _ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    novo->elemento = elemento;
    novo->proximo = novo;
    return novo;
}

//Liberta Memoria NO
int libertarNO(NO * elemento){
    if(!elemento)
        return _ERR_MEMORYFREE;
    elemento->proximo = NULL;
    libertarInscricao(elemento->elemento);
    elemento->elemento = NULL;
    free(elemento);
    elemento = NULL;
    return _SUCESSO;
}

//Libertar Memoria Pasta
int libertarPasta(NO_PASTA * elemento){
    if(!elemento)
        return _ERR_MEMORYFREE;
    while(elemento->elementos!=0)
        removerInscricoes(0,elemento);
    elemento->cauda = NULL;
    free(elemento->chave);
    elemento->chave = NULL;
    elemento->proximo = NULL;
    free(elemento);
    elemento=NULL;
    return _SUCESSO;
}

//Libertar memoria Lista Pastas
int libertarListaPasta(LISTA_PASTA * lista){
    if(!lista)
        return _ERR_MEMORYFREE;
    while(lista->pastas!=0){
        removerPasta(lista->cauda->proximo,lista);
    }
    lista->cauda =NULL;
    free(lista);
    lista = NULL;
    return _SUCESSO;
}

//Adicionar Inscrição na lista
int adicionarInscricao(INSCRICAO * nova, LISTA_PASTA * lista){
    if(!lista)
        return _ERR_IMPOSSIBLE;
    NO_PASTA * aux = procuraPasta(nova->anoLetivo, lista);
    if(!aux){ //Se não encontrou pasta cria uma nova e adiciona à lista
        aux = criarPasta(nova->anoLetivo);
        adicionaPasta(aux,lista);
    }
    adicionarInscricaoPasta(nova, aux); //Adiciona elemento na lista
    return _SUCESSO;
}

//Adicionar Pasta na lista
int adicionaPasta(NO_PASTA * pasta, LISTA_PASTA* lista){
    if(!pasta || !lista){
        wprintf(L"Erro %d: Impossível adicionar elemento na lista", _ERR_EMPTYLIST);
        return _ERR_EMPTYLIST;
    }
    if(lista->pastas==0) //Adiciona no inicio
        lista->cauda = pasta;
    else {//Adiciona no final
        pasta->proximo = lista->cauda->proximo;
        lista->cauda->proximo = pasta;
        lista->cauda = pasta;
    }
    lista->pastas++;
    return _SUCESSO;
}

//Adicionar na pasta a inscrição
int adicionarInscricaoPasta(INSCRICAO * inscricao, NO_PASTA * lista){
    if(!lista || !inscricao){
        wprintf(L"Erro %d: Impossível adicionar elemento na lista", _ERR_EMPTYLIST);
        return _ERR_EMPTYLIST;
    }
    NO * novo = criarNo(inscricao);
    if(lista->elementos==0) //Adiciona no inicio
        lista->cauda = novo;
    else {//Adiciona no final
        novo->proximo = lista->cauda->proximo;
        lista->cauda->proximo = novo;
        lista->cauda = novo;
    }
    lista->elementos++;
    return _SUCESSO;
}

//Procura pasta na lista
NO_PASTA * procuraPasta(wchar_t * ano, LISTA_PASTA* lista){
    if(!lista)
        return NULL;
    if(!lista->cauda)
        return NULL;
    NO_PASTA * temp = lista->cauda->proximo;
    int i =0;
    while(i<lista->pastas){
        if(wcscmp(temp->chave, ano)==0)
            return temp;
        temp= temp->proximo;
        i++;
    }
    return NULL;
}

//Procura Inscrição na pasta correspondente
//Retorna NULL se não encontrar
INSCRICAO * procuraInscricao(LISTA_PASTA * lista, wchar_t * ano, int numeroAluno, int numeroUC){
    if(!lista)
        return NULL;
    NO_PASTA * pasta = procuraPasta(ano,lista);
    if(!pasta)
        return NULL;
    NO * temp = pasta->cauda->proximo;
    INSCRICAO * aux= NULL;
    int i =0;
    while(i<pasta->elementos){
        if(temp->elemento->numeroAluno == numeroAluno && temp->elemento->numeroUC == numeroUC)
            return temp->elemento;
        temp = temp->proximo;
        i++;
    }
    return NULL;
}

//Procura posição na pasta do elemento inscrição
//Retorna -1 caso não encontre
int procuraPosicaoInscricao(INSCRICAO * elemento, LISTA_PASTA * lista){
    if(!elemento)
        return _ERR_IMPOSSIBLE;
    NO_PASTA * pasta = procuraPasta(elemento->anoLetivo,lista);
    if(!pasta)
        return -1;
    NO * temp = pasta->cauda->proximo;
    int i=0;
    while(i<pasta->elementos){
        if(temp->elemento->numeroUC == elemento->numeroUC && temp->elemento->numeroAluno == elemento->numeroAluno && !wcscmp(temp->elemento->anoLetivo, elemento->anoLetivo))
            return i;
        i++;
        temp = temp->proximo;
    }
    return -1;
}

//Remover elemento da pasta
int removerInscricoes(int pos, NO_PASTA * lista){
    if(!lista){
        wprintf(L"Erro %d: Impossível remover elemento na lista", _ERR_EMPTYLIST);
        return _ERR_EMPTYLIST;
    }
    if(pos < 0 || pos >= lista->elementos){
        wprintf(L"Erro %d: Possição inválida na lista", _ERR_IMPOSSIBLE);
        return _ERR_IMPOSSIBLE;
    }
    if(pos ==0){ //Remover na cabeça da lista
        NO * temp = lista->cauda->proximo;
        lista->cauda->proximo = temp->proximo;      //Aponta final da lista para segundo elemento da lista
        lista->elementos--;
        libertarNO(temp);
    } else {    //Remove na posição
        NO *temp = lista->cauda->proximo;
        for (int i = 0; i < pos-1; i++)
            temp = temp->proximo;
        NO * aux = temp->proximo;
        temp->proximo = aux->proximo; //Aponta elemento atual para o segundo elemento seguinte da posição da lista
        if (pos == lista->elementos - 1)
            lista->cauda = temp; //Atualiza cauda caso seja o ultimo elemento a remover
        lista->elementos--;
        libertarNO(aux);
    }
    return _SUCESSO;
}

//Remover pasta da lista
int removerPasta(NO_PASTA * pasta, LISTA_PASTA * lista){
    if(!lista ||!pasta){
        wprintf(L"Erro %d: Impossível remover elemento na lista", _ERR_EMPTYLIST);
        return _ERR_EMPTYLIST;
    }
    while(pasta->elementos !=0){
        removerInscricoes(0,pasta);
    }
    NO_PASTA * temp= lista->cauda->proximo;
    if(pasta == temp){//Remover na cabeça
        lista->cauda->proximo = pasta->proximo;
    } else {
        while(temp->proximo != pasta){
            temp = temp->proximo;
        }
        temp->proximo = pasta->proximo;
        
        if(pasta = lista->cauda)
            lista->cauda = temp;
    }
    libertarPasta(pasta);
    lista->pastas--;
    return _SUCESSO;
}

//Remover inscrição
int removerInscricao(INSCRICAO* inscricao, LISTA_PASTA * lista){
    if(!inscricao || !lista)
        return _ERR_IMPOSSIBLE;
    NO_PASTA * pasta = procuraPasta(inscricao->anoLetivo,lista);
    
    if(removerInscricoes(procuraPosicaoInscricao(inscricao,lista),pasta) == _SUCESSO)
        return _SUCESSO;
    else
        return _ERR_IMPOSSIBLE; 
}

//Obter inscrição na posição
INSCRICAO * obterInscricao(int pos, NO_PASTA * lista){
    int i =0;
    NO * temp;
    if(!lista){
        wprintf(L"Erro %d: Lista vazia", _ERR_EMPTYLIST);
        return NULL;
    }
    if(pos < 0 || pos >lista->elementos){
        wprintf(L"Erro %d: Possição inválida na lista", _ERR_IMPOSSIBLE);
        return NULL;
    }
    if(pos == lista->elementos-1)
        return lista->cauda->elemento;
    else{
        temp = lista->cauda;
        while(i<=pos){
            temp = temp->proximo;
            i++;
        }
        return temp->elemento;
    }
}

//Modificar Valores UC
void modificarValorInscricao(int numeroAluno, int numeroUC, INSCRICAO * inscricao){
    if(numeroAluno)
        inscricao->numeroAluno = numeroAluno;
    if(numeroUC)
        inscricao->numeroUC = numeroUC;
}