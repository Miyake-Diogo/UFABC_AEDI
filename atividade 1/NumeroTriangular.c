#include <stdio.h>
int num_triangular(int num);

int main(void) {
  int num;
  for(num = 1 ; num<1000; num++){
  //retorna se os itens são triangulares ou não 1 ou 0
  printf("%d",num_triangular(num));
  
}
return 0;
}

int num_triangular(int num){

    int i;
    int aux=0;
    // Faz a nultiplicação dos numeros
    for(i = 1 ; i*(i+1)*(i+2)<= num ; i++){
        
        if(i*(i+1)*(i+2)==num){
          aux = 1;
        }
    }
    //Valida se são trinagulares
    if (aux==1) 
      return 1;
    else  
      return 0;
};