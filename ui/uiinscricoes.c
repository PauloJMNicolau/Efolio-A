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
            if(novo != NULL && adicionarInscricao(novo, bd->inscricoes) == _SUCESSO)
                wprintf(L"Incrição Efectuada");
            else
                wprintf(L"Erro na Inscrição");    
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

//Mostrar lista de inscrições por ano letivo
void mostrarListaInscricoes(SGBD * bd){
    clearScreen();
    NO_PASTA * pasta;
    NO * tmp;
    int i, j = 0;
    wchar_t * anoLetivo, tecla = L' ';
    anoLetivo = calloc(_TAMDATAS, sizeof(wchar_t));
    wprintf(L"\nIndique o ano letivo que pretende consultar: ");
    wscanf(L"%ls", anoLetivo);
    pasta = procuraPasta(anoLetivo, bd->inscricoes);
    if (pasta != NULL){
        tmp = pasta->cauda;
        for(i =0; i<80; i++)
            wprintf(L"-");
        wprintf(L"\n|%25S|%25S|%26S|\n",L"Número Aluno",L"Número de UC",L"Ano Letivo");
        for(i =0; i<80; i++)
            wprintf(L"-");
        wprintf(L"\n");
        while (j < pasta->elementos) {
            wprintf(L"|%25d|%25d|%26S|\n", tmp->elemento->numeroAluno, tmp->elemento->numeroUC, tmp->elemento->anoLetivo);
            tmp = tmp->proximo;
            j++;
        }
        for(i =0; i<80; i++)
            wprintf(L"-");
        wprintf(L"\n|%52S%26d|\n", L"Total de Inscrições",pasta->elementos);
        for(i =0; i<80; i++)
            wprintf(L"-");
    }
    else
        wprintf(L"Não existe inscrições para o ano letivo indicado");
    free(anoLetivo);
    wprintf(L"\nPara continuar pressione ENTER");
    getwchar();
    do{
        wscanf(L"%c", &tecla);
    } while(tecla != L'\n');
}

//Remover uma inscrição
void removerInscricao(SGBD * bd){


}
