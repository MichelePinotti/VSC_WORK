#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct elemento {
    int value;
    struct elemento* next;
} Elemento;

void stampaLista(Elemento* lista){
    if(lista!=NULL){
        printf("%d ", lista->value); //printf("%d", lista->value);
        stampaLista(lista->next); //stampaLista(lista->next);
    }
}

void addToEndRef(Elemento** lista, int value){
    if(*lista == NULL){
        Elemento* newEnd = (Elemento*)malloc(sizeof(Elemento));

        newEnd->next = NULL;
        newEnd->value = value;

        *lista = newEnd;
    }
    else if((*lista)->next == NULL){
        Elemento* newEnd = (Elemento*)malloc(sizeof(Elemento));

        newEnd->next = NULL;
        newEnd->value = value;
        (*lista)->next = newEnd;
    }
    else{
        addToEndRef(&(*lista)->next, value);
    }
}

int main(){
    Elemento* s = NULL;


    addToEndRef(&s, 7);
    addToEndRef(&s, 14);
    addToEndRef(&s, 22);
    stampaLista(s);
    
}


