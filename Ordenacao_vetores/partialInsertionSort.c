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

int partial_selection_sort(int* array, int size, int k){
	int i, j, imin, aux;
	
	for(i = 0; i < k; i++){
	    imin = i;
	    
	    for(j = i + 1; j < size ; j++){
	        if(array[imin]>array[j])
            imin = j;   
	    }
	    if(imin!=i){
        aux=array[imin];
        array[imin]= array[i];
        array[i] = aux;
      }
	//printArray(array, size);    
	    
	}
}
/*
void selectionsort_partial (int* v, int tam, int k){
  int i,min, count=0;
  for (i=0; i<k; i++){
    min = menor(v,i,tam-1);
    if(min != i){
      count++;
      troca (v,min,i);}
  printArray(v, tam);
    
  }
  printf("%d\n", count);
    return;
}
*/
int main(void) {
  int n, v[10000], i, k;
  while (scanf("%d", &n) != EOF){  
  
  for (i = 0; i < n; i++){
    scanf("%d", &v[i]);
    }
  scanf("%d", &k);
  printArray(v, n);
  partial_selection_sort(v,n, k);
  printArray(v, n);
  break;
  }

}
