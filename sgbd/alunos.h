#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>

/************************
 *      Estruturas      *
 * **********************/

//Estrutura de Dados de Aluno
typedef struct aluno{
    int numero;    //Numero de Aluno
    wchar_t *nome; //Nome do Aluno
    wchar_t *pais; //Pais do Aluno
} ALUNO;

//Estrutura para No da Lista de Alunos
typedef struct noAluno{
    ALUNO *elemento;         //Elemento
    struct noAluno *proximo; //Proximo elemento na lista
} NoALUNO;

//Estrutura da Lista de Alunos (Lista Ligada)
typedef struct listAluno{
    int elementos; // Quantidade de elementos na lista
    NoALUNO *cauda;   //Cauda da lista
} LIST_ALUNO;

/********************************
 *          Headers             *
 ********************************/

//Criar lista vazia
LIST_ALUNO *criarListaAluno();
//Criar Aluno com dados
ALUNO *criarAluno(int numero, wchar_t *nome, wchar_t *pais);
//Criar No Lista Aluno
NoALUNO *criarNoAluno(ALUNO *aluno);
//Libertar Memoria Aluno
int libertarAluno(ALUNO *aluno);
//Libertar No Aluno
int libertarNoAluno(NoALUNO *no);
//Eliminar Lista
int libertarListaAluno(LIST_ALUNO *lista);
//Remover elemento da lista
int removerAluno(int pos, LIST_ALUNO *lista);
//Adicionar elemento na lista
int adicionarAluno(ALUNO *aluno, LIST_ALUNO *lista, int pos);