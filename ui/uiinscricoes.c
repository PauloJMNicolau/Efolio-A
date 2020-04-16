#include "uiinscricoes.h"

//Adicionar uma nova Inscrição
void novaInscricao(SGBD * bd) {
    clearScreen();
    INSCRICAO * novo;
    int numeroUC, numeroAluno;
    wchar_t * anoLetivo;
    
    anoLetivo = calloc(_TAMSTRING, sizeof(wchar_t)); //Na macro defenir um size para datas

    wprintf(L"Preencha os dados da nova Inscrição");
    wprintf(L"\nNúmero da UC: ");
    wscanf(L"%d", &numeroUC);
    wprintf(L"\nNúmero de aluno: ");
    wscanf(L"%s", &numeroAluno);
    wprintf(L"\nAno Letivo: ");
    wscanf(L"%d", &anoLetivo);

    

}