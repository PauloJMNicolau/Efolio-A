#include "../sgbd/sgbd.h"
#include "global.h"

#ifndef _UIALUNOS_
#define _UIALUNOS_

//Adicionar uma novo aluno a lista
void novoAluno(SGBD * bd);

//Remover aluno
void remov_aluno (SGBD * bd);

//consultarAluno
void mostrarAlunos (SGBD * bd);

//modificarAluno
void modificaraluno (SGBD * bd);

// Imprimir lista de alunos
void imprimirAlunos(SGBD * bd);
#endif


