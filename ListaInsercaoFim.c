#include <stdio.h>
#include <stdlib.h>

struct ponto{
  float x;
  float y;
  struct ponto *prox;
};

typedef struct ponto Ponto;
Ponto *head;
int length = 0;

void addFirst(float x, float y)
{
  Ponto *p = (Ponto*) malloc(sizeof(Ponto));
  p->x = x;
  p->y = y;
  p->prox = head;
  head = p;
}
void addLast(float x, float y){
  Ponto *p = (Ponto*) malloc(sizeof(Ponto));
  p->x = x;
  p->y = y;
  if(head==NULL){
    head = p;
  }else{
    Ponto *listaAux = head;
    while(listaAux->prox != NULL){
      listaAux = listaAux->prox;
    }
    listaAux->prox = p;
  }
}

void addRandom(float x, float y, int index){
  Ponto *p = (Ponto*) malloc(sizeof(Ponto));
  p->x = x;
  p->y = y;
  if(index > length){
    printf("Posição inválida!!");
  }else{
     if(index == 0){
       p->prox = head;
       head = p;
     }else{
       Ponto *listaAux = head;
       int i = 0;
       while(i != index - 1){
         listaAux = listaAux->prox;
         i++;
       }
       p->prox = listaAux->prox;
       listaAux->prox = p;
     }
     length++;
  }
}
void listRemove(int index){
  if(index > length || length ==0){
    printf("Posição inválida ou lista vazia!!\n\n ");
  }
  else{
    if(index == 0){
      head = head->prox;
    }else{
      Ponto *listaAux = head;
      int i = 0;
      while(i != index -1){
        listaAux = listaAux->prox;
        i++;
      }
      listaAux->prox = listaAux->prox->prox;
    }
    length--;
  }
}
void imprime(Ponto *p){
  
  if(p != NULL){
    printf("Ponto(%.1f, %.1f)\n\n", p->x, p->y);
    imprime(p->prox);
  }
}

int main(){
  //listapontos =  p(1, 5, prox = NULL)
  addFirst(1, 5);
  //listapontos =  p(2, 7, prox = p(1, 5, prox = NULL))
  addFirst(2, 7);
  addFirst(5, 3);
  addLast(1, 1);
  addRandom(1, 1, 0);
  listRemove(10);
  Ponto *auxLista = head;
  imprime(auxLista);
}