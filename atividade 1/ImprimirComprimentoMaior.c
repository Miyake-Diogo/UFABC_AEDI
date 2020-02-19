#include<stdio.h>
#include <string.h> 
#define TAMANHO 100
      
int main() {     
      char string[TAMANHO];  
      printf("Digite uma frase:  \n");
      fgets(string, TAMANHO, stdin);

      char words[TAMANHO][TAMANHO], menor[TAMANHO], maior[TAMANHO];  
      int linha = 0, coluna = 0, contador, comprimento; 
      // Divide a string em palavras de modo que cada linha de palavras da matriz represente uma palavra  
        for(contador=0; string[contador]!='\0'; contador++){  
            if(string[contador] != ' ' && string[contador] != '\0'){  
                
                words[linha][coluna++] = string[k];  
            }  
            else{  
                words[linha][coluna] = '\0';   
                linha++;  
                coluna = 0;  
            }  
        }  
        // Armazena a contagem de linhas em tamanho variável
        comprimento = linha + 1;  

        // Inicializa menor e maior com a primeira palavra na string
        strcpy(menor, words[0]);  
        strcpy(maior, words[0]);   
        // Determina a menor e a maior palavra na string
        for(contador = 0; contador < comprimento; contador++){   


            // Se o tamanho de menor for maior que qualquer palavra presente na string
            // Armazena o valor da palavra em menor
            if(strlen(menor) > strlen(words[contador])){  
                strcpy(menor, words[contador]);  
            }   
            // Se tamanho maior for menor que qualquer palavra presente na string
            // Armazena o valor da palavra na string maior
            if(strlen(maior) < strlen(words[contador]))  
                strcpy(maior, words[contador]);  
        }  
        //Pega o tamanho da e maior e armazena em variaveis
        int maior_tamanho = strlen(maior);

        //Retorna a variáveis na tela
 
        printf("Maior comprimento: %d \n", maior_tamanho);  
          
        return 0;  
    }  