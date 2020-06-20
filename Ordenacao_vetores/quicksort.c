#include<stdio.h> 
  
// troca dos elementos
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  
/* Esta função assume o último elemento como pivô, coloca
   o elemento pivô na sua posição correta em ordenado
    matriz e coloca todos menores (menores que o pivô)
   à esquerda do pivô e todos os elementos maiores à direita
   de pivô */

int partition (int arr[], int low, int high, int* count) 
{ 
    int pivot = arr[high];    // pivo 

    int i = (low - 1);  // Indice do menor elemento 
  
    for (int j = low; j <= high- 1; j++) 
    {   
        (*count)++;
        // se o elemento atual for menor que o pivo 
        if (arr[j] < pivot) 
        { 
            i++;    // incrementa o indice do menor elemento 
            swap(&arr[i], &arr[j]);
            //(*count)++; 
        } 
        
    }
    //(*count)++; 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

/* implementaçãão do quickSort
 arr[] --> vetor a ser ordenado, 
  low  --> primeiro indice, 
  high  --> indice final */
void quickSort(int arr[], int low, int high, int* count) 
{   
    
    if (low < high) 
    { 
        int pi = partition(arr, low, high, count);
        
        quickSort(arr, low, pi - 1,count); 
        //(*count)++;
        quickSort(arr, pi + 1, high,count);
        //(*count)++;
        
    } 
    
    //return (*count);
} 
  
/* Imprime o vetor */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
  
// Main
int main() 
{ 
  int n, v[10000], i, count=0;
  while (scanf("%d", &n) != EOF){  
  
  for (i = 0; i < n; i++){
    scanf("%d", &v[i]);
    }
  printArray(v, n);
  quickSort(v, 0, n-1, &count);
  printArray(v, n);
  printf("Comparacoes: %d\n", count);
  break;
  }
  return 0; 
} 
/*
Entrada
10
9 65 12 7 21 5 7 46 52 10
Saida
9 65 12 7 21 5 7 46 52 10
5 7 7 9 10 12 21 46 52 65
Comparacoes: 20
##########
Entrada 
1
20

Saida
20
20
Comparacoes: 0

Entrada 
10
0 1 2 3 4 5 6 7 8 9
Saida
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
Comparacoes: 45
*/