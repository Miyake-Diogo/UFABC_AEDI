#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
	int info;
	Node *ant;
	Node *prox;
};

int lista_vazia(Node *lista);
Node* inclui_fim(Node *lista, int x);
void imprime_lista(Node *lista);
Node* soma_listas(Node *lst1, Node *lst2);
void libera_lista(Node *lista);
Node *criano(int info);


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
	l3 = soma_listas(l1, l2);
	imprime_lista(l3);

	return 0;
}

int lista_vazia(Node *lista) {
	return (lista == NULL);
}

Node* soma_listas(Node *lst1, Node *lst2) {
    Node* resultado = NULL; 
    Node *temp, *ant = NULL; 
    int carry = 0, sum; 
  
    while (lst1 != NULL || lst2 != NULL) 
    { 
        sum = carry + (lst1? lst1->info: 0) + (lst2? lst2->info: 0); 
        carry = (sum >= 10)? 1 : 0; 
        sum = sum % 10; 
        temp = criano(sum); 
        if(resultado == NULL) 
            resultado = temp; 
        else 
            ant->prox = temp;  
        ant  = temp; 
        if (lst1) lst1 = lst1->prox; 
        if (lst2) lst2 = lst2->prox; 
    } 
  
    if (carry > 0) 
      temp->prox = criano(carry); 
    return resultado; 
}
Node *criano(int info) 
{ 
    Node *novo = (Node *) malloc(sizeof(Node)); 
    novo->info = info; 
    novo->prox = NULL; 
    return novo; 
} 

Node* inclui_fim(Node *lista, int x) {
	Node *p = (Node*) malloc(sizeof(Node));
	if (p == NULL) {
		printf("Não foi possível alocar memoria!\n");
		exit(1);
	}
	p->info = x;
	if (lista_vazia(lista)) {
		p->ant = NULL;
		p->prox = NULL;
		return p;
	}
	Node *q = lista;
	while (q->prox != NULL)
		q = q->prox;
	q->prox = p;
	p->ant = q;
	p->prox = NULL;

	return lista;
}

void imprime_lista(Node *lista) {
	Node *p = lista;
	if (lista_vazia(lista))
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