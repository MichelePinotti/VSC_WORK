#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char loc_partenza[30];
    char loc_arrivo[30];
    int n_giorni;
    float prezzo;
}Spedizione;

typedef struct nodo{
    Spedizione value;
    struct nodo* next;
}Nodo;

Nodo* initSpedizione(Nodo* l, char* loc_partenza, char* loc_arrivo, int n_giorni,float prezzo ){
    if(l == NULL){
        Nodo* newcoda = (Nodo*) malloc(sizeof(Nodo));
        strcpy(newcoda->value.loc_partenza, loc_partenza);
        strcpy(newcoda->value.loc_arrivo, loc_arrivo);
        newcoda->value.n_giorni = n_giorni;
        newcoda->value.prezzo = prezzo;
        newcoda->next = NULL;
        return(newcoda);
    }else if(l->next == NULL){
        Nodo* newcoda = (Nodo*)malloc(sizeof(Nodo));

        newcoda->next = NULL;
        strcpy(newcoda->value.loc_partenza, loc_partenza);
        strcpy(newcoda->value.loc_arrivo, loc_arrivo);
        newcoda->value.n_giorni = n_giorni;
        newcoda->value.prezzo = prezzo;
        l->next = newcoda;
    }
    else{
        initSpedizione(l->next,loc_partenza,loc_arrivo,n_giorni,prezzo );
    }
    return l;
}

void showSpedizioni(Nodo* l){
    while(l != NULL){
        printf("\n%s   %s   %d   %f",l->value.loc_partenza, l->value.loc_arrivo, l->value.n_giorni, l->value.prezzo);
        l = l->next;
    }
}
void searchByPartenza(Nodo* l, char* loc_partenza){
    while(l != NULL){
        if(strcmp(l->value.loc_partenza, loc_partenza) == 0){
            printf("\nspedizione trovata!!");
        }
        l=l->next;
    }
}

Nodo* deleteSpedizione(Nodo* l){
    Nodo* tmp;
    if(l != NULL){
        tmp = l;
        l = l->next;
        free(tmp);
    }
    return(l);
}

float totalPriceSpent(Nodo* l){
    float tot = 0;
    while(l != NULL){
        tot = tot + l->value.prezzo;
        l = l->next;
    }
    return tot;
}

void  saveToFile(Nodo* l, char* name_file){
    FILE* fpout;
    fpout = fopen(name_file, "wb");
    while(l != NULL){
        fwrite(&(l->value), sizeof(Spedizione), 1, fpout);
        l = l->next;
    }
    fclose(fpout);
}

void searchIntoFile(char* name_file, char* part, char* arriv){
    FILE* fpin;
    fpin = fopen(name_file, "rb");
    Spedizione tmp;
    while(fread(&tmp, sizeof(Spedizione), 1, fpin)){ // funzione feof() restituisce true se sono alla fine del file.
        if((strcmp(tmp.loc_arrivo, arriv) && strcmp(tmp.loc_partenza, part)) == 0){
            printf("\nspedizione in partenza da %s e arrivo a %s presente sul file", part, arriv);
        }
    }
    fclose(fpin);
}

int main(){
    Nodo* list = NULL;

    list = initSpedizione(list,"magnacavallo", "poggio", 5, 25.99);
    list = initSpedizione(list,"poggio", "rovigo", 8, 37.99);
    list = initSpedizione(list,"mantova", "bankok", 30, 100.99);
    list = initSpedizione(list,"los angeles", "new york", 25, 50.99);
    showSpedizioni(list);
    searchByPartenza(list, "magnacavallo");
    list = deleteSpedizione(list);
    printf("\ndopo cancellazione");
    showSpedizioni(list);
    float total = totalPriceSpent(list);
    printf("\ntotale della spesa: %f", total);
    saveToFile(list, "registro.bin");
    searchIntoFile("registro.bin", "mantova", "bankok");
    searchIntoFile("registro.bin", "los angeles", "new york");
}