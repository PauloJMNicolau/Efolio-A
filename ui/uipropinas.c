#include "uipropinas.h"

//Função para calcular valor da propina
void calcularPropinas(SGBD * bd) {
    clearScreen();
    int i, opcao=0, propina=0, numeroAluno,ects=0;
    NO * tmp;
    ALUNO * aluno;
    wprintf(L"\nIndique o número de aluno que deseja calcular a propina: ");
    wscanf(L"%d", &numeroAluno);
    aluno = procurarAluno(numeroAluno, bd->alunos);
    if(aluno!=NULL && bd->inscricoes->pastas > 0 && bd->inscricoes->cauda->elementos > 0){
    tmp = bd->inscricoes->cauda->cauda;
    opcao = condicaoPropina(aluno, bd->inscricoes);
    for (i=0; i < bd->inscricoes->cauda->elementos; i++){
        if (tmp->elemento->numeroAluno == numeroAluno)
            ects += tmp->elemento->ects;
        tmp = tmp->proximo;
    }
    propina = calculo(ects, opcao);
    aluno->propina = propina;
    }
    else
        wprintf(L"\nNúmero de Aluno inexistente ou Ano Letivo sem inscrições\n");
    if(opcao == 1)
        wprintf(L"\nValor propina aluno residente com taxa de inscrição 1º ano: %d €\n", aluno->propina);
    else if(opcao == 2)
        wprintf(L"\nValor propina aluno Residente: %d €\n", aluno->propina);
    else if(opcao == 3)
        wprintf(L"\nValor propina aluno estrangeiro com taxa de inscrição 1º ano: %d €\n", aluno->propina);  
    else if(opcao == 4)
            wprintf(L"\nValor propina aluno estrangeiro: %d €\n", aluno->propina);    
    pressioneENTER();
}

//Cálculo da propina mediante condicão do estudante
int calculo(int ects, int opcao) {
    int propina;
    if(opcao == 1)          //Residente 1º ano
        propina = 80 + 15 * ects;
    else if(opcao == 2)     //Residente não 1º ano
        propina = 15 * ects;
    else if(opcao == 3)     //Estrangeiro 1º ano
        propina = 80 + 15 * 1.2 * ects;
    else if (opcao == 4)    //Estrangeiro não 1º ano
        propina = 15 * 1.2 * ects;
    return propina;
}

//Verifica estatuto de residente do estudante e se é 1º inscrição
int condicaoPropina(ALUNO * aluno, LISTA_PASTA * inscricao) {
    int opcao;
    if(wcscmp(L"Portugal",aluno->pais) == 0)
        opcao = 1;
    else
        opcao = 3;
    opcao += verificaInsAnoAnterior(aluno->numero, inscricao);
    return opcao;
}
