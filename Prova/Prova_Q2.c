
#include <stdio.h>
#include <stdlib.h>

void recursive_insertion_sort(int* array, int size) 
{ 
    // Caso Base 
    if (size <= 1) 
        return; 
  
    // Sorteia os n-1 elementos
    recursive_insertion_sort( array, size-1 ); 
  
// Insere o último elemento na posição correta
    // no array classificado.
    int last = array[size-1]; 
    int j = size-2; 
  
    /* Move elementos do array, que são
      maior que a chave, para uma posição à frente
      de sua posição atual */
    while (j >= 0 && array[j] > last) 
    { 
        array[j+1] = array[j]; 
        j--; 
    } 
    array[j+1] = last; 
} 

/*Imprime o vetor do insertion*/
void print_array(int* array, int size){
    for(int i = 0; i < size; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}

/*Função principal*/
int main (void){
	int size, value, *array;
	// Insira primeiro a quantidade de itens a lista, depois os valores na linha de baixo
	while(scanf("%d", &size) != EOF){
	    array = malloc (size * sizeof (int));
		for(int i = 0; i < size; i++){
			scanf("%d", &value);
			array[i] = value;
		}
		print_array(array, size);
    recursive_insertion_sort(array, size);
		print_array(array, size); 
		free(array);
	}
 
 	return 0;
}
/*
Exemplo de inserção
10
5 4 3 6 90 10 45 78 50 12

Saída (consiste do vetor normal e depois da saida reranjada)
5 4 3 6 90 10 45 78 50 12  
3 4 5 6 10 12 45 50 78 90 
	
*/

