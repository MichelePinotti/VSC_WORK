<<<<<<< HEAD
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 2

typedef struct{
    char cognome[20];
    int anni;
}Persona;

void insert(Persona*);
void stampa(Persona*);
void insert_3(Persona*, Persona*, Persona*);
void stampa_ultimate(Persona*);

int main(){
    
    int retry = 1;
    int cnt = 0;

    Persona* vet1=(Persona*)malloc(SIZE * sizeof(Persona));      //inizializzazione 1 vettore
    Persona* vet2=(Persona*)malloc(SIZE * sizeof(Persona));      //inizializzazione 2 vettore

    
    insert(vet1);
    stampa(vet1);
    insert(vet2);
    stampa(vet2);
    
    Persona* vet3=(Persona*)malloc((SIZE*2) * sizeof(Persona));      //inizializzazione 3 vettore
    insert_3(vet1, vet2, vet3);
    stampa_ultimate(vet3);
}

void insert(Persona* vet){
    for(int i=0; i<SIZE; i++){
        printf("\ninserisci il cognome: ");
        scanf("%s", (vet+i)->cognome);
        fflush(stdin);
        printf("\ninserisci l'eta: ");
        scanf("%d", &(vet+i)->anni);
        fflush(stdin);
    }
}

void stampa(Persona* vet){
    for(int i=0; i<SIZE; i++){
       printf("%s %d\n", (vet+i)->cognome, (vet+i)->anni);
    }
}

void insert_3(Persona* vet1, Persona* vet2, Persona* vet3){     //nono funzia
    for(int i=0; i<SIZE; i++){
        strcpy((vet3+i)->cognome, (vet1+i)->cognome);
        (vet3+i)->anni = (vet1+i)->anni;
    }
    for(int i=0; i<SIZE; i++){
        Persona* tmp=vet3->cognome;
        for(int j=0; j<SIZE; j++){
                if(strcmp((tmp+j)->cognome, (vet2+j)->cognome)!= 0 && strcmp((vet3+i)->cognome, (vet1+j)->cognome) != 0){
                    strcpy((vet3+i)->cognome, (vet1+i)->cognome);
                    (vet3+i)->anni = (vet1+i)->anni;
                }
            }
        }
    /*for(int i=0; i<SIZE; i++){
        if(strcmp((vet3+i)->cognome, (vet3+i+1)->cognome) == 0){
            free((vet3+i+1));
        }
    }*/
    for(int i=SIZE, j=0; j<SIZE; i++, j++){
        if(strcmp((vet3+i)->cognome, (vet2+j)->cognome) != 0){
            strcpy((vet3+i)->cognome, (vet2+j)->cognome);
            (vet3+i)->anni = (vet2+j)->anni;
        }
    }
}

void stampa_ultimate(Persona* vet){
    printf("\nstampa ultimate\n");
    for(int i=0; i<(SIZE*2); i++){
       printf("%s %d\n", (vet+i)->cognome, (vet+i)->anni);
    }
=======
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 2

typedef struct{
    char cognome[20];
    int anni;
}Persona;

void insert(Persona*);
void stampa(Persona*);
void insert_3(Persona*, Persona*, Persona*);
void stampa_ultimate(Persona*);

int main(){
    
    int retry = 1;
    int cnt = 0;

    Persona* vet1=(Persona*)malloc(SIZE * sizeof(Persona));      //inizializzazione 1 vettore
    Persona* vet2=(Persona*)malloc(SIZE * sizeof(Persona));      //inizializzazione 2 vettore

    
    insert(vet1);
    stampa(vet1);
    insert(vet2);
    stampa(vet2);
    
    Persona* vet3=(Persona*)malloc((SIZE*2) * sizeof(Persona));      //inizializzazione 3 vettore
    insert_3(vet1, vet2, vet3);
    stampa_ultimate(vet3);
}

void insert(Persona* vet){
    for(int i=0; i<SIZE; i++){
        printf("\ninserisci il cognome: ");
        scanf("%s", (vet+i)->cognome);
        fflush(stdin);
        printf("\ninserisci l'eta: ");
        scanf("%d", &(vet+i)->anni);
        fflush(stdin);
    }
}

void stampa(Persona* vet){
    for(int i=0; i<SIZE; i++){
       printf("%s %d\n", (vet+i)->cognome, (vet+i)->anni);
    }
}

void insert_3(Persona* vet1, Persona* vet2, Persona* vet3){     //nono funzia
    for(int i=0; i<SIZE; i++){
        strcpy((vet3+i)->cognome, (vet1+i)->cognome);
        (vet3+i)->anni = (vet1+i)->anni;
    }
    for(int i=0; i<SIZE; i++){
        Persona* tmp=vet3->cognome;
        for(int j=0; j<SIZE; j++){
                if(strcmp((tmp+j)->cognome, (vet2+j)->cognome)!= 0 && strcmp((vet3+i)->cognome, (vet1+j)->cognome) != 0){
                    strcpy((vet3+i)->cognome, (vet1+i)->cognome);
                    (vet3+i)->anni = (vet1+i)->anni;
                }
            }
        }
    /*for(int i=0; i<SIZE; i++){
        if(strcmp((vet3+i)->cognome, (vet3+i+1)->cognome) == 0){
            free((vet3+i+1));
        }
    }*/
    for(int i=SIZE, j=0; j<SIZE; i++, j++){
        if(strcmp((vet3+i)->cognome, (vet2+j)->cognome) != 0){
            strcpy((vet3+i)->cognome, (vet2+j)->cognome);
            (vet3+i)->anni = (vet2+j)->anni;
        }
    }
}

void stampa_ultimate(Persona* vet){
    printf("\nstampa ultimate\n");
    for(int i=0; i<(SIZE*2); i++){
       printf("%s %d\n", (vet+i)->cognome, (vet+i)->anni);
    }
>>>>>>> 3bb886a2fa30b0b290ecdbe03fb4a04612cf4b9b
}