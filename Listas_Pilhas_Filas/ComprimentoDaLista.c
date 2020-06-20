#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
	int info;
	Node *prox;
};

Node* inclui_inicio(Node *lista, int k);
int comprimento_lista(Node *lista);
void libera_lista(Node *lista);

int main() {
	int valor;
	Node *lst = NULL;
	scanf("%d", &valor);
	while (valor != -1) {
		lst = inclui_inicio(lst, valor);
		scanf("%d", &valor);
	}
	printf("%d\n", comprimento_lista(lst));
    libera_lista(lst);
    
	return 0;
}

int comprimento_lista(Node *lista) {
    int c =0;
    Node* atual = lista;
    while (atual != NULL){
        c++;
        atual=atual->prox;
    }
    return c;
}

Node* inclui_inicio(Node *lista, int x) {
	Node *p = (Node*) malloc(sizeof(Node));
	if (p != NULL) {
		p->info = x;
		p->prox = lista;
	}
	return p;
}
int lista_vazia(Node *lista) {
    if (lista == NULL)
    
    return 1;
   
    else
    
    return 0;
}

void libera_lista(Node *lista) {
 while(lista != NULL) {
        Node *p = lista;
        lista = lista->prox;
        free(p);
    }
}
 
