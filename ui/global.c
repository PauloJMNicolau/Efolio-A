#include <stdio.h>
#include <wchar.h>
#include <sys/ioctl.h>	/* ioctl, TIOCGWINSZ */
#include <err.h>	/* err */
#include <fcntl.h>	/* open */
#include <stdio.h>	/* printf */
#include <unistd.h>	/* close */
#include <string.h>


int largTela() {
	struct winsize ws;
    int x, fd;

	fd = open("/dev/tty", O_RDWR);
	if (fd < 0)
		err(1, "/dev/tty");
	
	if (ioctl(fd, TIOCGWINSZ, &ws) < 0)	//Dimensão da tela
	    err(1, "/dev/tty");

	x = ws.ws_col;	//largura da tela em colunas
	
	close(fd);
    return x;
}

void imprimirMeio(char *str) {
	int x, len, cursor;

	x = largTela();
	len = strlen(str);
	cursor = (x-len)/2;
	wprintf(L"\033[%dC%s\n", cursor, str);
}

void cabecalho(char *str) {

    imprimirMeio("Sistema de Gestão de Inscrições");
   	imprimirMeio("     Universidade Aberta       ");
	imprimirMeio(str);
}