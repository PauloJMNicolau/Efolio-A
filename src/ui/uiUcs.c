/*
 * Ficheiro que possui todas as funções da UI (User Interface) de Unidades Curriculares
 */
#include "uiUcs.h"

//Adicionar uma nova Unidade Curricular
void uiAdicionarNovaUC(SGBD * bd){
    clearScreen();
    int ano, semestre, numero, ects;
    wchar_t * nome=calloc(_TAMSTRING, sizeof(wchar_t));
    if(!nome){
        wprintf(L"Erro %d: Não foi possivel alocar a memória",_ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    wprintf(L"Preencha os dados da nova Unidade Curricular");
    wprintf(L"\nNumero: ");
    wscanf(L"%d", &numero);
    wprintf(L"\nNome: ");
    wscanf(L"\n%l[^\n]", nome);
    do{
        wprintf(L"\nAno: ");
        wscanf(L"%d", &ano);
    } while(ano <=0 || ano >3);
    do{
        wprintf(L"\nSemestre: ");
        wscanf(L"%d", &semestre);
    } while(semestre <1 || semestre >2);
    wprintf(L"\nECTS: ");
    wscanf(L"%d", &ects);
    UC * unidade = criarUC(numero,nome,ano,semestre,ects);
    int res = adicionarUC(unidade,bd->ucs,bd->ucs->elementos);
    if(res == _SUCESSO)
        wprintf(L"Unidade Curricular Adicionada\n");
    else
        wprintf(L"Não foi possivel adicionar a Unidade Curricular\n");
    free(nome);
    pressioneENTER();
}

//Mostrar Lista de UCS
void uiImprimirListaUC(SGBD * bd){
    clearScreen();
    for(int i =0; i< 90; i++)
        wprintf(L"-");
    wprintf(L"\n|%8S%50S%10S%10S%10S|\n",L"Numero",L"Nome",L"Ano",L"Semestre",L"ECTS");
    for(int i =0; i< 90; i++)
        wprintf(L"-");
    for(int i=0; i< bd->ucs->elementos; i++){
        UC* temp = obterUCPos(i, bd->ucs);
        wprintf(L"\n|%8d%50S%10d%10d%10d|",temp->numero, temp->nome, temp->ano, temp->semestre,temp->ects);
    }
    wprintf(L"\n");
    for(int i =0; i< 90; i++)
        wprintf(L"-");
    wprintf(L"\n|%80S%8d|\n",L"Total Disciplinas",bd->ucs->elementos);
    for(int i =0; i< 90; i++)
        wprintf(L"-");
    pressioneENTER();
}

//Remover UC
void uiRemoverUnidade(SGBD * bd){
    clearScreen();
    uiImprimirUCS(bd);
    int id = -1;
    do{
        wprintf(L"\nQual o ID da disciplina a remover: ",bd->ucs->elementos);
        wscanf(L"%d",&id);
        if(id < 0|| id > bd->ucs->elementos)
            wprintf(L"\nID de UC inválida\n");
    }while(id < 0|| id > bd->ucs->elementos);
    clearScreen();
    int res = removerUC(id-1,bd->ucs);
    if(res == _SUCESSO)
        wprintf(L"Unidade Curricular Removida\n");
    else
        wprintf(L"Não foi possivel remover a Unidade Curricular\n");
    uiImprimirUCS(bd);
    pressioneENTER();
}

//Imprimir Lista de UC com ID
void uiImprimirUCS(SGBD * bd){
    for(int i =0; i< 90; i++)
        wprintf(L"-");
    wprintf(L"\n|%4S|%8S|%45S|%7S|%10S|%7S|\n",L"ID",L"Numero",L"Nome",L"Ano",L"Semestre",L"ECTS");
    for(int i =0; i< 90; i++)
        wprintf(L"-");
    for(int i=0; i< bd->ucs->elementos; i++){
        UC* temp = obterUCPos(i, bd->ucs);
        wprintf(L"\n|%4.d|%8d|%45S|%7d|%10d|%7d|",i+1, temp->numero, temp->nome, temp->ano, temp->semestre, temp->ects);
    }
    wprintf(L"\n");
    for(int i =0; i< 90; i++)
        wprintf(L"-");
}

//Imprimir Dados da UC sem ID
void uiImprimirDadosUC(UC * unidade){
    for(int i =0; i< 90; i++)
        wprintf(L"-");
    wprintf(L"\n|%8S|%50S|%7S|%10S|%7S|\n",L"Numero",L"Nome",L"Ano",L"Semestre",L"ECTS");
    for(int i =0; i< 90; i++)
        wprintf(L"-");
    wprintf(L"\n|%8d|%50S|%7d|%10d|%7d|\n",unidade->numero,unidade->nome,unidade->ano,unidade->semestre, unidade->ects);
    for(int i =0; i< 90; i++)
        wprintf(L"-");
}

//Alterar Unidade
void uiAlterarUnidade(SGBD * bd){
    clearScreen();
    uiImprimirUCS(bd);
    int id = -1;
    do{
        wprintf(L"\nQual o ID da Unidade Curricular a modificar: ");
        wscanf(L"%d",&id);
        if(id < 0|| id > bd->ucs->elementos)
            wprintf(L"\nID de UC inválida\n");
    }while(id < 0|| id > bd->ucs->elementos);
    //Alterar Dados
    UC * unidade = obterUCPos(id-1,bd->ucs);
    //Imprimir Dados da UC a alterar
    uiImprimirDadosUC(unidade);
    //Imprimir opções
    int continuar =1;
    do{
        id = -1;
        do{
            wprintf(L"\nQual o dado a alterar?\n\t0 - Numero\n\t1 - Nome\n\t2 - Ano\n\t3 - Semestre\n\t4 - ECTS\n\t5 - Cancelar\nOpção: ");
            wscanf(L"%d",&id);
            if(id<0 || id>5)
                wprintf(L"ID inválido");
        }while(id<0 || id>5);
        int n;
        wchar_t s[_TAMSTRING]=L"";
        //Executar opção escolhida
        switch(id){
            case 0:
                wprintf(L"Novo Numero: ");
                wscanf(L"%d", &n);
                modificarValoresUC(n,unidade->nome,unidade->ano,unidade->semestre,unidade->ects,unidade);
                break;
            case 1:
                wprintf(L"Novo Nome: ");
                wscanf(L"\n%l[^\n]", s);
                modificarValoresUC(unidade->numero,s,unidade->ano,unidade->semestre,unidade->ects,unidade);
                break;
            case 2:
                do{
                    wprintf(L"Novo Ano: ");
                    wscanf(L"%d", &n);
                    if(n<1 || n>3)
                        wprintf(L"Ano inválido\n");
                }while(n<1 || n>3);
                modificarValoresUC(unidade->numero,unidade->nome,n,unidade->semestre,unidade->ects,unidade);
                break;
            case 3:
                do{
                    wprintf(L"Novo Semestre: ");
                    wscanf(L"%d", &n);
                    if(n<1 || n>2)
                        wprintf(L"Semestre inválido\n");
                }while(n<1 || n>2); 
                modificarValoresUC(unidade->numero,unidade->nome,unidade->ano,n,unidade->ects,unidade); 
                break;
            case 4:
                do{
                    wprintf(L"Novo ECTS: ");
                    wscanf(L"%d", &n);
                    if(n<=0)
                        wprintf(L"ECTS inválido");
                }while(n<=0); 
                modificarValoresUC(unidade->numero,unidade->nome,unidade->ano,unidade->semestre,n,unidade); 
                break;
            case 5:
                continuar =0; continue;
        }
        wprintf(L"Pretende continuar a alterar?\n\t0 - Não\n\t1 - Sim\nOpção: ");
        wscanf(L"%d",&continuar);
    }while(continuar != 0);
    //Imprimir Dados da UC alterados
    uiImprimirDadosUC(unidade);
    //Esperar que utilizador diga para continuar
    pressioneENTER();
}