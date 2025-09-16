#include <stdio.h>
#include <string.h>

int main() {
    char produto1[50], produto2[50], produto3[50];
    float pantigo1, pantigo2, pantigo3;
    float patual1, patual2, patual3;
    float variacao1, variacao2, variacao3;
    char situacao1[50], situacao2[50], situacao3[50];

    printf("Digite o nome do produto: ");
    scanf("%49s", produto1);
    printf("Digite o preco antigo do produto: ");
    scanf("%f", &pantigo1);
    printf("Digite o preco atual do produto: ");
    scanf("%f", &patual1);

    printf("Digite o nome do produto: ");
    scanf("%49s", produto2);
    printf("Digite o preco antigo do produto: ");
    scanf("%f", &pantigo2);
    printf("Digite o preco atual do produto: ");
    scanf("%f", &patual2);

    printf("Digite o nome do produto: ");
    scanf("%49s", produto3);
    printf("Digite o preco antigo do produto: ");
    scanf("%f", &pantigo3);
    printf("Digite o preco atual do produto: ");
    scanf("%f", &patual3);

    // Calcular variação percentual para cada produto
    variacao1 = ((patual1 - pantigo1) / pantigo1) * 100;
    variacao2 = ((patual2 - pantigo2) / pantigo2) * 100;
    variacao3 = ((patual3 - pantigo3) / pantigo3) * 100;

    // Determinar a situação com base na variação para cada produto
    if (variacao1 == 10.0) {
        strcpy(situacao1, "Limite de Aumento");
    } 
    else if (variacao1 > 12.5) {
        strcpy(situacao1, "Aumento Abusivo");
    } 
    else if (variacao1 == 0.0) {
        strcpy(situacao1, "Estavel");
    } 
    else if (variacao1 < -3.3) {
        strcpy(situacao1, "Reducao de Preco");
    } 
    else {
        strcpy(situacao1, "Situacao Normal");
    }

    if (variacao2 == 10.0) {
        strcpy(situacao2, "Limite de Aumento");
    } 
    else if (variacao2 > 12.5) {
        strcpy(situacao2, "Aumento Abusivo");
    } 
    else if (variacao2 == 0.0) {
        strcpy(situacao2, "Estavel");
    } 
    else if (variacao2 < -3.3) {
        strcpy(situacao2, "Reducao de Preco");
    } 
    else {
        strcpy(situacao2, "Situacao Normal");
    }

    if (variacao3 == 10.0) {
        strcpy(situacao3, "Limite de Aumento");
    } 
    else if (variacao3 > 12.5) {
        strcpy(situacao3, "Aumento Abusivo");
    } 
    else if (variacao3 == 0.0) {
        strcpy(situacao3, "Estavel");
    } 
    else if (variacao3 < -3.3) {
        strcpy(situacao3, "Reducao de Preco");
    } 
    else {
        strcpy(situacao3, "Situacao Normal");
    }

    printf("\nProduto: %s\n", produto1);
    printf("Preco Antigo: R$ %.2f\n", pantigo1);
    printf("Preco Atual: R$ %.2f\n", patual1);
    printf("Variacao: %.2f%%\n", variacao1);
    printf("Situacao: %s\n", situacao1);

    printf("\nProduto: %s\n", produto2);
    printf("Preco Antigo: R$ %.2f\n", pantigo2);
    printf("Preco Atual: R$ %.2f\n", patual2);
    printf("Variacao: %.2f%%\n", variacao2);
    printf("Situacao: %s\n", situacao2);
    
    printf("\nProduto: %s\n", produto3);
    printf("Preco Antigo: R$ %.2f\n", pantigo3);
    printf("Preco Atual: R$ %.2f\n", patual3);
    printf("Variacao: %.2f%%\n", variacao3);
    printf("Situacao: %s\n", situacao3);

    return 0;
}