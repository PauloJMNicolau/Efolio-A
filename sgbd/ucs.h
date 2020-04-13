#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>

/************************
 *      Estruturas      *
 * **********************/

//Estrutura de Dados UC
typedef struct unidade{
    int numero;    //Numero da UC
    wchar_t *nome; //Nome da UC
    int ano;       //Ano da UC [1,2,3]
    int semestre;  //Semestre da UC [1,2]
} UC;

//Estrutura para No da Lista de UC
typedef struct noUC{
    UC * elemento; //Elemento
    struct noUC * proximo; //Proximo elemento na lista
} NoUC;

//Estrutura de Dados Lista de Unidades Curriculares
typedef struct lista_unidade{
    int elementos; // Quantidade de elementos na lista
    NoUC * cauda; //Cauda da lista
} LIST_UC;


/********************************
 *          Headers             *
 ********************************/

//Criar lista vazia
LIST_UC *criarListaUC();
//Criar Unidade Curricular
UC *criarUC(int numero, wchar_t *nome, int ano, int semestre);
//Criar No Lista UC
NoUC *criarNoUC(UC *unidade);
//Libertar No UC
int libertarNoUC(NoUC *no);
//Eliminar Lista
int libertarListaUC(LIST_UC *lista);
//Libertar Memoria da Unidade Curricular
int libertarUC(UC *unidade);
//Adicionar elemento na lista
int adicionarUC(UC *unidade, LIST_UC *lista, int pos);
//Remover elemento da lista
int removerUC(int pos, LIST_UC *lista);