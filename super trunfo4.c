#include <stdio.h>

int main(void) {
    // Carta 1
    char estado1;
    char codigo1[4];
    char cidade1[50];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontos1;
    float densidade1;
    float pibPerCapita1;
    float superPoder1;

    // Carta 2
    char estado2;
    char codigo2[4];
    char cidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontos2;
    float densidade2;
    float pibPerCapita2;
    float superPoder2;

    // Entrada da Carta 1
    printf("Carta 1:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Código da Carta (ex: A01): ");
    scanf(" %3s", codigo1);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", cidade1);
    printf("População: ");
    scanf(" %lu", &populacao1);
    printf("Área (em km²): ");
    scanf(" %f", &area1);
    printf("PIB (em bilhões de reais): ");
    scanf(" %f", &pib1);
    printf("Número de Pontos Turísticos: ");
    scanf(" %d", &pontos1);

    densidade1 = (float)populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000.0f) / (float)populacao1; // PIB em reais
    superPoder1 = (float)populacao1 + area1 + pib1 + pontos1 + pibPerCapita1 + (1.0f / densidade1);

    // Entrada da Carta 2
    printf("\nCarta 2:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Código da Carta (ex: B02): ");
    scanf(" %3s", codigo2);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", cidade2);
    printf("População: ");
    scanf(" %lu", &populacao2);
    printf("Área (em km²): ");
    scanf(" %f", &area2);
    printf("PIB (em bilhões de reais): ");
    scanf(" %f", &pib2);
    printf("Número de Pontos Turísticos: ");
    scanf(" %d", &pontos2);

    densidade2 = (float)populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000.0f) / (float)populacao2;
    superPoder2 = (float)populacao2 + area2 + pib2 + pontos2 + pibPerCapita2 + (1.0f / densidade2);

    // Exibição das cartas
    printf("\n--- Dados das Cartas ---\n");
    printf("\nCarta 1: %s (%c)\nPopulação: %lu\nÁrea: %.2f km²\nPIB: %.2f bilhões\nPontos Turísticos: %d\nDensidade: %.2f\nPIB per Capita: %.2f\nSuper Poder: %.2f\n",
           cidade1, estado1, populacao1, area1, pib1, pontos1, densidade1, pibPerCapita1, superPoder1);
    printf("\nCarta 2: %s (%c)\nPopulação: %lu\nÁrea: %.2f km²\nPIB: %.2f bilhões\nPontos Turísticos: %d\nDensidade: %.2f\nPIB per Capita: %.2f\nSuper Poder: %.2f\n",
           cidade2, estado2, populacao2, area2, pib2, pontos2, densidade2, pibPerCapita2, superPoder2);

    // Comparações usando if/else
    printf("\n--- Comparação de Cartas ---\n");

    if (populacao1 > populacao2)
        printf("População: Carta 1 venceu\n");
    else
        printf("População: Carta 2 venceu\n");

    if (area1 > area2)
        printf("Área: Carta 1 venceu\n");
    else
        printf("Área: Carta 2 venceu\n");

    if (pib1 > pib2)
        printf("PIB: Carta 1 venceu\n");
    else
        printf("PIB: Carta 2 venceu\n");

    if (pontos1 > pontos2)
        printf("Pontos Turísticos: Carta 1 venceu\n");
    else
        printf("Pontos Turísticos: Carta 2 venceu\n");

    // Densidade Populacional (menor vence)
    if (densidade1 < densidade2)
        printf("Densidade Populacional: Carta 1 venceu\n");
    else
        printf("Densidade Populacional: Carta 2 venceu\n");

    if (pibPerCapita1 > pibPerCapita2)
        printf("PIB per Capita: Carta 1 venceu\n");
    else
        printf("PIB per Capita: Carta 2 venceu\n");

    if (superPoder1 > superPoder2)
        printf("Super Poder: Carta 1 venceu\n");
    else
        printf("Super Poder: Carta 2 venceu\n");

    return 0;
}
