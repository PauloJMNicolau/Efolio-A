#include "../sgbd/sgbd.h"
#include "global.h"


#ifndef _UIINSCRICOES_
#define _UIINSCRICOES_

//Adicionar uma nova inscrição
void novaInscricao(SGBD * bd);
//Remover uma inscrição
void eliminarInscricao(SGBD * bd);
//Consultar uma inscrição
void consultarInscricao(SGBD * bd);
//Modificar uma inscrição
void modificarInscricao(SGBD * bd);

#endif