#include <stdio.h>
#include <string.h>
typedef struct {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_demografica;
} Carta;
Carta criar_carta() {
    Carta carta;
    printf("Digite o nome do pais: ");
    fgets(carta.nome, 50, stdin);
    // Remove o \n do final do fgets
    size_t len = strlen(carta.nome);
    if (len > 0 && carta.nome[len-1] == '\n') {
        carta.nome[len-1] = '\0';
    }
    printf("Digite a populacao: ");
    scanf("%d", &carta.populacao);
    printf("Digite a area: ");
    scanf("%f", &carta.area);
    printf("Digite o PIB: ");
    scanf("%f", &carta.pib);
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &carta.pontos_turisticos);
    printf("Digite a densidade demografica: ");
    scanf("%f", &carta.densidade_demografica);
    getchar(); // Limpa o '\n' que ficou no buffer
    return carta;
}
int comparar_cartas(Carta carta1, Carta carta2, int atributo) {
    if (atributo == 1) { // População
        if (carta1.populacao > carta2.populacao) return 1;
        else if (carta1.populacao < carta2.populacao) return 2;
        else return 0;
    } else if (atributo == 2) { // Área
        if (carta1.area > carta2.area) return 1;
        else if (carta1.area < carta2.area) return 2;
        else return 0;
    } else if (atributo == 3) { // PIB
        if (carta1.pib > carta2.pib) return 1;
        else if (carta1.pib < carta2.pib) return 2;
        else return 0;
    } else if (atributo == 4) { // Número de pontos turísticos
        if (carta1.pontos_turisticos > carta2.pontos_turisticos) return 1;
        else if (carta1.pontos_turisticos < carta2.pontos_turisticos) return 2;
        else return 0;
    } else if (atributo == 5) { // Densidade demográfica (menor vence)
        if (carta1.densidade_demografica < carta2.densidade_demografica) return 1;
        else if (carta1.densidade_demografica > carta2.densidade_demografica) return 2;
        else return 0;
    }
    return -1;
}
void mostrar_menu() {
    printf("Escolha um atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Numero de pontos turisticos\n");
    printf("5 - Densidade demografica\n");
    printf("0 - Sair\n");
}
int main() {
    printf("Cadastro da primeira carta:\n");
    Carta carta1 = criar_carta();
    printf("\nCadastro da segunda carta:\n");
    Carta carta2 = criar_carta();
    while (1) {
        mostrar_menu();
        int escolha;
        printf("Digite a opcao desejada: ");
        if (scanf("%d", &escolha) != 1) {
            printf("Entrada invalida! Tente novamente.\n");
            while(getchar() != '\n');
            continue;
        }
        getchar(); // Limpa o \n do buffer
        if (escolha == 0) {
            printf("Encerrando o jogo.\n");
            break;
        }
        if (escolha < 1 || escolha > 5) {
            printf("Opcao invalida! Tente novamente.\n\n");
            continue;
        }
        int resultado = comparar_cartas(carta1, carta2, escolha);
        char *nome_atributo;
        float valor1, valor2;
        switch (escolha) {
            case 1:
                nome_atributo = "Populacao";
                valor1 = (float)carta1.populacao;
                              valor2 = (float)carta2.populacao;
                break;
            case 2:
                nome_atributo = "Area";
                valor1 = carta1.area;
                valor2 = carta2.area;
                break;
            case 3:
                nome_atributo = "PIB";
                valor1 = carta1.pib;
                valor2 = carta2.pib;
                break;
            case 4:
                nome_atributo = "Numero de pontos turisticos";
                valor1 = (float)carta1.pontos_turisticos;
                valor2 = (float)carta2.pontos_turisticos;
                break;
            case 5:
                nome_atributo = "Densidade demografica";
                valor1 = carta1.densidade_demografica;
                valor2 = carta2.densidade_demografica;
                break;
            default:
                nome_atributo = "Desconhecido";
                valor1 = valor2 = 0.0;
        }
        printf("\nComparacao entre %s e %s\n", carta1.nome, carta2.nome);
        printf("Atributo escolhido: %s\n", nome_atributo);
        printf("%s: %.2f\n", carta1.nome, valor1);
        printf("%s: %.2f\n", carta2.nome, valor2);
        if (resultado == 0) {
            printf("Empate!\n\n");
        } else if (resultado == 1) {
            printf("Vencedor: %s\n\n", carta1.nome);
        } else if (resultado == 2) {
            printf("Vencedor: %s\n\n", carta2.nome);
        } else {
            printf("Erro na comparacao.\n\n");
        }
    }
    return 0;
}