#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    
    // OBS: O enunciado sugere 5x5, mas para ficar igual ao exemplo visual (até a letra J), 
    // eu defini a matriz como 10x10 logo de inicio.
    int tabuleiro[10][10] = {0};

    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    
    // Posicionando navios manualmente (hardcoded) como pedido no nível básico.
    // Navio Vertical (coluna H/índice 7, linhas 6, 7, 8)
    tabuleiro[5][7] = 3;
    tabuleiro[6][7] = 3;
    tabuleiro[7][7] = 3;

    // Navio Horizontal (linha 3/índice 2, colunas E, F, G)
    tabuleiro[2][4] = 3;
    tabuleiro[2][5] = 3;
    tabuleiro[2][6] = 3;

    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Aqui eu fiz a estrutura de repetição para exibir o tabuleiro formatado
    // com as letras em cima e os números na lateral.
    
    printf(" TABULEIRO BATALHA NAVAL\n");
    printf("   A B C D E F G H I J\n"); // Cabeçalho das colunas

    for (int i = 0; i < 10; i++) {
        // O %2d serve para alinhar o número 10 com os números de 1 digito
        printf("%2d ", i + 1); 

        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n"); // Quebra de linha para montar o grid
    }
    
    // Exibindo coordenadas específicas como o nível pede
    printf("\nCoordenadas exibidas:\n");
    printf("Navio Vertical: (H6, H7, H8)\n");
    printf("Navio Horizontal: (E3, F3, G3)\n");


    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // (Código a ser implementado futuramente...)


    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}