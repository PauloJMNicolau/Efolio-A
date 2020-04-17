#include "uiinscricoes.h"

//Adicionar uma nova Inscrição
void novaInscricao(SGBD * bd) {
    clearScreen();
    INSCRICAO * novo;
    int numeroUC, numeroAluno;
    wchar_t * anoLetivo, tecla = L' ';   
    anoLetivo = calloc(_TAMDATAS, sizeof(wchar_t)); 
    wprintf(L"Preencha os dados da nova Inscrição");
    wprintf(L"\nNúmero da UC: ");
    wscanf(L"%d", &numeroUC);
    if (procurarUC(numeroUC, bd->ucs)) {
        wprintf(L"\nNúmero de aluno: ");
        wscanf(L"%d", &numeroAluno);
        if (procurarAluno(numeroAluno, bd->alunos)) {
            wprintf(L"\nAno Letivo [xxxx/yyyy]: ");
            wscanf(L"%ls", anoLetivo);
            novo = criarInscricao(numeroUC, numeroAluno, anoLetivo);
            adicionarInscricao(novo, bd->inscricoes);
        }
        else
            wprintf(L"Número de aluno inexistente");
    }
    else
        wprintf(L"Unidade Curricular inexistente");
    free(anoLetivo);
    wprintf(L"\nPara continuar pressione ENTER");
    getwchar();
    do{
        wscanf(L"%c", &tecla);
    } while(tecla != L'\n');
}

//Mostrar lista de inscrições
void mostrarListaInscricoes(){


}

