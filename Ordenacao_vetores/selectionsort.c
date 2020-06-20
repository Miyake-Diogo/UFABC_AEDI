#include <stdio.h>

// Selection Sort


/*Funçãão imprime vetor */
void printArray(int v[], int n) 
{ 
    int i; 
    for (i=0; i < n; i++) 
        printf("%d ", v[i]); 
    printf("\n"); 
} 


/*Função para troca de elementos do vetor
*/
void troca (int* v, int i, int j){
  int tmp, c;
  tmp = v[i];
  v[i] = v[j];
  v[j] = tmp;
  c++;
  return;
}
/* Devolve o indice do menor elemento dosub-vetor v[a..b] */

int menor (int* v, int a, int b){
  
  int i,min = a;
  for (i=a+1; i<=b; i++){
    if (v[i] < v[min]){
      min = i;
    }
  }
  return min;
}

void selectionsort (int* v, int tam){
  int i,min, count=0;
  for (i=0; i<tam; i++){
    min = menor(v,i,tam-1);
    if(min != i){
      count++;
      troca (v,min,i);}
  printArray(v, tam);
    
  }
  printf("%d\n", count);
    return;
}

int main(void) {
  int n, v[10000], i;
  while (scanf("%d", &n) != EOF){  
  
  for (i = 0; i < n; i++){
    scanf("%d", &v[i]);
    }
  printArray(v, n);
  selectionsort(v,n);
  break;
  }

}

/* in
10
54 12 2 90 4 78 55 21 2 48
*/

/* out


54 12 2 90 4 78 55 21 2 48 
2 12 54 90 4 78 55 21 2 48 
2 2 54 90 4 78 55 21 12 48 
2 2 4 90 54 78 55 21 12 48 
2 2 4 12 54 78 55 21 90 48 
2 2 4 12 21 78 55 54 90 48 
2 2 4 12 21 48 55 54 90 78 
2 2 4 12 21 48 54 55 90 78 
2 2 4 12 21 48 54 55 90 78 
2 2 4 12 21 48 54 55 78 90 
2 2 4 12 21 48 54 55 78 90 
10

Esperado
54 12 2 90 4 78 55 21 2 48 ok
2 12 54 90 4 78 55 21 2 48 ok
2 2 54 90 4 78 55 21 12 48 ok
2 2 4 90 54 78 55 21 12 48 ok
2 2 4 12 54 78 55 21 90 48 ok
2 2 4 12 21 78 55 54 90 48 ok
2 2 4 12 21 48 55 54 90 78
2 2 4 12 21 48 54 55 90 78
2 2 4 12 21 48 54 55 90 78 r
2 2 4 12 21 48 54 55 78 90
2 2 4 12 21 48 54 55 78 90 r
8
*/