#include <stdio.h>
#include <locale.h>

float sum(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    while (b == 0) {
        printf("Erro: Divisão por zero não é permitida.\n");
        break;
    }
    return a / b;
}

int main(void) {
    int operation, c;
    float a, b;
    char yOrN;

    setlocale(LC_ALL, "Portuguese_Brazil.1252");

    do {
        printf("\n+-*/+-*/+-*/+-*/+-*/+-*/+-*\n");
        printf("    Calculadora simples    \n");
        printf("/*-+/*-+/*-+/*-+/*-+/*-+/*-+\n");
        printf("Selecione uma operação:\n");
        printf("1. Adição\n2. Subtração\n3. Multiplicação\n4. Divisão\n5. Sair\n");
        printf("Opção: ");

        while (scanf("%d", &operation) != 1 || operation < 1 || operation > 5) {
            printf("Entrada inválida. Digite um número de 1 a 5: ");
            while ((c = getchar()) != '\n' && c != EOF); //Limpa o buffer caso a entrada for inválida
        }


        if (operation == 5) {
            printf("Muito obrigado por usar a calculadora. Até a próxima!\n");
            return 0;
        }

        printf("Digite o primeiro número: ");
        while (scanf("%f", &a) != 1) {
            printf("Entrada inválida. Escreva um NÚMERO ok?");
            while ((c = getchar()) != '\n' && c != EOF);
        }

        printf("Digite o segundo número: ");
        while (scanf("%f", &b) != 1) {
            printf("Entrada inválida. Escreva outro NÚMERO ok?");
            while ((c = getchar()) != '\n' && c != EOF);
        }

        switch (operation) {
            case 1:
                printf("Resultado: %.2f + %.2f = %.2f\n", a, b, sum(a, b));
                break;
            case 2:
                printf("Resultado: %.2f - %.2f = %.2f\n", a, b, subtract(a, b));
                break;
            case 3:
                printf("Resultado: %.2f * %.2f = %.2f\n", a, b, multiply(a, b));
                break;
            case 4: {
                if (b == 0){
                    divide(a, b);
                    break;
                }
                float result = divide(a, b);
                printf("Resultado: %.2f / %.2f = %.2f\n", a, b, result);
                break;
            }
            default:
                printf("Erro interno: operação desconhecida.\n");
                break;
        }

        printf("Deseja realizar outra operação? (s/n): ");
        scanf(" %c", &yOrN);

        while (yOrN != 's' && yOrN != 'n' && yOrN != 'S' && yOrN != 'N') {
            printf("Resposta inválida. Por favor, digite 's' para sim e 'n' para não: ");
            scanf(" %c", &yOrN);
            while ((getchar()) != '\n');
        }
    } while (yOrN ==  's' || yOrN == 'S');

    printf("Muito obrigado por usar a calculadora. Até a próxima!\n");
    return 0;
}
//Não está funcionando a ascentuação no cmd ;-;
