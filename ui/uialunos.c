#include "uialunos.h"

//Adicionar um novo aluno
// falta acrescentar as restantes memorias
void novoAluno(SGBD * bd){
    clearScreen();
    int  numero;
    wchar_t *nome, *pais;

    nome=calloc(_TAMSTRING, sizeof(wchar_t));
    if(!nome){
        wprintf(L"Erro %d: Não foi possivel alocar a memória",_ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);

    }
    pais=calloc(_TAMSTRING, sizeof(wchar_t));
    if(!pais){
        wprintf(L"Erro %d: Não foi possivel alocar a memória",_ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    wprintf(L"Preencha os dados do aluno");
    wprintf(L"\nNumero: ");
    wscanf(L"%d", &numero);
    
    wprintf(L"\nNome: ");
    
    wscanf(L"\n%l[^\n]", nome);
   
    wprintf(L"\nPaís: ");
    wscanf(L"\n%l[^\n]", pais);

    ALUNO * pessoa = criarAluno(numero,nome,pais);
    adicionarAluno(pessoa,bd->alunos,bd->alunos->elementos);
    free(nome);
    free(pais);
}

//Mostrar Lista de  alunos
void mostrarAlunos(SGBD * bd){
    int  numero;
    wchar_t nome, pais;
    clearScreen();
    for(int i =0; i< 100; i++)
        wprintf(L"-");
        wprintf(L"\n|%8S%50S%40S|\n",L"Numero",L"Nome",L"País");
    for(int i =0; i< 100; i++)
        wprintf(L"-");
    for(int i=0; i< bd->alunos->elementos; i++){
        ALUNO* temp = obterAluno(i, bd->alunos);
        wprintf(L"\n|%8d%50S%40S|",temp->numero, temp->nome, temp->pais);
    }
    wprintf(L"\n");
    for(int i =0; i< 100; i++)
        wprintf(L"-");
    wprintf(L"\n|%90S%8d|\n",L"Total Alunos",bd->alunos->elementos);
    for(int i =0; i< 100; i++)
        wprintf(L"-");
    wprintf(L"\nPara continuar precione ENTER");
    wchar_t tecla = L' ';
    getwchar();
    do{
        wscanf(L"%c", &tecla);
    } while(tecla != L'\n');
}

//Remover UC
void remov_aluno(SGBD * bd){
    int  numero;
    wchar_t nome, pais;
    clearScreen();
    imprimirAlunos(bd);
    int id = -1;
    do{
        wprintf(L"\nQual o numero do aluno a remover: ",bd->alunos->elementos);
        wscanf(L"%d",&id);
        if(id < 0|| id > bd->alunos->elementos)
            wprintf(L"\nnumero de aluno inválido\n");
    }while(id < 0|| id > bd->alunos->elementos);
    removerAluno(id-1,bd->alunos);
    imprimirAlunos(bd);
    wprintf(L"\nPara continuar precione ENTER");
    wchar_t tecla = L' ';
    getwchar();
    do{
        wscanf(L"%c", &tecla);
    } while(tecla != L'\n');
}

// Imprimir lista de alunos
void imprimirAlunos(SGBD * bd){
    for(int i =0; i< 80; i++)
        wprintf(L"-");
    wprintf(L"\n|%4S|%8S|%45S|%7S|%10S|\n",L"ID",L"Numero",L"Nome",L"País");
    for(int i =0; i< 80; i++)
        wprintf(L"-");
    for(int i=0; i< bd->alunos->elementos; i++){
        ALUNO* temp = obterAluno(i, bd->alunos);
        wprintf(L"\n|%4.d|%8d|%45S|%7d|%10d|",i+1, temp->numero, temp->nome, temp->pais);
    }
    wprintf(L"\n");
    for(int i =0; i< 80; i++)
        wprintf(L"-");
    
}


//imprimir dados dos alunos
void imprimirdadosaluno(ALUNO * elem){
    for(int i =0; i< 80; i++)
        wprintf(L"-");
        wprintf(L"\n|%8S|%50S|%7S|%10S|\n",L"Numero",L"Nome",L"País");
    for(int i =0; i< 80; i++)
        wprintf(L"-");
        wprintf(L"\n|%8d|%50S|%7d|%10d|\n",elem->numero,elem->nome,elem->pais);
    for(int i =0; i< 80; i++)
        wprintf(L"-");
}

//Alterar Aluno
void modificaraALuno(SGBD * bd){
    clearScreen();
    imprimirAlunos(bd);
    int id = -1;
    do{
        wprintf(L"\nQual o ID do aluno a modificar: ",bd->alunos->elementos);
        wscanf(L"%d",&id);
        if(id < 0|| id > bd->alunos->elementos)
            wprintf(L"\nID de aluno inválida\n");
    }while(id < 0|| id > bd->alunos->elementos);
    //Alterar Dados
    ALUNO * elem = obterAluno(id-1,bd->alunos);
    //Imprimir Dados dos alunos a alterar
    imprimirdadosaluno(elem);
    //Imprimir opções
    int continuar =1;
    do{
        id = -1;
        do{
            wprintf(L"\nQual o dado a alterar?\n\t0 - Numero\n\t1 - Nome\n\t2 - Pais\n\t3\n\t4 - Cancelar\nOpção: ");
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
                modificarValoresAluno(n,elem->nome,elem->pais,elem);
                break;
            case 1:
                wprintf(L"Novo Nome: ");
                wscanf(L"%S", &s);
                modificarValoresAluno(elem->numero,s,elem->pais,elem);
                break;
            case 2:
                do{
                    wprintf(L"Novo País: ");
                    wscanf(L"%S", &s);
                }while(s<1 || s>3);
                modificarValoresAluno(elem->numero,elem->nome,s,elem);
                break;
        }
        wprintf(L"Pretende continuar a alterar?\n\t0 - Não\n\t1 - Sim\nOpção: ");
        wscanf(L"%d",&continuar);
    }while(continuar != 0);
    //Imprimir Dados do aluno alterados
    imprimirdadosaluno(elem);
    //Esperar que utilizador diga para continuar
    wprintf(L"\nPara continuar precione ENTER",bd->alunos->elementos);
    wchar_t tecla = L' ';
    getwchar();
    do{
        wscanf(L"%c", &tecla);
    } while(tecla != L'\n');
}

