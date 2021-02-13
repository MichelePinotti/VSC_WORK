
#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>


void stampaLista(Elemento* lista){
    if(lista!=NULL){
        printf("%d ", lista->value); //printf("%d", lista->value);
        stampaLista(lista->next); //stampaLista(lista->next);
    }
}

void stampaListaRev(Elemento* lista){
    if(lista!=NULL){
        stampaListaRev(tail(lista)); //stampaLista(lista->next);
        printf("%d ", head(lista)); //printf("%d", lista->value);
    }
}

int head(Elemento* lista){
    if(lista==NULL)
        return 0;
    else
        return lista->value;
}

Elemento* tail(Elemento* lista){
    if(lista==NULL)
        return NULL;
    else
        return lista->next;
}

Elemento* addToHead(Elemento* lista, int value){
    Elemento* newHead = (Elemento*)malloc(sizeof(Elemento));

    newHead->value = value;
    newHead->next = lista;

    return newHead;
}

void addToEnd(Elemento* lista, int value){
    if((lista->next)==NULL){
        Elemento* newEnd = (Elemento*)malloc(sizeof(Elemento));
        newEnd->next = NULL;
        newEnd->value = value;
        lista->next = newEnd;
    }else
        addToEnd(lista->next, value);
}

Elemento* addOrdered(Elemento* lista, int value){
    if(lista != NULL)
        if(value < lista->value){
            Elemento *newEl = (Elemento *)malloc(sizeof(Elemento));
            newEl->next = lista;
            newEl->value = value;
            return newEl;
        }else if(lista->next == NULL)
            addToEnd(lista, value);
        else{
            lista->next = addOrdered(lista->next, value);
            return lista;
        }
}

int find(Elemento* lista, int num){
    if(lista != NULL)
        if (num == lista->value)
		    return 1;
        else
            return find(lista->next, num);
}

int findIndex(Elemento* lista, int num, int* cnt){
    if(lista != NULL){
        if(num == lista->value){
            *cnt=1;
            return 0;
        }
        else{
            return 1 + findIndex(lista->next, num, cnt);
        }
    }
}

Elemento* rimuovi(Elemento* lista, int num){ 
    if(lista != NULL){
        if(num == lista->value){
			Elemento* tmp = lista->next;
			free(lista);
			return tmp;
        }else if(num == lista->next->value){
			lista->next = lista->next->next;
			free(lista->next);
        }else if(lista->next->next == NULL){
            lista->next = NULL;
        }
    }
    return lista;
}

int lenght(Elemento* lista){
    if(lista != NULL){
        return 1 + lenght(lista->next);
    }
    return 0;
>>>>>>> 3bb886a2fa30b0b290ecdbe03fb4a04612cf4b9b
}