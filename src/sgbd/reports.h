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
 *      Report A       *
 * **********************/

//Estrutura de Dados Elemento Report A
typedef struct repAElemento{
    int numero;      //Numero de aluno
    wchar_t *nome; //Nome do aluno
    int ects;       //ECTS
    wchar_t * observacao;  //observacao serviços académicos
} REP_A_ELEM;

//Estrutura para No da Lista de Report A
typedef struct noRepA{
    REP_A_ELEM * elemento; //Elemento
    struct noRepA * proximo; //Proximo elemento na lista
} No_REP_A;

//Estrutura de Dados Lista de Report A
typedef struct reportA{
    int elementos; // Quantidade de elementos na lista
    No_REP_A * cauda; //Cauda da lista
} REP_A;


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


/************************
 *      Report C        *
 * **********************/

/************************
 *      Report D        *
 * **********************/

//Estrutura de dados do elemento da lista de dados do ano letivo
typedef struct reportDElemento{
    int idAluno;    //ID Aluno
    struct reportDElemento * proximo;   //Proximo elemento da lista
} REP_D_LISTA_ELEM;

//Estrutura de Dados para guardar a lista de dados do ano letivo
typedef struct reportDLista{
    int elementos;              //Total de elementos na lista
    REP_D_LISTA_ELEM * cauda;   //Elemento do final da lista
} REP_D_LISTA;

//Estrutura para armazenar o elemento da Lista de Report D
typedef struct reportDElementoD{
    wchar_t * ano;          //Ano Letivo
    int totalAlunos;        //Total Alunos
    struct reportDElementoD * proximo; //Proximo elemento da lista
} REP_D_ELEM;

//Estrutura para guardar a lista de dados do report D
typedef struct reportD{
    int elementos;      //Total de elementos na lista
    REP_D_ELEM * cauda; //Elemento final da lista
}REP_D;

/* **********************
 *        Headers       *
 * **********************/

/************************
 *      Report A       *
 * **********************/
//Criar elemento
REP_A_ELEM * criarElementoReportA(int numeroAluno, wchar_t * nomeAluno, int ects, wchar_t * observacao);
//Libertar elemento
REP_A_ELEM * libertarElementoReportA(REP_A_ELEM * elemento);
//Criar nó da lista
No_REP_A * criarNoReportA(REP_A_ELEM * elemento);
//Libertar nó 
int  libertarNoReportA(No_REP_A * no);
//Criar lista report A
REP_A * criarListaReportA();
//Libertar a lista
int libertarListaReportA(REP_A * lista);
//Adicionar elemento na lista
int adicionarElementoRepA(REP_A_ELEM * unidade, REP_A * lista);
//Remover elemento da lista
int removerElementoRepA(REP_A * lista);
//Adicionar no elemento 
void adicionarDadoElementoRepA(REP_A_ELEM * elemento, int ects, wchar_t * observacao);
//Verificar se o aluno consta da lista do ReportA
int verificaElementoRepA(int numeroAluno, REP_A * report);

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

//Crar lista de Report D
REP_D * criarListaReportD();
//Criar elemento da lista ReportD
REP_D_ELEM * criarElementoReportD(wchar_t * ano, int total);
//Crar lista de Anos letivos de Report D
REP_D_LISTA * criarListaAnoReportD();
//Criar elemento da lista de anos letivos ReportD
REP_D_LISTA_ELEM * criarElementoAnoReportD(int id);
//Libertar memoria do Elemento Report D
void libertarElementoReportD(REP_D_ELEM * elemento);
//Libertar memoria do Elemento da lista de ano letivo de Report D
void libertarElementoAnoReportD(REP_D_LISTA_ELEM * elemento);
//Remover no inicio da lista
int removerElementoRepDInicio(REP_D * lista);
//Remover no inicio da lista
int removerElementoRepDAnoInicio(REP_D_LISTA * lista);
//Adiciona elemento no final da lista
int adicionarElementoRepDFim(REP_D * lista, REP_D_ELEM * elemento);
//Adiciona elemento no final da lista de Anos Letivos
int adicionarElementoAnoRepDFim(REP_D_LISTA * lista, REP_D_LISTA_ELEM * elemento);
//Liberta Memoria da Lista Report D
void libertarListaReportD(REP_D * lista);
//Liberta Memoria da Lista de Anos letivos Report D
void libertarListaAnoReportD(REP_D_LISTA * lista);
//Obter Elemento com idAluno igual a id
REP_D_LISTA_ELEM * obterElementoReportDNum(int id, REP_D_LISTA * lista);

#endif