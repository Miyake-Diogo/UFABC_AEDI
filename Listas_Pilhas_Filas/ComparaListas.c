#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
	int info;
	Node *prox;
};

Node* inclui_fim(Node *lista, int x);
int compara_listas(Node *lst1, Node *lst2);
void libera_lista(Node *lista);

int main() {
	int n, i, valor;
	Node *l1 = NULL;
	Node *l2 = NULL;
	scanf("%d", &n);
	for (i=0; i < n; i++) {
		scanf("%d", &valor);
		l1 = inclui_fim(l1, valor);
	}
    scanf("%d", &n);
    for (i=0; i < n; i++) {
		scanf("%d", &valor);
		l2 = inclui_fim(l2, valor);
	}
    printf("%d\n", compara_listas(l1, l2));
    libera_lista(l1);
    libera_lista(l2);
	return 0;
}

int compara_listas(Node *lst1, Node *lst2) {
	while(lst1!=NULL && lst2!=NULL && lst1->info==lst2->info){
	    lst1=lst1->prox;
	    lst2=lst2->prox;
    }
    return lst1==lst2;
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

void libera_lista(Node *lista) {
 while(lista != NULL) {
        Node *p = lista;
        lista = lista->prox;
        free(p);
    }
}