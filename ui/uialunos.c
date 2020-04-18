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
    wprintf(L"Indique os seus dados pessoais: ");
    wprintf(L"\nNumero: ");
    wscanf(L"%d", &numero);
    wprintf(L"\nNome: ");
    wscanf(L"%s", nome);
    wprintf(L"\npais: ");
    wscanf(L"%d", &pais);
    ALUNO * unidade = criaraluno(numero,nome,pais);
    adicionaraluno(unidade,bd->alunos,bd->alunos->elementos);
    free(nome);
}


//Remover aluno
int removerAluno(int pos, LIST_ALUNO *lista);


//consultarAluno
void consultaralunos(SGBD * bd){
    int numero, nome , pais;
    clearScreen();
    for(int i =0; i< 80; i++)
        wprintf(L"-");
    wprintf(L"\n|%8S%50S%10S%10S|\n",L"Numero",L"Nome",L"pais");
    for(int i =0; i< 80; i++)
        wprintf(L"-");
    for(int i=0; i< bd->alunos->elementos; i++){
        UC* temp = obterUC(i, bd->ucs);
        wprintf(L"\n|%8d%50S%10d%10d|",temp->numero, temp->nome, temp->ano, temp->semestre);    wprintf(L"\nNumero: ");
        wscanf(L"%d", &numero);
        wprintf(L"\nNome: ");
        wscanf(L"%s", nome);
        wprintf(L"\npais: ");
        wscanf(L"%d", &pais);
        ALUNO * unidade = criaraluno(numero,nome,pais);
        adicionaraluno(unidade,bd->alunos,bd->alunos->elementos);
        free(nome);
}
    wprintf(L"\n");
    for(int i =0; i< 80; i++)
        wprintf(L"-");
    wprintf(L"\n|%70S%8d|\n",L"Total Alunos",bd->alunos->elementos);
    for(int i =0; i< 80; i++)
        wprintf(L"-");
    wprintf(L"\nPara continuar precione ENTER",bd->alunos->elementos);
    wchar_t tecla = L' ';
    getwchar();
    do{
        wscanf(L"%c", &tecla);
    } while(tecla != L'\n');
}
//modificarAluno
void modificaraluno(SGBD * bd){
    clearScreen();
    int numero, nome , pais;
    wchar_t * nome=calloc(_TAMSTRING, sizeof(wchar_t));
    wprintf(L"Indique os seus dados do aluno que pretende modificar: ");
    wprintf(L"\nNumero: ");
    wscanf(L"%d", &numero);
    wprintf(L"\nNome: ");
    wscanf(L"%s", nome);
    wprintf(L"\npais: ");
    wscanf(L"%d", &pais);
    ALUNO * unidade = alterar_aluno(numero,nome,pais);
    alterar_aluno(unidade,bd->alunos,bd->alunos->elementos);
    free(nome);
}