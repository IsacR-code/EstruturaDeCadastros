// %s - String (char[])
// %d - Inteiro (int)
// %f - Ponto flutuante (float, double)
// %c - Caractere (char)

#include <stdio.h>

struct Pessoa {
    char nome[50];
    int idade;
    float altura;
    char sexo;
};

void imprimirPessoa(struct Pessoa p) {
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d anos\n", p.idade);
    printf("Altura: %.2f m\n", p.altura);
    printf("Sexo: %c\n", p.sexo);

    printf("Classificação: ");
    if (p.idade >= 18) {
        printf("Maior de idade");
    } else {
        printf("Menor de idade");
    }

    if (p.sexo == 'M' || p.sexo == 'm') {
        printf(" (Masculino)");
    } else if (p.sexo == 'F' || p.sexo == 'f') {
        printf(" (Feminino)");
    } else {
        printf(" (Não informado)");
    }

    printf("\n");
}

void salvarPessoa(FILE *arquivo, struct Pessoa p) {
    fprintf(arquivo, "Nome: %s\n", p.nome);
    fprintf(arquivo, "Idade: %d anos\n", p.idade);
    fprintf(arquivo, "Altura: %.2f m\n", p.altura);
    fprintf(arquivo, "Sexo: %c\n", p.sexo);

    fprintf(arquivo, "Classificação: ");
    if (p.idade >= 18) {
        fprintf(arquivo, "Maior de idade");
    } else {
        fprintf(arquivo, "Menor de idade");
    }

    if (p.sexo == 'M' || p.sexo == 'm') {
        fprintf(arquivo, " (Masculino)");
    } else if (p.sexo == 'F' || p.sexo == 'f') {
        fprintf(arquivo, " (Feminino)");
    } else {
        fprintf(arquivo, " (Não informado)");
    }

    fprintf(arquivo, "\n\n");
}

int main() {
    struct Pessoa pessoas[5];
    int totalIdade = 0;    

    // Para a entrada de Dados.
    for (int i = 0; i < 5; i++) { 
        printf("Digite seu nome %d: ", i+1);
        scanf("%s", pessoas[i].nome); // scanf é usado para ler e amarzenar valores.

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
    imprimirPessoa(pessoas[i]);  // Chama a função e imprime tudo
    totalIdade += (pessoas[i].idade >= 18);  // Mantém a contagem
    printf("\n");
}
    printf("Total de Maiores de idade: %d\n", totalIdade);

        // Salvando os dados em um arquivo
    FILE *arquivo = fopen("cadastros.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return 1; // encerra o programa
    }

    fprintf(arquivo, "--- DADOS CADASTRADOS ---\n");
    for (int i = 0; i < 5; i++) {
    salvarPessoa(arquivo, pessoas[i]);
}

    fprintf(arquivo, "Total de Maiores de idade: %d\n", totalIdade);

    fclose(arquivo);


    return 0;
}