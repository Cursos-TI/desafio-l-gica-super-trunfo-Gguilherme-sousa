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
    int opcao;
    int continuar = 1;

    // ===== Cálculos =====
    densidade1 = (float) populacao1 / area1;
    densidade2 = (float) populacao2 / area2;

    pibPerCapita1 = (pib1 * 1000000000.0) / (float) populacao1;
    pibPerCapita2 = (pib2 * 1000000000.0) / (float) populacao2;

    superPoder1 = (float) populacao1 + area1 + pib1 + pontosTuristicos1 + pibPerCapita1 + (1 / densidade1);
    superPoder2 = (float) populacao2 + area2 + pib2 + pontosTuristicos2 + pibPerCapita2 + (1 / densidade2);

    // ===== Exibição inicial =====
    printf("===== JOGO SUPER TRUNFO - CIDADES BRASILEIRAS =====\n\n");

    printf("=== CARTA 1 ===\n");
    printf("Estado: %s\nCódigo: %s\nCidade: %s\n", estado1, codigo1, cidade1);
    printf("População: %lu hab\nÁrea: %.2f km²\nPIB: %.2f bilhões\n", populacao1, area1, pib1);
    printf("Pontos Turísticos: %d\nDensidade: %.2f hab/km²\nPIB per Capita: %.2f reais\n", pontosTuristicos1, densidade1, pibPerCapita1);
    printf("Super Poder: %.2f\n\n", superPoder1);

    printf("=== CARTA 2 ===\n");
    printf("Estado: %s\nCódigo: %s\nCidade: %s\n", estado2, codigo2, cidade2);
    printf("População: %lu hab\nÁrea: %.2f km²\nPIB: %.2f bilhões\n", populacao2, area2, pib2);
    printf("Pontos Turísticos: %d\nDensidade: %.2f hab/km²\nPIB per Capita: %.2f reais\n", pontosTuristicos2, densidade2, pibPerCapita2);
    printf("Super Poder: %.2f\n\n", superPoder2);

    // ===== MENU INTERATIVO =====
    while (continuar) {
        printf("\n===== MENU DE COMPARAÇÃO =====\n");
        printf("Escolha o atributo para comparar:\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Pontos Turísticos\n");
        printf("5 - Densidade Populacional\n");
        printf("6 - PIB per Capita\n");
        printf("7 - Super Poder\n");
        printf("0 - Sair do jogo\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao);

        printf("\n===== RESULTADO =====\n");

        switch (opcao) {
            case 1: // População
                printf("Atributo: População\n");
                printf("%s: %lu habitantes\n", cidade1, populacao1);
                printf("%s: %lu habitantes\n", cidade2, populacao2);
                if (populacao1 > populacao2)
                    printf("Vencedor: %s (maior população)\n", cidade1);
                else if (populacao2 > populacao1)
                    printf("Vencedor: %s (maior população)\n", cidade2);
                else
                    printf("Empate!\n");
                break;

            case 2: // Área
                printf("Atributo: Área\n");
                printf("%s: %.2f km²\n", cidade1, area1);
                printf("%s: %.2f km²\n", cidade2, area2);
                if (area1 > area2)
                    printf("Vencedor: %s (maior área)\n", cidade1);
                else if (area2 > area1)
                    printf("Vencedor: %s (maior área)\n", cidade2);
                else
                    printf("Empate!\n");
                break;

            case 3: // PIB
                printf("Atributo: PIB (em bilhões de reais)\n");
                printf("%s: %.2f bilhões\n", cidade1, pib1);
                printf("%s: %.2f bilhões\n", cidade2, pib2);

                // If-else aninhado com desempate por PIB per capita
                if (pib1 > pib2) {
                    printf("Vencedor: %s (maior PIB)\n", cidade1);
                } else if (pib2 > pib1) {
                    printf("Vencedor: %s (maior PIB)\n", cidade2);
                } else {
                    printf("Empate em PIB! Desempate pelo PIB per capita...\n");
                    if (pibPerCapita1 > pibPerCapita2)
                        printf("Desempate: %s venceu.\n", cidade1);
                    else if (pibPerCapita2 > pibPerCapita1)
                        printf("Desempate: %s venceu.\n", cidade2);
                    else
                        printf("Empate total!\n");
                }
                break;

            case 4: // Pontos Turísticos
                printf("Atributo: Pontos Turísticos\n");
                printf("%s: %d pontos\n", cidade1, pontosTuristicos1);
                printf("%s: %d pontos\n", cidade2, pontosTuristicos2);
                if (pontosTuristicos1 > pontosTuristicos2)
                    printf("Vencedor: %s (mais pontos turísticos)\n", cidade1);
                else if (pontosTuristicos2 > pontosTuristicos1)
                    printf("Vencedor: %s (mais pontos turísticos)\n", cidade2);
                else
                    printf("Empate!\n");
                break;

            case 5: // Densidade Populacional (regra invertida)
                printf("Atributo: Densidade Populacional\n");
                printf("%s: %.2f hab/km²\n", cidade1, densidade1);
                printf("%s: %.2f hab/km²\n", cidade2, densidade2);
                if (densidade1 < densidade2)
                    printf("Vencedor: %s (menor densidade populacional)\n", cidade1);
                else if (densidade2 < densidade1)
                    printf("Vencedor: %s (menor densidade populacional)\n", cidade2);
                else
                    printf("Empate!\n");
                break;

            case 6: // PIB per Capita
                printf("Atributo: PIB per Capita\n");
                printf("%s: %.2f reais\n", cidade1, pibPerCapita1);
                printf("%s: %.2f reais\n", cidade2, pibPerCapita2);
                if (pibPerCapita1 > pibPerCapita2)
                    printf("Vencedor: %s (PIB per capita maior)\n", cidade1);
                else if (pibPerCapita2 > pibPerCapita1)
                    printf("Vencedor: %s (PIB per capita maior)\n", cidade2);
                else
                    printf("Empate!\n");
                break;

            case 7: // Super Poder
                printf("Atributo: Super Poder (somatório simbólico de atributos)\n");
                printf("%s: %.2f\n", cidade1, superPoder1);
                printf("%s: %.2f\n", cidade2, superPoder2);
                if (superPoder1 > superPoder2)
                    printf("Vencedor: %s\n", cidade1);
                else if (superPoder2 > superPoder1)
                    printf("Vencedor: %s\n", cidade2);
                else
                    printf("Empate!\n");
                break;

            case 0:
                printf("Encerrando o jogo...\n");
                continuar = 0;
                break;

            default:
                printf(" Opção inválida! Digite um número de 0 a 7.\n");
                break;
        }

        if (opcao != 0 && continuar) {
            printf("\nDeseja jogar novamente? (1 - Sim / 0 - Não): ");
            scanf("%d", &continuar);
        }
    }

    printf("\n===== FIM DO PROGRAMA =====\n");
    return 0;
}




