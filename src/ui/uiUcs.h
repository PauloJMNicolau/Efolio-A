/*
 * Ficheiro que possui todas as funções da UI (User Interface) de Unidades Curriculares
 */
#ifndef _UIUCS_
#define _UIUCS_

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

//Adicionar uma nova Unidade Curricular
void uiAdicionarNovaUC(SGBD * bd);
//Mostrar Lista de UCS
void uiImprimirListaUC(SGBD * bd);
//Imprimir Lista de UC com ID
void uiImprimirUCS(SGBD * bd);
//Remover UC
void uiRemoverUnidade(SGBD * bd);
//Imprimir Dados da UC sem ID
void uiImprimirDadosUC(UC * unidade);
//Alterar Unidade
void uiAlterarUnidade(SGBD * bd);


#endif