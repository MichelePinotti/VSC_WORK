<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>

/*
    Ctrl + C => copia
    Ctrl + X => taglia
    Ctrl + V => incolla
    F2 => rinomina simbolo (variabile, funzione, struttura, ...)
    Ctrl + H => trova e sostituisci
    Ctrl + F => trova
    Ctrl + Shift + (F|H) => trova/sostituisci su tutti i file
    Ctrl + Shift + B => compila
    Ctrl + K, C => commenta righe selezione
    Ctrl + K, U => scommenta righe selezione
*/
typedef struct elemento{
    int value;
    struct elemento* next;
} Elemento;

int head(Elemento* lista);
Elemento* tail(Elemento* lista);
Elemento* addToHead(Elemento* lista, int value);
void addToEnd(Elemento *, int value);
Elemento* addOrdered(Elemento *, int);
int find(Elemento *, int);
int findIndex(Elemento *, int, int*);
Elemento* rimuovi(Elemento *, int);
int lenght(Elemento *);

void stampaLista(Elemento* lista);
void stampaListaRev(Elemento* lista);

int main(){

    Elemento* s = NULL;

    printf("%d\n", head(s));

    s = addToHead(s, 9);
    //printf("%d\n", head(s));
    s = addToHead(s, 6);
    //printf("%d\n", head(s));
    s = addToHead(s, 3);
    //printf("%d\n", head(s));
    addToEnd(s, 10);

    printf("lista prima --> ");
    stampaLista(s);
    printf("\n");
    s = addOrdered(s, 11);
    printf("lista dopo ---> ");
    stampaLista(s);
    printf("\nlunghezza = %d\n", lenght(s));
    int num;
    printf("\binserisci il numero che vuoi trovare:");
    scanf("%d", &num);
    printf("presenza = %d\n", find(s,num));
    printf("\binserisci il numero che vuoi trovare:");
    scanf("%d", &num);
    int cnt=0;
    int idx=findIndex(s,num, &cnt);
    if(cnt==0){
        printf("\nelemento non presente");
    }else{
        printf("\nindice se presente = %d", idx);
    }
    

    return 0;
}

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
=======
#include <stdio.h>
#include <stdlib.h>

/*
    Ctrl + C => copia
    Ctrl + X => taglia
    Ctrl + V => incolla
    F2 => rinomina simbolo (variabile, funzione, struttura, ...)
    Ctrl + H => trova e sostituisci
    Ctrl + F => trova
    Ctrl + Shift + (F|H) => trova/sostituisci su tutti i file
    Ctrl + Shift + B => compila
    Ctrl + K, C => commenta righe selezione
    Ctrl + K, U => scommenta righe selezione
*/
typedef struct elemento{
    int value;
    struct elemento* next;
} Elemento;

int head(Elemento* lista);
Elemento* tail(Elemento* lista);
Elemento* addToHead(Elemento* lista, int value);
void addToEnd(Elemento *, int value);
Elemento* addOrdered(Elemento *, int);
int find(Elemento *, int);
int findIndex(Elemento *, int, int*);
Elemento* rimuovi(Elemento *, int);
int lenght(Elemento *);

void stampaLista(Elemento* lista);
void stampaListaRev(Elemento* lista);

int main(){

    Elemento* s = NULL;

    printf("%d\n", head(s));

    s = addToHead(s, 9);
    //printf("%d\n", head(s));
    s = addToHead(s, 6);
    //printf("%d\n", head(s));
    s = addToHead(s, 3);
    //printf("%d\n", head(s));
    addToEnd(s, 10);

    printf("lista prima --> ");
    stampaLista(s);
    printf("\n");
    s = addOrdered(s, 11);
    printf("lista dopo ---> ");
    stampaLista(s);
    printf("\nlunghezza = %d\n", lenght(s));
    int num;
    printf("\binserisci il numero che vuoi trovare:");
    scanf("%d", &num);
    printf("presenza = %d\n", find(s,num));
    printf("\binserisci il numero che vuoi trovare:");
    scanf("%d", &num);
    int cnt=0;
    int idx=findIndex(s,num, &cnt);
    if(cnt==0){
        printf("\nelemento non presente");
    }else{
        printf("\nindice se presente = %d", idx);
    }
    

    return 0;
}

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