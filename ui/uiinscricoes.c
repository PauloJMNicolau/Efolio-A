#include "uiinscricoes.h"

//Adicionar uma nova Inscrição
void novaInscricao(SGBD * bd) {
    clearScreen();
    INSCRICAO * novo;
    int numeroUC, numeroAluno;
    wchar_t * anoLetivo;   
    anoLetivo = calloc(_TAMDATAS, sizeof(wchar_t)); 
    wprintf(L"Preencha os dados da nova Inscrição");
    wprintf(L"\nNúmero da UC: ");
    wscanf(L"%d", &numeroUC);
    if (procurarUC(numeroUC, bd->ucs)) {
        wprintf(L"\nNúmero de Aluno: ");
        wscanf(L"%d", &numeroAluno);
        if (procurarAluno(numeroAluno, bd->alunos)) {
            wprintf(L"\nAno Letivo [xxxx/yyyy]: ");
            wscanf(L"%ls", anoLetivo);
            novo = criarInscricao(numeroUC, numeroAluno, anoLetivo);
            if(adicionarInscricao(novo, bd->inscricoes) == _SUCESSO)
                wprintf(L"Incrição Efectuada");
            else
                wprintf(L"Erro na Inscrição");    
        }
        else
            wprintf(L"Número de Aluno inexistente");
    }
    else
        wprintf(L"Unidade Curricular inexistente");
    free(anoLetivo);
    pressioneENTER();
}

//Mostrar lista de inscrições por ano letivo
void mostrarListaInscricoes(SGBD * bd){
    clearScreen();
    NO_PASTA * pasta;
    wchar_t * anoLetivo;
    anoLetivo = calloc(_TAMDATAS, sizeof(wchar_t));
    wprintf(L"\nIndique o ano letivo que pretende consultar: ");
    wscanf(L"%ls", anoLetivo);
    pasta = procuraPasta(anoLetivo, bd->inscricoes);
    if (pasta != NULL)
        imprimirInscricoes(pasta);
    else
        wprintf(L"Não existe inscrições para o ano letivo indicado");
    free(anoLetivo);
    pressioneENTER();
}

//Remover uma inscrição
void eliminarInscricao(SGBD * bd){
    clearScreen();
    INSCRICAO * inscricao;
    int numeroUC, numeroAluno;
    wchar_t * anoLetivo;   
    anoLetivo = calloc(_TAMDATAS, sizeof(wchar_t)); 
    wprintf(L"Preencha os dados da Inscrição que pretende remover");
    wprintf(L"\nNúmero da UC: ");
    wscanf(L"%d", &numeroUC);
    wprintf(L"\nNúmero de Aluno: ");
    wscanf(L"%d", &numeroAluno);
    wprintf(L"\nAno Letivo [xxxx/yyyy]: ");
    wscanf(L"%ls", anoLetivo);
    inscricao = criarInscricao(numeroUC, numeroAluno, anoLetivo);
    if(removerInscricao(inscricao, bd->inscricoes) == _SUCESSO)
        wprintf(L"\nInscrição removida com sucesso\n");
    else
        wprintf(L"\nNão existe inscrição para os dados inseridos");
    free(anoLetivo);
    pressioneENTER(); 
}

//Modificar valores de uma inscrição
void modificarInscricao(SGBD * bd){
    clearScreen();
    NO_PASTA * pasta;
    INSCRICAO * inscricao;
    int id, nA, nU, opcao, continuar, numeroAluno, numeroUC;
    wchar_t * anoLetivo;
    anoLetivo = calloc(_TAMDATAS,sizeof(wchar_t));
    wprintf(L"\nIndique o Ano Letivo que pretende consultar: ");
    wscanf(L"%S", anoLetivo);
    if(bd->inscricoes->pastas){
        pasta = procuraPasta(anoLetivo, bd->inscricoes);
        imprimirInscricoes(pasta);
        wprintf(L"\nIndique o ID da inscrição que pretende modificar: ");
        wscanf(L"%d", &id);
        if(pasta->elementos){
            inscricao = obterInscricao(id-1,pasta);
            do{
                opcao = -1;
                do{
                    wprintf(L"\nQual o dado a alterar?\n\t0 - Número Aluno\n\t1 - Número Unidade Curricular\n\t3 - Cancelar\nOpção: ");
                    wscanf(L"%d",&opcao);
                }while(opcao<0 || opcao>3);
                //Sair do ciclo
                if(opcao==3){
                    continuar =0;
                    continue;
                }
                //Executar opção escolhida
                switch(opcao){
                    case 0:
                        wprintf(L"\nNovo Número de Aluno: ");
                        wscanf(L"%d", &nA);
                        if(procurarAluno(nA,bd->alunos))
                            modificarValorInscricao(nA,nU,inscricao);
                        else
                            wprintf(L"\nNúmero de Aluno inexistente");
                        break;
                    case 1:
                        wprintf(L"\nNova Unidade Curricular: ");
                        wscanf(L"%d", &nU);
                        if(procurarUC(nU,bd->ucs))
                            modificarValorInscricao(nA,nU,inscricao);
                        else
                            wprintf(L"\nNúmero de UC inexistente");
                        break;
                }
                wprintf(L"\nPretende continuar a alterar?\n\t0 - Não\n\t1 - Sim\nOpção: ");
                wscanf(L"%d",&continuar);
            }while(continuar != 0);
            free(anoLetivo);
            }
            else
                wprintf(L"\nNão existe Inscrições neste Ano Letivo");
            
    }
    else
        wprintf(L"\nNão existe Ano Letivos");
    pressioneENTER;
}

//Imprimir dado da inscrição
void imprimirDadoInscricao(INSCRICAO * inscricao){
    int i;
    for(i =0; i<46; i++)
        wprintf(L"-");
    wprintf(L"\n|%23S|%23S|\n",L"Número de Aluno",L"Número de UC");
    for(i =0; i<46; i++)
        wprintf(L"-");
    wprintf(L"\n");
    wprintf(L"|%23d|%23d|\n", inscricao->numeroAluno, inscricao->numeroUC);
    for(i =0; i<46; i++)
        wprintf(L"-");
}

//Imprimir dados da inscrições
void imprimirInscricoes(NO_PASTA * pasta){
    clearScreen();
    NO * tmp;
    int i, j = 0;
    tmp = pasta->cauda;
    for(i =0; i<80; i++)
        wprintf(L"-");
    wprintf(L"\n|%6S|%23S|%23S|%23S|\n",L"ID",L"Número de Aluno",L"Número de UC",L"Ano Letivo");
    for(i =0; i<80; i++)
        wprintf(L"-");
    wprintf(L"\n");
    while (j < pasta->elementos) {
        wprintf(L"|%6d|%23d|%23d|%23S|\n",j+1, tmp->elemento->numeroAluno, tmp->elemento->numeroUC, tmp->elemento->anoLetivo);
        tmp = tmp->proximo;
        j++;
    }
    for(i =0; i<80; i++)
        wprintf(L"-");
    wprintf(L"\n|%52S%26d|\n", L"Total de Inscrições",pasta->elementos);
    for(i =0; i<80; i++)
        wprintf(L"-");
}