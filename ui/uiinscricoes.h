#include "../sgbd/sgbd.h"
#include "global.h"


#ifndef _UIINSCRICOES_
#define _UIINSCRICOES_

//Adicionar uma nova inscrição
void novaInscricao(SGBD * bd);
//Remover uma inscrição
void removerInscricao(SGBD * bd);
//Mostrar lista de inscrições por ano letivo
void mostrarListaInscricoes(SGBD * bd);
//Modificar uma inscrição
void modificarInscricao(SGBD * bd);

#endif