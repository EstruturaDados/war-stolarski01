#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    char cor[20];
    int tropas;
} Territorio;

int main() {
    Territorio mapa[5]; // vetor fixo
    int i;

    printf("==== NÍVEL NOVATO ====\n");

    for(i=0;i<5;i++){
        printf("\nDigite nome do territorio %d: ", i+1);
        fgets(mapa[i].nome, 50, stdin);
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0';

        printf("Digite a cor do exercito: ");
        fgets(mapa[i].cor, 20, stdin);
        mapa[i].cor[strcspn(mapa[i].cor, "\n")] = '\0';

        printf("Digite o numero de tropas: ");
        scanf("%d", &mapa[i].tropas);
        getchar(); // limpar buffer
    }

    printf("\n--- Estado inicial do mapa ---\n");
    for(i=0;i<5;i++){
        printf("%d) %s - Cor: %s - Tropas: %d\n", i+1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }

    return 0;
}
