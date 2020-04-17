#include "../sgbd/sgbd.h"
#include "global.h"

#ifndef _UIUCS_
#define _UIUCS_

//Adicionar uma nova Unidade Curricular
void novaUC(SGBD * bd);
//Mostrar Lista de UCS
void mostrarListaUC(SGBD * bd);
//Remover UC
void removerUnidade(SGBD * bd);
//Imprimir Lista de UC
void imprimirUCS(SGBD * bd);
#endif