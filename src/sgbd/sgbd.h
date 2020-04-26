/*
 * Ficheiro que possui todas as funções de gestão da Base de dados
 */

#ifndef _SGBD_
#define _SGBD_

//Bibliotecas Padrão
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>
#include <uchar.h>
#include <locale.h>
//Bibliotecas Próprias
#include "ficheiros.h"
#include "inscricoes.h"
#include "alunos.h"
#include "ucs.h"
#include "macro.h"
#include "reports.h"
#include"../ui/global.h"

/* ***********************
 *      Estruturas       *
 * ********************* */

//Estrutura de Dados da Base Dados
typedef struct sgdb{
    LIST_ALUNO *alunos;         //Lista de Alunos
    LIST_UC *ucs;               //Lista de Unidades Curriculares
    LISTA_PASTA *inscricoes;    //Lista de Inscrições
} SGBD;

/* ***********************
 *       Headers         *
 * ********************* */

//Criar Base de Dados vazia
SGBD *criarBaseDados();
//Libertar Memoria Base Dados
int libertarBD(SGBD * bd);
//Gravar informação da bd nos ficheiros novamente
int gravarDados(SGBD * bd);
//Ler informação dos ficheiros
int carregarFicheiros(SGBD * bd);
//Validar Inscriçoes
int validarInscricoes(SGBD * bd, ALUNO * aluno, wchar_t * ano,int ects);
//Cálculo da propina mediante condicão do estudante
int calculoPropina(int ects, int opcao);
//Calcular Propinas para o ultimo Ano
void calcularPropinas(SGBD * bd, ALUNO * aluno);
//Verifica estatuto de residente do estudante e se é 1º inscrição
int condicaoPropina(ALUNO * aluno, LISTA_PASTA * inscricao);

/************************************
 *            Report A              *
 ************************************/

REP_A * ReportA(SGBD * bd);


/************************************
 *            Report B              *
 ************************************/

void ReportB(SGBD * bd);


/************************************
 *            Report C              *
 ************************************/

/************************************
 *            Report D              *
 ************************************/

#endif
