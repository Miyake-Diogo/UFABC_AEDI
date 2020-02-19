#include <stdio.h>
int vetor_inverso(int tamanho);

int main(void) {
  int tamanho;
  printf("Digite o tamanho do vetor:\n");
  scanf("%d", &tamanho);
  vetor_inverso(tamanho);
  //printf("%d",vetor_inverso(tamanho));
  
return 0;
}

int vetor_inverso(int tamanho){
    //Recebe o tamnho do vetor e de seu inverso
    int vetor[tamanho], vet_inverso[tamanho];
    int i;
    //Escreve os numeros no Vetor
    for(i = 0; i < tamanho; i++) {
        printf("Digite um número:\n");
        scanf("%d", &vetor[i]);
    }
    //Inverte os vetores
    for(i = 0; i < tamanho; i++) {
        vet_inverso[i] = vetor[tamanho-i-1];
        printf("%d ", vet_inverso[i]);
    }
    return 0;
};