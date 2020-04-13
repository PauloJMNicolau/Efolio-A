#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>

/************************
 *      Estruturas      *
 * **********************/

//Estrutura para Inscrição
typedef struct inscricao{
    int numeroAluno; //Numero Aluno
    int numeroUC; //Numero da UC
    wchar_t * anoLetivo; //Ano Letivo
}INSCRICAO;

//Estrutura para No da Lista de inscrições
typedef struct no{
    INSCRICAO * elemento;    //Elemento
    struct no * anterior;    //No Anterior
    struct no * proximo;     //No Proximo
    struct no * ramo;
} NoINSCRICAO;

//Estrutura para Arvore de inscrições
typedef struct tree{
    int elementos;          //Quantidade de elementos da arvore
    NoINSCRICAO * raiz;      //Raiz da arvore
}TREE_INSCRICAO;


/********************************
 *          Headers             *
 ********************************/

//Criar Inscricao
INSCRICAO * criarInscricao(int numeroUC, int numeroAluno, wchar_t* ano);
//Libertar memória da Inscricao
int libertarInscricao(INSCRICAO * inscricao);

//Criar Arvore de Inscrições
//Retorna arvore criada
TREE_INSCRICAO * criarArvore();
//Criar No da Arvore
//Retorna No criado
NoINSCRICAO * criarNoArvore(INSCRICAO * elemento);
//Inserir No na arvore
//Retorna o no adicionado
NoINSCRICAO * inserirNoArvore(NoINSCRICAO * noPai, NoINSCRICAO * no);
//Procura elemento na arvore
//Retorna No Encontrado
NoINSCRICAO * procuraInscricao(int numeroUC, int numeroAluno, wchar_t * ano, NoINSCRICAO * no);
//Inserir elementos na arvore
int inserirArvore(TREE_INSCRICAO * arvore, INSCRICAO * elemento);