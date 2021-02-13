#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct nodo{
    int value;
    struct nodo* next;
}Nodo;
/*aggiunge un elemento in testa 
@param Nodo* riceve un puntatore a struttura di tipo Nodo
@param int valore della nuova testa
@return Nodo* ritorna l'indirizzo della nuova testa 
*/ 
Nodo* pushTesta(Nodo* t, int n){
    Nodo* newhead = (Nodo*) malloc(sizeof(Nodo));
    newhead->value = n;
    newhead->next = t;
    return newhead;
}
/*stampa la lista 
@param Nodo* riceve un puntatore a struttura di tipo Nodo 
*/ 
void stampaLista(Nodo* t){
    if(t != NULL){
        printf("nodo[%d]: %d --> %d\n", t, t->value, t->next);
        stampaLista(t->next);
    }
}