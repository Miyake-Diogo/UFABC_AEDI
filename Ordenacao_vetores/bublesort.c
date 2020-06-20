#include <stdio.h>
#include <stdlib.h>


void print_array(int* array, int size){
    for(int i = 0; i < size; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}

void swap (int* array, int i, int j){
    int tmp;
    
    tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
    return;
}


void bubble_sort(int* array, int size){
	int i, j;
	for(i = size - 1; i >= 0; i--){
	    
	    for(j = size - 1; j >= 1; j--){
	        if(array[j] < array[j-1]){
	            swap(array, j, j-1);
            }
            
	    }
	    print_array(array, size);
	}
	return;
}

int main (void){
	int size, value, *array;
	
	while(scanf("%d", &size) != EOF){
	    array = malloc (size * sizeof (int));
		for(int i = 0; i < size; i++){
			scanf("%d", &value);
			array[i] = value;
		}
		print_array(array, size);
		bubble_sort (array, size);
		free(array);
	}
	
	return 0;
}