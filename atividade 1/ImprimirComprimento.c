#include<stdio.h>
#include <string.h> 
#define TAMANHO 100
      
int main() {     
      char string[TAMANHO];  
      printf("Digite uma frase:  \n");
      fgets(string, TAMANHO, stdin);

      char words[TAMANHO][TAMANHO], menor[TAMANHO], maior[TAMANHO];  
      int i = 0, j = 0, k, comprimento; 
      // Divide a string em palavras de modo que cada linha de palavras da matriz represente uma palavra  
        for(k=0; string[k]!='\0'; k++){  
            if(string[k] != ' ' && string[k] != '\0'){  
                // O i é a linha e j a coluna de palavras na matriz 
                words[i][j++] = string[k];  
            }  
            else{  
                words[i][j] = '\0';   
                i++;  
                j = 0;  
            }  
        }  
        // Armazena a contagem de linhas em tamanho variável
        comprimento = i + 1;  

        // Inicializa menor e grande com a primeira palavra na string
        strcpy(menor, words[0]);  
        strcpy(maior, words[0]);   
        // Determina a menor e a maior palavra na string
        for(k = 0; k < comprimento; k++){   


            // Se o tamanho de menor for maior que qualquer palavra presente na string
            // Armazena o valor da palavra em menor
            if(strlen(menor) > strlen(words[k])){  
                strcpy(menor, words[k]);  
            }   
            // Se tamanho maior for menor que qualquer palavra presente na string
            // Armazena o valor da palavra na string maior
            if(strlen(maior) < strlen(words[k]))  
                strcpy(maior, words[k]);  
        }  
        //Pega o tamnaho das strings menor e maior e armazena em variaveis
        int maior_tamanho = strlen(maior);
        int menor_tamanho = strlen(menor);

        //Retorna as variáveis na tela
        printf("Menor palavra: %s \n", menor);  
        printf("Menor palavra: %s \n", menor_tamanho); 
        printf("Maior Palavra: %d \n", maior);
        printf("Maior comprimento: %d \n", maior_tamanho);  
          
        return 0;  
    }  