#include <stdio.h>
#include <wchar.h>
#include <unistd.h>
#include <locale.h>
#include "global.h"
#include "uiucs.h"
#include "../sgbd/sgbd.h"

#ifndef _MENU_
#define _MENU_

//Menu com lista de opções possíveis
void menuPrincipal(SGBD * bd);
//Submenu para funções relacionadas directamente com alunos
void menuAlunos(SGBD * bd);
//Submenu para funções relacionadas directamente com UCs
void menuUCS(SGBD * bd);
//Submenu para funções relacionadas directamente com incrições
void menuInscricoes(SGBD * bd);
//Submenu para funções relacionadas directamente com propinas
void menuPropinas(SGBD * bd);
//Submenu para funções relacionadas directamente com consultas
void menuConsultas(SGBD * bd);
//Submenu para funções relacionadas directamente com reports
void menuReports(SGBD * bd);

#endif