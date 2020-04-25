/*
 * Ficheiro que possui todas as funções principais do UI (User Interface)
 */

#ifndef _UI_
#define _UI_

//Bibliotecas Padrão
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>
//Bibliotecas Proprias
#include "../sgbd/sgbd.h"
#include "uiUcs.h"
#include "uiAlunos.h"
#include "uiInscricoes.h"
#include "uiPropinas.h"
#include "uiReports.h"

//Menu principal com as opções possíveis
void menuPrincipal(SGBD * bd);
//Menu com funcionalidades extra
void menuExtra(SGBD * bd);
//Submenu para funções relacionadas directamente com alunos
void menuAlunos(SGBD * bd);
//Submenu para funções relacionadas directamente com UCs
void menuUCS(SGBD * bd);
//Submenu para funções relacionadas directamente com Inscriçoes
void menuInscricoes(SGBD * bd);
//Submenu para funções relacionadas directamente com consultas
void menuConsultas(SGBD * bd);
//Submenu para funções relacionadas directamente com reports
void menuReports(SGBD * bd);

#endif