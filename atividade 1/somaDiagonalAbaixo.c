#include <stdio.h>
//precisa acertar a entrada da função
int soma_diagonal_abaixo(int a[5][5]);

int main(void) {
  int i,j,m,sum=0;
  int mat[m][m];

	printf("Quantidade de colunas e linhas:\n");
	scanf("%d",&mat[m][m]);
  soma_diagonal_abaixo(mat);

  
return 0;
}

int soma_diagonal_abaixo(int mat[5][5]){
    int i,j,m,sum=0;
    printf("Quais os elementos? \n");
    for(i=0;i<m;++i){
		   for(j=0;j<m;++j){
			  scanf("%d",&mat[i][j]);
				  if(j>i)
					  sum+=mat[i][j];}
}
    printf("\nSoma dos elementos abaixo da diagonal é%d\n",sum);
    return 0;
};