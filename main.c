#include <stdio.h>
#include <string.h>

// Definição da estrutura para uma carta
typedef struct {
    char estado;           // Letra de A a H
    char codigo[4];        // Ex: A01 (3 chars + '\0')
    char cidade[100];      // Nome da cidade
    int populacao;         // Número de habitantes
    float area;            // Área em km²
    float pib;             // PIB em bilhões de reais
    int pontos_turismo;    // Número de pontos turísticos
} Carta;

// Função que preenche e retorna uma carta
Carta preencherCarta(int num) {
    Carta c;
    char buffer[100];

    printf("Digite os dados da Carta %d:\n", num);

    // Estado
    printf("Estado (A-H): ");
    if (fgets(buffer, sizeof(buffer), stdin)) {
        c.estado = buffer[0];
    }

    // Código
    printf("Código da Carta (ex: %c01): ", c.estado);
    if (fgets(c.codigo, sizeof(c.codigo), stdin)) {
        c.codigo[strcspn(c.codigo, "\n")] = '\0';
    }

    // Nome da Cidade
    printf("Nome da Cidade: ");
    if (fgets(c.cidade, sizeof(c.cidade), stdin)) {
        c.cidade[strcspn(c.cidade, "\n")] = '\0';
    }

    // População
    printf("População: ");
    if (fgets(buffer, sizeof(buffer), stdin)) {
        sscanf(buffer, "%d", &c.populacao);
    }

    // Área
    printf("Área (km²): ");
    if (fgets(buffer, sizeof(buffer), stdin)) {
        sscanf(buffer, "%f", &c.area);
    }

    // PIB
    printf("PIB (bilhões de reais): ");
    if (fgets(buffer, sizeof(buffer), stdin)) {
        sscanf(buffer, "%f", &c.pib);
    }

    // Pontos Turísticos
    printf("Número de Pontos Turísticos: ");
    if (fgets(buffer, sizeof(buffer), stdin)) {
        sscanf(buffer, "%d", &c.pontos_turismo);
    }

    printf("\n"); // Linha em branco após cada carta
    return c;
}

int main() {
    Carta cartas[2];

    // Preencher as duas cartas
    cartas[0] = preencherCarta(1);
    cartas[1] = preencherCarta(2);

    // Exibição dos dados das cartas
    for (int i = 0; i < 2; i++) {
        printf("Carta %d:\n", i + 1);
        printf("Estado: %c\n", cartas[i].estado);
        printf("Código: %s\n", cartas[i].codigo);
        printf("Nome da Cidade: %s\n", cartas[i].cidade);
        printf("População: %d\n", cartas[i].populacao);
        printf("Área: %.2f km²\n", cartas[i].area);
        printf("PIB: %.2f bilhões de reais\n", cartas[i].pib);
        printf("Número de Pontos Turísticos: %d\n", cartas[i].pontos_turismo);
        printf("\n");
    }

    return 0;
}
