#include <stdio.h>

int main() {
      
      char estado[50];
      char codigo[50] = "a1";
      char cidade[50];
      int populacao;
      float area;
      float PIB;
      
          printf("Digite seu estado: \n");
          scanf("%s", estado);
          printf("Seu estado é: %s\n", estado);
          
          printf("O código do seu estado é: %s\n", codigo);

          printf("Digite sua cidade: \n");
          scanf("%s", cidade);
          printf("Sua cidade é: %s\n", cidade);

          printf("Digite a população: \n");
          scanf("%d", &populacao);
          printf("Seu estado possui: %d de habitantes\n", populacao);

          printf("Digite a área de seu estado: \n");
          scanf("%f", &area);
          printf("Seu estado possui: %2.f km2\n", area);

          printf("Digite o PIB do seu estado: \n");
          scanf("%f", &PIB);
          printf("O PIB do seu estado é de: %f de reais\n", PIB);
          
          char estado2[50];
          char codigo2[50] = "a2";
          char cidade2[50];
          int populacao2;
          float area2;
          float PIB2;

          printf("Digite o nome de outro estado: \n");
          scanf("%s", estado2);
          printf("Seu estado é: %s\n", estado2);
          
          printf("O código do seu estado é: %s\n", codigo2);

          printf("Escolha sua cidade: \n");
          scanf("%s", cidade2);
          printf("Essa é a sua cidade: \n");

          printf("Digite a população: \n");
          scanf("%d", &populacao2);
          printf("Seu estado possui: %d de habitantes\n", populacao2);

          printf("Digite a área de seu estado: \n");
          scanf("%f", &area2);
          printf("Seu estado possui: %2.f km2\n", area2);

          printf("Digite o PIB do seu estado: \n");
          scanf("%f", &PIB2);
          printf("O PIB do seu estado é de: %f de reais\n", PIB2);


    return 0;
}