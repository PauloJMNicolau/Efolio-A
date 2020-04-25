
#ifndef _UIREPORTS_
#define _UIREPORTS_


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

//Report número total ECTS por aluno no ano letivo corrente
void repECTSAluno(SGBD * bd);
//Verificar se o aluno consta da lista do Report
int verificaRepECTS(int numeroAluno, ListRepECTS * report);

void imprimirReportECTS(ListRepECTS * report);
#endif