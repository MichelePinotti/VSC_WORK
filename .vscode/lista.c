#include <stdio.h>
#include <stdlib.h>
#include "nodo.c"

int main(){
    Nodo* testa = NULL;
    printf("testa: %d\n",testa);
    testa = pushTesta(testa,16);
    testa = pushTesta(testa,8);
    testa = pushTesta(testa,4);
    printf("testa: %d\n",testa);
    stampaLista(testa);
    printf("\nprima del push");
    testa = pushCoda(testa,88);
    stampaLista(testa);
}