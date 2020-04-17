#include "ucs.h"
#include "macro.h"

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
    swprintf(unidade->nome, wcslen(nome)+1, L"%ls", nome);
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
        wprintf(L"Erro %d: Impossível adicionar elemento na lista\n", _ERR_EMPTYLIST);
        return _ERR_EMPTYLIST;
    }
    if(pos<0 || pos > lista->elementos){
        wprintf(L"Erro %d: Posição inválida na lista\n", _ERR_IMPOSSIBLE);
        return _ERR_IMPOSSIBLE;
    }
    NoUC * no = criarNoUC(unidade);
    if(lista->elementos==0){ //Lista vazia adiciona no inicio
        lista->cauda = no;
        lista->elementos++;
    } else if(pos == lista->elementos){// Adiciona no final
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
        wprintf(L"Erro %d: Impossível remover elemento na lista", _ERR_EMPTYLIST);
        return _ERR_EMPTYLIST;
    }
    if(pos < 0 || pos >= lista->elementos){
        wprintf(L"Erro %d: Posição inválida na lista", _ERR_IMPOSSIBLE);
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

//Obter Unidade curricular na posição
UC * obterUC(int pos, LIST_UC * lista){
    if(!lista){
        wprintf(L"Erro %d: Lista vazia", _ERR_EMPTYLIST);
        return NULL;
    }
    if(pos < 0 || pos >lista->elementos){
        wprintf(L"Erro %d: Possição inválida na lista", _ERR_IMPOSSIBLE);
        return NULL;
    }
    if(pos == lista->elementos-1){
        return lista->cauda->elemento;
    } else{
        int i =0;
        NoUC * temp = lista->cauda;
        while(i<=pos){
            temp = temp->proximo;
            i++;
        }
        return temp->elemento;
    }
}

//Procurar na lista de UC's 
int procurarUC(int numeroUC, LIST_UC * lista) { //recebe numeroUC e bd->ucs que é do tipo LIST_UC
    int i;
    NoUC * tmp;  //ponteiro para percorrer lista temporariamente
    printf("aqui");
    tmp = lista->cauda->proximo;

    while (tmp != NULL || tmp->elemento->numero != numeroUC)
        tmp = tmp->proximo;

    if (tmp == NULL)
        return _FALSE_;
    else
        return _TRUE_;
}
