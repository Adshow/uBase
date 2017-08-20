#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bibliotecaCriar.h"
#include "help.h"

void criar(int argc, char* argv[])
{
    Parametro *p;
    FILE *stream1, *ListaArq;
    int i;

    if(argc != 3 || argc != 5)
        help(2);
    
    if(argc == 3)
    { // uBase -criar NOME_ARQUIVO

        p = alocaParametro(p);
        //aloca uma string pro nome do arquivo
        p->nomeDoArquivo = alocaString(100, p->nomeDoArquivo);
        // chama a função que separa o argumento
        p->nomeDoArquivo = pegaNomeArq(argv, p->nomeDoArquivo);

        //cria arquivo como o nome dado na instrução
        stream1 = fopen(p->nomeDoArquivo, "ab");
        //abre a lista de arquivos
        ListaArq = fopen("ListaArquivo.ori", "ab");

        // escreve o campo
        /*i = fwrite(p->nomeDoArquivo, sizeof(char), sizeof(p->nomeDoArquivo), stream1);
        if(i != 1)
            printf("Erro na escrita do nome!");
        */

        //salva o campo no arquivo auxiliar para busca
        i = fwrite(p->nomeDoArquivo, sizeof(char), sizeof(p->nomeDoArquivo), ListaArq);
        if(i != 1)
            printf("Erro na escrita do arquivo aux!");

        p->id_geral += 1;

        //salva no arquivo auxliar o id para busca
        i = fwrite(&p->id_geral, sizeof(int), 1, ListaArq);
        if(i != 1)
            printf("Erro na escrita do id_geral!");

        fclose(stream1);
        fclose(ListaArq);
    }

    if(argc == 5)//uBase -inserir NOME_ARQUIVO.NOME_ATRIBUTO -tipo Inteiro
        insere(argc, argv);


    return;
}