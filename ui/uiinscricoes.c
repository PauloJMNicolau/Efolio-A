#include "uiinscricoes.h"

//Adicionar uma nova Inscrição
void novaInscricao(SGBD * bd) {
    INSCRICAO * novo;
    int numeroUC, numeroAluno;
    wchar_t * anoLetivo;    
    clearScreen();
    
    anoLetivo = calloc(_TAMSTRING, sizeof(wchar_t)); //Na macro pode-se definir um size para datas

    wprintf(L"Preencha os dados da nova Inscrição");
    wprintf(L"\nNúmero da UC: ");
    wscanf(L"%d", &numeroUC);
    wprintf(L"\nNúmero de aluno: ");
    wscanf(L"%d", &numeroAluno);
    wprintf(L"\nAno Letivo: ");
    wscanf(L"%s", anoLetivo);

    if (procurarUC(numeroUC, bd->ucs)) {
        novo = criarInscricao(numeroUC, numeroAluno, anoLetivo);
        adicionarInscricao(novo, bd->inscricoes);
    }
    else
        printf("uc não existe");
    
}