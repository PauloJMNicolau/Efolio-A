#include "ficheiros.h"
#include "macro.h"

/* **********************
 *  Ficheiros de Texto  *
 * **********************/

//Ler ficheiro de UC
void lerUCTexto(LIST_UC * lista){
    FILE * fp = fopen("dadosUC.txt","r");
    if(!fp){
        wprintf("Erro %d: Não foi possivel abrir o ficheiro",_ERR_READFILE);
        exit(_ERR_READFILE);
    }
    wchar_t * linha = calloc(_TAMSTRING,sizeof(wchar_t));
    if(!linha){
        wprintf("Erro %d: Não foi possivel alocar memoria para a linha",_ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    while(!feof(fp)){
        fwscanf(fp,"%s\n",&linha);
        if(wcsncmp(linha,L"#",1)==0 || wcsncmp(linha," ",wcslen(linha))==0)
            continue;
        processarLinhaUC(linha,lista);
    }

    fclose(fp);
}

//Processar Linha de Texto do ficheiro de UC
void processarLinhaUC(wchar_t * linha, LIST_UC * lista){
    wchar_t * temp;
    wcstok(linha, L"\t", temp);
    while(temp != NULL){
        wprintf("%s", temp);
        wcstok(NULL, L"\t", temp);
    }
}