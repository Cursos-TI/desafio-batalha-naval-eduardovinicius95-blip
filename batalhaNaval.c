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
    
    printf(" TABULEIRO BATALHA NAVAL (Nivel Novato)\n");
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


    // ------------------------------------------------------------------------
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // ------------------------------------------------------------------------
    printf("\n--------------------------------------------------\n");
    printf("INICIANDO NIVEL AVENTUREIRO\n");
    
    // Requisito: Inicialize todas as posições com o valor 0.
    // Estou limpando a matriz para posicionar os 4 novos navios deste nível sem interferência do nível anterior.
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            tabuleiro[i][j] = 0;
        }
    }

    // Requisito: Posicionar 4 navios (2 horizontais/verticais e 2 diagonais).
    // Tamanho fixo = 3. Valor = 3.
    
    // 1. NAVIO VERTICAL (Colocando na Coluna B)
    // Validação: Verifico se a linha final (linha + 2) está dentro do tabuleiro (menor que 10).
    // Como limpei o tabuleiro agora, não preciso checar sobreposição neste primeiro, mas a lógica seria (tabuleiro[x][y] == 0).
    int lin_v = 1, col_v = 1; // Início em B2
    if (lin_v + 2 < 10) {
        tabuleiro[lin_v][col_v] = 3;
        tabuleiro[lin_v+1][col_v] = 3;
        tabuleiro[lin_v+2][col_v] = 3;
    }

    // 2. NAVIO HORIZONTAL (Colocando na Linha 8)
    // Validação: Verifico se a coluna final (coluna + 2) está dentro do limite.
    int lin_h = 7, col_h = 3; // Início em D8
    if (col_h + 2 < 10) {
        // Verificação de sobreposição simples (embora eu saiba que está vazio, o requisito pede validação)
        if (tabuleiro[lin_h][col_h] == 0 && tabuleiro[lin_h][col_h+1] == 0 && tabuleiro[lin_h][col_h+2] == 0) {
            tabuleiro[lin_h][col_h] = 3;
            tabuleiro[lin_h][col_h+1] = 3;
            tabuleiro[lin_h][col_h+2] = 3;
        }
    }

    // 3. NAVIO DIAGONAL PRINCIPAL (Descendo a escada: linha aumenta, coluna aumenta)
    // Início: (0, 8) -> Canto superior direito (I1)
    int lin_d1 = 0, col_d1 = 8;
    
    // Validação: Preciso garantir que tanto linha quanto coluna não estouram o limite 10 ao somar 2.
    if (lin_d1 + 2 < 10 && col_d1 + 2 < 10) {
         // Validação de sobreposição para as 3 partes
         if (tabuleiro[lin_d1][col_d1] == 0 && 
             tabuleiro[lin_d1+1][col_d1+1] == 0 && 
             tabuleiro[lin_d1+2][col_d1+2] == 0) {
                 
            tabuleiro[lin_d1][col_d1] = 3;
            tabuleiro[lin_d1+1][col_d1+1] = 3;
            tabuleiro[lin_d1+2][col_d1+2] = 3;
         }
    }

    // 4. NAVIO DIAGONAL SECUNDÁRIA (Subindo a escada: linha diminui, coluna aumenta)
    // Início: (9, 0) -> Canto inferior esquerdo (A10)
    // Vai ocupar: (9,0), (8,1), (7,2)
    int lin_d2 = 9, col_d2 = 0;

    // Validação: Linha deve ser >= 2 (pois vamos subtrair) e coluna < 8 (pois vamos somar).
    if (lin_d2 - 2 >= 0 && col_d2 + 2 < 10) {
        if (tabuleiro[lin_d2][col_d2] == 0 && 
            tabuleiro[lin_d2-1][col_d2+1] == 0 && 
            tabuleiro[lin_d2-2][col_d2+2] == 0) {
            
            tabuleiro[lin_d2][col_d2] = 3;
            tabuleiro[lin_d2-1][col_d2+1] = 3;
            tabuleiro[lin_d2-2][col_d2+2] = 3;
        }
    }

    // Requisito: Exibir o Tabuleiro Completo
    printf(" TABULEIRO AVENTUREIRO (4 Navios)\n");
    printf("   A B C D E F G H I J\n"); 

    for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1); 
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n"); 
    }


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