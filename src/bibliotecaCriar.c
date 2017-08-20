#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bibliotecaCriar.h"

char* alocaString(int tam, char* ptrC)
{
    ptrC = malloc((sizeof(char) * tam) + 4);
    if(ptrC == NULL)
    {
        printf("Erro de Alocação ! (função Criar)");
        exit(-1);
    }
    return ptrC;
}
char* pegaNomeArq(char* argv[], char* aux)
{
    int i = 0;
    int j = 0;

    while(argv[3][i] != '\0')
    {
        aux[j] = argv[3][i];
        i++;
        j++;
    }
    j++;

    aux[j] = '\0';

    return aux;

}

char* pegaNomeAtr(char* argv[], char* aux)
{
    int i = 0;
    int j = 0;

    while(argv[3][i] != '.')
        i++;

    while(argv[3][i] != ' ')
    {
        aux[j] = argv[3][i];
        i++;
        j++;
    }

    j++;

    aux[j] = '\0';

    return aux;
}

int pegaTip(char* argv[])
{
    if(argv[5][0] == 'i' || argv[5][0] == 'I')
        return 1;

    else if (argv[5][0] == 'd' || argv[5][0] == 'D')
        return 2;

    else if (argv[5][0] == 'c' || argv[5][0] == 'C' || argv[5][0] == 's' || argv[5][0] == 'S')
        return 3;
}

void insere(int argc, char* argv[])
{
    bloco *b;
    char* aux;
    FILE *stream2, *ArqAux;
    int i;

    b = malloc(sizeof(bloco));
    b->nome_atributo = alocaString(100, b->nome_atributo);
    b->nome_atributo = pegaNomeAtr(argv, b->nome_atributo);

    aux = alocaString(100, aux);
    aux = pegaNomeArq(argv, aux);

    stream2 = fopen(aux, "ab");
    ArqAux = fopen("ArquivoAuxiliar.ori", "ab");
    b->id_campo += 1;
    b->typ = pegaTip(argv);
    //escreve no arquivo o campo
    i = fwrite(b->nome_atributo, sizeof(char), sizeof(b->nome_atributo), stream2 );
    if (i != 1)
    {
        printf("Erro na escrita do atributo");
        exit(-1);
    }

    i = fwrite(&b->typ, sizeof(int), sizeof(b->typ), stream2);
    if (i != 1)
    {
        printf("Erro na escrita do atributo");
        exit(-1);
    }

    i = fwrite(&b->id_campo, sizeof(int), sizeof(b->id_campo), stream2);
    if (i != 1)
    {
        printf("Erro na escrita do atributo");
        exit(-1);
    }

    //esceve no auxiliar
    i = fwrite(&b->nome_atributo, sizeof(char), sizeof(b->nome_atributo), ArqAux);
    if (i != 1)
    {
        printf("Erro na escrita do atributo");
        exit(-1);
    }
    i = fwrite(&b->typ, sizeof(int), sizeof(b->typ), ArqAux);
    if (i != 1)
    {
        printf("Erro na escrita do atributo");
        exit(-1);
    }

    i = fwrite(&b->id_campo, sizeof(int), sizeof(b->id_campo), ArqAux);
    if (i != 1)
    {
        printf("Erro na escrita do atributo");
        exit(-1);
    }

    return;
}

Parametro* alocaParametro(Parametro* ptr)
{
    ptr = malloc(sizeof(Parametro));
    if(ptr == NULL)
    {
        printf("Erro na alocação do Parametro!");
        exit(-1);
    }

    return ptr;
}
