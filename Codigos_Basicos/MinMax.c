#include <stdio.h>
#include <stdlib.h>
#define T 100

void minmax(int *vet, int n, int *min, int *max)
{
   int i;

   *min = vet[0];
   *max = vet[0];

    for ( i = 1; i < n; i++ )
    {
        if(vet[i] < *min)
            *min =  vet[i];

        if(vet[i] > *max)
            *max =  vet[i];
    }
}


int main()
{
    int *vet=NULL;
    int min, max;
    int i, n;

    vet = (int*) malloc (T* sizeof(int));
    // Inserir o tamanho do vetor
    printf("Qual o tamanho do vetor: ");
    scanf("%d", &n);
    
    printf("Insira os elementos do vetor: ");
    for(i=0; i<n; i++)
    {
        scanf("%d", &vet[i]);
    }
    
    
    minmax(vet, n, &min, &max);
    printf("\n");
    printf("Menor elemento: %d\n",min);
    printf("Maior elemento: %d\n",max);

    return 0;
}