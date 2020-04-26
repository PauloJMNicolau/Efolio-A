/*
 * Ficheiro que possui todas as funções que gerem os reports
 */

#ifndef _REPORTS_
#define _REPORTS_

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

/************************
 *      Report B        *
 * **********************/

//Guarda Informação sobre a UC
typedef struct reportbElemento{
    int chave;  //ID UC
    int estado; //Aprovado -> 1 | Reprovado -> 0
    struct reportbElemento * proximo; //Proximo elemento
} REP_B_ELEM;

//Lista do Report B
typedef struct reportb{
    int quantidade;     //Quantidade de Elementos
    REP_B_ELEM * cauda; //Ultimo elemento da lista
}REP_B;
//////////////////////////////////////////////////

/************************
 *      Estruturas      *
 * **********************/
/************************
 *      Report C        *
 * **********************/
/////////////////->>possibilidade de abandono
typedef struct potencialAbandono{
    int ID_c;  //ID aluno
    int semestre[2]; //semestre 1[0] e 2[1]
    int UCS;//qunatidade de Ucs
    struct potencialAbadono * Seguinte; //Proximo elemento
} Abandono;

//Lista do Report c
typedef struct reportc{
    int quntidade_c;     //Quantidade de Elementos
    Abandono* cauda_c; //Ultimo elemento da lista->verificar
}REP_C;

/* **********************
 *        Headers       *
 * **********************/

/************************
 *      Report A       *
 * **********************/

/************************
 *      Report B        *
 * **********************/
////////////////////////////////////////////////////////////////////////
//Crar lista de Report B
REP_B * criarListaReportB();
//Libertar memoria do Elemento Report B
void libertarElementoReportc(REP_B_ELEM * elemento);
//Criar elemento da lista ReportB
REP_B_ELEM * criarElementoReportB(int id, int nota);
//Remover no inicio da lista
int removerElementoRepBInicio(REP_B * lista);
//Adiciona elemento no final da lista
int adicionarElementoRepBFim(REP_B * lista, REP_B_ELEM * elemento);
//Modifica estado do elemento
void modificarEstado(REP_B_ELEM * elemento, int nota);
//Liberta Memoria da Lista Report B
void libertarListaReportB(REP_B * lista);
//Obter Elemento com chave igual a id
REP_B_ELEM * obterElementoReportBNum(int id, REP_B * lista);
////////////////////////////////////////////////////////////////////////
/* **********************
 *        Headers       *
 * **********************/
/************************
 *      Report C        *
 * **********************/
//Crar lista de Report c->
REP_C * criarListaReportC();
//Libertar memoria do Elemento Report c
void libertarElementoReportC(Abandono * elemento_C);
//Criar elemento da lista Reportc
REP_C * criarElementoReportc(int id_C, int UCS_C);
//Remover no inicio da lista:c
int removerElementoRepCInicio(REP_C * lista_C);
//Adiciona elemento no final da lista_c
int adicionarElementoRepCFim(REP_C * lista, Abandono * elemento);
//Modifica estado do elemento
void modificarEstado_C(Abandono * elemento, int nota);
//Liberta Memoria da Lista Report B
void libertarListaReportC(REP_C * lista);
//Obter Elemento com chave igual a id
Abandono * obterElementoReportCNum(int id, REP_C * lista);

/************************
 *      Report D        *
 * **********************/


#endif