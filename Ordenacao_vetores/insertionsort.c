#include <stdio.h>
#include <stdlib.h>


void print_array(int* array, int size){
    for(int i = 0; i < size; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}

int insertion_sort(int* array, int size){
	int i, j, temp, temp2, counter = 0;
	for(i = 1; i < size; i++){
	    temp = array[i];
	    for(j = i - 1; j >= 0 && array[j] > temp; j--){
	        temp2 = array[j+1];
	        array[j+1] = array[j];
	        array[j] = temp2;
	        counter++;
	        print_array(array, size);    
	    }
	    array[j+1] = temp;
	    
	    
	}
	return counter;
}

int main (void){
	int size, value, *array, swap;
	
	while(scanf("%d", &size) != EOF){
	    array = malloc (size * sizeof (int));
		for(int i = 0; i < size; i++){
			scanf("%d", &value);
			array[i] = value;
		}
		print_array(array, size);
		swap = insertion_sort(array, size);
		print_array(array, size); 
		printf("Trocas:%d\n", swap);
		free(array);
	}
	
	return 0;
}