#include <stdio.h>
#include <stdlib.h>

struct pessoa{
  int senha;
  struct pessoa *prox;
};
typedef struct pessoa Pessoa;

Pessoa *fila;
void add(int senha){
  Pessoa *p = (Pessoa*) malloc(sizeof(Pessoa));
  p->senha = senha;
  p->prox = NULL;

  if(fila == NULL){
    fila = p;
  }else{
    Pessoa *filaAux = fila;
    while(filaAux->prox != NULL){
      filaAux = filaAux->prox;
    }
    filaAux->prox = p;
  }
}
void removeLast(){
  if(fila == NULL){
    printf("Fila vazia");
  }else{
    fila = fila->prox;
  }
}
typedef struct pessoa Pessoa;
void imprime(Pessoa *f){
  if(f != NULL){
    printf("Senha: %d\n\n", f->senha);
    imprime(f->prox);
  }
}
int main(void){
  
  add(222);
  add(11);
  removeLast();
  Pessoa *teste = fila;
  imprime(teste);
  return 0;
} 