#include <stdio.h>
#include <stdlib.h>

int *contaprimos(int a, int b){
    int aux, i, j;
    int *primo;
    primo = (int*)malloc(a * sizeof(int) );
    for (i = a; i <= b; i++) { 
        if (i == 1 || i == 0) 
            continue; 
            
        aux = 1; 

        for (j = 2; j < i/2; ++j) { 
          if (i%j == 0) { 
              aux = 0; 
              break; 
          } 
        } 

        if (aux == 1) 
            primo = &i;
            printf("%d ", *(primo)); 
        
    }
    return primo;
}
int main() {
    int a, b;
    int *p;

    scanf("%d %d", &a, &b);
    p = contaprimos(a, b);
    
    printf("%d\n", *(p));
    
    return 0;
}
