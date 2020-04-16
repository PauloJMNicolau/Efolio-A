
#include "menu.h"


//Menu principal com as opções possíveis
void menuPrincipal(SGBD * bd) {
    int opcao;
    
    do {
        clearScreen();
        cabecalho("Menu Principal");
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
                menuAlunos(bd); 
                break;
            case 2:
                menuUCS(bd); 
                break;
            case 3:
                menuInscricoes(bd); 
                break;
            case 4:
                menuPropinas(bd); 
                break;
            case 5:
                menuConsultas(bd);
                break;
            case 6:
<<<<<<< HEAD
                menuReports(); 
                break;
=======
                menuReports(bd); 
>>>>>>> 90d96be405c2db3c0803a93039495ed2a37404eb
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

        switch (opcao) {/*
            case 1:
                //adicionarAluno();
                break;
            case 2:
                //removerAluno();
                break;
            case 3:
                //consultarAluno();
                break;
            case 4:
<<<<<<< HEAD
                modificarAluno();
                break;*/
=======
                //modificarAluno();
                break;
>>>>>>> 90d96be405c2db3c0803a93039495ed2a37404eb
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
        wprintf(L"5 - Listagem de UC\n");
        wprintf(L"0 - Menu anterior\n");

        wscanf(L"%d", &opcao);

        switch (opcao) {/*
           case 1:
                novaUC(bd);
                break;
            case 2:
                //removerUC();
                break;
            case 3:
                //consultarUC();
                break;
            case 4:
<<<<<<< HEAD
                modificarUC();
                break;*/
=======
                //modificarUC();
                break;
            case 5:
                mostrarListaUC(bd);
                break;
>>>>>>> 90d96be405c2db3c0803a93039495ed2a37404eb
            case 0:
                break;
            default: {
                wprintf(L"Opção inválida!\n");
                sleep(1);
            }
        }
    } while (opcao != 0);
}

//Submenu para funções relacionadas directamente com incrições
void menuInscricoes(SGBD * bd) {
    int opcao;
    
    do {
        clearScreen();
        cabecalho("Menu Inscrições");
        wprintf(L"Escolha uma das seguintes opções:\n");
        wprintf(L"1 - Adicionar Inscrição\n");
        wprintf(L"2 - Remover Inscrição\n");
        wprintf(L"3 - Consultar Inscrição\n");
        wprintf(L"4 - Modificar Inscrição\n");
        wprintf(L"0 - Menu anterior\n");

        wscanf(L"%d", &opcao);

        switch (opcao) {/*
            case 1:
                //adicionarInscricao();
                break;
            case 2:
                //removerInscricao();
                break;
            case 3:
                //consultarInscricao();
                break;
            case 4:
<<<<<<< HEAD
                modificarInscricao();
                break;*/
=======
                //modificarInscricao();
                break;
>>>>>>> 90d96be405c2db3c0803a93039495ed2a37404eb
            case 0:
                break;
            default: {
                wprintf(L"Opção inválida!\n");
                sleep(1);
            }
        }
    } while (opcao != 0);
}


//Submenu para funções relacionadas directamente com propinas
void menuPropinas(SGBD* bd) {
    int opcao;

    do {
        clearScreen();
        cabecalho("Menu Propinas");
        wprintf(L"Escolha uma das seguintes opções:\n");
        wprintf(L"1 - Calcular Propinas\n");
        wprintf(L"0 - Menu anterior\n");

        wscanf(L"%d", &opcao);

        switch (opcao) {/*
            case 1:
<<<<<<< HEAD
                calcularPropina();
                break;*/
=======
                //calcularPropina();
                break;
>>>>>>> 90d96be405c2db3c0803a93039495ed2a37404eb
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

        switch (opcao) {/*
            case 1:
                //listaInscAluno();
                break;
            case 2:
<<<<<<< HEAD
                listaInscUC();
                break;*/
=======
                //listaInscUC();
                break;
>>>>>>> 90d96be405c2db3c0803a93039495ed2a37404eb
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

        switch (opcao) {/*
            case 1:
                //repECTSAluno();
                break;
            case 2:
                //repEpocaEspExame();
                break;
            case 3:
                //repAbanEscolar();
                break;
            case 4:
<<<<<<< HEAD
                repTotalAlunAnoLet();
                break;*/
=======
                //repTotalAlunAnoLet();
                break;
>>>>>>> 90d96be405c2db3c0803a93039495ed2a37404eb
            case 0:
                break;
            default: {
                wprintf(L"Opção inválida!\n");
                sleep(1);
            }
        }
    } while (opcao != 0);
}