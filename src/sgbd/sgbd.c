/*
 * Ficheiro que possui todas as funções de gestão da Base de dados
 */

#include "sgbd.h"

/************************************
 *          Motor SGBD              *
 ************************************/

//Criar Base de Dados vazia
SGBD *criarBaseDados(){
    SGBD * baseDados = calloc(1, sizeof(SGBD));
    if (!baseDados){
        wprintf(L"Erro %d: Impossível alocar memória para Base de Dados", _ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    baseDados->alunos = criarListaAluno();
    baseDados->inscricoes = criarListaPastas();
    baseDados->ucs = criarListaUC();
    return baseDados;
}

//Libertar Memoria Base Dados
int libertarBD(SGBD * bd){
    if(!bd){
        wprintf(L"Erro %d: Não foi possivel libertar memória!", _ERR_MEMORYFREE);
        return _ERR_MEMORYFREE;
    }
    if(bd->alunos){
        libertarListaAluno(bd->alunos);
        bd->alunos = NULL;
    }
    if(bd->ucs){
        libertarListaUC(bd->ucs);
        bd->ucs = NULL;
    }
    if(bd->inscricoes){
        libertarListaPasta(bd->inscricoes);
        bd->inscricoes = NULL;
    }
    free(bd);
    bd=NULL;
    return _SUCESSO;
}

//Gravar informação da bd nos ficheiros novamente
int gravarDados(SGBD * bd){
    if(!bd){
        wprintf(L"Erro %d: Base de Dados não existe\n");
        return _ERR_RESOURCENOTFOUND;
    }
    //Gravar ficheiro de UCS
    gravarUCTexto(bd->ucs);
    //Gravar ficheiro de Alunos
    gravarAlunosTexto(bd->alunos);
    //Gravar ficheiro de inscrições
    gravarInscricoesTexto(bd->inscricoes);
    return _SUCESSO;
}

//Ler informação dos ficheiros
int carregarFicheiros(SGBD * bd){
    if(!bd){
        wprintf(L"Erro %d: Base de Dados não existe\n");
        return _ERR_RESOURCENOTFOUND;
    }
    //Carregar ficheiro de UCS
    lerUCTexto(bd->ucs);
    //Carregar ficheiro de Alunos
    lerListaAlunos(bd->alunos);
    //Carregar ficheiro de inscrições
    lerInscricoesTexto(bd->inscricoes);
    return _SUCESSO;
}

//Validar Inscriçoes
int validarInscricoes(SGBD * bd, ALUNO * aluno, wchar_t * ano, int ects){
    return validarInscricao(aluno,bd->ucs,ects,ano,bd->inscricoes);
}

//Calcular Propinas para o ultimo Ano
void calcularPropinas(SGBD * bd, ALUNO * aluno){
    NO_PASTA * aux = obterAnoLetivoRecente(bd->inscricoes);
    if(aux){
        int opcao = condicaoPropina(aluno,bd->inscricoes);
        int ects = 0;
        NO * temp = aux->cauda;
        for(int i =0; i<aux->elementos; i++){
            temp = temp->proximo;
            if(temp->elemento->numeroAluno == aluno->numero){
                ects += obterECTS(obterUCNum(temp->elemento->numeroUC,bd->ucs));
            }
        }
        aluno->propina = calculoPropina(ects,opcao);
    }
}

//Cálculo da propina mediante condicão do estudante
int calculoPropina(int ects, int opcao) {
    int propina;
    if(opcao == 1)          //Residente 1º ano
        propina = 80 + 15 * ects;
    else if(opcao == 2)     //Residente não 1º ano
        propina = 15 * ects;
    else if(opcao == 3)     //Estrangeiro 1º ano
        propina = 80 + 15 * 1.2 * ects;
    else if (opcao == 4)    //Estrangeiro não 1º ano
        propina = 15 * 1.2 * ects;
    return propina;
}

//Verifica estatuto de residente do estudante e se é 1º inscrição
int condicaoPropina(ALUNO * aluno, LISTA_PASTA * inscricao) {
    int opcao;
    if(wcscmp(L"Portugal",aluno->pais) == 0)
        opcao = 1;
    else
        opcao = 3;
    opcao += verificaInsAnoAnterior(aluno->numero, inscricao);
    return opcao;
}