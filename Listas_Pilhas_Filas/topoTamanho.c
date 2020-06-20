#include <stdio.h>
#include <stdlib.h>
#include "topoTamanho.h"

int elemento_topo(Pilha *p) {
	if (pilha_vazia(p)) 
        return 0;
    Node *no = (Node *)malloc(sizeof(Node));
    no = p->topo;
    int v = no->valor;
    return v;
}

int tamanho_pilha(Pilha *p) {
	Node *aux = p->topo;
	int tamanho = 0;
	while(aux != NULL) {
		aux = aux->prox; 
		tamanho++;
	}
	return tamanho;
}

