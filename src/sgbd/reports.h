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

//Estrutura de Dados UC
typedef struct ects{
    int numero;      //Numero de aluno
    wchar_t *nome; //Nome do aluno
    int ects;       //ECTS 
    wchar_t * observacao;  //observacao serviços acadêmicos
} ECTS;

//Estrutura para No da Lista de UC
typedef struct norepECTS{
    ECTS * elemento; //Elemento
    struct norepECTS * proximo; //Proximo elemento na lista
} NoRepECTS;

//Estrutura de Dados Lista de Unidades Curriculares
typedef struct lista_repects{
    int elementos; // Quantidade de elementos na lista
    NoRepECTS * cauda; //Cauda da lista
} ListRepECTS;

//Criar elemento
ECTS * criarElementoECTS(int numeroAluno, wchar_t * nomeAluno, int ects, wchar_t * observacao);
//Libertar elemento
ECTS * libertarElementoECTS(ECTS * elemento);
//Criar nó da lista tendo como chave número de aluno
NoRepECTS * criarNoECTS(ECTS * elemento);
//Libertar nó Report ECTS
int  libertarNoECTS(NoRepECTS * no);
//Criar lista report ECTS
ListRepECTS * criarListaECTS();
//Libertar a lista
int libertarListaECTS(ListRepECTS * lista);
//Adicionar elemento ECTS na lista
int adicionarRepECTS(ECTS * unidade, ListRepECTS * lista, int pos);
//Remover elemento da lista
int removerElementoECTS(int pos, ListRepECTS * lista);
//Adicionar no elemento 
void adicionarECTS(ECTS * elemento, int ects, wchar_t * observacao);
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


#endif