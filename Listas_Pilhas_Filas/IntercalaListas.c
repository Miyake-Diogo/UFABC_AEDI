#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
	int info;
	Node *prox;
};

Node* inclui_fim(Node *lista, int x);
Node *intercala_listas(Node *lst1, Node *lst2);
void imprime_lista(Node *lista);
void libera_lista(Node *lista);

int main() {
	int n, i, valor;
	Node *l1 = NULL;
	Node *l2 = NULL;
	Node *l3 = NULL;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &valor);
		l1 = inclui_fim(l1, valor);
	}
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &valor);
		l2 = inclui_fim(l2, valor);
	}
    
	l3 = intercala_listas(l1, l2);
	imprime_lista(l3);
	libera_lista(l1);
	libera_lista(l2);
    libera_lista(l3);
    
	return 0;
}

Node *intercala_listas(Node *lst1, Node *lst2) {
	Node* resultado = NULL; 
  
  if (lst1 == NULL)  
     return(lst2); 
  else if (lst2==NULL)  
     return(lst1); 
//-----------------
  if (lst1->info <= lst2->info)  
  { 
     resultado = lst1; 
     resultado->prox = intercala_listas(lst1->prox, lst2); 
  } 
  else 
  { 
     resultado = lst2; 
     resultado->prox = intercala_listas(lst1, lst2->prox); 
  } 
  return(resultado);
	
}

Node* inclui_fim(Node *lista, int x) {
	Node *p = (Node*) malloc(sizeof(Node));
	if (p != NULL) {
		p->info = x;
		if (lista == NULL) {
			p->prox = NULL;
			return p;
		}
		Node *q = lista;
		while (q->prox != NULL)
			q = q->prox;
		q->prox = p;
		p->prox = NULL;
	}
	return lista;
}

void imprime_lista(Node *lista) {
	Node *p = lista;
	if (lista == NULL)
		printf("Lista vazia");
	while (p != NULL) {
		printf(" %d ", p->info);
		p = p->prox;
	}
	printf("\n");
}

void libera_lista(Node *lista) {
 while(lista != NULL) {
        Node *p = lista;
        lista = lista->prox;
        free(p);
    }
}

