/*
 * Ficheiro que possui todas as funções relacionas com a UI (User Interface) das propinas
 */
#include "uiPropinas.h"

//Função para calcular valor da propina
void uiCalcularPropinas(SGBD * bd) {
    clearScreen();
    int numeroAluno;
    ALUNO * aluno;
    wprintf(L"\nIndique o número de aluno que deseja calcular a propina: ");
    wscanf(L"%d", &numeroAluno);
    aluno = obterAlunoNum(numeroAluno, bd->alunos);
    if(aluno){
        calcularPropinas(bd,aluno);
        int opcao = condicaoPropina(aluno,bd->inscricoes);
        if(opcao == 1)
            wprintf(L"\nValor propina aluno residente com taxa de inscrição 1º ano: %d €\n", aluno->propina);
        else if(opcao == 2)
            wprintf(L"\nValor propina aluno Residente: %d €\n", aluno->propina);
        else if(opcao == 3)
            wprintf(L"\nValor propina aluno estrangeiro com taxa de inscrição 1º ano: %d €\n", aluno->propina);  
        else if(opcao == 4)
            wprintf(L"\nValor propina aluno estrangeiro: %d €\n", aluno->propina);  
    }
    else
        wprintf(L"\nNúmero de Aluno inexistente\n");  
    pressioneENTER();
}