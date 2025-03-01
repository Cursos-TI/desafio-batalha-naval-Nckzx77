#include <stdio.h>

int main() {
    char letras[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; //letras das colunas
    int tabuleiro[10][10] = {0}; //tabuleiro do jogo batalha naval
    int fimDoCone = 0;

    //apresentação
    printf("TABULEIRO DE BATALHA NAVAL\n");
    printf("\n");

    //definição dos navios horinzotalmente
    //alterar horinzotalmente significa alterar os segundos quadrados
    tabuleiro[2][2]= 3;
    tabuleiro[2][3]= 3;
    tabuleiro[2][4]= 3;

    //definição dos navios verticalmente
    //alterar verticalmente significa alterar os primeiros quadrados
    tabuleiro[5][8]= 3;
    tabuleiro[6][8]= 3;
    tabuleiro[7][8]= 3;
    
    //definição dos navios na diagonal
    //diagonal primária
    for (int i = 0; i < 10; i++)//declarando externo            
    {
        for (int j = 4; j < 7; j++)//declarando interno. O valor de J indica onde a diagonal segue
        {
            if (i == j )
            {
                tabuleiro[i][j] = 3;
            }
        }
    }

    //diagonal secundária
    for (int i = 0; i < 10; i++) //declarando externo
    {
        for (int j = 0; j < 3; j++) //declarando interno. O valor de J indica onde a diagonal segue
        {
            int soma = i + j; 
            if (soma == 9)
            {
                tabuleiro[i][j] = 3;
            }
        }
    }

    //Habilidades especiais. Habilidades tem o valor 5
    //habilidade do cone
    for (int i = 0; i < 10; i++) //declarando externo
    {
        for (int j = 0; j < 10; j++) //declarando interno.
        {
            if (i == 4 && i * j == 8)
            {
                tabuleiro[i][j] = 5; // primeira camada
            }

            if (i == 5 && i * j <= 15 && j != 0) 
            {
                tabuleiro[i][j] = 5; //segunda camada
            }

            if (i == 6 && i * j <= 24)
            {
                tabuleiro[i][j] = 5; //tericeira camada
            }
    
        }
    }

    //habilidade da cruz
    for (int i = 0; i < 10; i++) //declarando externo
    {
        for (int j = 0; j < 10; j++) //declarando interno.
        {
            if (j == 7 && i < 3)
            {
                tabuleiro[i][j] = 5; //parte vertical
            }

            if (i == 1 && j >= 5)
            {
                tabuleiro[i][j] = 5; //parte horizontal
            }
        }
    }

    //habilidade do octaedro
     for (int i = 0; i < 10; i++) //declarando externo
    {
        for (int j = 0; j < 10; j++) //declarando interno.
        {
            if (j == 5 && i >= 7)
            {
                tabuleiro[i][j] = 5;
            }

            if (i == 8 && j > 3 && j < 7)
            {
                tabuleiro[i][j] = 5;
            }
        }
    }
    
    
    //loops
    //loop aninhados para exibir as letras das colunas
    printf("   ");
    for (int i = 0; i < 10; i++){
        printf("%c ", letras[i]); //imprimindo as colunas
    }
    printf("\n");
    
    //loop aninhados para exibir tabuleiro
    for (int i = 0; i < 10; i++)
    {
        printf("%d  ", i); //mostrar as linhas
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }

        printf("\n");
    }

    printf("\n");
   
    return 0;
}