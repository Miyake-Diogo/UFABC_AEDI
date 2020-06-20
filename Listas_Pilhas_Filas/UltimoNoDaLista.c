#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
	int info;
	Node *prox;
};

Node* inclui_fim(Node *lista, int x);
Node* ultimo_no(Node *lista);
void libera_lista(Node *lista);

int main() {
	int n, valor, i;
	Node *lst = NULL;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
	    scanf("%d", &valor);
		lst = inclui_fim(lst, valor);

	}

	Node *p = ultimo_no(lst);
	if (p != NULL)
		printf("%d\n", p->info);
    libera_lista(lst);
	return 0;
}

Node* ultimo_no(Node *lst) {

	Node  *ultimo_no;

    ultimo_no = lst;
    if (ultimo_no == NULL) 
        return (NULL);
    while(ultimo_no->prox != NULL) 
      ultimo_no = ultimo_no->prox;
    return (ultimo_no);
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
