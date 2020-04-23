#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>

#ifndef _INSCRICOES_
#define _INSCRICOES_
/************************
 *      Estruturas      *
 * **********************/

//Estrutura para Inscrição
typedef struct inscricao{
    int numeroAluno; //Numero Aluno
    int numeroUC; //Numero da UC
    int ects;
    wchar_t * anoLetivo; //Ano Letivo
}INSCRICAO;

typedef struct no{
    INSCRICAO * elemento;       //Elemento da lista
    struct no * proximo;        //Proximo elemento na lista
} NO;

//Estrutura para no de pasta
typedef struct noPasta{
    wchar_t * chave;            //Chave da pasta
    int elementos;              //Quantidade de elementos na lista
    NO * cauda;                 //Ultimo elemento na lista
    struct noPasta * proximo;   //Proxima Pasta na lista
} NO_PASTA;

//Estrutura para pasta 
typedef struct listaAnual{
    int pastas;         //Quantidade de pastas
    NO_PASTA * cauda;   //Fim da lista
} LISTA_PASTA;


/********************************
 *          Headers             *
 ********************************/

//Criar Inscricao
INSCRICAO * criarInscricao(int numeroUC, int ects, int numeroAluno, wchar_t* ano);
//Cria lista para pastas
LISTA_PASTA * criarListaPastas();
//Criar Pasta Anual
NO_PASTA * criarPasta(wchar_t * chave);
//Cria no da lista na pasta
//Retorna no criado
NO * criarNo(INSCRICAO * elemento);
//Libertar memória da Inscricao
int libertarInscricao(INSCRICAO * inscricao);
//Liberta Memoria NO
int libertarNO(NO * elemento);
//Libertar Memoria Pasta
int libertarPasta(NO_PASTA * elemento);
//Libertar memoria Lista Pastas
int libertarListaPasta(LISTA_PASTA * lista);
//Procura pasta na lista
NO_PASTA * procuraPasta(wchar_t * ano, LISTA_PASTA* lista);
//Adicionar Inscrição na lista
int adicionarInscricao(INSCRICAO * nova, LISTA_PASTA * lista);
//Adicionar Pasta na lista
int adicionaPasta(NO_PASTA * pasta, LISTA_PASTA* lista);
//Adicionar na pasta a inscrição
int adicionarInscricaoPasta(INSCRICAO * inscricao, NO_PASTA * lista);
//Procura Inscrição na pasta correspondente
//Retorna NULL se não encontrar
INSCRICAO * procuraInscricao(LISTA_PASTA * lista, wchar_t * ano, int numeroAluno, int numeroUC);
//Procura posição na pasta do elemento inscrição
//Retorna -1 caso não encontre
int procuraPosicaoInscricao(INSCRICAO * elemento, LISTA_PASTA * lista);
//Remover pasta da lista
int removerPasta(NO_PASTA * pasta, LISTA_PASTA * lista);
//Remover elemento da pasta
int removerInscricoes(int pos, NO_PASTA * lista);
//Remover inscrição
int removerInscricao(INSCRICAO* inscricao, LISTA_PASTA * lista);
//Obter inscrição na posição
INSCRICAO * obterInscricao(int pos, NO_PASTA * lista);
//Modificar valor de uma inscrição
void modificarValorInscricao(int numeroAluno, int numeroUC, INSCRICAO * inscricao);
//Verifica se aluno frequentou o ano letivo anterior ao ano currente
int verificaInsAnoAnterior(int numeroAluno, LISTA_PASTA * inscricao);
#endif