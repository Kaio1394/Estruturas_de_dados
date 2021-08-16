#include <stdio.h>
#include <stdlib.h>

struct prato{
  int valor;
  struct prato *prox;
};
typedef struct prato Prato;

Prato *pilha;
int length = 0;

typedef struct pessoa Pessoa;

void insert_sort(Prato *pilha){

 for(int i = 0; i < length; i++){

 }
}

void push(int valor){
  Prato *p = (Prato*) malloc(sizeof(Prato));
  p->valor = valor;
  p->prox = pilha;
  pilha = p;
  length++;
}

void pop(){
  if(pilha == NULL){
    printf("Pilha vazia");
  }else{
    pilha = pilha->prox;
  }
  length--;
}
void print(Prato *p){
  if(p!= NULL){
    printf("|%d|\n\n", p->valor);
    print(p->prox);
  }
}
int main(void){
  
  push(500);
  push(2);
  push(10);
  push(13);
  pop();


  Prato *teste = pilha;
  print(teste);
  printf("Tamanho da pilha: %d\n\n", length);
  return 0;
} 