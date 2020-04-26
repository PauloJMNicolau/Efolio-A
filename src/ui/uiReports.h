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
void gerarReportA(SGBD * bd);
//Imprimir report total ECTS por aluno no ano corrente
void imprimirReportA(REP_A * report);

/************************************
 *            Report B              *
 ************************************/
//Gerar ReportB
void gerarReportB(SGBD * bd);

/************************************
 *            Report c              *
 ************************************/
//Gerar ReportC
void gerarReportC(SGBD * bd);
/************************************
 *            Report D              *
 ************************************/
//Gerar ReportD
void gerarReportD(SGBD * bd);
#endif