#include <stdio.h>
#include <stdlib.h>

struct cel {
int chave;
struct cel *prox;
};
typedef struct cel no;

struct lista {
no* inicio;
};
typedef struct lista lista;

no* menorElemento (lista* L){
L = L->prox; 
int menor_valor = L->chave;
while (L != NULL) { 
if (menor_valor > L->chave) {
menor_valor = L->chave; 
}
L = L->prox; 
} 
return menor_valor; 
}
