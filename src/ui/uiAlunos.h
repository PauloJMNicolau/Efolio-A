/*
 * Ficheiro que possui todas as funções da UI (User Interface) de Alunos
 */
#ifndef _UIALUNOS_
#define _UIALUNOS_

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

//Adicionar um novo aluno
void uiAdicionarNovoAluno(SGBD * bd);
//Remover UC
void uiRemoverAluno(SGBD * bd);
// Imprimir lista de alunos com ID
void uiImprimirAlunos(SGBD * bd);
//imprimir dados dos alunos
void uiImprimirDadosAluno(ALUNO * elem);
//Alterar Aluno
void uiAlterarAluno(SGBD * bd);
//Mostrar Lista de  alunos
void uiImprimirListaAlunos(SGBD * bd);

#endif