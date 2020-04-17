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
    wprintf(L"\nPara continuar precione ENTER",bd->ucs->elementos);
    wchar_t tecla = L' ';
    getwchar();
    do{
        wscanf(L"%c", &tecla);
    } while(tecla != L'\n');
}

//Remover UC
void removerUnidade(SGBD * bd){
    clearScreen();
    imprimirUCS(bd);
    int id = -1;
    do{
        wprintf(L"\nQual o ID da disciplina a remover: ",bd->ucs->elementos);
        wscanf(L"%d",&id);
        if(id < 0|| id > bd->ucs->elementos)
            wprintf(L"\nID de UC inválida\n");
    }while(id < 0|| id > bd->ucs->elementos);
    removerUC(id-1,bd->ucs);
    imprimirUCS(bd);
    wprintf(L"\nPara continuar precione ENTER",bd->ucs->elementos);
    wchar_t tecla = L' ';
    getwchar();
    do{
        wscanf(L"%c", &tecla);
    } while(tecla != L'\n');
}

//Imprimir Lista de UC
void imprimirUCS(SGBD * bd){
    for(int i =0; i< 80; i++)
        wprintf(L"-");
    wprintf(L"\n|%4S|%8S|%45S|%7S|%10S|\n",L"ID",L"Numero",L"Nome",L"Ano",L"Semestre");
    for(int i =0; i< 80; i++)
        wprintf(L"-");
    for(int i=0; i< bd->ucs->elementos; i++){
        UC* temp = obterUC(i, bd->ucs);
        wprintf(L"\n|%4.d|%8d|%45S|%7d|%10d|",i+1, temp->numero, temp->nome, temp->ano, temp->semestre);
    }
    wprintf(L"\n");
    for(int i =0; i< 80; i++)
        wprintf(L"-");
    
}