/*
 * Ficheiro que possui todas as funções principais do UI (User Interface)
 */
#include "ui.h"

//Menu principal com as opções possíveis
void menuPrincipal(SGBD * bd) {
    int opcao;
    do {
        clearScreen();
        cabecalho("Menu Principal");
        wprintf(L"Escolha uma das seguintes opções:\n");
        wprintf(L"1 - Inscrever\n");
        wprintf(L"2 - Anular\n");
        wprintf(L"3 - Listagem de Inscrições\n");
        wprintf(L"4 - Calcular Propinas de um aluno\n");
        wprintf(L"5 - Gravar\n");
        wprintf(L"6 - Gerar Reports\n");
        wprintf(L"7 - Funcionalidades Extra\n");
        wprintf(L"0 - Sair\n");
        wscanf(L"%d", &opcao);
        //Verifica Opção selecionada
        switch (opcao) {
            case 1:
                uiAdicionarNovaInscricao(bd); break;
            case 2:
                uiRemoverInscricao(bd); break;
            case 3:
                menuConsultas(bd); break;
            case 4:
                uiCalcularPropinas(bd);break;
            case 5:
                gravarDados(bd);break;
            case 6:
                menuReports(bd);break;
            case 7:
                menuExtra(bd); break;
            case 0:
                break;
            default: 
                wprintf(L"Opção inválida!\n");
                sleep(1);
        }
    } while (opcao != 0);
}

//Menu com funcionalidades extra
void menuExtra(SGBD * bd) {
    int opcao;
    do {
        clearScreen();
        cabecalho("Menu Extra");
        wprintf(L"Escolha uma das seguintes opções:\n");
        wprintf(L"1 - Gerir Alunos\n");
        wprintf(L"2 - Gerir UC's\n");
        wprintf(L"3 - Gerir Incrições\n");
        wprintf(L"0 - Sair\n");
        wscanf(L"%d", &opcao);
        //Verifica Opção selecionada
        switch (opcao) {
            case 1:
                menuAlunos(bd); break;
            case 2:
                menuUCS(bd); break;
            case 3:
                menuInscricoes(bd); break;
            case 0:
                break;
            default: {
                wprintf(L"Opção inválida!\n");
                sleep(1);
            }
        }
    } while (opcao != 0);
}

//Submenu para funções relacionadas directamente com alunos
void menuAlunos(SGBD * bd) {
    int opcao;
    do {
        clearScreen();
        cabecalho("Menu Alunos"); 
        wprintf(L"Escolha uma das seguintes opções:\n");
        wprintf(L"1 - Adicionar Aluno\n");
        wprintf(L"2 - Remover Aluno\n");
        wprintf(L"3 - Consultar Aluno\n");
        wprintf(L"4 - Modificar Aluno\n");
        wprintf(L"0 - Menu anterior\n");
        wscanf(L"%d", &opcao);
        switch (opcao) {
            case 1:
                uiAdicionarNovoAluno(bd); break;
            case 2:
                uiRemoverAluno(bd); break;
            case 3:
                uiImprimirListaAlunos(bd); break;
            case 4:
                uiAlterarAluno(bd); break;
            case 0:
                break;
            default: {
                wprintf(L"Opção inválida!\n");
                sleep(1);
            }
        }
    } while (opcao != 0);
}

//Submenu para funções relacionadas directamente com UCs
void menuUCS(SGBD * bd) {
    int opcao;
    do {
        clearScreen();
        cabecalho("Menu UC's");
        wprintf(L"Escolha uma das seguintes opções:\n");
        wprintf(L"1 - Adicionar UC\n");
        wprintf(L"2 - Remover UC\n");
        wprintf(L"3 - Consultar UC\n");
        wprintf(L"4 - Modificar UC\n");
        wprintf(L"0 - Menu anterior\n");
        wscanf(L"%d", &opcao);
        //Verifica opção selecionada
        switch (opcao) {
           case 1:
                uiAdicionarNovaUC(bd); break;
            case 2:
                uiRemoverUnidade(bd); break;
            case 3:
                uiImprimirListaUC(bd); break;
            case 4:
                uiAlterarUnidade(bd); break;
            case 0:
                break;
            default: {
                wprintf(L"Opção inválida!\n");
                sleep(1);
            }
        }
    } while (opcao <0 || opcao >4);
}

//Submenu para funções relacionadas directamente com Inscriçoes
void menuInscricoes(SGBD * bd) {
    int opcao;
    do {
        clearScreen();
        cabecalho("Menu Inscrições");
        wprintf(L"Escolha uma das seguintes opções:\n");
        wprintf(L"1 - Adicionar Inscrição\n");
        wprintf(L"2 - Remover Inscrição\n");
        wprintf(L"3 - Consultar Inscrições\n");
        wprintf(L"4 - Modificar Inscrição\n");
        wprintf(L"0 - Menu anterior\n");
        wscanf(L"%d", &opcao);
        //Verificar opção selecionada
        switch (opcao) {
            case 1:
                uiAdicionarNovaInscricao(bd); break;
            case 2:
                uiRemoverInscricao(bd); break;
            case 3:
                uiImprimirListaInscricoes(bd); break;
            case 4:
                uiAlterarInscricao(bd); break;
            case 0:
                break;
            default: {
                wprintf(L"Opção inválida!\n");
                sleep(1);
            }
        }
    } while (opcao != 0);
}

//Submenu para funções relacionadas directamente com consultas
void menuConsultas(SGBD * bd) {
    int opcao;
    do {
        clearScreen();
        cabecalho("Menu Consultas");
        wprintf(L"Escolha uma das seguintes opções:\n");
        wprintf(L"1 - Lista de inscrições por aluno\n");
        wprintf(L"2 - Lista de inscrições por UC\n");
        wprintf(L"0 - Menu anterior\n");
        wscanf(L"%d", &opcao);
        //Verifica opção selecionada
        switch (opcao) {
            case 1:
                //listaInscAluno();
                break;
            case 2:
                //listaInscUC();
                break;
            case 0:
                break;
            default: {
                wprintf(L"Opção inválida!\n");
                sleep(1);
            }
        }
    } while (opcao != 0);
}

//Submenu para funções relacionadas directamente com reports
void menuReports(SGBD * bd) {
    int opcao;
    do {
        clearScreen();
        cabecalho("Menu Reports");
        wprintf(L"Escolha uma das seguintes opções:\n");        
        wprintf(L"1 - Número total de ECTS por aluno\n");
        wprintf(L"2 - Alunos para época especial de exames\n");
        wprintf(L"3 - Situações de potencial abandono escolar\n");
        wprintf(L"4 - Número de alunos por ano letivo\n");
        wprintf(L"0 - Menu anterior\n");
        wscanf(L"%d", &opcao);
        //Verifica opção selecionada
        switch (opcao) {
            case 1:
                gerarReportA(bd); break;
            case 2:
                gerarReportB(bd); break;
            case 3:
                //repAbanEscolar(); break;
            case 4:
                //repTotalAlunAnoLet(); break;
            case 0:
                break;
            default: {
                wprintf(L"Opção inválida!\n");
                sleep(1);
            }
        }
    } while (opcao != 0);
}
