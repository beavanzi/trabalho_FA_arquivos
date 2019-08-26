/* Acadêmicos:  Beatriz Avanzi Ecli             RA: 108612
                Pedro Henrique Melo             RA: 


*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cad_bibli
{
    char autor[50];
    char titulo[50];
    int codigo;
    int situacao;
};

void cadastro(struct cad_bibli *l, int *cont)
{
    char r;

    system("CLS");
    printf("\n--- CADASTRO ---\n\n");

    (*cont)++;

    fflush(stdin);
    setbuf(stdin,NULL);

    printf("Titulo:\n");
    fgets(l[*cont].titulo, 50, stdin);
    fflush(stdin);
    setbuf(stdin,NULL);

    printf("\nAutor:\n");
    printf("\nObs: Apenas em letras minusculas.\n");
    fgets(l[*cont].autor, 50, stdin);
    fflush(stdin);
    setbuf(stdin,NULL);

    l[*cont].codigo=(*cont)+1;
    l[*cont].situacao=0;

    printf("\n\nLivro adicionado.\nAperte enter ou qualquer tecla seguida por enter para retornar ao menu.\n");
    fflush(stdin);
    setbuf(stdin,NULL);

    scanf("%c", &r);
    system("CLS");

}

void remocao(struct cad_bibli *l, int *cont)
{
    int i, j, aux, cod;
    char r;

    system("CLS");
    printf("\n--- REMOCAO ---\n\n");
    fflush(stdin);
    printf("Qual o codigo do livro a ser removido?\n");
    scanf("%d", &cod);

    if (*cont>=0){
        for (i=0; i<=*cont; i++)
        {
            if(l[i].codigo == cod){
                aux=i;
                for (j = aux; j < *cont; j++)
                {
                    l[j] = l[j+1];
                    l[j].codigo=l[j+1].codigo-1;  //serve para atualizar o codigo dos livros após um ser removido, para não dar problema com o cadastro de novos livros depois
                }

                (*cont)--;
            }
        }
    }
    printf("\n\nLivro removido.\nAperte enter ou qualquer tecla seguida por enter para retornar ao menu.\n");
    fflush(stdin);
    setbuf(stdin,NULL);
    scanf("%c", &r);
    system("CLS");
}

void listagem(struct cad_bibli *l, int *cont)
{
     int i;
     char r;

     system("CLS");
     printf("\n--- LISTAGEM ---\n\n");
     for(i = 0; i <= *cont; i++)
     {
         printf("\tTitulo: %s\n\tAutor: %s\n\tCodigo de registro: %d\n", l[i].titulo, l[i].autor, l[i].codigo);
         if (l[i].situacao == 0){
            printf("\tSituacao: Disponivel\n\n\n");
         }
            else if (l[i].situacao == 1){
                printf("\tSituacao: Indisponivel\n\n\n");
            }
     }

     printf("\n\nAperte enter ou qualquer tecla seguida por enter para retornar ao menu.\n");
     fflush(stdin);
     setbuf(stdin,NULL);
     scanf("%c",&r);
     system("CLS");
}

 void consulta(struct cad_bibli *l, int *cont)
 {
    int i, aux, resp, flag=0;
    char r, autor[50];

    system("CLS");
    printf("\n--- CONSULTA ---\n\n");
    printf("\nDeseja consultar pelo codigo ou pelo nome do autor?\n");
    printf("\nDigite:\n1- Codigo.\n2- Autor\n");
    scanf("%d", &resp);
    switch(resp){
    case 1:
        system("CLS");
        printf("\nInsira o codigo do livro a ser consultado:\n\n");
        scanf("%d", &aux);
        for(i=0; i <= *cont; i++)
        {
            if(aux == l[i].codigo)
            {
                flag=1;
                printf("\tTitulo: %s\n\tAutor: %s\n\tCodigo de registro: %d\n", l[i].titulo, l[i].autor, l[i].codigo);
                if (l[i].situacao == 0)
                {
                    printf("\tSituacao: Disponivel\n\n\n");
                }
                    else if (l[i].situacao == 1)
                    {
                        printf("\tSituacao: Indisponivel\n\n\n");
                    }
            }
        }
        if (!flag){
            printf("Codigo inexistente.\n");
        }
        printf("\n\nAperte enter ou qualquer tecla seguida por enter para retornar ao menu.\n");
        fflush(stdin);
        setbuf(stdin,NULL);
        scanf("%c", &r);
        system("CLS");
    break;

    case 2:
        system("CLS");
        printf("\nInsira o nome do autor apenas em letras minusculas: \n\n");
        fflush(stdin);
        setbuf(stdin,NULL);
        fgets(autor, 50, stdin);
        for(i=0; i <= *cont; i++)
        {
            if(strcmp(autor, l[i].autor) == 0)
            {
                printf("\tTitulo: %s\n\tAutor: %s\n\tCodigo de registro: %d\n", l[i].titulo, l[i].autor, l[i].codigo);
                if (l[i].situacao == 0)
                {
                    printf("\n\tSituacao: Disponivel\n\n\n");
                }
                    else if (l[i].situacao == 1)
                    {
                        printf("\n\tSituacao: Indisponivel\n\n\n");
                    }
            }
        }
        if (!flag){
            printf("Autor inexistente.\n");
        }
        printf("\n\nAperte enter ou qualquer tecla seguida por enter para retornar ao menu.\n");
        fflush(stdin);
        setbuf(stdin,NULL);
        scanf("%c", &r);
        system("CLS");
    break;

    default:
        system("CLS");
        printf("\nOpcao invalida.\n");
        printf("\n\nAperte enter ou qualquer tecla seguida por enter para retornar ao menu.\n");
        fflush(stdin);
        setbuf(stdin,NULL);
        scanf("%c", &r);
        system("CLS");
    break;
    }
 }
 void atualizacao(struct cad_bibli *l, int *cont)
 {
     int cod, i;
     char r;

     system("CLS");
     printf("\n--- ATUALIZACAO DE EMPRESTIMO ---\n\n");
     printf("Codigo do livro: \n");
     scanf("%d", &cod);

     for (i=0; i <= *cont; i++)
     {
         if (l[i].codigo == cod){
            printf("Situacao?\n\t0- Disponivel\n\t1- Indisponivel\n");
            scanf("%d", &l[i].situacao);
         }
     }

     printf("\n\nAperte enter ou qualquer tecla seguida por enter para retornar ao menu.\n");
     fflush(stdin);
     scanf("%c", &r);
     system("CLS");

 }

void arquivo_abrir(struct cad_bibli *l, int *cont){
    int i;
    char lixo;
    FILE *fp;
    fp = fopen("trabalho_p3.txt", "r+");

    if (fp == NULL){
        fp = fopen("trabalho_p3.txt", "w+");
    }
        fscanf(fp, "%d", cont);
        for(i=0; i<=*cont; i++){
            fscanf(fp, "%d", &l[i].codigo);
            fscanf(fp, "%c", &lixo); //Para tirar o espaçamento \n do arquivo de texto que é salvo depois que o arquivo é aberto pela primeira vez e depois salvo novamente.
            fgets(l[i].titulo, 50, fp);
            fgets(l[i].autor, 50, fp);
            fscanf(fp, "%d", &l[i].situacao);
        }

}

 void arquivo_salvar(struct cad_bibli *l, int *cont){
    int i;
    FILE *fp; 
    fp = fopen("trabalho_p3.txt", "w+");

    fprintf(fp, "%d\n", *cont); //Serve para armazenar a última posição salva do vetor de struct.
    for(i=0; i<=*cont; i++){
        fprintf(fp, "%d\n", l[i].codigo);
        fprintf(fp, "%s", l[i].titulo);
        fprintf(fp, "%s", l[i].autor);
        fprintf(fp, "%d\n", l[i].situacao);
    }
    fclose(fp);

int main()
{
    int cont = -1, i, resp;

    struct cad_bibli livro[10000];

    arquivo_abrir(livro, &cont);

    printf("\n\n1- Acessar menu.\n0- Sair.\n\n");
    scanf("%d", &resp);

    if (resp == 1)
    {
        system("CLS");
        while(resp != 0)
        {
            printf("\n---- MENU ----\n\n");
            resp = -1;
            printf("\n1- Cadastro\n2- Remocao\n3- Listagem\n4- Consulta\n5- Atualizacao de emprestimo\n0- Sair\n");
            fflush(stdin);
            setbuf(stdin,NULL);
            scanf("%d", &resp);

            if ((resp == 1) || (resp == 2) || (resp == 3) || (resp == 4) || (resp == 5) || (resp == 0))
            {
                switch(resp){
                case 1:
                    cadastro(livro, &cont);
                break;
                case 2:
                    remocao(livro, &cont);
                break;
                case 3:
                    listagem(livro, &cont);
                break;
                case 4:
                    consulta(livro, &cont);
                break;
                case 5:
                    atualizacao(livro, &cont);
                break;
                default:
                    printf("\nProcesso finalizado.\n");
                    arquivo_salvar(livro, &cont);
                break;
                }
            }
                else{
                    printf("Erro.\n");
                    system("PAUSE");
                    getchar();
                }
        }
    }

    return 0;
}