#include <stdio.h>
#include <string.h>

// Estrutura de uma carta
struct Carta {
    char nome[30];
    float populacao;
    float area;
    float pib;
    float densidade;
};

int main() {
    struct Carta carta1 = {"Brasil", 213.3, 8516.0, 2200.0, 213.3 / 8516.0};
    struct Carta carta2 = {"Canadá", 38.0, 9984.0, 2000.0, 38.0 / 9984.0};

    int atributo1, atributo2;
    float valor1_c1, valor1_c2, valor2_c1, valor2_c2;
    float soma_c1, soma_c2;

    printf("=== SUPER TRUNFO - COMPARAÇÃO AVANÇADA ===\n\n");
    printf("Carta 1: %s\n", carta1.nome);
    printf("Carta 2: %s\n\n", carta2.nome);

    // Menu de escolha do primeiro atributo
    printf("Escolha o primeiro atributo:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &atributo1);

    // Menu dinâmico (retira o atributo já escolhido)
    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    switch (atributo1) {
        case 1:
            printf("2 - Área\n3 - PIB\n4 - Densidade Demográfica\n");
            break;
        case 2:
            printf("1 - População\n3 - PIB\n4 - Densidade Demográfica\n");
            break;
        case 3:
            printf("1 - População\n2 - Área\n4 - Densidade Demográfica\n");
            break;
        case 4:
            printf("1 - População\n2 - Área\n3 - PIB\n");
            break;
        default:
            printf("Opção inválida!\n");
            return 1;
    }
    printf("Opção: ");
    scanf("%d", &atributo2);

    // Impedir que os dois atributos sejam iguais
    if (atributo1 == atributo2) {
        printf("\nErro: os atributos devem ser diferentes!\n");
        return 1;
    }

    // Função auxiliar (com if simples)
    float pegarValor(struct Carta c, int atributo) {
        switch (atributo) {
            case 1: return c.populacao;
            case 2: return c.area;
            case 3: return c.pib;
            case 4: return c.densidade;
            default: return 0;
        }
    }

    valor1_c1 = pegarValor(carta1, atributo1);
    valor1_c2 = pegarValor(carta2, atributo1);
    valor2_c1 = pegarValor(carta1, atributo2);
    valor2_c2 = pegarValor(carta2, atributo2);

    // Comparações (densidade vence com menor valor)
    int resultado1 = (atributo1 == 4) ? (valor1_c1 < valor1_c2) : (valor1_c1 > valor1_c2);
    int resultado2 = (atributo2 == 4) ? (valor2_c1 < valor2_c2) : (valor2_c1 > valor2_c2);

    soma_c1 = valor1_c1 + valor2_c1;
    soma_c2 = valor1_c2 + valor2_c2;

    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");
    printf("%s - Atributos: %.2f e %.2f (soma: %.2f)\n", carta1.nome, valor1_c1, valor2_c1, soma_c1);
    printf("%s - Atributos: %.2f e %.2f (soma: %.2f)\n", carta2.nome, valor1_c2, valor2_c2, soma_c2);

    if (soma_c1 > soma_c2)
        printf("\nVencedor: %s!\n", carta1.nome);
    else if (soma_c2 > soma_c1)
        printf("\nVencedor: %s!\n", carta2.nome);
    else
        printf("\nEmpate!\n");

    return 0;
}
