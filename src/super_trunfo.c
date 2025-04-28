#include <stdio.h>
#include <string.h>

// Definição da estrutura para uma carta
typedef struct
{
    char estado;                   // Letra de A a H
    char codigo[4];                // Ex: A01 (3 chars + '\0')
    char cidade[100];              // Nome da cidade
    unsigned long int populacao;   // Número de habitantes
    float area;                    // Área em km²
    float pib;                     // PIB em bilhões de reais
    int pontos_turismo;            // Número de pontos turísticos
    float desnsidade_populacional; // Densidade populacional
    float pib_per_capita;          // PIB per capita
    float super_poder;             // Soma dos valores (população, área, PIB,
                                   // número de pontos turísticos, PIB per capita e o inverso da densidade populacional
} Carta;


// Função que preenche e retorna uma carta
Carta preencherCarta(int num)
{
    Carta c;

    printf("Digite os dados da Carta %d:\n", num);

    printf("Estado (A-H): ");
    scanf(" %c", &c.estado); 

    printf("Código da Carta (ex: %c01): ", c.estado);
    scanf(" %3[^\n]", c.codigo);

    printf("Nome da Cidade: ");
    scanf(" %199[^\n]", c.cidade);

    printf("População: ");
    scanf("%lu", &c.populacao);

    printf("Área (km²): ");
    scanf("%f", &c.area);

    printf("PIB (bilhões de reais): ");
    scanf("%f", &c.pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &c.pontos_turismo);

    c.desnsidade_populacional = (float)c.populacao / c.area;

    float pib_em_bilhao = c.pib * 1e9;
    c.pib_per_capita = pib_em_bilhao / (float)c.populacao;

    c.super_poder = (float)c.populacao + 
                    c.area + 
                    c.pib + 
                    (float)c.pontos_turismo + 
                    c.pib_per_capita - 
                    (1 / c.desnsidade_populacional);

    printf("\n"); // Linha em branco para separar cartas

    return c;
}

// Função para comparar cartas atributo por atributo
void compararCartas(Carta cartas [], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = i + 1; j < tamanho; j++)
        {
            printf("População: Carta %d venceu (%d)\n", 
                cartas[i].populacao > cartas[j].populacao ? i + 1 : j + 1, 
                cartas[i].populacao > cartas[j].populacao ? 1 : 0);
            
            printf("Área: Carta %d venceu (%d)\n",
                cartas[i].area > cartas[j].area ? i + 1 : j + 1, 
                cartas[i].area > cartas[j].area ? 1 : 0);

            printf("PIB: Carta %d venceu (%d)\n",
                cartas[i].pib > cartas[j].pib ? i + 1 : j + 1, 
                cartas[i].pib > cartas[j].pib ? 1 : 0);
            
            printf("Pontos Turísticos: Carta %d venceu (%d)\n",
                cartas[i].pontos_turismo > cartas[j].pontos_turismo ? i + 1 : j + 1, 
                cartas[i].pontos_turismo > cartas[j].pontos_turismo ? 1 : 0);
            
            printf("Densidade Populacional: Carta %d venceu (%d)\n",
                cartas[i].desnsidade_populacional > cartas[j].desnsidade_populacional ? j + 1 : i + 1, 
                cartas[i].desnsidade_populacional > cartas[j].desnsidade_populacional ? 0 : 1);
            
            printf("PIB per Capita: Carta %d venceu (%d)\n",
                cartas[i].pib_per_capita > cartas[j].pib_per_capita ? i + 1 : j + 1, 
                cartas[i].pib_per_capita > cartas[j].pib_per_capita ? 1 : 0);
            
            printf("Super Poder: Carta %d venceu (%d)\n",
                cartas[i].super_poder > cartas[j].super_poder ? i + 1 : j + 1, 
                cartas[i].super_poder > cartas[j].super_poder ? 1 : 0);
            
            printf("\n"); // Linha em branco para separar comparações
        }
    }       

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
        printf("População: %lu\n", cartas[i].populacao);
        printf("Área: %.2f km²\n", cartas[i].area);
        printf("PIB: %.2f bilhões de reais\n", cartas[i].pib);
        printf("Número de Pontos Turísticos: %d\n", cartas[i].pontos_turismo);
        printf("Densidade Populacional: %.2f hab/km²\n", cartas[i].desnsidade_populacional);
        printf("PIB per Capita: %.2f reais\n", cartas[i].pib_per_capita);
        printf("Super Poder: %.2f Pontos\n", cartas[i].super_poder);
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

    // Comparar as cartas
    compararCartas(cartas, 2);

    return 0;
}
