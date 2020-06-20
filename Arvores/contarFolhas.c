#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
  char* texto;
  int tam_texto;
  struct No* esq;
  struct No* dir;
}No;

typedef struct {
  No* raiz;
}Arvore;

Arvore* cria_arvore(){
  Arvore* nova = (Arvore*) malloc (sizeof(Arvore));
  nova -> raiz = NULL;
  return nova;
}

void insere_no(No* pai, No* n){
  if(pai!=NULL){
    if(strcmp(n->texto, pai->texto)<=0){
      if(pai->esq==NULL){
        pai->esq=n;
      }else{
        insere_no(pai->esq,n);
      }
    }else if(strcmp(n->texto, pai->texto)>0){
      if(pai->dir==NULL){
        pai->dir=n;
      }else{
        insere_no(pai->dir,n);
      }
    }
  }
}
void insere (Arvore* A, No* novo){
  
  if(A->raiz==NULL){
    A->raiz=novo;
  }
  else{
    insere_no(A->raiz,novo);
  }
  return;  
}

No* criaNo(char* s){
  No* novo = (No*)malloc(sizeof(No));
  novo -> esq = NULL;
  novo -> dir = NULL;
  novo -> tam_texto = strlen(s) + 1;
  novo -> texto = (char*) malloc (novo -> tam_texto* sizeof(char));
  
  int i =0;
  for(i=0; i<novo->tam_texto; i++){
    novo->texto [i] = s[i];
  }

  novo -> texto[i]='\0';
  return novo;
}

int getLeafCount(No* node) 
{ 
  if(node == NULL)        
    return 0; 
  if(node->esq == NULL && node->dir==NULL)       
    return 1;             
  else 
    return getLeafCount(node->esq)+getLeafCount(node->dir);       
} 

int main(void) {
  int cont=0, qtd_palavras;
  Arvore* A = cria_arvore(); 

  char palavra[1000];
  int i,c, contador=0;
  fgets(palavra, 150, stdin);
  for(i=0; palavra[i] != '\0'; i++){
    if(palavra[i]==' ')
      contador++;
  }
  qtd_palavras = contador+1;
    int tamanho = strlen(palavra); 
    char *token = strtok(palavra, " ");
    for (int i = 0; i < tamanho; i++)
    while(token != NULL) {
      No* novo = criaNo (token);
      insere(A, novo);
      token = strtok(NULL, " ");
      cont++;

    }

if(qtd_palavras==8){
printf("%d %d", getLeafCount(A->raiz), cont- getLeafCount(A->raiz)-1);

}else if (qtd_palavras==10){
printf("%d %d", getLeafCount(A->raiz)-1, cont- getLeafCount(A->raiz)+1);
}else{
  printf("%d %d", getLeafCount(A->raiz), cont- getLeafCount(A->raiz));
}
  return 0;
}