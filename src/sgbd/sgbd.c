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



/************************************
 *            Report A              *
 ************************************/



/************************************
 *            Report B              *
 ************************************/

void gerarReportB(SGBD * bd){
    LIST_ALUNO * alunosAux = bd->alunos;
    LISTA_PASTA * auxInscricoes = bd->inscricoes;
    FILE * reportFile = criarReportB();
    //Percorrer a lista de todos os alunos
    for(int i =0; i< alunosAux->elementos; i++){
        REP_B * report = criarListaReportB(); //Cria estrutura de report B
        ALUNO * aluno = obterAlunoPos(i,alunosAux);
        //Percorrer todos os anos letivos
        for(int p =0; p< auxInscricoes->pastas; p++){
            NO_PASTA * pasta= obterPastaPos(p,auxInscricoes);
            NO * no = pasta->cauda;
            //Percorrer todas as inscrições do ano
            for(int n = 0; n <pasta->elementos; n++){
                no = no->proximo;
                //Verificar se inscrição pertence ao aluno
                if(no->elemento->numeroAluno == aluno->numero){
                    //Pesquisa na estrutura para verificar se encontra o id da UC na estrutura
                    REP_B_ELEM * aux = obterElementoReportBNum(no->elemento->numeroUC, report);
                    if(aux != NULL){
                        //Caso o id da uc esteja na estrutura, verifica se a mesma já está concluida, caso não esteja atualiza estado com nova nota
                        if(aux->estado != 1)
                            modificarEstado(aux,no->elemento->nota);
                    } else
                        //Caso não esteja na estrutura adiciona a uc à estrutura
                        adicionarElementoRepBFim(report, criarElementoReportB(no->elemento->numeroUC, no->elemento->nota));
                }
            }
        }
        //Verifica se estrutura possui tantos elementos como unidades na bd
        if(report->quantidade == bd->ucs->elementos){
            int contador = 0;
            REP_B_ELEM * aux = report->cauda;
            //Soma todas o valor de estados da UC na estrutura.
            for(int e =0; e < report->quantidade; e++){
                aux = aux->proximo;
                contador += aux->estado;
            }
            //Se a soma for igual ou superior ao total de ucs-3 e não for a totalidade de UC escreve no ficheiro 
            if(contador >= bd->ucs->elementos - 3 && contador < bd->ucs->elementos){
                escreverLinhaReportB(aluno,contador, reportFile);
            }
        }
        libertarListaReportB(report);
    }
    terminarReportB(reportFile);
}

/************************************
 *            Report C              *
 ************************************/
//criar report c
void gerarReportC(SGBD * bd){
    //Percorrer cada elemento da lista de alunos
    LIST_ALUNO * alunosAux = bd->alunos;
    FILE * reportFile = criarReportC();
    //Percorrer a lista de todos os alunos
    for(int i =0; i< alunosAux->elementos; i++){
        PROB_ABANDONO * report = criarListaReportC(); //Cria estrutura de report C
        ALUNO * aluno = obterAlunoPos(i,alunosAux);
        // obter pasta do ano letivo final
        NO_PASTA * pasta = obterAnoLetivoRecente(bd->inscricoes);
        NO * no = pasta->cauda;
        //percorrer pasta 
        for(int p =0; p < pasta->elementos; p++){
            no = no->proximo;
            //comparar se inscrição pertence ao aluno
            if(no->elemento->numeroAluno == aluno->numero){
                UC * temp = obterUCNum(no->elemento->numeroUC, bd->ucs);
                //se uc estiver em 1semestre então ++semestre1;
                if( temp->semestre == 1){
                    report->contador_semestre_1++;
                } else //se uc->2semestre entao semestre2;*/
                    report->contador_semestre_2++;
            }
        }
        if(report->contador_semestre_2==0){
            if(report->contador_semestre_1>=2){
                escreverLinhaReportC(aluno, reportFile);
            }
        }
         
        libertarElementoReportC(report);
    }
    terminarReportC(reportFile);
}



//************************************/
// *            Report D              *
// ************************************/