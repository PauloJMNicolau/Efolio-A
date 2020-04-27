/*
 * Ficheiro que possui todas as funções relacionas com a UI (User Interface) dos Reports
 */

#ifndef _UIREPORTS_
#define _UIREPORTS_

//Bibliotecas Padrão
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>
//Bibliotecas Proprias
#include "../sgbd/sgbd.h"

/************************************
 *            Report A              *
 ************************************/

//Gerar ReportA
void ReportA(SGBD * bd);

/************************************
 *            Report B              *
 ************************************/
//Gerar ReportB
void ReportB(SGBD * bd);

/************************************
 *            Report c              *
 ************************************/
//Gerar ReportC
void ReportC(SGBD * bd);
/************************************
 *            Report D              *
 ************************************/
//Gerar ReportD
void ReportD(SGBD * bd);
#endif
