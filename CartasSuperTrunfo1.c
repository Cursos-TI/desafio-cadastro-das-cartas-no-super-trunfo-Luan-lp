#include <stdio.h>

typedef struct {
    char nome[50];
    char estado[50];
    unsigned long int populacao;
    unsigned long int area;
    unsigned long int pib;
    unsigned long int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

void calcular_dados(Carta *carta) {
    // Calcular a densidade populacional
    carta->densidade_populacional = (float)carta->populacao / carta->area;

    // Calcular o PIB per capita
    carta->pib_per_capita = (carta->populacao > 0) ? (float)carta->pib / carta->populacao : 0;

    // Calcular o Super Poder
    carta->super_poder = (float)carta->populacao + carta->area + carta->pib +
                         carta->pontos_turisticos + carta->pib_per_capita +
                         (1 / carta->densidade_populacional);
}

void comparar_cartas(Carta carta1, Carta carta2) {
    printf("\nComparação de Cartas:\n");

    // Comparar População
    printf("População: %lu (Carta 1) vs %lu (Carta 2) - Vencedor: Carta %d\n", 
           carta1.populacao, carta2.populacao, (carta1.populacao > carta2.populacao) + 1);

    // Comparar Área
    printf("Área: %lu (Carta 1) vs %lu (Carta 2) - Vencedor: Carta %d\n", 
           carta1.area, carta2.area, (carta1.area > carta2.area) + 1);

    // Comparar PIB
    printf("PIB: %lu (Carta 1) vs %lu (Carta 2) - Vencedor: Carta %d\n", 
           carta1.pib, carta2.pib, (carta1.pib > carta2.pib) + 1);

    // Comparar Pontos Turísticos
    printf("Pontos Turísticos: %lu (Carta 1) vs %lu (Carta 2) - Vencedor: Carta %d\n", 
           carta1.pontos_turisticos, carta2.pontos_turisticos, (carta1.pontos_turisticos > carta2.pontos_turisticos) + 1);

    // Comparar Densidade Populacional (menor vence)
    printf("Densidade Populacional: %.2f (Carta 1) vs %.2f (Carta 2) - Vencedor: Carta %d\n", 
           carta1.densidade_populacional, carta2.densidade_populacional, (carta1.densidade_populacional < carta2.densidade_populacional) + 1);

    // Comparar PIB per Capita
    printf("PIB per Capita: %.2f (Carta 1) vs %.2f (Carta 2) - Vencedor: Carta %d\n", 
           carta1.pib_per_capita, carta2.pib_per_capita, (carta1.pib_per_capita > carta2.pib_per_capita) + 1);

    // Comparar Super Poder
    printf("Super Poder: %.2f (Carta 1) vs %.2f (Carta 2) - Vencedor: Carta %d\n", 
           carta1.super_poder, carta2.super_poder, (carta1.super_poder > carta2.super_poder) + 1);
}

void entrada_dados(Carta *carta, int numero) {
    printf("\nDigite os dados da Carta %d:\n", numero);
    
    printf("Nome: ");
    scanf("%s", carta->nome);
    
    printf("Estado: ");
    scanf("%s", carta->estado);
    
    printf("População: ");
    scanf("%lu", &carta->populacao);
    
    printf("Área: ");
    scanf("%lu", &carta->area);
    
    printf("PIB: ");
    scanf("%lu", &carta->pib);
    
    printf("Pontos Turísticos: ");
    scanf("%lu", &carta->pontos_turisticos);
}

int main() {
    Carta carta1, carta2;

    // Entrada de dados para as cartas
    entrada_dados(&carta1, 1);
    entrada_dados(&carta2, 2);

    // Calcular dados para ambas as cartas
    calcular_dados(&carta1);
    calcular_dados(&carta2);

    // Comparar as cartas
    comparar_cartas(carta1, carta2);

    return 0; // Finaliza o programa
}
