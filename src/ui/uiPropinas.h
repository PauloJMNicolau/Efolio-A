/*
 * Ficheiro que possui todas as funções relacionas com a UI (User Interface) das propinas
 */

#ifndef _UIPROPINAS_
#define _UIPROPINAS_

//Bibliotecas Padrão
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>
//Bibliotecas Proprias
#include "../sgbd/sgbd.h"
#include "uiAlunos.h"

/* ***********************
 *       Headers         *
 * ********************* */

//Função para calcular valor da propina
void uiCalcularPropinas(SGBD * bd);


#endif