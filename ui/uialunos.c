#include "uialunos.h"


//Adicionar uma novo aluno
void novoaluno(SGBD * bd){
    clearScreen();
    int numero;
    wchar_t nome , pais;
    int * numero=calloc(_TAMSTRING, sizeof(int));//numero
    if(!numero){
        wprintf(L"Erro %d: Não foi possivel guardar o  numero do aluno",_ERR_READFILE);
        exit(_ERR_READFILE);
    wchar_t * nome=calloc(_TAMSTRING, sizeof(wchar_t));//nome
     if(!nome){
        wprintf(L"Erro %d: Não foi possivel guardar o  nome do aluno",_ERR_READFILE);
        exit(_ERR_READFILE);
    wchar_t * pais=calloc(_TAMSTRING, sizeof(wchar_t));//pais
     if(!numero){
        wprintf(L"Erro %d: Não foi possivel guardar o  pais do aluno",_ERR_READFILE);
        exit(_ERR_READFILE);

    wprintf(L"Indique os seus dados pessoais: ");
    wprintf(L"\nNumero: ");
    wscanf(L"%d", &numero);
    wprintf(L"\nNome: ");
    wscanf(L"%S", nome);
    wprintf(L"\npais: ");
    wscanf(L"%S", &pais);
    ALUNO * lista =criaraluno(numero,nome,pais);
    adicionarAluno(lista,bd->alunos,bd->alunos->elementos);
    free(nome);
    free(numero);
    free(pais);
}

//Remover aluno
void remov_aluno(SGBD * bd){
    clearScreen();
    imprimirlistalunos(bd);
    int numero = -1;
    do{
        wprintf(L"\nQual o numero do aluno a remover: ",bd->alunos->elementos);
        wscanf(L"%d",&numero);
        if(numero < 0|| numero > bd->alunos->elementos)
            wprintf(L"\nNumero de aluno inválido\n");
    }while(numero < 0|| numero > bd->alunos->elementos);
    removerAluno(numero-1,bd->alunos);
    imprimirlistalunos(bd);
    wprintf(L"\nPara continuar precione ENTER",bd->alunos->elementos);
    wchar_t tecla = L' ';
    getwchar();
    do{
        wscanf(L"%c", &tecla);
    } while(tecla != L'\n');
}


//Mostrar Lista de alunos
void mostrarListalunos(SGBD * bd){
    clearScreen();
    for(int i =0; i< 80; i++)
        wprintf(L"-");
        wprintf(L"\n|%8S%50S%10S%10S|\n",L"Numero",L"Nome",L"pais");
    for(int i =0; i< 80; i++)
        wprintf(L"-");
    for(int i=0; i< bd->alunos->elementos; i++){
        ALUNO* temp = obterUC(i, bd->ucs);
        wprintf(L"\n|%8d%50S%10d%10d|",temp->numero, temp->nome, temp->pais);
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

/*consultarAluno
void consultaraluno(SGBD * bd){
    int numero, nome, pais;
    clearScreen();
    for(int i =0; i< 80; i++)
        wprintf(L"-");
        wprintf(L"\n|%8S%50S%10S|\n",L"Numero",L"Nome",L"pais");
    for(int i =0; i< 80; i++)
        wprintf(L"-");
    for(int i=0; i< bd->alunos->elementos; i++){
        ALUNO* temp = obterUC(i, bd->alunos);
        wprintf(L"\n|%8d%50S%10d|",temp->numero, temp->nome, temp->pais);   
        wprintf(L"\nNumero: ");
        wscanf(L"%d", &numero);
        wprintf(L"\nNome: ");
        wscanf(L"%s", nome);
        wprintf(L"\npais: ");
        wscanf(L"%d", &pais);*/


        //ALUNO * lista = criaraluno(numero,nome,pais);
        //adicionaraluno(lista,bd->alunos,bd->alunos->elementos);
        //free(nome);
    }
        wprintf(L"\n");
        for(int i =0; i< 80; i++)
            wprintf(L"-");
        wprintf(L"\n|%70S%10d|\n",L"Total Alunos",bd->alunos->elementos);
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
            wprintf(L"\nNumero de aluno inválido\n");
    }while(numero < 0|| numero > bd->alunos->elementos);
    //Alterar Dados
    ALUNO * lista = obteraluno(numero-1,bd->ucs);
    //Imprimir Dados do aluno a alterar
    imprimiralunos(lista);
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
            wchar_t continuar=0;
            wchar_t continue;
        }
        int n;
        wchar_t s[_TAMSTRING]=L"";
        //Executar opção escolhida
        switch(numero){
            case 0:
                wprintf(L"Novo Numero: ");
                wscanf(L"%d", &n);
                modificarValoresaluno(n,lista->nome,lista->numero,lista->pais,lista);
                break;
            case 1:
                wprintf(L"Novo Nome: ");
                wscanf(L"%S", &s);
                modificarValoresaluno(lista->numero,s,lista->nome,lista->pais,lista);
                break;
            case 2:
                do{
                    wprintf(L"Novo pais: ");
                    wscanf(L"%d", &n);
                }while(n<1 || n>3);
                modificarValoresaluno(lista->numero,lista->nome,n,lista->pais,lista);
                break;
        }
        wprintf(L"Pretende continuar a alterar?\n\t0 - Não\n\t1 - Sim\nOpção: ");
        wscanf(L"%d",&continuar);
    }while(continuar != 0);
    //Imprimir Dados da UC alterados
    imprimirlistalunos(lista);
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
        wprintf(L"\n|%15S|%19S|%46S|\n",L"Numero",L"Nome",L"pais");
    for(int i =0; i< 80; i++)
        wprintf(L"-");
    for(int i=0; i< bd->alunos->elementos; i++){
        ALUNO* temp = obteraluno(i, bd->alunos);
        wprintf(L"\n|%15.d|%19d|%46S|",i+1, temp->numero, temp->nome, temp->pais);
    }
    wprintf(L"\n");
    for(int i =0; i< 80; i++)
        wprintf(L"-");
    
}

void imprimirDadosaluno(ALUNO * lista){
    for(int i =0; i< 80; i++)
        wprintf(L"-");
    wprintf(L"\n|%15S|%19S|%46S|\n",L"Numero",L"Nome",L"pais");
    for(int i =0; i< 80; i++)
        wprintf(L"-");
        wprintf(L"\n|%15d|%19S|%46d|\n",lista->numero,lista->nome, lista->pais);
    for(int i =0; i< 80; i++)
        wprintf(L"-");
}


    



