/*
 * Ficheiro que possui todas as funções da UI (User Interface) de Inscrições
 */

#ifndef _UIINSCRICOES_
#define _UIINSCRICOES_

//Bibliotecas Padrão
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>
//Bibliotecas Próprias
#include "../sgbd/macro.h"
#include "../sgbd/sgbd.h"
#include "global.h"

/* **********************
 *        Headers       *
 * **********************/
//Adicionar uma nova Inscrição
void uiAdicionarNovaInscricao(SGBD * bd);
//Mostrar lista de inscrições por ano letivo
void uiImprimirListaInscricoes(SGBD * bd);
//Imprimir dados da inscrições
void uiImprimirInscricoes(NO_PASTA * pasta);
//Remover uma inscrição
void uiRemoverInscricao(SGBD * bd);
//Imprimir dado da inscrição
void uiImprimirDadoInscricao(INSCRICAO * inscricao);
//Modificar valores de uma inscrição
void uiAlterarInscricao(SGBD * bd);
//Imprimir Listagem por UC
void uiImprimirListagemPorUC(SGBD * bd);
//Imprime Titulo da Listagem UC
void uiImprimirCabecalhoUC(UC * unidade, wchar_t *ano);
//Imprime Titulo da Listagem Aluno
void uiImprimirCabecalhoAluno(ALUNO * aluno, wchar_t * ano);
//Imprimir Listagem por Aluno
void uiImprimirListagemPorAluno(SGBD * bd);
#endif