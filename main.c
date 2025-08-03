#include <stdio.h>

int main() {
    // Aqui tô declarando a variavel
    char nome[50];
    int idade;

    // Para a entrada de Dados.
    printf("Digite seu nome: ");
    scanf("%s", nome); // Vai lê até o primeiro espaço

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    // Aqui a saida já sai formatada
    printf("\n--- DADOS CADASTRADOS ---\n");
    printf("Nome: %s\n", nome);
    printf("Idade: %d anos\n", idade);

    return 0;
}