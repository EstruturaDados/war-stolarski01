#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char nome[50];
    char cor[20];
    int tropas;
} Territorio;

int main() {
    printf("==== NÍVEL AVENTUREIRO ====\n");

    Territorio *mapa;
    mapa = (Territorio*) calloc(5, sizeof(Territorio));
    if(!mapa) return 1;

    // cadastro inicial
    for(int i=0;i<5;i++){
        printf("\nDigite nome do territorio %d: ", i+1);
        fgets(mapa[i].nome, 50, stdin);
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0';

        printf("Digite a cor do exercito: ");
        fgets(mapa[i].cor, 20, stdin);
        mapa[i].cor[strcspn(mapa[i].cor, "\n")] = '\0';

        printf("Digite o numero de tropas: ");
        scanf("%d", &mapa[i].tropas);
        getchar();
    }

    srand(time(NULL));
    char continuar='s';
    while(continuar=='s'){
        int atacante, defensor;
        printf("\nEscolha atacante (1-5): ");
        scanf("%d", &atacante);
        printf("Escolha defensor (1-5): ");
        scanf("%d", &defensor);

        if(atacante<1 || atacante>5 || defensor<1 || defensor>5 || atacante==defensor){
            printf("Escolha invalida\n");
        } else {
            int dadoAtk = rand()%6+1;
            int dadoDef = rand()%6+1;
            printf("Atacante jogou %d, Defensor jogou %d\n", dadoAtk, dadoDef);

            if(dadoAtk >= dadoDef){
                mapa[defensor-1].tropas--;
                if(mapa[defensor-1].tropas<=0){
                    mapa[defensor-1].tropas=1;
                    strcpy(mapa[defensor-1].cor, mapa[atacante-1].cor);
                    printf("%s conquistou o territorio %s!\n", mapa[atacante-1].nome, mapa[defensor-1].nome);
                } else {
                    printf("Defensor perdeu 1 tropa, restam %d\n", mapa[defensor-1].tropas);
                }
            } else {
                printf("Defensor segurou o ataque!\n");
            }
        }

        printf("\nMapa atual:\n");
        for(int i=0;i<5;i++){
            printf("%d) %s - %s - Tropas: %d\n", i+1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
        }

        printf("\nDeseja continuar atacando? (s/n): ");
        scanf(" %c", &continuar);
    }

    free(mapa);
    return 0;
}
