#include <stdio.h>
#include <string.h> 
#define TAMANHO 100

int main()
{

 char string[TAMANHO];

  printf("Digite uma frase: ");
  fgets(string, TAMANHO, stdin);
  printf("O tamanho da string é: %lu\n", strlen(string));

return 0;
}