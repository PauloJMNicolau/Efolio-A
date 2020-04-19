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
    wscanf(L"%S", nome);
    wprintf(L"\nPaís: ");
    wscanf(L"%S", pais);
   
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
    for(int i =0; i< 80; i++)
        wprintf(L"-");
        wprintf(L"\n|%8S%50S%10S%10S|\n",L"Numero",L"Nome",L"País");
    for(int i =0; i< 80; i++)
        wprintf(L"-");
    for(int i=0; i< bd->alunos->elementos; i++){
        ALUNO* temp = obterAluno(i, bd->alunos);
        wprintf(L"\n|%8d%50S%10d%10d|",temp->numero, temp->nome, temp->pais);
    }
    wprintf(L"\n");
    for(int i =0; i< 80; i++)
        wprintf(L"-");
    wprintf(L"\n|%70S%8d|\n",L"Total Disciplinas",bd->alunos->elementos);
    for(int i =0; i< 80; i++)
        wprintf(L"-");
    wprintf(L"\nPara continuar precione ENTER",bd->alunos->elementos);
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
    wprintf(L"\nPara continuar precione ENTER",bd->alunos->elementos);
    wchar_t tecla = L' ';
    getwchar();
    do{
        wscanf(L"%c", &tecla);
    } while(tecla != L'\n');
}

//Imprimir Lista de UC
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

    



