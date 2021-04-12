
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>

void insert(Persona );
int search(Persona, char*, char*);

typedef struct{
    char cognome[20];
    char nome[20];
    int anni;
    char sesso
}Persona;

int main(){
    Persona* vet[5];
    int scelta;
    for(int i=0; i<5; i++){
        
        do{
        printf("\ncognome:%c\nnome:%c\nanni:%d\nsesso:%c", vet->cognome,vet->nome,vet->anni,vet->sesso);
        printf("\n1.Inserimento\n2.Ricerca\n3.Eta' media\n4.Ordinamento\n0.USCITA");

        if(scelta==1){
            insert(vet);
        }if(scelta == 2){
            char cognome[20];
            char nome[20];
            printf("inserisci il cognome della persona che vuoi cercare:");
            scanf("%s", cognome);
            fflush(stdin);
            printf("inserisci il nome della persona che vuoi cercare:");
            scanf("%s", nome);
            fflush(stdin);

            int flag = search(vet, cognome, nome);
            if(flag){
                printf("\nla persona da te cercata e' presente");
            }else{
                printf("\nla persona da te cercata non e' presente");
            }
        }
        }while(scelta != 0 || scelta<0 || scelta>4);
    }
}

void insert(Persona vet){
    printf("inserisci il nome: ");
    scanf("%s", vet.cognome);
    fflush(stdin);

    printf("inserisci il cognome: ");
    scanf("%s", vet.nome);
    fflush(stdin);

    printf("inserisci giorno di nascita: ");
    scanf("%d", vet.anni);
    fflush(stdin);

    printf("inserisci il sesso in formato (M o F): ");
    scanf("%s", vet.sesso);
    fflush(stdin);
}

int search(Persona p, char cognome,char nome){
    for(int i=0; i<5; i++){
        if(p->cognome == cognome){
            if(p->nome == nome){
                return 1;
            }
        }
    }
    return 0;
}