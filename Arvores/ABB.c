#include <stdio.h>
#include <stdlib.h>



// Estruturas

struct node{
  int key;
  struct node *left, *right;

};
typedef struct node Node;

// estrutura para usar um booleano
typedef enum {false, true} bool;

//Cria��o da ABB

Node *newNode(int item){
  Node* temp = (Node*)malloc((sizeof(Node)));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}
// imprime inordem
void inOrder(Node *root) 
{ 
    if (root != NULL) 
    { 
        inOrder(root->left); 
        printf("%d ", root->key); 
        inOrder(root->right); 
    } 
} 
// imprime pre ordem
void preOrder(Node *root) 
{ 
    if (root != NULL) 
    { 
        printf("%d ", root->key); 
        preOrder(root->left); 
        preOrder(root->right); 
    } 
} 
//imprime pos ordem
void posOrder(Node *root) 
{ 
    if (root != NULL) 
    { 
        posOrder(root->left); 
        posOrder(root->right); 
        printf("%d ", root->key); 
    } 
} 

//inser��o dos n�s na ABB

Node* insert(Node* no, int key){
  //Se esta vazio retorna new Node
  if(no == NULL)
    return newNode(key);
  // sen��o vai inserir o no na esquerda
  if (key<no->key)
    no->left = insert(no->left, key);
  //senao insere na direita
  else if(key > no->key)
    no->right = insert(no->right, key);
  //retorna no do ponteiro
  return no;
}

// busca
/*
bool search(Node* root, int key) 
{ 
    // Casos b�sicos: raiz � nula ou chave est� presente na raiz
    if (root == NULL) 
       return false; 
    if (root->key == key)
      return true;  
    
    bool res1 = search(root->left, key); 
    if(res1) return true; // node encontrado, nao precisa olhar 
    // node n��o encontrado a esquerda, olha a direita 
    bool res2 = search(root->right, key); 
    return res2; 
 
  
  // Chave � maior que a chave da raiz
    if (root->key < key) 
       return search(root->right, key); 
  
    // Chave � menor que a chave da raiz
    return search(root->left, key); 
} 
*/
Node* search(Node *root, int key)
{
    if(root == NULL || root->key ==  key) //if root->data is x then the element is found
        return root;
    else if(key > root->key ) // x is greater, so we will search the right subtree
        return search(root->right, key);
    else //x is smaller than the data, so we will search the left subtree
        return search(root->left,key);
}


// min value
Node* minValueNode(Node* node){
  Node* current = node;
  // loop para encontrar o menor item
  while(current && current->left != NULL)
    current = current->left;
  return current;
}


// deletar no 
Node* deleteNode(Node* root, int key){
  // caso base
  if(root == NULL){
    return NULL;
  }
  //if(search(root,key)) return NULL;
  // Se a chave a ser exclu�da for menor que a chave da raiz, ent�o fica na sub-�rvore esquerda
  if (key < root->key){
    root->left = deleteNode(root->left, key);
  }
  // Se a chave a ser exclu�da for maior que a chave da raiz, ent�o est� na sub-�rvore direita
  else if (key > root->key){
    root->right = deleteNode(root->right, key);
  }
  // se a chave � igual � chave da raiz, ent�o este � o n� para ser deletado
  else{
    // Nos com somente uma folha ou sem folhas
    if (root->left == NULL){
      Node* temp = root->right;
      free(root);
      return temp;
    }
    else if(root->right == NULL){
      Node* temp = root->left;
      free(root);
      return temp;
    }
    // n� com dois filhos: obtenha o sucessor inorder (menor na sub�rvore direita)
    Node* temp = minValueNode(root->right);
    // usa uma copua co conteudoo do sucessor inordem para este n�
    root->key = temp->key;
    // deleta o sucessor inordem 
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

// quantidade de n�s

int countNodes(Node* root) {

    if (root == NULL) 
      return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}

// altura 

int height(Node* root){
  int u, v;
  if(root == NULL)
    return -1;
  u = height(root->left);
  v = height(root->right);
  if (u>v)
    return u+1;
  else 
    return v+1;
}
int height_v2(Node *root){
    if (root == NULL)
        return 0;
    int height_left = height_v2(root->left);
    int height_right = height_v2(root->right);
    if (height_left > height_right)
        return (height_left + 1);
    else
        return(height_right + 1);
}

// main()
/*

    I n: Insere o n�mero inteiro n em uma ABB.
    P: imprime os elementos em pr�-ordem (separados por um espa�o branco)
    N: imprime os elementos em inordem (separados por um espa�o branco)
    S: imprime os elementos em p�s-ordem (separados por um espa�o branco)
    B n: Busca o valor n na ABB. Se n estiver na �rvore, imprime "SIM"; caso contr�rio "NAO".
    R n: Remove o elemento n da ABB. Se n n�o estiver na �rvore, o comando deve ser ignorado.
    H: Exibe a altura da ABB.
*/

int main() 
{ 
    Node *root = NULL; 
    int n;
    char c;
    
   // while(scanf(" %c%d", &c, &n)!= EOF){
     while(scanf(" %c", &c)!= EOF){
     if(c == 'I'){
       scanf("%d", &n);
       root = insert(root, n);
     }
     else if(c == 'P'){
       preOrder(root); 
       printf("\n");
     }
     else if(c == 'N'){
       inOrder(root); 
       printf("\n");
     }
     else if(c == 'S'){
       posOrder(root); 
       printf("\n");
     }
     else if(c == 'B'){
        scanf("%d", &n);
        if (search(root, n)) 
          printf("SIM\n"); 
        else
          printf("NAO\n");
     }
     else if(c == 'R'){
       scanf("%d", &n);
       root = deleteNode(root, n);
     }
     else if(c == 'H'){
      int a = height(root);
      printf("%d\n", a); 
     }
     else
      return EOF;


    }
    return 0;
}

/*
I 12
R 20
I 4
I 8
I 1
I 4
I 15
N
P
S
H
B 12
B 21
R 4
N
*/
