#include "uialunos.h"
#ifndef _FICHEIROS_

//Adicionar uma novo aluno
//Remover aluno
//consultarAluno
//modificarAluno


//Adicionar uma novo aluno
void novoaluno(SGBD * bd){
    clearScreen();
    int numero, nome , pais;
    wchar_t * nome=calloc(_TAMSTRING, sizeof(wchar_t));
    wprintf(L"Indique os seus dados pessoais: ");
    wprintf(L"\nNumero: ");
    wscanf(L"%d", &numero);
    wprintf(L"\nNome: ");
    wscanf(L"%s", nome);
    wprintf(L"\npais: ");
    wscanf(L"%d", &pais);
    ALUNO * unidade = criaraluno(numero,nome,pais);
    adicionaraluno(unidade,bd->alunos,bd->alunos->elementos);
    free(nome);
}

//Remover aluno
int removerAluno(int pos, LIST_ALUNO *lista);

//consultarAluno
void consultaralunos(SGBD * bd){
    int numero, nome, pais;
    clearScreen();
    for(int i =0; i< 80; i++)
        wprintf(L"-");
        wprintf(L"\n|%8S%50S%10S%10S|\n",L"Numero",L"Nome",L"pais");
    for(int i =0; i< 80; i++)
        wprintf(L"-");
    for(int i=0; i< bd->alunos->elementos; i++){
        ALUNO* temp = obterUC(i, bd->alunos);
        wprintf(L"\n|%8d%50S%10d%10d|",temp->numero, temp->nome, temp->pais);   
        wprintf(L"\nNumero: ");
        wscanf(L"%d", &numero);
        wprintf(L"\nNome: ");
        wscanf(L"%s", nome);
        wprintf(L"\npais: ");
        wscanf(L"%d", &pais);
        ALUNO * unidade = criaraluno(numero,nome,pais);
        adicionaraluno(unidade,bd->alunos,bd->alunos->elementos);
        free(nome);
    }
        wprintf(L"\n");
        for(int i =0; i< 80; i++)
            wprintf(L"-");
        wprintf(L"\n|%70S%8d|\n",L"Total Alunos",bd->alunos->elementos);
        for(int i =0; i< 80; i++)
            wprintf(L"-");
        wprintf(L"\nPara continuar precione ENTER",bd->alunos->elementos);
        wchar_t tecla = L' ';
        getwchar();
        do{
            wscanf(L"%c", &tecla);
        } while(tecla != L'\n');
}
//modificarAluno
void modificaraluno(SGBD * bd){
    clearScreen();
    imprimirlistalunos(bd);
    int numero = -1;
    do{
        wprintf(L"\nQual o Numero do aluno a modificar: ",bd->alunos->elementos);
        wscanf(L"%d",&numero);
        if(numero < 0|| numero > bd->alunos->elementos)
            wprintf(L"\nID de aluno inválido\n");
    }while(numero < 0|| numero > bd->alunos->elementos);
    //Alterar Dados
    ALUNO * unidade = obteraluno(numero-1,bd->ucs);
    //Imprimir Dados da UC a alterar
    imprimiralunos(unidade);
    //Imprimir opções
    int continuar =1;
    do{
        numero = -1;
        do{
            wprintf(L"\nQual o dado a alterar?\n\t0 - Numero\n\t1 - Nome\n\t2 - Ano\n\t3 - Semestre\n\t4 - Cancelar\nOpção: ");
            wscanf(L"%d",&numero);
        }while(numero<0 || numero >4);
        //Sair do ciclo
        if(numero==4){
            continuar =0;
            continue;
        }
        int n;
        wchar_t s[_TAMSTRING]=L"";
        //Executar opção escolhida
        switch(numero){
            case 0:
                wprintf(L"Novo Numero: ");
                wscanf(L"%d", &n);
                modificarValoresaluno(n,unidade->nome,unidade->numero,unidade->pais,unidade);
                break;
            case 1:
                wprintf(L"Novo Nome: ");
                wscanf(L"%S", &s);
                modificarValoresaluno(unidade->numero,s,unidade->nome,unidade->pais,unidade);
                break;
            case 2:
                do{
                    wprintf(L"Novo pais: ");
                    wscanf(L"%d", &n);
                }while(n<1 || n>3);
                modificarValoresaluno(unidade->numero,unidade->nome,n,unidade->pais,unidade);
                break;
        }
        wprintf(L"Pretende continuar a alterar?\n\t0 - Não\n\t1 - Sim\nOpção: ");
        wscanf(L"%d",&continuar);
    }while(continuar != 0);
    //Imprimir Dados da UC alterados
    imprimirlistalunos(unidade);
    //Esperar que utilizador diga para continuar
    wprintf(L"\nPara continuar precione ENTER",bd->alunos->elementos);
    wchar_t tecla = L' ';
    getwchar();
    do{
        wscanf(L"%c", &tecla);
    } while(tecla != L'\n');
}

//Imprimir Lista de UC
void imprimirlistalunos(SGBD * bd){
    for(int i =0; i< 80; i++)
        wprintf(L"-");
        wprintf(L"\n|%4S|%8S|%45S|%7S|%10S|\n",L"Numero",L"Nome",L"pais");
    for(int i =0; i< 80; i++)
        wprintf(L"-");
    for(int i=0; i< bd->ucs->elementos; i++){
        UC* temp = obterUC(i, bd->ucs);
        wprintf(L"\n|%4.d|%8d|%45S|%7d|%10d|",i+1, temp->numero, temp->nome, temp->ano, temp->semestre);
    }
    wprintf(L"\n");
    for(int i =0; i< 80; i++)
        wprintf(L"-");
    
}

void imprimirDadosUC(UC * unidade){
    for(int i =0; i< 80; i++)
        wprintf(L"-");
    wprintf(L"\n|%8S|%50S|%7S|%10S|\n",L"Numero",L"Nome",L"Ano",L"Semestre");
    for(int i =0; i< 80; i++)
        wprintf(L"-");
    wprintf(L"\n|%8d|%50S|%7d|%10d|\n",unidade->numero,unidade->nome,unidade->ano,unidade->semestre);
    for(int i =0; i< 80; i++)
        wprintf(L"-");
}


    
    #endif
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Adicionar uma nova Unidade Curricular
/*void novaUC(SGBD * bd){
    clearScreen();
    int ano, semestre, numero;
    wchar_t * nome=calloc(_TAMSTRING, sizeof(wchar_t));
    wprintf(L"Preencha os dados da nova Unidade Curricular");
    wprintf(L"\nNumero: ");
    wscanf(L"%d", &numero);
    wprintf(L"\nNome: ");
    wscanf(L"%S", nome);
    wprintf(L"\nAno: ");
    wscanf(L"%d", &ano);
    wprintf(L"\nSemestre: ");
    wscanf(L"%d", &semestre);
    UC * unidade = criarUC(numero,nome,ano,semestre);
    adicionarUC(unidade,bd->ucs,bd->ucs->elementos);
    free(nome);
}

//Mostrar Lista de UCS
void mostrarListaUC(SGBD * bd){
    clearScreen();
    for(int i =0; i< 80; i++)
        wprintf(L"-");
    wprintf(L"\n|%8S%50S%10S%10S|\n",L"Numero",L"Nome",L"Ano",L"Semestre");
    for(int i =0; i< 80; i++)
        wprintf(L"-");
    for(int i=0; i< bd->ucs->elementos; i++){
        UC* temp = obterUC(i, bd->ucs);
        wprintf(L"\n|%8d%50S%10d%10d|",temp->numero, temp->nome, temp->ano, temp->semestre);
    }
    wprintf(L"\n");
    for(int i =0; i< 80; i++)
        wprintf(L"-");
    wprintf(L"\n|%70S%8d|\n",L"Total Disciplinas",bd->ucs->elementos);
    for(int i =0; i< 80; i++)
        wprintf(L"-");
    wprintf(L"\nPara continuar precione ENTER",bd->ucs->elementos);
    wchar_t tecla = L' ';
    getwchar();
    do{
        wscanf(L"%c", &tecla);
    } while(tecla != L'\n');
}

//Remover UC
void removerUnidade(SGBD * bd){
    clearScreen();
    imprimirUCS(bd);
    int id = -1;
    do{
        wprintf(L"\nQual o ID da disciplina a remover: ",bd->ucs->elementos);
        wscanf(L"%d",&id);
        if(id < 0|| id > bd->ucs->elementos)
            wprintf(L"\nID de UC inválida\n");
    }while(id < 0|| id > bd->ucs->elementos);
    removerUC(id-1,bd->ucs);
    imprimirUCS(bd);
    wprintf(L"\nPara continuar precione ENTER",bd->ucs->elementos);
    wchar_t tecla = L' ';
    getwchar();
    do{
        wscanf(L"%c", &tecla);
    } while(tecla != L'\n');
}

//Alterar Unidade
void modificarUnidade(SGBD * bd){
    clearScreen();
    imprimirUCS(bd);
    int id = -1;
    do{
        wprintf(L"\nQual o ID da disciplina a modificar: ",bd->ucs->elementos);
        wscanf(L"%d",&id);
        if(id < 0|| id > bd->ucs->elementos)
            wprintf(L"\nID de UC inválida\n");
    }while(id < 0|| id > bd->ucs->elementos);
    //Alterar Dados
    UC * unidade = obterUC(id-1,bd->ucs);
    //Imprimir Dados da UC a alterar
    imprimirDadosUC(unidade);
    //Imprimir opções
    int continuar =1;
    do{
        id = -1;
        do{
            wprintf(L"\nQual o dado a alterar?\n\t0 - Numero\n\t1 - Nome\n\t2 - Ano\n\t3 - Semestre\n\t4 - Cancelar\nOpção: ");
            wscanf(L"%d",&id);
        }while(id<0 || id >4);
        //Sair do ciclo
        if(id==4){
            continuar =0;
            continue;
        }
        int n;
        wchar_t s[_TAMSTRING]=L"";
        //Executar opção escolhida
        switch(id){
            case 0:
                wprintf(L"Novo Numero: ");
                wscanf(L"%d", &n);
                modificarValoresUC(n,unidade->nome,unidade->ano,unidade->semestre,unidade);
                break;
            case 1:
                wprintf(L"Novo Nome: ");
                wscanf(L"%S", &s);
                modificarValoresUC(unidade->numero,s,unidade->ano,unidade->semestre,unidade);
                break;
            case 2:
                do{
                    wprintf(L"Novo Ano: ");
                    wscanf(L"%d", &n);
                }while(n<1 || n>3);
                modificarValoresUC(unidade->numero,unidade->nome,n,unidade->semestre,unidade);
                break;
            case 3:
                do{
                    wprintf(L"Novo Semestre: ");
                    wscanf(L"%d", &n);
                }while(n<1 || n>2); 
                modificarValoresUC(unidade->numero,unidade->nome,unidade->ano,n,unidade); 
                break;
        }
        wprintf(L"Pretende continuar a alterar?\n\t0 - Não\n\t1 - Sim\nOpção: ");
        wscanf(L"%d",&continuar);
    }while(continuar != 0);
    //Imprimir Dados da UC alterados
    imprimirDadosUC(unidade);
    //Esperar que utilizador diga para continuar
    wprintf(L"\nPara continuar precione ENTER",bd->ucs->elementos);
    wchar_t tecla = L' ';
    getwchar();
    do{
        wscanf(L"%c", &tecla);
    } while(tecla != L'\n');
}

//Imprimir Lista de UC
void imprimirUCS(SGBD * bd){
    for(int i =0; i< 80; i++)
        wprintf(L"-");
    wprintf(L"\n|%4S|%8S|%45S|%7S|%10S|\n",L"ID",L"Numero",L"Nome",L"Ano",L"Semestre");
    for(int i =0; i< 80; i++)
        wprintf(L"-");
    for(int i=0; i< bd->ucs->elementos; i++){
        UC* temp = obterUC(i, bd->ucs);
        wprintf(L"\n|%4.d|%8d|%45S|%7d|%10d|",i+1, temp->numero, temp->nome, temp->ano, temp->semestre);
    }
    wprintf(L"\n");
    for(int i =0; i< 80; i++)
        wprintf(L"-");
    
}

void imprimirDadosUC(UC * unidade){
    for(int i =0; i< 80; i++)
        wprintf(L"-");
    wprintf(L"\n|%8S|%50S|%7S|%10S|\n",L"Numero",L"Nome",L"Ano",L"Semestre");
    for(int i =0; i< 80; i++)
        wprintf(L"-");
    wprintf(L"\n|%8d|%50S|%7d|%10d|\n",unidade->numero,unidade->nome,unidade->ano,unidade->semestre);
    for(int i =0; i< 80; i++)
        wprintf(L"-");
}
*/