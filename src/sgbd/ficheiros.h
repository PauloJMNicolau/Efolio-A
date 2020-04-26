/*
 * Ficheiro que possui todas as funções de ficheiros
 */

#ifndef _FICHEIROS_
#define _FICHEIROS_
//Bibliotecas Padrão
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>
//Bibliotecas Próprias
#include "macro.h"
#include "inscricoes.h"
#include "alunos.h"
#include "ucs.h"
#include "reports.h"

/* **********************
 *        Headers       *
 * **********************/

//Ler ficheiro de UC
void lerUCTexto(LIST_UC * lista);
//Gravar Dados da UC no ficheiro
void gravarUCTexto(LIST_UC * lista);
//Processar Linha de Texto do ficheiro de UC
void processarLinhaUC(wchar_t * linha, LIST_UC * lista);
//ler lista de alunos
void lerListaAlunos(LIST_ALUNO * aluno);
//processar linha de texto do  ficheiro da lista de alunos
void processarLinhaAlunos(wchar_t * linhas, LIST_ALUNO * aluno);
//Gravar Dados dos Alunos no ficheiro
void gravarAlunosTexto(LIST_ALUNO * lista);
//Ler ficheiro de Inscricoes
void lerInscricoesTexto(LISTA_PASTA * lista);
//Processar Linha de Texto do ficheiro de UC
void processarLinhaInscricao(wchar_t * linha, LISTA_PASTA * lista);
//Gravar Dados dos Alunos no ficheiro
void gravarInscricoesTexto(LISTA_PASTA * lista);

/************************************
 *            Report A              *
 ************************************/

//Criar ficheiro para guardar Report A
FILE * criarReportA();
//Escrever no Report A
int escreverReportA(REP_A * report, FILE * fp);
//Termina a escrita no report A
int terminarReportA(FILE * fp);

/************************************
 *            Report B              *
 ************************************/
//Termina a escrita no report B
int terminarReportB(FILE * fp);
//Cria ficheiro e cabeçalho do Report B
FILE * criarReportB();
//Escrever linha no Report
int escreverLinhaReportB(ALUNO * aluno, int ucsRealizadas, FILE * fp);
//Abrir report B para leitura
FILE * abrirLeituraReportB();
//Fechar ficheiro Report B
void terminarLeituraReportB(FILE * fp);

/************************************
 *            Report C              *
 ************************************/
//Abrir report C para leitura
FILE * abrirLeituraReportC();
//Fechar ficheiro Report C
void terminarLeituraReportC(FILE * fp);
/************************************
 *            Report D              *
 ************************************/
//Abrir report D para leitura
FILE * abrirLeituraReportD();
//Fechar ficheiro Report D
void terminarLeituraReportD(FILE * fp);


#endif