#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CARTAS 3
#define NUM_ATRIBUTOS 4

typedef struct {
    char nome[30];
    int populacao;
    int area;
    int pib;
    int densidade_demografica;
} Carta;

Carta cartas[NUM_CARTAS] = {
    {"Brasil", 211000000, 8515767, 2100000, 25},
    {"Argentina", 45000000, 2780400, 450000, 16},
    {"Chile", 19000000, 756102, 300000, 25}
};

void exibir_menu_atributos() {
    printf("Escolha o primeiro atributo:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Densidade Demográfica\n");
}

void exibir_menu_atributos_secundario(int atributo1) {
    printf("Escolha o segundo atributo:\n");
    for (int i = 1; i <= NUM_ATRIBUTOS; i++) {
        if (i != atributo1) {
            switch (i) {
                case 1: printf("1. População\n"); break;
                case 2: printf("2. Área\n"); break;
                case 3: printf("3. PIB\n"); break;
                case 4: printf("4. Densidade Demográfica\n"); break;
            }
        }
    }
}

int comparar_atributos(int atributo, Carta carta1, Carta carta2) {
    switch (atributo) {
        case 1: return carta1.populacao - carta2.populacao; // População
        case 2: return carta1.area - carta2.area; // Área
        case 3: return carta1.pib - carta2.pib; // PIB
        case 4: return carta2.densidade_demografica - carta1.densidade_demografica; // Densidade Demográfica
        default: return 0;
    }
}

void comparar_cartas(int carta1_index, int carta2_index, int atributo1, int atributo2) {
    Carta carta1 = cartas[carta1_index];
    Carta carta2 = cartas[carta2_index];

    int resultado1 = comparar_atributos(atributo1, carta1, carta2);
    int resultado2 = comparar_atributos(atributo2, carta1, carta2);

    printf("Comparando %s e %s:\n", carta1.nome, carta2.nome);
    printf("Atributo 1: %s - %d vs %d\n", atributo1 == 1 ? "População" : atributo1 == 2 ? "Área" : atributo1 == 3 ? "PIB" : "Densidade Demográfica", 
           resultado1 > 0 ? carta1.populacao : carta2.populacao, resultado1 < 0 ? carta1.populacao : carta2.populacao);
    printf("Atributo 2: %s - %d vs %d\n", atributo2 == 1 ? "População" : atributo2 == 2 ? "Área" : atributo2 == 3 ? "PIB" : "Densidade Demográfica", 
           resultado2 > 0 ? carta1.populacao : carta2.populacao, resultado2 < 0 ? carta1.populacao : carta2.populacao);

    int soma1 = carta1.populacao + carta1.area + carta1.pib + carta1.densidade_demografica;
    int soma2 = carta2.populacao + carta2.area + carta2.pib + carta2.densidade_demografica;

    printf("Soma dos atributos: %s = %d, %s = %d\n", carta1.nome, soma1, carta2.nome, soma2);
    
    if (soma1 > soma2) {
        printf("Vencedor: %s\n", carta1.nome);
    } else if (soma1 < soma2) {
        printf("Vencedor: %s\n", carta2.nome);
    } else {
        printf("Empate!\n");
    }
}

int main() {
    int carta1_index, carta2_index, atributo1, atributo2;

    printf("Escolha a primeira carta (0 - Brasil, 1 - Argentina, 2 - Chile): ");
    scanf("%d", &carta1_index);
    printf("Escolha a segunda carta (0 - Brasil, 1 - Argentina, 2 - Chile): ");
    scanf("%d", &carta2_index);

    exibir_menu_atributos();
    scanf("%d", &atributo1);
    exibir_menu_atributos_secundario(atributo1);
    scanf("%d", &atributo2);

    comparar_cartas(carta1_index, carta2_index, atributo1, atributo2);

    return 0;
}
