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

/************************************
 *            Report c              *
 ************************************/

/************************************
 *            Report D              *
 ************************************/

