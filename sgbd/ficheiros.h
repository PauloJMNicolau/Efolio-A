#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>
#include "inscricoes.h"
#include "alunos.h"
#include "ucs.h"

#ifndef _Ficheiros_
#define _Ficheiros_

//Ler ficheiro de UC
void lerUCTexto(LIST_UC * lista);
//Processar Linha de Texto do ficheiro de UC
void processarLinhaUC(wchar_t * linha, LIST_UC * lista);

#endif
