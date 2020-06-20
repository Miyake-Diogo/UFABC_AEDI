#include <stdio.h>
#include <stdlib.h>
//#include "pilhaDinamica.h"

//interface
// estrutura da lista encadeada
// /*
struct node{
    float info;
    struct node* prox;
};
typedef struct node Node;
//Estrutura da pilha

struct pilha {
    Node* topo;
};
typedef struct pilha Pilha;

Pilha *cria_pilha ();
int pilha_vazia(Pilha *p);
void empilha(Pilha *pilha, float valor);
float desempilha(Pilha *p);
void libera_pilha(Pilha *p);
void imprime (Pilha*p);
// */

Node* ret_ini(Node* l);
Node* ins_ini(Node* l, float valor);


//criação da pilha
Pilha* cria_pilha(void){
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}
//Funções auxiliares para inserir e remover node inicio da lista
Node* ins_ini(Node* l, float valor){
    Node* p = (Node*)malloc(sizeof(Node));
    p->info = valor;
    p->prox=l;
    return p;
}

Node* ret_ini(Node* l){
    Node* p = l->prox;
    free(l);
    return p;
}



//inserção de item na pilha
void empilha(Pilha* pilha, float valor){
    pilha->topo = ins_ini(pilha->topo,valor);
}

//retirar o elemento do topo da pilha
float desempilha(Pilha* p){
    float valor;
    if(pilha_vazia(p)){
        printf("Pilha Vazia.\n");
        exit(1); //aborta o programa.
    }
    //retirar o elemento do topo.
    valor = p->topo->info;
    p->topo = ret_ini(p->topo);
    return valor;
}

//Verificação da pilha vazia
int pilha_vazia(Pilha* p){
    return (p->topo ==NULL);
}
//liberar a pilha
void libera_pilha(Pilha* p){
    Node* q = p->topo;
    while (q!=NULL){
        Node* t = q->prox;
        free(q);
        q = t;
    }
    free(p);
}
/*
//Imprime a pilha
void imprime (Pilha* p){
    Node*q;
    for(q=p->topo; q!=NULL; q=q->prox){
        printf("%f\n", q->info);
    }
}
*/