#include <stdio.h>

int main() {
    // ===== Dados fixos das cartas =====
    // Carta 1 - São Paulo
    char estado1[] = "SP";
    char codigo1[] = "A01";
    char cidade1[] = "Sao Paulo";
    unsigned long int populacao1 = 11451245; // 11,45 milhões
    float area1 = 1521.11;                   // km²
    float pib1 = 899.3;                      // bilhões de reais
    int pontosTuristicos1 = 35;

    // Carta 2 - Rio de Janeiro
    char estado2[] = "RJ";
    char codigo2[] = "B02";
    char cidade2[] = "Rio de Janeiro";
    unsigned long int populacao2 = 6718903; // 6,71 milhões
    float area2 = 1182.30;                  // km²
    float pib2 = 410.7;                     // bilhões de reais
    int pontosTuristicos2 = 50;

    // ===== Variáveis de cálculo =====
    float densidade1, densidade2;
    float pibPerCapita1, pibPerCapita2;
    float superPoder1, superPoder2;

    // ===== Cálculos =====
    densidade1 = (float) populacao1 / area1;
    densidade2 = (float) populacao2 / area2;

    pibPerCapita1 = (pib1 * 1000000000.0) / (float) populacao1;
    pibPerCapita2 = (pib2 * 1000000000.0) / (float) populacao2;

    // Super poder (somatório simbólico de atributos)
    superPoder1 = (float) populacao1 + area1 + pib1 + pontosTuristicos1 + pibPerCapita1 + (1 / densidade1);
    superPoder2 = (float) populacao2 + area2 + pib2 + pontosTuristicos2 + pibPerCapita2 + (1 / densidade2);

    // ===== Exibição das cartas =====
    printf("===== JOGO SUPER TRUNFO - CIDADES BRASILEIRAS =====\n\n");

    printf("=== CARTA 1 ===\n");
    printf("Estado: %s\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Cidade: %s\n", cidade1);
    printf("População: %lu habitantes\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Pontos Turísticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);
    printf("Super Poder: %.2f\n\n", superPoder1);

    printf("=== CARTA 2 ===\n");
    printf("Estado: %s\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Cidade: %s\n", cidade2);
    printf("População: %lu habitantes\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Pontos Turísticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);
    printf("Super Poder: %.2f\n\n", superPoder2);

    // ===== Comparação de um único atributo =====
    // Escolha do atributo: PIB per Capita
    printf("===== COMPARAÇÃO DE CARTAS =====\n");
    printf("Atributo escolhido: PIB per Capita\n\n");

    printf("Carta 1 - %s (%s): %.2f reais\n", cidade1, estado1, pibPerCapita1);
    printf("Carta 2 - %s (%s): %.2f reais\n\n", cidade2, estado2, pibPerCapita2);

    if (pibPerCapita1 > pibPerCapita2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
    } else if (pibPerCapita2 > pibPerCapita1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
    } else {
        printf("Resultado: Empate!\n");
    }

    printf("\n===== FIM DO PROGRAMA =====\n");

    return 0;
}