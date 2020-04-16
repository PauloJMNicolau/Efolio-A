#include "uiucs.h"

//Adicionar uma nova Unidade Curricular
void novaUC(SGBD * bd){
    clearScreen();
    int ano, semestre, numero;
    wchar_t * nome=calloc(_TAMSTRING, sizeof(wchar_t));
    wprintf(L"Preencha os dados da nova Unidade Curricular");
    wprintf(L"\nNumero: ");
    wscanf(L"%d", &numero);
    wprintf(L"\nNome: ");
    wscanf(L"%s", nome);
    wprintf(L"\nAno: ");
    wscanf(L"%d", &ano);
    wprintf(L"\nSemestre: ");
    wscanf(L"%d", &semestre);
    UC * unidade = criarUC(numero,nome,ano,semestre);
    adicionarUC(unidade,bd->ucs,bd->ucs->elementos);
    free(nome);
}

//Mostrar Lista de UCS
void mostrarListaUC(SGBD * bd){
    clearScreen();
    for(int i =0; i< 80; i++)
        wprintf(L"-");
    wprintf(L"\n|%8S%50S%10S%10S|\n",L"Numero",L"Nome",L"Ano",L"Semestre");
    for(int i =0; i< 80; i++)
        wprintf(L"-");
    for(int i=0; i< bd->ucs->elementos; i++){
        UC* temp = obterUC(i, bd->ucs);
        wprintf(L"\n|%8d%50S%10d%10d|",temp->numero, temp->nome, temp->ano, temp->semestre);
    }
    wprintf(L"\n");
    for(int i =0; i< 80; i++)
        wprintf(L"-");
    wprintf(L"\n|%70S%8d|\n",L"Total Disciplinas",bd->ucs->elementos);
    for(int i =0; i< 80; i++)
        wprintf(L"-");
}