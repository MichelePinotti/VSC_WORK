#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cart{
    char name[20];
    float price;
    int day;
    int month;
    int year;
    struct cart* next;
}Cart;

typedef struct action{
    char name[20];
    float price;
    int number;
    struct action* next;
}Action;

int controlForBuy(float price, float saldo){
    if(saldo > price){
        return 1;
    }else{   
        return 0;
    }
}

Cart* acquista(Cart* c, char* name, float price, int day, int month, int year, float* spese, float* saldo){
    if(controlForBuy(price, *saldo)){
        Cart* newHead = (Cart*)malloc(sizeof(Cart));
        strcpy(newHead->name, name);
        newHead->price = price;
        newHead->day = day;
        newHead->month = month;
        newHead->year = year;
        newHead->next = c;
        *spese = *spese + price;
        *saldo = *saldo - price;
        printf("\n acquisto eseguito su %s...", name);
        return newHead;
    }else{
        printf("\n soldi sul contro insufficenti per effettuare l'acquisto su %s...", name);
    }
}

void ricarica(float* saldo, int importo){
    *saldo = *saldo + importo;
}

void print(Cart* c){
    while(c != NULL){
        printf("\nnome: %s  prezzo: %f  data: %d/%d/%d", c->name, c->price, c->day, c->month, c->year);
        c = c->next;
    }
}

Action* azioni(Action* a, char* name, float price, float* saldo, float* spese){
    int numberOfAction;
    printf("\n quante azioni vuoi comprare: ");
    scanf("%d", &numberOfAction);
    fflush(stdin);
    float buy = numberOfAction * price;
    if(controlForBuy(buy, *saldo)){
        Action* newHead = (Action*)malloc(sizeof(Action));
        strcpy(newHead->name, name);
        newHead->number = numberOfAction;
        newHead->price = price;
        newHead->next = a;
        *spese = *spese + price;
        *saldo = *saldo - price;
        printf("\n acquisto dell'azione di %s...", name);
        return newHead;
    }else{
        printf("\n soldi sul contro insufficenti per effettuare l'acquisto dell'azione di %s...", name);
    }
}

void trend(Action* a, float* spese){
    float bilancio;
    while(a != NULL){
        
        float molti = (rand()%100)-20;
        bilancio = (molti - a->price) * a->number;
        printf("     %f    ", molti);
        a = a->next;
    }
    printf(" %f", bilancio);
}

int main(){
    int scelta; 
    Cart* cart = NULL;
    Action* actionCart = NULL;
    float saldo = 0;
    float speseMensili = 0;
    float speseAzioni = 0;
    do{
        printf("\nSALDO: %f", saldo);
        printf("\nTOTALE SPESE MENSILI: %f", speseMensili);
        printf("\nBILANCIO AZIONI:");
        trend(actionCart, &speseAzioni);
        printf("\n---------------------------------------------------"); 
        printf("\n1.ACQUISTA");   
        printf("\n2.CARICA CARTA");     
        printf("\n3.ACQUISTA AZIONI");  
        printf("\n4.INVIA o RICEVI DENARO");      
        printf("\n5.VISUALIZZA ABBONAMENTI");   
        printf("\n6.INVITA UN TUO AMICO");      
        printf("\n7.PIANO DI RISPARMIO");  
        printf("\n8.ATTIVA FUNZIONE SUPERMERCATO");      
        printf("\n9.DONAZIONI");  
        printf("\n10.VISUALIZZA ACQUISTI");    
        printf("\n11.!HELP!");       
        printf("\n0.USCITA"); 

        printf("\ndove vuoi andare:");
        scanf("%d", &scelta);
        fflush(stdin);
        printf("---------------------------------------------------");

        if(scelta == 1){
        cart = acquista(cart, "amazon", 7.99, 25, 03, 2021, &speseMensili, &saldo);  //acquisto andrà a buon fine perche soldi sufficenti(105 - 7.99 = 0)
        cart = acquista(cart, "e-bay", 101.99, 4, 5, 2021, &speseMensili, &saldo);  //acquisto non andrà a buon fine perche soldi insufficenti(97.01 - 101.99 = -8.98 < 0)
        cart = acquista(cart, "subito", 57.99, 9, 10, 2021, &speseMensili,&saldo);  //acquisto andrà a buon fine perche soldi sufficenti(97.01 - 57.99 = 39.02 >0)
        }else if(scelta == 2){
            ricarica(&saldo, 502);
        }else if(scelta == 3){
            actionCart = azioni(actionCart, "tesla", 25.00, &saldo, &speseAzioni);
            actionCart = azioni(actionCart, "ktm", 20.00, &saldo, &speseAzioni);
            actionCart = azioni(actionCart, "ferrari", 35.00, &saldo, &speseAzioni);
        }else if(scelta == 4){
            
        }else if(scelta == 5){
            
        }else if(scelta == 6){
            
        }else if(scelta == 7){
            
        }else if(scelta == 8){
            
        }else if(scelta == 10){
            printf("\nACQUISTI");
            print(cart);
            printf("\n---------------------------------------------------");
        }else if(scelta == 10){
            
        }
    }while(scelta != 0);

}