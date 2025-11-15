#include <stdio.h>
#include <stdlib.h> // Inclui para usar a função abs() no Octaedro

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
        // Verificação de sobreposição
        if (tabuleiro[lin_h][col_h] == 0 && tabuleiro[lin_h][col_h+1] == 0 && tabuleiro[lin_h][col_h+2] == 0) {
            tabuleiro[lin_h][col_h] = 3;
            tabuleiro[lin_h][col_h+1] = 3;
            tabuleiro[lin_h][col_h+2] = 3;
        }
    }

    // 3. NAVIO DIAGONAL PRINCIPAL (Descendo a escada: linha aumenta, coluna aumenta)
    int lin_d1 = 0, col_d1 = 8;
    if (lin_d1 + 2 < 10 && col_d1 + 2 < 10) {
         if (tabuleiro[lin_d1][col_d1] == 0 && 
             tabuleiro[lin_d1+1][col_d1+1] == 0 && 
             tabuleiro[lin_d1+2][col_d1+2] == 0) {
                 
            tabuleiro[lin_d1][col_d1] = 3;
            tabuleiro[lin_d1+1][col_d1+1] = 3;
            tabuleiro[lin_d1+2][col_d1+2] = 3;
         }
    }

    // 4. NAVIO DIAGONAL SECUNDÁRIA (Subindo a escada: linha diminui, coluna aumenta)
    int lin_d2 = 9, col_d2 = 0;
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


    // ------------------------------------------------------------------------
    // Nível Mestre - Habilidades Especiais com Matrizes
    // ------------------------------------------------------------------------
    printf("\n--------------------------------------------------\n");
    printf("INICIANDO NIVEL MESTRE\n");

    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    int matriz_cone[5][5];
    int matriz_cruz[5][5];
    int matriz_octaedro[5][5];

    // Inicializando e desenhando as matrizes de habilidade dinamicamente
    // Uso loops aninhados e condicionais conforme pedido.
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Resetando para 0 (não afetado) antes de desenhar
            matriz_cone[i][j] = 0;
            matriz_cruz[i][j] = 0;
            matriz_octaedro[i][j] = 0;

            // Habilidade CONE (Triângulo apontando para baixo)
            // A lógica é: linha 0 tem 1 elemento, linha 1 tem 3, linha 2 tem 5.
            // O centro da coluna é o índice 2.
            if (i < 3) { // Limita a altura do cone
                if (j >= (2 - i) && j <= (2 + i)) {
                    matriz_cone[i][j] = 1;
                }
            }

            // Habilidade CRUZ
            // Preenche toda a linha central (2) ou toda a coluna central (2)
            if (i == 2 || j == 2) {
                matriz_cruz[i][j] = 1;
            }

            // Habilidade OCTAEDRO (Losango)
            // A lógica matemática do losango é a Distância de Manhattan do centro (2,2).
            // Soma da distância da linha + distância da coluna deve ser <= 1 (para um losango pequeno).
            // abs() pega o valor absoluto (módulo).
            if (abs(i - 2) + abs(j - 2) <= 1) {
                matriz_octaedro[i][j] = 1;
            }
        }
    }

    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Vou definir um "ponto de origem" no tabuleiro 10x10 para aplicar cada habilidade.
    // Esse ponto representa onde o canto superior esquerdo da matriz 5x5 da habilidade vai encaixar.
    
    // Aplicando CONE (origem na linha 0, coluna 2)
    int origem_cone_lin = 0;
    int origem_cone_col = 2;
    
    // Aplicando CRUZ (origem na linha 4, coluna 4)
    int origem_cruz_lin = 4;
    int origem_cruz_col = 4;

    // Aplicando OCTAEDRO (origem na linha 7, coluna 0)
    int origem_octa_lin = 7;
    int origem_octa_col = 0;

    // Loop para percorrer o tabuleiro e aplicar as mascaras
    // A lógica aqui é percorrer a matriz 5x5 da habilidade e somar sua posição à origem.
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            
            // Aplicando o CONE
            if (matriz_cone[i][j] == 1) {
                int tabuleiro_lin = origem_cone_lin + i;
                int tabuleiro_col = origem_cone_col + j;
                
                // Validação de limites: só pinta se estiver dentro do 10x10
                if (tabuleiro_lin >= 0 && tabuleiro_lin < 10 && tabuleiro_col >= 0 && tabuleiro_col < 10) {
                    tabuleiro[tabuleiro_lin][tabuleiro_col] = 5; // 5 representa área afetada
                }
            }

            // Aplicando a CRUZ
            if (matriz_cruz[i][j] == 1) {
                int tabuleiro_lin = origem_cruz_lin + i;
                int tabuleiro_col = origem_cruz_col + j;
                
                if (tabuleiro_lin >= 0 && tabuleiro_lin < 10 && tabuleiro_col >= 0 && tabuleiro_col < 10) {
                    tabuleiro[tabuleiro_lin][tabuleiro_col] = 5;
                }
            }

            // Aplicando o OCTAEDRO
            if (matriz_octaedro[i][j] == 1) {
                int tabuleiro_lin = origem_octa_lin + i;
                int tabuleiro_col = origem_octa_col + j;
                
                if (tabuleiro_lin >= 0 && tabuleiro_lin < 10 && tabuleiro_col >= 0 && tabuleiro_col < 10) {
                    tabuleiro[tabuleiro_lin][tabuleiro_col] = 5;
                }
            }
        }
    }

    // Sugestão: Exiba o tabuleiro com as áreas afetadas.
    printf(" TABULEIRO MESTRE (Com Habilidades)\n");
    printf("   A B C D E F G H I J\n"); 

    for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1); 
        for (int j = 0; j < 10; j++) {
            // Exibe 0 para água, 3 para navio, 5 para habilidade
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n"); 
    }

    return 0;
}