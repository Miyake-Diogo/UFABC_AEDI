#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
	int info;
	Node *prox;
};

Node* inclui_fim(Node *lista, int x);
void imprime_lista(Node *lista);
Node* inverte_lista(Node *lst);
void libera_lista(Node *lista);

int main() {
	int n, valor, i;
	Node *lst = NULL;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &valor);
		lst = inclui_fim(lst, valor);
	}
	lst = inverte_lista(lst);
	imprime_lista(lst);
    libera_lista(lst);
	return 0;
}

Node* inverte_lista(Node *lst) {
    Node* ant = NULL; 
    Node* atual = lst; 
    Node* prox = NULL; 
    while (atual != NULL) { 

        prox = atual->prox; 
        atual->prox = ant; 
        ant = atual; 
        atual = prox; 
    } 
    lst = ant; 
    return lst;
    
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
