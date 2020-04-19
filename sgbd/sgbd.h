#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>
#include "ficheiros.h"
#include "inscricoes.h"
#include "alunos.h"
#include "ucs.h"
#include <uchar.h>
#include <locale.h>
#include "macro.h"

#ifndef _SGBD_
#define _SGBD_
/* ***********************
 *      Estruturas       *
 * ********************* */

//Estrutura de Dados da Base Dados
typedef struct sgdb{
    LIST_ALUNO *alunos;         //Lista de Alunos
    LIST_UC *ucs;               //Lista de Unidades Curriculares
    LISTA_PASTA *inscricoes;    //Lista de Inscrições
} SGBD;

/* ***********************
 *       Headers         *
 * ********************* */

//Criar Base de Dados vazia
SGBD *criarBaseDados();
int carregarFicheiros(SGBD * bd);
int libertarBD(SGBD * bd);
int gravarDados(SGBD * bd);
#endif
