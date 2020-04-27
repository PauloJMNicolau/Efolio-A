/********************************************
*                                           *
* Ferramentas de Desenvolvimento Utilizadas *
*                                           *
*********************************************/

/* IDE */
    - VSCode - Visual Studio Code

/* Versionamento */
    - Git - Utilização de Repositório na plataforma GitHub para alojar o código

/* Sistema Operativo */
    - Linux (Preferencial)

/* Validação de erros */
    - Valgrind - Permite verificar as falhas de memória que o programa possui


/************************************************
*                                               *
*   Arquitatura de Software e Desenvolvimento   *
*                                               *
************************************************/

/* Código */

Todo o código desenvolvido foi testado em sistemas operativo baseado em kernel linux.
Foi tentado que o desenvolvimento fosse compativel com outros sistemas operativos (SO).
Sempre que possivel foi utilizado código padrão da linguagem C.
Procuro-se dar preferência a padrões de desenvolvimento e bibliotecas mais recentes e seguras, desde que estas não interfiram com a compatibilidade entre SO.
Tentou-se que as funções fossem o mais pequenas possiveis, realizando apenas uma tarefa por função.
Tentou-se utilizar padrões da linguagem C11, ou superior, desde que não interfira na compatibilidade com o C99. (caso das declarações de variaveis ao longo da função)
Foi tentado que o código tivesse uma consistencia identica, na declaração e nomeação de variáveis e funções, bem como as estruturas.

/* Software */

Foi tentado segui uma lógica de programação identica ao padrão de desenvolvimento MVC (Model - View - Controler)
O Programa encontra-se separado em diversos modulos, onde cada ficheiro .c possui o respetivo ficheiro .h
Os ficheiros (modulos) encontram-se separados por duas pastas 
    SGBD - Motor da AF2 e Efolio A
    UI - Interface do programa
Tentou-se que todo o código de impressão no ecrã e leitura do teclado ficasse nos ficheiros da pasta UI.
Deu-se preferência ao UTF (Unicode)

/* Desenvolvimento */

Foi utilizado o git como ferramenta de versionamento do código
Foram definidas Macros no ficheiro macro.h que foram utilizadas ao longo do código


/************************************
*                                   *
*       Outras Informações          *
*                                   *
************************************/

Dado que foi utilizado o VSCode como IDE de desenvolvimento, a compilação foi realizada de forma automatizada através de configuração de tarefas

O comando de compilação manual é o seguinte:

        gcc -g3 -Wall main.c /ui/ui.c /ui/uiUcs.c /ui/uiAlunos.c /ui/uiInscricoes.c ui/uiPropinas.c /ui/uiReports.c /ui/global.c 
                /sgbd/sgbd.c /sgbd/alunos.c /src/sgbd/ucs.c /sgbd/inscricoes.c /sgbd/ficheiros.c /sgbd/reports.c -o /dist/efolio

    ou de forma abreviada:

        gcc -g3 -Wall main.c /ui/*c /sgbd/*c -o efolio