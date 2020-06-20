#include<stdio.h>

int main()
{
	//declaração de variáveis
	int i,j,m,soma=0,mat[7][7];
	// inserir a quantidade de linhas e colunas - matriz quadrada
	//printf("Digite a quanitdade de linhas e colunas:");
	scanf("%d",&m);
	//printf("digite os elementos:\n");
	//insere os elementos e faz a soma no loop
	for(i=0;i<m;++i)
		for(j=0;j<m;++j)
		{
			scanf("%d",&mat[i][j]);
				if(j<i)
					soma+=mat[i][j];
		}

	//retorna a soma
	printf("%d \n",soma);

 
	return 0;
}