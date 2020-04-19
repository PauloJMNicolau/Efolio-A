#include "../sgbd/sgbd.h"
#include "global.h"

#ifndef _UIALUNOS_
#define _UIALUNOS_

//Adicionar uma novo aluno a lista
void novoaluno(SGBD * bd);

//Remover aluno
void remov_aluno (SGBD * bd);

//consultarAluno
void consultaraluno (SGBD * bd);

//modificarAluno
void modificaraluno (SGBD * bd);
#endif


