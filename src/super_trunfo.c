#include <stdio.h>
#include <string.h>

// Definição da estrutura para uma carta
typedef struct
{
    char estado;                   // Letra de A a H
    char codigo[4];                // Ex: A01 (3 chars + '\0')
    char cidade[100];              // Nome da cidade
    int populacao;                 // Número de habitantes
    float area;                    // Área em km²
    float pib;                     // PIB em bilhões de reais
    int pontos_turismo;            // Número de pontos turísticos
    float desnsidade_populacional; // Densidade populacional
    float pib_per_capita;          // PIB per capita
} Carta;

// Função que preenche e retorna uma carta
Carta preencherCarta(int num)
{
    Carta c;
    char buffer[100];

    printf("Digite os dados da Carta %d:\n", num);

    // Estado
    printf("Estado (A-H): ");
    if (fgets(buffer, sizeof(buffer), stdin))
    {
        c.estado = buffer[0];
    }

    // Código
    printf("Código da Carta (ex: %c01): ", c.estado);
    if (fgets(c.codigo, sizeof(c.codigo), stdin))
    {
        c.codigo[strcspn(c.codigo, "\n")] = '\0';
    }

    // Nome da Cidade
    printf("Nome da Cidade: ");
    if (fgets(c.cidade, sizeof(c.cidade), stdin))
    {
        c.cidade[strcspn(c.cidade, "\n")] = '\0';
    }

    // População
    printf("População: ");
    if (fgets(buffer, sizeof(buffer), stdin))
    {
        sscanf(buffer, "%d", &c.populacao);
    }

    // Área
    printf("Área (km²): ");
    if (fgets(buffer, sizeof(buffer), stdin))
    {
        sscanf(buffer, "%f", &c.area);
    }

    // PIB
    printf("PIB (bilhões de reais): ");
    if (fgets(buffer, sizeof(buffer), stdin))
    {
        sscanf(buffer, "%f", &c.pib);
    }

    // Pontos Turísticos
    printf("Número de Pontos Turísticos: ");
    if (fgets(buffer, sizeof(buffer), stdin))
    {
        sscanf(buffer, "%d", &c.pontos_turismo);
    }

    c.desnsidade_populacional = (float)c.populacao / c.area; // Cálculo da densidade populacional
    c.pib_per_capita = c.pib / c.populacao;                  // Cálculo do PIB per capita

    printf("\n"); // Linha em branco após cada carta
    return c;
}

// Função para exibir os dados de todas as cartas
void exibirCartas(Carta cartas[], int tamanho)
{

    for (int i = 0; i < tamanho; i++)
    {
        printf("Carta %d:\n", i + 1);
        printf("Estado: %c\n", cartas[i].estado);
        printf("Código: %s\n", cartas[i].codigo);
        printf("Nome da Cidade: %s\n", cartas[i].cidade);
        printf("População: %d\n", cartas[i].populacao);
        printf("Área: %.2f km²\n", cartas[i].area);
        printf("PIB: %.2f bilhões de reais\n", cartas[i].pib);
        printf("Número de Pontos Turísticos: %d\n", cartas[i].pontos_turismo);
        printf("Densidade Populacional: %.2f habitantes/km²\n", cartas[i].desnsidade_populacional);
        printf("PIB per Capita: %.2f reais\n", cartas[i].pib_per_capita);
        printf("\n");
    }
}

int main()
{
    Carta cartas[2];

    // Preencher as duas cartas
    cartas[0] = preencherCarta(1);
    cartas[1] = preencherCarta(2);

    // Exibição dos dados das cartas
    exibirCartas(cartas, 2);

    return 0;
}
