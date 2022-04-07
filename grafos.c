//Júlia da Rocha Junqueira
//19200496

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 20

void menu(void);
int resetar(int tamanho, int grafo[MAX_VERTICES][MAX_VERTICES]);

int main()
{
    int grafo[MAX_VERTICES][MAX_VERTICES];
    int opcao;
    int tamanho = 0;
    int vA, vB;
    int peso;

    char alfabeto[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char simnao[3];

    resetar(MAX_VERTICES, grafo);

    printf("\nOlá!! \n\n");

    do {
        menu();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                if (tamanho == 0) {
                    do{
                        system("clear || cls");
                        printf("\nInsira quantos vértices este grafo irá possuir: (O numero máximo de vertices é 20)\n\n");
                        scanf("%d", &tamanho);
                        printf("\n\tInicializando o grafo..\n\n");

                        resetar(tamanho, grafo);
                    } while (tamanho <= 0 || tamanho > 20);

                } else {
                    printf("\nVocê já inseriu a quantidade de vértices. Deseja resetar o grafo? (S / N)\n\n");
                    scanf("%s", &simnao);

                    if (strcmp(simnao, "s") == 0 || strcmp(simnao, "S") == 0) {
                        printf("\nInsira quantos vértices este grafo irá possuir: (O número máximo de vertices é 20)\n\n");
                        scanf("%d", &tamanho);
                        printf("\n\tReinicializando o grafo..\n\n");

                        resetar(tamanho, grafo);

                    } else {
                        printf("Quantidade de vertices não alterada.\n");
                    }
                }

            break;

            case 2:
                system("clear || cls");
                printf("\nPara inserir uma aresta, informe qual é seu primeiro e segundo vertice: \n\n");

                do {
                    printf("Inserir o primeiro vértice: ");
                    scanf("%d", &vA);
                    vA--;

                    printf("Inserir o segundo vértice: ");
                    scanf("%d", &vB);
                    vB--;

                } while ((vA < 0 || vA >= tamanho) && (vB < 0 || vB >= tamanho));

                do {
                    if (grafo[vA][vB] == 0) {
                        printf("\nInsira qual será o peso desta aresta: \n\n");
                        scanf("%d", &peso);

                    } else {
                        printf("\nHá uma aresta existente entre os vertices %c e %c. \n", alfabeto[vA], alfabeto[vB]);
                        printf("\nDeseja alterar o peso desta aresta? (S / N) \n");
                        scanf("%s", &simnao);

                        if (strcmp(simnao, "s") == 0 || strcmp(simnao, "S") == 0) {
                            printf("\nInsira qual será o novo peso desta aresta: \n\n");
                            scanf("%d", &peso);
                        }
                    }
                } while (peso < 0);

                grafo[vA][vB] = peso;
                grafo[vB][vA] = peso;

                break;

            case 3:
                system("clear || cls");
                printf("\n\tMatriz de Adjacência:");
                printf("\n  ");

                for (int i = 0; i < tamanho; i++) {
                    printf("%c ", alfabeto[i]);
                }

                printf("\n");

                for (int i = 0; i < tamanho; i++) {
                    printf("%c ", alfabeto[i]);

                    for (int j = 0; j < tamanho; j++) {
                        printf("%d ", grafo[i][j]);
                    }

                    printf("\n");
                }

            break;

            case 4:
                system("clear || cls");
                printf("\nTodas as arestas do grafo foram zeradas.\n\n");
                
                resetar(tamanho, grafo);
            break;

            case 5:
                printf("\nAté mais!\n\n");
            break;

            default:
            break;
        }
    } while (opcao != 5);
}

void menu() {
    printf("\n\t\tMenu: \n\n");
    printf("\t1) Inserir vértices");
    printf("\n\t2) Inserir uma aresta");
    printf("\n\t3) Listar o grafo");
    printf("\n\t4) Resetar o grafo");
    printf("\n\t5) Sair\n");
    printf("\nEscreva o número da opção escolhida: ");
}

int resetar(int tamanho, int grafo[MAX_VERTICES][MAX_VERTICES]) {
    int i, j;

    for (i = 0; i < tamanho; i++) {
        for (j = 0; j < tamanho; j++) {
            grafo[i][j] = 0;
        }
    }

    return 0;
}