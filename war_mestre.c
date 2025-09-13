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
    printf("==== NÍVEL MESTRE ====\n");

    Territorio *mapa;
    mapa = (Territorio*) calloc(5, sizeof(Territorio));
    if(!mapa) return 1;

    // inicialização automática (simples, sem pedir pro usuário)
    strcpy(mapa[0].nome, "Territorio A"); strcpy(mapa[0].cor,"Vermelho"); mapa[0].tropas=3;
    strcpy(mapa[1].nome, "Territorio B"); strcpy(mapa[1].cor,"Verde"); mapa[1].tropas=4;
    strcpy(mapa[2].nome, "Territorio C"); strcpy(mapa[2].cor,"Azul"); mapa[2].tropas=5;
    strcpy(mapa[3].nome, "Territorio D"); strcpy(mapa[3].cor,"Amarelo"); mapa[3].tropas=2;
    strcpy(mapa[4].nome, "Territorio E"); strcpy(mapa[4].cor,"Verde"); mapa[4].tropas=6;

    srand(time(NULL));
    int missao = rand()%2; // 0 destruir verde, 1 conquistar 3
    int venceu = 0, opcao;

    do {
        printf("\nMenu: 1-Atacar  2-Verificar Missao  0-Sair\n");
        scanf("%d", &opcao);

        if(opcao==1){
            int atk, def;
            printf("Escolha atacante: ");
            scanf("%d", &atk);
            printf("Escolha defensor: ");
            scanf("%d", &def);
            if(atk>=1 && atk<=5 && def>=1 && def<=5 && atk!=def){
                int d1=rand()%6+1, d2=rand()%6+1;
                if(d1>=d2){
                    mapa[def-1].tropas--;
                    if(mapa[def-1].tropas<=0){
                        mapa[def-1].tropas=1;
                        strcpy(mapa[def-1].cor, mapa[atk-1].cor);
                    }
                }
                printf("Ataque feito (%d vs %d)\n", d1, d2);
            }
        } else if(opcao==2){
            if(missao==0){
                printf("Missao: destruir exercito Verde\n");
                int temVerde=0;
                for(int i=0;i<5;i++){
                    if(strcmp(mapa[i].cor,"Verde")==0){ temVerde=1; break; }
                }
                if(!temVerde){ venceu=1; }
            } else {
                printf("Missao: conquistar 3 territorios\n");
                char minhaCor[20]; strcpy(minhaCor,mapa[0].cor);
                int cont=0;
                for(int i=0;i<5;i++){
                    if(strcmp(mapa[i].cor,minhaCor)==0) cont++;
                }
                if(cont>=3){ venceu=1; }
            }
            if(venceu) printf(">>> VOCE CUMPRIU A MISSAO! <<<\n");
            else printf("Ainda nao cumpriu.\n");
        }
    } while(opcao!=0 && !venceu);

    free(mapa);
    return 0;
}
