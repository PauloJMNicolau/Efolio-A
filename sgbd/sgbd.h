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



#ifndef _SGBD_
#define _SGBD_
/* ***********************
 *      Estruturas       *
 * ********************* */

//Estrutura de Dados da Base Dados
typedef struct sgdb{
    LIST_ALUNO *alunos;         //Lista de Alunos
    LIST_UC *ucs;               //Lista de Unidades Curriculares
    //TREE_INSCRICAO *inscricoes; //Lista de Inscrições
    int proxIDAluno;            //Variável que controla auto-incremento ID Aluno
    int proxIDUC;               //Variavel que controla auto-incremento ID UC
} SGBD;

#endif
