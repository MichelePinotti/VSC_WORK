
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<time.h>

typedef struct{
    char name;
    int value;
}Processo;

//ho fatto solo la print e la push a metà
Processo* push(Processo*, int*);
Processo* pop(Processo*, int*);
void print(Processo*, int*);

int main(){
    int scelta;
    int dim;
    Processo* vet = (Processo*)malloc(sizeof(Processo));
    do{
        print(vet, &dim);
        printf("1.PUSH\n2.POP\n3.USCITA\n");
        scanf("%d", &scelta);
        
        if(scelta==1){
            vet = push(vet, &dim);
        }
        if(scelta==2){
            vet = pop(vet, &dim);
        }
    }while(scelta != 0 && scelta != 3);
}

void print(Processo* v, int* dim){
    for(int i = 0; i<*dim; i++){
        printf("name: %c  value: %d\n", *(v+i)->name, (v+i)->value);
    }
}

Processo* push(Processo* v, int* dim){      //mi stampa sempre lo stesso carattere e come value mi stampa sempre solo &d
    int temp;
    printf("quanti processi vuoi aggiungere: ");
    scanf("%d", &temp);
    fflush(stdin);
    *dim = *dim + temp;
    v=(Processo*)realloc(v, (*dim) * sizeof(Processo));
    srand(time(NULL));
    for(int i = 0; i<*dim; i++){
        
        *(v+i)->name = rand()%26+97;
        (v+i)->value = rand()%10;    //mi da errore con & ma senza mi stampa male  
    }
    return v;
}

Processo* pop(Processo* v, int* dim){       //funziona
    int kill;
    printf("inserisci quanti processi eliminare: ");
    scanf("%d", &kill);
    if(kill<*dim){
        *dim = *dim - kill;
        v=(Processo*)realloc(v,sizeof(Processo) * (*dim));
    }else{
        printf("troppi pochi processi a disposizione\n");
    }
    return v ;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<time.h>

typedef struct{
    char name;
    int value;
}Processo;

//ho fatto solo la print e la push a metà
Processo* push(Processo*, int*);
Processo* pop(Processo*, int*);
void print(Processo*, int*);

int main(){
    int scelta;
    int dim;
    Processo* vet = (Processo*)malloc(sizeof(Processo));
    do{
        print(vet, &dim);
        printf("1.PUSH\n2.POP\n3.USCITA\n");
        scanf("%d", &scelta);
        
        if(scelta==1){
            vet = push(vet, &dim);
        }
        if(scelta==2){
            vet = pop(vet, &dim);
        }
    }while(scelta != 0 && scelta != 3);
}

void print(Processo* v, int* dim){
    for(int i = 0; i<*dim; i++){
        printf("name: %c  value: %d\n", *(v+i)->name, (v+i)->value);
    }
}

Processo* push(Processo* v, int* dim){      //mi stampa sempre lo stesso carattere e come value mi stampa sempre solo &d
    int temp;
    printf("quanti processi vuoi aggiungere: ");
    scanf("%d", &temp);
    fflush(stdin);
    *dim = *dim + temp;
    v=(Processo*)realloc(v, (*dim) * sizeof(Processo));
    srand(time(NULL));
    for(int i = 0; i<*dim; i++){
        
        *(v+i)->name = rand()%26+97;
        (v+i)->value = rand()%10;    //mi da errore con & ma senza mi stampa male  
    }
    return v;
}

Processo* pop(Processo* v, int* dim){       //funziona
    int kill;
    printf("inserisci quanti processi eliminare: ");
    scanf("%d", &kill);
    if(kill<*dim){
        *dim = *dim - kill;
        v=(Processo*)realloc(v,sizeof(Processo) * (*dim));
    }else{
        printf("troppi pochi processi a disposizione\n");
    }
    return v ;
}