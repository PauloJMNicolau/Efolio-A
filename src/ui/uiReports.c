
#include "uiReports.h"


//Report número total ECTS por aluno no ano letivo corrente
void repECTSAluno(SGBD * bd) {
    clearScreen();
    int i, j, ects;
    ListRepECTS * report = criarListaECTS();
    NO_PASTA * pasta = bd->inscricoes->cauda;   //pasta ano corrente
    NO * no = pasta->cauda;
    ALUNO * aluno;
    UC * uc;
    for(i=0; i < pasta->elementos; i++){
        if(verificaRepECTS(no->elemento->numeroAluno, report)){
            no = no->proximo;
            continue;
        }
        aluno = obterAlunoNum(no->elemento->numeroAluno, bd->alunos);
        uc = obterUCNum(no->elemento->numeroUC, bd->ucs);
        adicionarRepECTS(criarElementoECTS(aluno->numero,aluno->nome,0,L"N/A"),report,report->elementos);
        no = no->proximo;
    }

    NoRepECTS * norep = report->cauda;
    
    wchar_t * obsv;
    obsv=calloc(_TAMSTRING,sizeof(wchar_t));

    for(i=0; i<report->elementos; i++){
        ects=0;
        obsv = L"N/A";
        for(j=0; j< pasta->elementos; j++){
            if(norep->elemento->numero == no->elemento->numeroAluno)
                ects += obterECTS(obterUCNum(no->elemento->numeroUC, bd->ucs));   
            no = no->proximo;
        }
        if(ects > 60)
            obsv = L"Necessita validação";
        adicionarECTS(norep->elemento, ects, obsv);
        norep = norep->proximo;
    }
    imprimirReportECTS(report);
    free(obsv);
    libertarListaECTS(report);
    pressioneENTER();
}

//Verificar se o aluno consta da lista do Report
int verificaRepECTS(int numeroAluno, ListRepECTS * report){
    NoRepECTS * no = report->cauda;
    for(int i=0; i<report->elementos; i++) {
        if(no->elemento->numero == numeroAluno)
            return 1;
        no = no->proximo;
    }
    return 0;
}

void imprimirReportECTS(ListRepECTS * report){
    NoRepECTS * norep = report->cauda;
    int i;
    for(i=0;i<report->elementos;i++)
    {
        wprintf(L"%d ", report->elementos);
        wprintf(L"%d %S %d %S\n", norep->elemento->numero, norep->elemento->nome,norep->elemento->ects, norep->elemento->observacao);
        norep =  norep->proximo;
    }
}