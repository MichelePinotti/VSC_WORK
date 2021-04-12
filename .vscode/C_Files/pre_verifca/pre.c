#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct persona{
    char nome[20];
    char cognome[20];
    int anni;    
}Persona;

typedef struct nodo{
    Persona p;
    struct nodo *next;
}Nodo;

void addNodoTesta(Nodo **l, char c[], char n[], int a){
    Nodo* newhead =(Nodo*)malloc(sizeof(Nodo));
    strcpy(newhead->p.cognome, c);
    strcpy(newhead->p.nome, n);
    newhead->p.anni = a;
    newhead->next = *l;
    *l = newhead;
    
}

void stampaLista(Nodo *l){
    if(l != NULL){
        printf("\ncognome: %s  nome: %s  anni: %d", l->p.cognome, l->p.nome,l->p.anni);
        stampaLista(l->next);
    }
}

void salvaLista(Nodo *l){
    FILE* fpout;
    fpout = fopen("achivio.bin", "wb");
    while(l != NULL){
        fwrite(&(l->p), sizeof(Persona), 1, fpout);
        l = l->next;
    }
    fclose(fpout);
}

void caricaLista(Nodo **l){
    FILE* fpin;
    Nodo* newHead;
    fpin = fopen("achivio.bin", "rb");
    Persona tmp;
    while(fread(&tmp, sizeof(Persona), 1, fpin) != 0){
        newHead = (Nodo*) malloc(sizeof(Nodo));
        strcpy(newHead->p.cognome, tmp.cognome);
        strcpy(newHead->p.nome, tmp.nome);
        newHead->p.anni = tmp.anni;
        newHead->next = *l;
        *l = newHead;
    }
    fclose(fpin);
}

void modificaPersona(Nodo *l, char c[], char n[], int a){

}
void modificaPersona2(Nodo *l, char src[]){

}

int contanodi(Nodo* l){
    int cnt = 0;
    while(l != NULL){
        cnt = cnt + 1;
    }
    return cnt;
}

void freecoda(Nodo** l){
    Nodo* tmp;
    if(*l != NULL){
        if((*l)->next == NULL){
            tmp = *l;
            *l = NULL;
            free(tmp);
        }
    }else{
        tmp = *l;
        while(tmp->next->next != NULL){
            tmp = tmp->next;
        }
        free(tmp->next);
        tmp->next = NULL;
    }
}

void freetesta(Nodo** l){
    while(*l != NULL){
        Nodo* tmp = *l;
        *l = (*l)->next;
        free(tmp);
    }
}

int main(){
    Nodo* list = NULL;
    addNodoTesta(&list, "barbnieri", "fabio", 19);
    addNodoTesta(&list, "pinotti", "michele", 19);
    addNodoTesta(&list, "gendile", "stone", 19);
    addNodoTesta(&list, "sineghe", "robi", 19);
    addNodoTesta(&list, "cioncale", "brati", 19);
    addNodoTesta(&list, "ronny", "chris", 19);
    stampaLista(list);
    salvaLista(list);
    freecoda(&list);
    printf("\nlista salvata");
    caricaLista(&list);
    stampaLista(list);
}