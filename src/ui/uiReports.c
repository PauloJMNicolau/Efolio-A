/*
 * Ficheiro que possui todas as funções relacionas com a UI (User Interface) dos Reports
 */

#include "uiReports.h"

/************************************
 *            Report A              *
 ************************************/
//Gerar Report A
void ReportA(SGBD * bd) {
    REP_A * reportA = gerarReportA(bd);
    imprimirReportA(reportA);
    pressioneENTER();
    libertarListaReportA(reportA);
}

/************************************
 *            Report B              *
 ************************************/
//Gerar Report B
void ReportB(SGBD * bd){
    gerarReportB(bd);
    imprimirReportB();
    pressioneENTER();
}

/************************************
 *            Report c              *
 ************************************/
//Gerar Report C
void ReportC(SGBD * bd){
    gerarReportC(bd);
    imprimirReportC();
    pressioneENTER();
}
/************************************
 *            Report D              *
 ************************************/
//Gerar Report D
void ReportD(SGBD * bd){
    gerarReportD(bd);
    imprimirReportD();
    pressioneENTER();
}

