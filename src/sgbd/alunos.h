/*
 * Ficheiro que possui todas as funções que gerem a lista de alunos
 */

#ifndef _ALUNOS_
#define _ALUNOS_

//Bibliotecas Padrão
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>
//Bibliotecas Próprias
#include "macro.h"

/************************
 *      Estruturas      *
 * **********************/

//Estrutura de Dados de Aluno
typedef struct aluno{
    int numero;    //Numero de Aluno
    wchar_t *nome; //Nome do Aluno
    wchar_t *pais; //Pais do Aluno
    int propina;   //Valor da propina do Aluno
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

//Criar Aluno com dados
//Retorna Aluno
ALUNO *criarAluno(int numero, wchar_t *nome, wchar_t *pais);
//Criar lista vazia
LIST_ALUNO * criarListaAluno();
//Libertar Memoria Aluno
int libertarAluno(ALUNO *aluno);
//Eliminar Lista
int libertarListaAluno(LIST_ALUNO *lista);
//Criar No Lista Aluno
NoALUNO *criarNoAluno(ALUNO *aluno);
//Libertar No Aluno
int libertarNoAluno(NoALUNO *no);
//Adicionar elemento na lista
int adicionarAluno(ALUNO * aluno, LIST_ALUNO *lista, int pos);
//Remover elemento da lista
int removerAluno(int pos, LIST_ALUNO *lista);
//Procurar na lista de alunos 
ALUNO * obterAlunoNum(int numeroAluno, LIST_ALUNO * lista);
//Obter Aluno na posição
ALUNO * obterAlunoPos(int pos, LIST_ALUNO * lista);
//Modificar Valores Aluno
void modificarValoresAluno(int numero, wchar_t *nome, wchar_t *pais, ALUNO * elem);

#endif