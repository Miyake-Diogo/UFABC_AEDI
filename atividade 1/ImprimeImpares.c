#include <stdio.h>
int imprime_naturais_impares(int num);

int main(void) {
  int num;
  printf("Escolha um inteiro: \n");

  scanf("%d", &num);
  printf("%d",imprime_naturais_impares(num));
  return 0;
}

int imprime_naturais_impares(int num){
  int i;
  int impar=1;
  //recebe os numeros e verficia se são impares ou não
  for(i=0; i < num-1; i++){
      printf("%d ", impar);
      impar = impar + 2;
  } 
  return impar;
};