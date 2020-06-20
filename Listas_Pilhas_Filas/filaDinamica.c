#include <stdio.h>
#include <stdlib.h>
//#include "filaDinamica.h"


//Estrutura dos nós
typedef struct node Node;
struct node{
    float valor;
    Node *prox;
};

//estrutura referenciando ao inicio e fim da fila.
typedef struct fila Fila;
struct fila{
    Node *inicio;
    Node *fim;
};

Fila *cria_fila();
int fila_vazia(Fila *f);
void *insere(Fila *f, float valor);
float retira(Fila *f);
void libera_fila(Fila *f);



//Cria uma lista vazia

Fila* cria_fila(){
    Fila* f=(Fila*)malloc(sizeof(Fila));
    f->inicio = f->fim =NULL;
    return f;
}

//Verifica se a fila está vazia

int fila_vazia(Fila *f){
    return(f->inicio == NULL);
}

//Insere um elemento no fim da fila
void *insere(Fila *f, float valor){
    Node *n = (Node*)malloc(sizeof(Node));
    n->valor = valor;
    n->prox = NULL;
    if(!fila_vazia(f)){
        f->fim->prox = n;
        f->fim = n;
    }else{
        f->inicio = n;
        f->fim = n;
    }
    return f;
}

//remove um elemento do inicio da fila

float retira(Fila *f){
    if (fila_vazia(f)){
        printf("Fila Vazia.\n");
        exit(1);
    }
    float v;
    Node *p = f->inicio;
    v = p->valor;
    f->inicio = p->prox;
    //v = f->inicio->valor;
    //f->inicio = retira_inicio(f->inicio);
    if(f->inicio ==NULL){
        f->fim =NULL;
    }
    free(p);
    
    return v;
}

void libera_fila(Fila *f){
    Node* q = f->inicio;
    while (q!= NULL){
        Node* t = q -> prox;
        free(q);
        q = t;
    }
    free(f);
}
