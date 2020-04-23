#include "../sgbd/sgbd.h"
#include "global.h"

#ifndef _UIPROPINAS_
#define _UIPROPINAS_

//Função para calcular valor da propina
void calcularPropinas(SGBD * bd);
//Cálculo da propina mediante condicão do estudante
int calculo(int ects, int opcao);
//Verifica estatuto de residente do estudante e se é 1º inscrição
int condicaoPropina(ALUNO *aluno,LISTA_PASTA * inscricao);
#endif