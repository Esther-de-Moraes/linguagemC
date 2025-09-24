#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constantes do programa
#define DIAS_SEMANA 7
#define MAX_DIAS 30

// Função para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para exibir um dia em destaque (negrito)
void exibirDestaque(const char* texto) {
    printf("\033[1m%s\033[0m", texto); // \033[1m para negrito, \033[0m para reset
}

// Função para exibir um dia com cor vermelha
void exibirDiaPico(const char* texto) {
    printf("\033[1;31m%s\033[0m", texto); // \033[1;31m para vermelho em negrito
}

int main() {
    // Variáveis do programa
    int periodo, opcao;
    int pedagio[DIAS_SEMANA] = {0}; // Vetor para armazenar carros por dia da semana
    char dias[DIAS_SEMANA][20] = {"Segunda-feira", "Terca-feira", "Quarta-feira", 
                                  "Quinta-feira", "Sexta-feira", "Sabado", "Domingo"};
    
    printf("=== SISTEMA DE CONTROLE DE PEDAGIO ===\n\n");
    
    // Solicitar o período de análise
    printf("Escolha o periodo de analise:\n");
    printf("1 - 7 dias (1 semana)\n");
    printf("2 - 15 dias (2 semanas)\n");
    printf("3 - 30 dias (1 mes)\n");
    printf("Digite sua opcao (1-3): ");
    scanf("%d", &opcao);
    
    // Definir período baseado na opção
    switch(opcao) {
        case 1:
            periodo = 7;
            break;
        case 2:
            periodo = 15;
            break;
        case 3:
            periodo = 30;
            break;
        default:
            printf("Opcao invalida! Usando periodo padrao de 7 dias.\n");
            periodo = 7;
    }
    
    printf("\nPeriodo selecionado: %d dias\n\n", periodo);
    
    // Coletar dados de carros por dia da semana
    printf("=== ENTRADA DE DADOS ===\n");
    printf("Digite a quantidade media de carros para cada dia da semana:\n\n");
    
    for(int i = 0; i < DIAS_SEMANA; i++) {
        printf("%s: ", dias[i]);
        scanf("%d", &pedagio[i]);
        limparBuffer(); // Limpar buffer após scanf
    }
    
    // Calcular totais e encontrar dia de pico
    int totalCarros = 0;
    int diaPico = 0;
    int maxCarros = pedagio[0];
    
    for(int i = 0; i < DIAS_SEMANA; i++) {
        totalCarros += pedagio[i];
        if(pedagio[i] > maxCarros) {
            maxCarros = pedagio[i];
            diaPico = i;
        }
    }
    
    // Calcular média diária
    float mediaDiaria = (float)totalCarros / DIAS_SEMANA;
    
    // EXIBIR RELATÓRIO COMPLETO
    printf("\n\n=== RELATORIO DO PEDAGIO ===\n");
    printf("Periodo analisado: %d dias\n", periodo);
    printf("========================================\n\n");
    
    // Exibir dados por dia da semana
    printf("CARROS POR DIA DA SEMANA:\n");
    printf("-------------------------\n");
    
    for(int i = 0; i < DIAS_SEMANA; i++) {
        printf("%-12s: ", dias[i]);
        
        // Verificar se é o dia de pico para aplicar formatação especial
        if(i == diaPico) {
            exibirDiaPico("");
            printf("%5d carros (DIA DE PICO!)\n", pedagio[i]);
            printf("\033[0m"); // Resetar cor
        } else {
            printf("%5d carros\n", pedagio[i]);
        }
    }
    
    printf("\n");
    
    // Exibir estatísticas
    printf("ESTATISTICAS GERAIS:\n");
    printf("--------------------\n");
    printf("Total de carros no periodo: %d\n", totalCarros * (periodo / DIAS_SEMANA));
    printf("Media diaria de carros: %.2f\n", mediaDiaria);
    printf("Dia de maior movimento: ");
    exibirDestaque(dias[diaPico]);
    printf(" com %d carros\n", maxCarros);
    
    printf("\n");
    
    // Exibir projeção para o período completo
    printf("PROJECAO PARA %d DIAS:\n", periodo);
    printf("----------------------\n");
    
    int semanasCompletas = periodo / DIAS_SEMANA;
    int diasExtras = periodo % DIAS_SEMANA;
    int carrosPeriodo = totalCarros * semanasCompletas;
    
    // Adicionar carros dos dias extras
    for(int i = 0; i < diasExtras; i++) {
        carrosPeriodo += pedagio[i];
    }
    
    printf("Total projetado: %d carros\n", carrosPeriodo);
    printf("Media projetada: %.2f carros/dia\n", (float)carrosPeriodo / periodo);
    
    printf("\n");
    
    // Exibir gráfico simples de comparação
    printf("COMPARACAO VISUAL:\n");
    printf("------------------\n");
    
    // Encontrar o valor máximo para escala do gráfico
    int escala = maxCarros / 20; // Cada * representa 5% do máximo
    if(escala == 0) escala = 1;
    
    for(int i = 0; i < DIAS_SEMANA; i++) {
        printf("%-12s: ", dias[i]);
        
        int barras = pedagio[i] / escala;
        
        // Aplicar cor diferente para o dia de pico
        if(i == diaPico) {
            exibirDiaPico("");
        }
        
        for(int j = 0; j < barras; j++) {
            printf("█");
        }
        
        if(i == diaPico) {
            printf("\033[0m"); // Resetar cor
        }
        
        printf(" (%d carros)\n", pedagio[i]);
    }
    
    printf("\nLegenda: Cada █ representa aproximadamente %d carros\n", escala);
    
    printf("\n=== FIM DO RELATORIO ===\n");
    
    return 0;
}