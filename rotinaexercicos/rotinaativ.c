#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define DIAS_SEMANA 7
#define MAX_EXERCICIOS 10
#define TAM_NOME 50

// Estrutura para armazenar informações de exercícios
typedef struct {
    char nome[TAM_NOME];
    int duracao_minutos;
    int calorias;
} Exercicio;

// Estrutura para armazenar informações de cada dia
typedef struct {
    Exercicio exercicios[MAX_EXERCICIOS];
    int quantidade_exercicios;
    int total_minutos;
    int total_calorias;
} DiaSemana;

// Nomes dos dias da semana
const char *nomes_dias[] = {
    "Segunda-feira", "Terca-feira", "Quarta-feira", 
    "Quinta-feira", "Sexta-feira", "Sabado", "Domingo"
};

// Função para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para exibir o menu principal
void exibirMenu() {
    printf("\n=== ROTINA DE ATIVIDADE FISICA ===\n");
    printf("1. Registrar exercicio\n");
    printf("2. Consultar dia\n");
    printf("3. Exibir resumo da semana\n");
    printf("4. Mostrar Top Day\n");
    printf("5. Sair\n");
    printf("Escolha uma opcao: ");
}

// Função para registrar um exercício
void registrarExercicio(DiaSemana semana[]) {
    int dia;
    printf("\n--- Registrar Exercicio ---\n");
    printf("Dias da semana:\n");
    for (int i = 0; i < DIAS_SEMANA; i++) {
        printf("%d. %s\n", i + 1, nomes_dias[i]);
    }
    printf("Escolha o dia (1-7): ");
    scanf("%d", &dia);
    
    if (dia < 1 || dia > DIAS_SEMANA) {
        printf("Dia invalido!\n");
        return;
    }
    
    dia--; // Ajusta para índice do array (0-6)
    
    if (semana[dia].quantidade_exercicios >= MAX_EXERCICIOS) {
        printf("Limite de exercicios atingido para este dia!\n");
        return;
    }
    
    Exercicio novo_exercicio;
    limparBuffer();
    
    printf("Nome do exercicio: ");
    fgets(novo_exercicio.nome, TAM_NOME, stdin);
    novo_exercicio.nome[strcspn(novo_exercicio.nome, "\n")] = '\0'; // Remove quebra de linha
    
    printf("Duracao (minutos): ");
    scanf("%d", &novo_exercicio.duracao_minutos);
    
    printf("Calorias gastas: ");
    scanf("%d", &novo_exercicio.calorias);
    
    // Adiciona o exercício ao dia
    semana[dia].exercicios[semana[dia].quantidade_exercicios] = novo_exercicio;
    semana[dia].quantidade_exercicios++;
    semana[dia].total_minutos += novo_exercicio.duracao_minutos;
    semana[dia].total_calorias += novo_exercicio.calorias;
    
    printf("Exercicio registrado com sucesso!\n");
}

// Função para consultar um dia específico
void consultarDia(DiaSemana semana[]) {
    int dia;
    printf("\n--- Consultar Dia ---\n");
    printf("Dias da semana:\n");
    for (int i = 0; i < DIAS_SEMANA; i++) {
        printf("%d. %s\n", i + 1, nomes_dias[i]);
    }
    printf("Escolha o dia (1-7): ");
    scanf("%d", &dia);
    
    if (dia < 1 || dia > DIAS_SEMANA) {
        printf("Dia invalido!\n");
        return;
    }
    
    dia--; // Ajusta para índice do array
    
    printf("\n=== %s ===\n", nomes_dias[dia]);
    printf("Total de exercicios: %d\n", semana[dia].quantidade_exercicios);
    printf("Tempo total: %d minutos\n", semana[dia].total_minutos);
    printf("Calorias totais: %d\n", semana[dia].total_calorias);
    
    if (semana[dia].quantidade_exercicios > 0) {
        printf("\nExercicios realizados:\n");
        for (int i = 0; i < semana[dia].quantidade_exercicios; i++) {
            printf("%d. %s - %d min - %d cal\n", 
                i + 1, 
                semana[dia].exercicios[i].nome,
                semana[dia].exercicios[i].duracao_minutos,
                semana[dia].exercicios[i].calorias);
        }
    } else {
        printf("Nenhum exercicio registrado para este dia.\n");
    }
}

// Função para exibir resumo da semana
void exibirResumoSemana(DiaSemana semana[]) {
    printf("\n=== RESUMO DA SEMANA ===\n");
    printf("%-15s %-10s %-10s %-10s\n", "Dia", "Exercicios", "Minutos", "Calorias");
    printf("------------------------------------------------\n");
    
    for (int i = 0; i < DIAS_SEMANA; i++) {
        printf("%-15s %-10d %-10d %-10d\n", 
            nomes_dias[i], 
            semana[i].quantidade_exercicios,
            semana[i].total_minutos,
            semana[i].total_calorias);
    }
}

// Função para encontrar e mostrar o Top Day
void mostrarTopDay(DiaSemana semana[]) {
    int top_dia = 0;
    int max_exercicios = semana[0].quantidade_exercicios;
    int max_minutos = semana[0].total_minutos;
    int max_calorias = semana[0].total_calorias;
    
    // Encontra o dia com mais exercícios
    for (int i = 1; i < DIAS_SEMANA; i++) {
        if (semana[i].quantidade_exercicios > max_exercicios) {
            max_exercicios = semana[i].quantidade_exercicios;
            top_dia = i;
        }
    }
    
    printf("\n === TOP DAY === \n");
    printf("Dia com mais atividades: %s\n", nomes_dias[top_dia]);
    printf("Total de exercicios: %d\n", semana[top_dia].quantidade_exercicios);
    printf("Tempo total: %d minutos\n", semana[top_dia].total_minutos);
    printf("Calorias totais: %d\n", semana[top_dia].total_calorias);
    
    if (semana[top_dia].quantidade_exercicios > 0) {
        printf("\nExercicios realizados:\n");
        for (int i = 0; i < semana[top_dia].quantidade_exercicios; i++) {
            printf("- %s - %d min - %d cal\n", 
                semana[top_dia].exercicios[i].nome,
                semana[top_dia].exercicios[i].duracao_minutos,
                semana[top_dia].exercicios[i].calorias);
        }
    }
}

// Função para inicializar a semana
void inicializarSemana(DiaSemana semana[]) {
    for (int i = 0; i < DIAS_SEMANA; i++) {
        semana[i].quantidade_exercicios = 0;
        semana[i].total_minutos = 0;
        semana[i].total_calorias = 0;
    }
}

int main() {
    DiaSemana semana[DIAS_SEMANA];
    int opcao;
    
    // Inicializa a semana
    inicializarSemana(semana);
    
    printf("Bem-vindo ao Sistema de Rotina de Atividade Fisica!\n");
    
    do {
        exibirMenu();
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                registrarExercicio(semana);
                break;
            case 2:
                consultarDia(semana);
                break;
            case 3:
                exibirResumoSemana(semana);
                break;
            case 4:
                mostrarTopDay(semana);
                break;
            case 5:
                printf("Obrigado por usar o sistema! Ate mais!\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
        
    } while (opcao != 5);
    
    return 0;
}