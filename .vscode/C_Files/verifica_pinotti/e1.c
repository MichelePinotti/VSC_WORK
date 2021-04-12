#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char titolo[20];
    float prezzo;
    int anno_pubblicazione;
}Fumetto;

void initCollana(Fumetto v[5], int indice,char* titolo,float prezzo,int anno_pubblicazione, int* celle_usate){
    strcpy(v[indice].titolo, titolo);
    v[indice].prezzo = prezzo;
    v[indice].anno_pubblicazione = anno_pubblicazione;
    *celle_usate = *celle_usate + 1;
}

void showCollana(Fumetto v[5], int celle_usate){
    for(int i =0; i < celle_usate; i++){
        printf("\n%s   %f   %d",v[i].titolo,v[i].prezzo,v[i].anno_pubblicazione);
    }
}

void searchFumettoByTitle(Fumetto v[5] ,char* titolo, int celle_usate){
    for(int i = 0; i < celle_usate; i++){
        if(strcmp(v[i].titolo, titolo) == 0){
            printf("\nfumetto di titolo : %s, trovato!!", titolo);
        }
    }
}

void searchFumettoByPrice(Fumetto v[5] ,float prezzo, int celle_usate){
    for(int i = 0; i < celle_usate; i++){
        if(v[i].prezzo == prezzo){
            printf("\nfumetto di titolo : %s ha il prezzo da te selezionato!!", v[i].titolo);
        }
    }
}

int main(){
    Fumetto vettore[5];
    int celle_usate = 0;    //indica il numero di celle utilizzate delle 5 disponibili cosi non vengono stampate e confrontate cose non inserite dall'utente
    initCollana(vettore,3,"Malala",35.99,2000, &celle_usate);
    initCollana(vettore,0,"In trincea",25.99,1999, &celle_usate);
    initCollana(vettore,1,"Ready player one",20.99,2008, &celle_usate);
    initCollana(vettore,2,"Messi",15.99,2010, &celle_usate);
    showCollana(vettore, celle_usate);
    searchFumettoByTitle(vettore,"In trincea", celle_usate);
    searchFumettoByPrice(vettore, 25.99, celle_usate);
}