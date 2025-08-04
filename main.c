#include <stdio.h>

struct Pessoa {
    char nome[50];
    int idade;
    float altura;
    char sexo;
};


int main() {
    struct Pessoa pessoas[5];
    int totalIdade = 0;

    // Para a entrada de Dados.
    for (int i = 0; i < 5; i++) { 
        printf("Digite seu nome %d: ", i+1);
        scanf("%s", pessoas[i].nome); // Vai lê até o primeiro espaço

        printf("Digite sua idade: ");
        scanf("%d", &pessoas[i].idade);

        printf("Digite sua altura: ");
        scanf("%f", &pessoas[i].altura);

        printf("Digite seu sexo (M/F): ");
        scanf(" %c", &pessoas[i].sexo);

        printf("\n");
    }

    // Aqui a saida já sai formatada
    printf("\n--- DADOS CADASTRADOS ---\n");
    for (int i = 0; i < 5; i++) {
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Idade: %d anos\n", pessoas[i].idade);
        printf("Altura: %.2f m\n", pessoas[i].altura);
        printf("Sexo: %c\n", pessoas[i].sexo);
    

        printf("Classificação: ");

        if (pessoas[i].idade >= 18) {
            printf("Maior de idade");
            totalIdade += 1;
        } else{
            printf("Menor de idade");
        }

        if (pessoas[i].sexo == 'M' || pessoas[i].sexo == 'm') {
        printf(" (Masculino)");
        } else if (pessoas[i].sexo == 'F' || pessoas[i].sexo == 'f') {
        printf(" (Feminino)");
        } else {
        printf(" (Não informado)");
        }

        printf("\n");
    }

    printf("Total de Maiores de idade: %d\n", totalIdade);

    return 0;
}