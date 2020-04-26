/*
 * Ficheiro que possui todas as funções relacionas com a UI (User Interface) dos Reports
 */

#include "uiReports.h"

/************************************
 *            Report A              *
 ************************************/
//Gerar Report A
void gerarReportA(SGBD * bd) {
    REP_A * reportA = ReportA(bd);
    imprimirReportA(reportA);
    pressioneENTER();
    libertarListaReportA(reportA);
}

//Imprimir reportA total ECTS por aluno no ano corrente 
void imprimirReportA(REP_A * reportA){
    clearScreen();
    No_REP_A * norep = reportA->cauda;
    int i;
    for(i =0; i<80; i++)
        wprintf(L"-");
    wprintf(L"\n|%17S|%24S|%10S|%24S|\n",L"Número de Aluno",L"Nome do Aluno",L"ECTS",L"Observações");
    for(i =0; i<80; i++)
        wprintf(L"-");
    wprintf(L"\n");
    for(i=0;i<reportA->elementos;i++){
        wprintf(L"|%17d|%24S|%10d|%24S|\n", norep->elemento->numero, norep->elemento->nome,norep->elemento->ects, norep->elemento->observacao);
        norep =  norep->proximo;
    }
    for(i =0; i<80; i++)
        wprintf(L"-");
}

/************************************
 *            Report B              *
 ************************************/

void gerarReportB(SGBD * bd){
    ReportB(bd);
    imprimirReportB();
    pressioneENTER();
}
//Imprimir linha Report B
void imprimirLinhaReportB(wchar_t * linha){
    wchar_t * temp, * buffer;
    int numeroAluno = wcstol(wcstok(linha, L";", &buffer), &temp,10);
    wchar_t * nome = wcstok(NULL,L";",&buffer);
    int totalUC = wcstol(wcstok(NULL, L";", &buffer), &temp,10);
    wprintf(L"\n|%25d|%25S|%26d|",numeroAluno,nome,totalUC);

}
//Imprimir do Report B
void imprimirReportB(){
    clearScreen();
    FILE * fp = abrirLeituraReportB();
    wchar_t * linha = calloc(_TAMSTRING,sizeof(wchar_t));
    if(!fp){
        wprintf(L"Erro %d: Não foi possivel encontrar o ficheiro a terminar.", _ERR_RESOURCENOTFOUND);
        exit(_ERR_RESOURCENOTFOUND);
    }
    for(int i=0;i<80;i++)
        wprintf(L"-");
    wprintf(L"\n|%25S|%25S|%26S|\n",L"Número de Aluno", L"Nome de Aluno", L"Total de UCs Realizadas");
    for(int i=0;i<80;i++)
        wprintf(L"-");
    while(!feof(fp)){
        fwscanf(fp,L"%l[^\n]\n",linha);
        if(wmemcmp(linha,L"#",1)==0 || wcsncmp(linha,L" ",1)==0)
            continue;
        imprimirLinhaReportB(linha);
    }
    wprintf(L"\n");
    for(int i=0;i<80;i++)
        wprintf(L"-");
    free(linha);
    linha = NULL;
    terminarLeituraReportB(fp);
}

/************************************
 *            Report c              *
 ************************************/

/************************************
 *            Report D              *
 ************************************/