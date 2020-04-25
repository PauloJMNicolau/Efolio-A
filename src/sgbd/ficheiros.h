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

#endif