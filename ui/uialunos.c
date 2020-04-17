#include "uialunos.h"


//Adicionar uma novo aluno
//Remover aluno
//consultarAluno
//modificarAluno


//Adicionar uma novo aluno
void novoaluno(SGBD * bd){
    clearScreen();
    int numero, nome , pais;
    wchar_t * nome=calloc(_TAMSTRING, sizeof(wchar_t));
    wprintf(L"Indique o seu nome: ");
    wprintf(L"\nNumero: ");
    wscanf(L"%d", &numero);
    wprintf(L"\nNome: ");
    wscanf(L"%s", nome);
    wprintf(L"\npais: ");
    wscanf(L"%d", &pais);
    aluno * unidade = criaraluno(numero,nome,pais);
    adicionaraluno(unidade,bd->ucs,bd->ucs->elementos);
    free(nome);
}

//Mostrar Lista de UCS
/*void mostrarListalunos(SGBD * bd){
    clearScreen();
    for(int i =0; i< 80; i++)
        wprintf(L"-");
    wprintf(L"\n|%8S%50S%10S%10S|\n",L"Numero",L"Nome",L"pais");
    for(int i =0; i< 80; i++)
        wprintf(L"-");
    for(int i=0; i< bd->ucs->elementos; i++){
        UC* temp = obterUC(i, bd->ucs);
        wprintf(L"\n|%8d%50S%10d%10d|",temp->numero, temp->nome, temp->ano, temp->semestre);    wprintf(L"\nNumero: ");
    wscanf(L"%d", &numero);
    wprintf(L"\nNome: ");
    wscanf(L"%s", nome);
    wprintf(L"\npais: ");
    wscanf(L"%d", &pais);
    Aluno * unidade = criaraluno(numero,nome,pais);
    adicionaraluno(unidade,bd->ucs,bd->ucs->elementos);
    free(nome);
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
}*/