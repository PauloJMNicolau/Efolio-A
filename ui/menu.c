#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include "menu.h"

//Menu principal com as opções possíveis
void menuPrincipal() {
    int opcao;
    
    do {
        wprintf(L"Menu Principal\n");
        wprintf(L"Escolha uma das seguintes opções:\n");
        wprintf(L"1 - Alunos\n");
        wprintf(L"2 - UC's\n");
        wprintf(L"3 - Incrições\n");
        wprintf(L"4 - Propinas\n");
        wprintf(L"5 - Consultas\n");
        wprintf(L"6 - Reports\n");
        wprintf(L"0 - Sair\n");

        wscanf(L"%d", &opcao);

        switch (opcao) {
            case 1:
                menuAlunos(); 
                break;
            case 2:
                menuUCS(); 
                break;
            case 3:
                menuInscricoes(); 
                break;
            case 4:
                menuPropinas(); 
                break;
            case 5:
                menuConsultas();
            case 6:
                menuReports(); 
            case 0:
                break;
            default:
                wprintf(L"Opção inválida!\n");
        }
    } while (opcao != 0);
}

//Submenu para funções relacionadas directamente com alunos
void menuAlunos() {
    int opcao;

    do {
        wprintf(L"1 - Adicionar Aluno\n");
        wprintf(L"2 - Remover Aluno\n");
        wprintf(L"3 - Consultar Aluno\n");
        wprintf(L"4 - Modificar Aluno\n");
        wprintf(L"0 - Menu anterior\n");

        wscanf(L"%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarAluno();
                break;
            case 2:
                removerAluno();
                break;
            case 3:
                consultarAluno();
                break;
            case 4:
                modificarAluno();
                break;
            case 0:
                break;
            default:
                wprintf(L"Opção inválida!\n");
        }
    } while (opcao != 0);
}

//Submenu para funções relacionadas directamente com UCs
void menuUCS() {
    int opcao;

    do {
        wprintf(L"1 - Adicionar UC\n");
        wprintf(L"2 - Remover UC\n");
        wprintf(L"3 - Consultar UC\n");
        wprintf(L"4 - Modificar UC\n");
        wprintf(L"0 - Menu anterior\n");

        wscanf(L"%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarUC();
                break;
            case 2:
                removerUC();
                break;
            case 3:
                consultarUC();
                break;
            case 4:
                modificarUC();
                break;
            case 0:
                break;
            default:
                wprintf(L"Opção inválida!\n");
        }
    } while (opcao != 0);
}

//Submenu para funções relacionadas directamente com incrições
void menuInscricoes() {
    int opcao;

    do {
        wprintf(L"1 - Adicionar Inscrição\n");
        wprintf(L"2 - Remover Inscrição\n");
        wprintf(L"3 - Consultar Inscrição\n");
        wprintf(L"4 - Modificar Inscrição\n");
        wprintf(L"0 - Menu anterior\n");

        wscanf(L"%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarInscricao();
                break;
            case 2:
                removerInscricao();
                break;
            case 3:
                consultarInscricao();
                break;
            case 4:
                modificarInscricao();
                break;
            case 0:
                break;
            default:
                wprintf(L"Opção inválida!\n");
        }
    } while (opcao != 0);
}


//Submenu para funções relacionadas directamente com propinas
void menuPropinas() {
    int opcao;

    do {
        wprintf(L"1 - Calcular Propinas\n");
        wprintf(L"0 - Menu anterior\n");

        wscanf(L"%d", &opcao);

        switch (opcao) {
            case 1:
                calcularPropina();
                break;
            case 0:
                break;
            default:
                wprintf(L"Opção inválida!\n");
        }
    } while (opcao != 0);
}


//Submenu para funções relacionadas directamente com consultas
void menuConsultas() {
    int opcao;

    do {
        wprintf(L"1 - Lista de inscrições por aluno\n");
        wprintf(L"2 - Lista de inscrições por UC\n");
        wprintf(L"0 - Menu anterior\n");

        wscanf(L"%d", &opcao);

        switch (opcao) {
            case 1:
                listaInscAluno();
                break;
            case 2:
                listaInscUC();
                break;
            case 0:
                break;
            default:
                wprintf(L"Opção inválida!\n");
        }
    } while (opcao != 0);
}

//Submenu para funções relacionadas directamente com reports
void menuReports() {
    int opcao;

    do {
        wprintf(L"1 - Número total de ECTS por aluno\n");
        wprintf(L"2 - Alunos para época especial de exames\n");
        wprintf(L"3 - Situações de potencial abandono escolar\n");
        wprintf(L"4 - Número de alunos por ano letivo\n");
        wprintf(L"0 - Menu anterior\n");

        wscanf(L"%d", &opcao);

        switch (opcao) {
            case 1:
                repECTSAluno();
                break;
            case 2:
                repEpocaEspExame();
                break;
            case 3:
                repAbanEscolar();
                break;
            case 4:
                repTotalAlunAnoLet();
                break;
            case 0:
                break;
            default:
                wprintf(L"Opção inválida!\n");
        }
    } while (opcao != 0);
}