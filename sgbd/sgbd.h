#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>

/************************
 *      Estruturas      *
 * **********************/

/* Unidades Curriculares */

//Estrutura de Dados UC
typedef struct unidade{
    int numero;    //Numero da UC
    wchar_t *nome; //Nome da UC
    int ano;       //Ano da UC [1,2,3]
    int semestre;  //Semestre da UC [1,2]
} UC;

//Estrutura para No da Lista de UC
typedef struct noUC{
    UC * elemento; //Elemento
    struct noUC * proximo; //Proximo elemento na lista
} NoUC;

//Estrutura de Dados Lista de Unidades Curriculares
typedef struct lista_unidade{
    int elementos; // Quantidade de elementos na lista
    NoUC * cauda; //Cauda da lista
} LIST_UC;


/* Alunos */

//Estrutura de Dados de Aluno
typedef struct aluno{
    int numero;    //Numero de Aluno
    wchar_t *nome; //Nome do Aluno
    wchar_t *pais; //Pais do Aluno
} ALUNO;

//Estrutura para No da Lista de Alunos
typedef struct noAluno{
    ALUNO *elemento;         //Elemento
    struct noAluno *proximo; //Proximo elemento na lista
} NoALUNO;

//Estrutura da Lista de Alunos (Lista Ligada)
typedef struct listAluno{
    int elementos; // Quantidade de elementos na lista
    NoALUNO *cauda;   //Cauda da lista
} LIST_ALUNO;


/* Inscriçoes */

//Estrutura para Inscrição
typedef struct inscricao{
    int numeroAluno; //Numero Aluno
    int numeroUC; //Numero da UC
    wchar_t * anoLetivo; //Ano Letivo
}INSCRICAO;

//Estrutura para No da Lista de inscrições
typedef struct no{
    INSCRICAO *elemento;         //Elemento
    struct no * anterior;   //No Anterior
    struct no * ramo;       //No do mesmo ramo
    struct no *proximo;     //No Proximo
} NoINSCRICAO;

//Estrutura para Arvore de inscrições
typedef struct tree{
    int elementos;          //Quantidade de elementos da arvore
    NoINSCRICAO * raiz;      //Raiz da arvore
}TREE_INSCRICAO;

/* Base de Dados */

//Estrutura de Dados da Base Dados
typedef struct sgdb{
    LIST_ALUNO *alunos;         //Lista de Alunos
    LIST_UC *ucs;               //Lista de Unidades Curriculares
    //TREE_INSCRICAO *inscricoes; //Lista de Inscrições
    int proxIDAluno;            //Variável que controla auto-incremento ID Aluno
    int proxIDUC;               //Variavel que controla auto-incremento ID UC
} SGBD;


/********************************
 *          Headers             *
 ********************************/

/* Unidades Curriculares */

//Criar lista vazia
LIST_UC *criarListaUC();
//Criar Unidade Curricular
UC *criarUC(int numero, wchar_t *nome, int ano, int semestre);
//Criar No Lista UC
NoUC *criarNoUC(UC *unidade);
//Libertar No UC
int libertarNoUC(NoUC *no);
//Eliminar Lista
int libertarListaUC(LIST_UC *lista);
//Libertar Memoria da Unidade Curricular
int libertarUC(UC *unidade);
//Adicionar elemento na lista
int adicionarUC(UC *unidade, LIST_UC *lista, int pos);
//Remover elemento da lista
int removerUC(int pos, LIST_UC *lista);


/* Alunos */

//Criar lista vazia
LIST_ALUNO *criarListaAluno();
//Criar Aluno com dados
ALUNO *criarAluno(int numero, wchar_t *nome, wchar_t *pais);
//Criar No Lista Aluno
NoALUNO *criarNoAluno(ALUNO *aluno);
//Libertar Memoria Aluno
int libertarAluno(ALUNO *aluno);
//Libertar No Aluno
int libertarNoAluno(NoALUNO *no);
//Eliminar Lista
int libertarListaAluno(LIST_ALUNO *lista);
//Remover elemento da lista
int removerAluno(int pos, LIST_ALUNO *lista);
//Adicionar elemento na lista
int adicionarAluno(ALUNO *aluno, LIST_ALUNO *lista, int pos);

/* Arvore de Inscrições */

//Cria a arvore vazia
TREE_INSCRICAO * criarArvore();
//Criar Inscricao
INSCRICAO * criarInscricao(int numeroUC, int numeroAluno, wchar_t* ano);
//Criar No de inscricao
NoINSCRICAO * criarNoInscricao(INSCRICAO * inscricao);

//Libertar memória da Inscricao
int libertarInscricao(INSCRICAO * inscricao);
//Libertar NoInscricao
int libertarNoInscricao(NoINSCRICAO * no);
//Liberta a memoria da arvore
int libertarArvore(TREE_INSCRICAO * arvore);
//Inserir NO na arvore
int inserirNaArvore(INSCRICAO * inscricao, TREE_INSCRICAO* arvore);
//Inserir No na subArvore
NoINSCRICAO * inserirInscricao(INSCRICAO * inscricao, NoINSCRICAO * no);