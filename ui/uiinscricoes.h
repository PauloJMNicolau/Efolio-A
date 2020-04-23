#include "../sgbd/sgbd.h"
#include "global.h"


#ifndef _UIINSCRICOES_
#define _UIINSCRICOES_

//Adicionar uma nova inscrição
void novaInscricao(SGBD * bd);
//Remover uma inscrição
void eliminarInscricao(SGBD * bd);
//Mostrar lista de inscrições por ano letivo
void mostrarListaInscricoes(SGBD * bd);
//Modificar uma inscrição
void modificarInscricao(SGBD * bd);
//Imprimir dados da inscrições
void imprimirInscricoes(NO_PASTA * pasta);

#endif