#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include "menu.h"

//Menu com lista de opções possíveis
void menuPrincipal()
{
    int opcao;
    do
    {
        wprintf(L"Menu Principal\n");
        wprintf(L"Escolha uma das seguintes opções:\n");
        wprintf(L"1-Incrições\n");
        wprintf(L"2-Anular incrições\n");
        wprintf(L"3-Listagem de inscrições\n");
        wprintf(L"4-Calcular propinas\n");
        wprintf(L"5-Gravar\n");
        wprintf(L"0-Sair\n");
        wprintf(L"Opção escolhida: ");
        wscanf(L"%d\n", &opcao);

        switch (opcao)
        {
            case 1:
                inscricaoAluno(); //Incricão aluno numa UC
                break;
            case 2:
                anularInscricao(); //Anular inscrição aluno numa UC
                break;
            case 3:
                listaInscricao(); //Listagem de inscrições
                break;
            case 4:
                calculoPropinas(); //Valor de propinas
                break;
            case 5:
                gravarDados(); //Gravar dados antes de sair
            case 0:
                break;
            default:
                wprintf(L"Opção inválida!\n");
        }
    } while (opcao != 0);
}