#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
	int info;
	Node *prox;
};

Node* cria_lista (int v){   
    Node* p = (Node*) malloc(sizeof(Node));   
    p->info = v;   
    return p;
    
}

Node* insere_ordenado(Node *vet, int k);
void imprime_lista(Node *lista);
void libera_lista(Node *lista);

int main() {
	int n, i, valor;
	Node *lst = NULL;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &valor);
		lst = insere_ordenado(lst, valor);
	}
	scanf("%d", &valor);
	lst = insere_ordenado(lst, valor);
	imprime_lista(lst);
	
    libera_lista(lst);
	return 0;
}

Node* insere_ordenado(Node *lst, int k) {
	
	Node* novo = cria_lista(k); 
	Node* ant = NULL;    
	Node* p = lst;         
	while (p != NULL && p->info < k) {     
	    ant = p;      
	    p = p->prox;   }   
	if (ant == NULL) {   
	    novo->prox = lst;      
	    lst = novo;   }   
	else {
	    novo->prox = ant->prox;      
	    ant->prox = novo;   }   

	return (lst);
	
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