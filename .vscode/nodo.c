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
/*aggiunge il tuo valore in coda alla lista
@param Nodo* riceve un puntatore a struttura di tipo Nodo 
@param int valore della nuova coda
*/ 
Nodo* pushCoda(Nodo* t, int n){
    Nodo* tmp = t;
    printf("\nentra nella funzione");
    while(tmp != NULL){
        printf("\ntmp[%d]: %d", tmp, tmp->value);
        if(tmp->next == NULL){
            printf("\nif");
            Nodo* newend = (Nodo*)malloc(sizeof(Nodo));
            tmp->next = newend;
            newend->value = n;
            newend->next = NULL; 
        }
        tmp=tmp->next;
    }
    return t;
}

/*Nodo* pushCoda(Nodo** t, int n){
    *t = (*t)->next;
    printf("\nentra nella funzione");
    if(*t != NULL){
        printf("\nwhile");
        if((*t)->next == NULL){
            printf("\nif");
            Nodo* newend = (Nodo*)malloc(sizeof(Nodo));
            (*t)->next = newend;
            newend->value = n;
            newend->next = NULL; 
        }else
            pushCoda(t,n);
    }
    return *t;
}*/