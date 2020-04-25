/*
 * Ficheiro que possui todas as funções de gestão da lista de UCs
 */

#ifndef _UCS_
#define _UCS_

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

//Estrutura de Dados UC
typedef struct unidade{
    int numero;    //Numero da UC
    wchar_t *nome; //Nome da UC
    int ano;       //Ano da UC [1,2,3]
    int semestre;  //Semestre da UC [1,2]
    int ects;      //ECTS da UC [1-6]
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

/* Criar Unidade Curricular */
UC * criarUC(int numero, wchar_t *nome, int ano, int semestre, int ects);
//Libertar Memoria da Unidade Curricular
UC * libertarUC(UC *unidade);
//Criar lista de UC vazia
LIST_UC * criarListaUC();
//Eliminar Lista de UC
int libertarListaUC(LIST_UC * lista);
//Criar No Lista UC
NoUC * criarNoUC(UC * unidade);
//Libertar No UC
int libertarNoUC(NoUC * no);
//Adicionar elemento UC na lista
int adicionarUC(UC * unidade, LIST_UC * lista, int pos);
//Remover elemento da lista
int removerUC(int pos, LIST_UC * lista);
//Obter Unidade curricular na posição
UC * obterUCPos(int pos, LIST_UC * lista);
//Obter UC por numero UC 
UC * obterUCNum(int numeroUC, LIST_UC * lista);
//Modificar Valores UC
void modificarValoresUC(int numero, wchar_t *nome, int ano, int semestre, int ects, UC * unidade);
//Obter valor de ECTS
int obterECTS(UC* unidade);

#endif