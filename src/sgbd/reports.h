
#ifndef _REPORTS_
#define _REPORTS_

#include "macro.h"
#include "alunos.h"
#include "ucs.h"
#include "inscricoes.h"

/************************
 *      Estruturas      *
 * **********************/

//Estrutura de Dados UC
typedef struct ects{
    int numero;      //Numero de aluno
    wchar_t *nome; //Nome do aluno
    int ects;       //ECTS 
    wchar_t * observacao;  //observacao serviços acadêmicos
} ECTS;

//Estrutura para No da Lista de UC
typedef struct norepECTS{
    ECTS * elemento; //Elemento
    struct norepECTS * proximo; //Proximo elemento na lista
} NoRepECTS;

//Estrutura de Dados Lista de Unidades Curriculares
typedef struct lista_repects{
    int elementos; // Quantidade de elementos na lista
    NoRepECTS * cauda; //Cauda da lista
} ListRepECTS;

//Criar elemento
ECTS * criarElementoECTS(int numeroAluno, wchar_t * nomeAluno, int ects, wchar_t * observacao);
//Libertar elemento
ECTS * libertarElementoECTS(ECTS * elemento);
//Criar nó da lista tendo como chave número de aluno
NoRepECTS * criarNoECTS(ECTS * elemento);
//Libertar nó Report ECTS
int  libertarNoECTS(NoRepECTS * no);
//Criar lista report ECTS
ListRepECTS * criarListaECTS();
//Libertar a lista
int libertarListaECTS(ListRepECTS * lista);
//Adicionar elemento ECTS na lista
int adicionarRepECTS(ECTS * unidade, ListRepECTS * lista, int pos);
//Remover elemento da lista
int removerElementoECTS(int pos, ListRepECTS * lista);
//Adicionar no elemento 
void adicionarECTS(ECTS * elemento, int ects, wchar_t * observacao);
#endif