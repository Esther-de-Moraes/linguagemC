#include <stdio.h>

// Função para imprimir o vetor
void imprimirVetor(float vetor[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        printf("%.1f", vetor[i]);
        if(i < tamanho - 1) printf(", ");
    }
    printf("\n");
}

// Função para ordenar em ordem crescente usando Bubble Sort
void bubbleSortCrescente(float vetor[], int tamanho) {
    int i, j;
    float temp;
    
    // Loop externo: controla o número de passagens pelo vetor
    for(i = 0; i < tamanho - 1; i++) {
        // Loop interno: compara elementos adjacentes
        for(j = 0; j < tamanho - i - 1; j++) {
            // Se o elemento atual é maior que o próximo, troca-os
            if(vetor[j] > vetor[j + 1]) {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

// Função para ordenar em ordem decrescente usando Bubble Sort
void bubbleSortDecrescente(float vetor[], int tamanho) {
    int i, j;
    float temp;
    
    // Loop externo: controla o número de passagens pelo vetor
    for(i = 0; i < tamanho - 1; i++) {
        // Loop interno: compara elementos adjacentes
        for(j = 0; j < tamanho - i - 1; j++) {
            // Se o elemento atual é menor que o próximo, troca-os
            if(vetor[j] < vetor[j + 1]) {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Vetor para armazenar os pesos dos 10 pacotes
    float pesos[10];
    float pesosBackup[10]; // Backup para preservar os dados originais
    
    printf("=== SISTEMA DE PESOS DE ENCOMENDAS ===\n\n");
    
    // Leitura dos pesos dos pacotes
    printf("Digite os pesos dos 10 pacotes:\n");
    for(int i = 0; i < 10; i++) {
        printf("Pacote %d: ", i + 1);
        scanf("%f", &pesos[i]);
    }
    
    // Faz uma cópia do vetor original para preservar os dados
    for(int i = 0; i < 10; i++) {
        pesosBackup[i] = pesos[i];
    }
    
    printf("\n=== DADOS ORIGINAIS ===\n");
    printf("Pesos originais: ");
    imprimirVetor(pesos, 10);
    
    // Ordenação crescente
    bubbleSortCrescente(pesos, 10);
    printf("\n=== ORDENACAO CRESCENTE ===\n");
    printf("Pesos ordenados (menor para maior): ");
    imprimirVetor(pesos, 10);
    
    // Restaura os dados originais do backup
    for(int i = 0; i < 10; i++) {
        pesos[i] = pesosBackup[i];
    }
    
    // Ordenação decrescente
    bubbleSortDecrescente(pesos, 10);
    printf("\n=== ORDENACAO DECRESCENTE ===\n");
    printf("Pesos ordenados (maior para menor): ");
    imprimirVetor(pesos, 10);
    
    printf("\n=== PROCESSO CONCLUIDO ===\n");
    
    return 0;
}