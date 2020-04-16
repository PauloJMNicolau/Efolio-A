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
void menuAlunos();
//Submenu para funções relacionadas directamente com UCs
void menuUCS(SGBD * bd);
//Submenu para funções relacionadas directamente com incrições
void menuInscricoes();
//Submenu para funções relacionadas directamente com propinas
void menuPropinas();
//Submenu para funções relacionadas directamente com consultas
void menuConsultas();
//Submenu para funções relacionadas directamente com reports
void menuReports();

<<<<<<< HEAD
#endif;
=======
#endif
>>>>>>> 90d96be405c2db3c0803a93039495ed2a37404eb
