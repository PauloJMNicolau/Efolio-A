<<<<<<< HEAD
=======
/*
 * Ficheiro que possui todas as funções que gerem os reports
 */
>>>>>>> f30fae9c53582f7d72561669d64e356dd2b5ec07

#ifndef _REPORTS_
#define _REPORTS_

<<<<<<< HEAD
#include "macro.h"
#include "alunos.h"
#include "ucs.h"
#include "inscricoes.h"




=======
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


/* **********************
 *        Headers       *
 * **********************/

/************************
 *      Report A       *
 * **********************/

/************************
 *      Report B        *
 * **********************/

//Crar lista de Report B
REP_B * criarListaReportB();
//Libertar memoria do Elemento Report B
void libertarElementoReportB(REP_B_ELEM * elemento);
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

/************************
 *      Report C        *
 * **********************/

/************************
 *      Report D        *
 * **********************/
>>>>>>> f30fae9c53582f7d72561669d64e356dd2b5ec07


#endif