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
    int type;   //se type = 1 vuol dire che è un abbonamento
    struct cart* next;
}Cart;

typedef struct action{
    char name[20];
    float price;
    int number;
    struct action* next;
}Action;

void caricaListinoAzioni(){
    FILE* fpout;
    fpout = fopen("litinoAzioni.bin", "wb");
    char name[20] = "tesla";
    float* prezzo;
    *prezzo = 25.00;
    fwrite(name, sizeof(name),1,fpout);
    fwrite(prezzo, sizeof(prezzo),1,fpout);
    strcpy(name, "");
    strcpy(name, "ferrari");
    *prezzo = 30.00;
    fwrite(name, sizeof(name),1,fpout);
    fwrite(prezzo, sizeof(prezzo),1,fpout);
    strcpy(name, "");
    strcpy(name, "bugatti");
    *prezzo = 20.00;
    fwrite(name, sizeof(name),1,fpout);
    fwrite(prezzo, sizeof(prezzo),1,fpout);
    strcpy(name, "");
    strcpy(name, "nasa");
    *prezzo = 35.00;
    fwrite(name, sizeof(name),1,fpout);
    fwrite(prezzo, sizeof(prezzo),1,fpout);
    strcpy(name, "");
    strcpy(name, "mediaset");
    *prezzo = 15.00;
    fwrite(name, sizeof(name),1,fpout);
    fwrite(prezzo, sizeof(prezzo),1,fpout);
    fclose(fpout);
}

void scaricaListinoAzioni(){
    FILE* fpin;
    fpin = fopen("litinoAzioni.bin", "rb");
    char name[20];
    float* price;
    fread(name, sizeof(name),1,fpin);
    fread(price, sizeof(price),1,fpin);
    printf("\n1. %s  %f", name, *price);
    strcpy(name, "");
    fread(name, sizeof(name),1,fpin);
    fread(price, sizeof(price),1,fpin);
    printf("\n1. %s  %f", name, *price);
    strcpy(name, "");
    fread(name, sizeof(name),1,fpin);
    fread(price, sizeof(price),1,fpin);
    printf("\n1. %s  %f", name, *price);
    strcpy(name, "");
    fread(name, sizeof(name),1,fpin);
    fread(price, sizeof(price),1,fpin);
    printf("\n1. %s  %f", name, *price);
    strcpy(name, "");
    fread(name, sizeof(name),1,fpin);
    fread(price, sizeof(price),1,fpin);
    printf("\n1. %s  %f", name, *price);
    fclose(fpin);
}

float visualizzaSpeseMensili(Cart* c, int mese){
    float spese = 0;
    while(c != NULL){
        if(c->month == mese){
            spese = spese + c->price;
        }
        c = c->next;
    }
    
    return spese;
}

int controlForBuy(float price, float saldo){
    if(saldo > price){
        return 1;   //se saldo è maggiore dell'importo di acquisto acquisterà il prodotto
    }else{   
        return 0;   //se saldo è minore dell'importo di acquisto non acquisterà il prodotto
    }
}

Cart* acquista(Cart* c, char* name, float price, int day, int month, int year,int type, float* spese, float* saldo, int supermercato){
    if(supermercato == 0){  //se funzione supermercato è disattivata sarà possibile effettuare acquisti
        if(controlForBuy(price, *saldo)){
            Cart* newHead = (Cart*)malloc(sizeof(Cart));
            strcpy(newHead->name, name);
            newHead->price = price;
            newHead->day = day;
            newHead->month = month;
            newHead->year = year;
            newHead->type = type;
            newHead->next = c;
            *spese = *spese + price;
            *saldo = *saldo - price;
            printf("\n acquisto eseguito su %s al prezzo di %f...", name, price);
            return newHead;
        }else{
            printf("\n soldi sul contro insufficenti per effettuare l'acquisto su %s...", name);
            return c;
        }
    }else   //se funzione supermercato è attivata non sarà possibile effettuare acquisti
        printf("\nfunzione supermercato attiva, disattivala per effettuare acquisti");
}

void ricarica(float* saldo, int importo){
    *saldo = *saldo + importo;
}

void visualizzaAcquisti(Cart* c){
    while(c != NULL){
        printf("\nnome: %s  prezzo: %f  data: %d/%d/%d", c->name, c->price, c->day, c->month, c->year);
        c = c->next;
    }
}

void visualizzaAbbonamenti(Cart* c){
    while(c != NULL){
        if(c->type == 1)    //se il tipo dell'acquisto è abbonamento stamperà l'acquisto
            printf("\nnome: %s  prezzo: %f  data: %d/%d/%d", c->name, c->price, c->day, c->month, c->year);
        c = c->next;
    }
}

Action* azioni(Action* a, char* name, float price,int numberOfAction, float* saldo, float* spese, int supermercato){
    if(supermercato == 0){  //se funzione supermercato è disattivata sarà possibile effettuare acquisti
        float buy = numberOfAction * price;
        if(numberOfAction){
            if(controlForBuy(buy, *saldo)){
                Action* newHead = (Action*)malloc(sizeof(Action));
                strcpy(newHead->name, name);
                newHead->number = numberOfAction;
                newHead->price = price;
                newHead->next = a;
                *spese = *spese + price;
                *saldo = *saldo - price;
                printf("\n acquisto dell'azione di %s al costo di %f...", name, price);
                return newHead;
            }else{
                printf("\n soldi sul contro insufficenti per effettuare l'acquisto dell'azione di %s...", name);
                return a;
            }
        }
    }else   //se funzione supermercato è attivata non sarà possibile effettuare acquisti
        printf("\nfunzione supermercato attiva, disattivala per effettuare acquisti");
}

void trend(Action* a, float* spese){
    float bilancio;
    while(a != NULL){
        
        float molti = (rand()%100)-20;  //estrazione casuale di un numero da -20 a 99 e sarà il prezzo corrente dell'azione acquistata
        bilancio = (molti - a->price) * a->number;
        a = a->next;
    }
    printf(" %f", bilancio);
}

void inviaDenaro(float importo, float* saldo){
    if(controlForBuy(importo, *saldo)){
        char inutile[13];   //numero della carta avrà 12 cifre massimo 
        printf("\ninserisci il numero della carta a cui inviare i soldi (12 numeri): ");
        scanf("%s", &inutile);
        printf("%s", inutile);
        if(strlen(inutile) == 12){  //se il numero della carta non è di 12 cifre non avverrà la transazione
            printf("\ntransazione eseguita");
            *saldo = *saldo - importo;
        }else{
            printf("\ntransazione non eseguita... RIPROVA");
        }
    }else{
        printf("\n soldi insufficenti sulla carta");
    }
}

void invitaAmico(char* email){
    char* token;
    for(int i=0; email[i]!='\0';i++){
        if(email[i] == '@'){
            strcpy(token, email+i); //se l'email inserita non finisce con "@gmail.com" non invierà l'invito
            break;
        }
    }
    //mettere strcpy per confrontare @gmail.com
}

void donazioni(float importo, float* saldo){
    if(controlForBuy(importo, *saldo)){
        int scelta;
        do{
            printf("\na chi vuoi inviare la tua donazione?  1.UNICEF  2.TELETHON  3.SAVE THE CHILDREN :");
            scanf("%d",&scelta);
            *saldo = *saldo - importo;
            if(scelta<1 || scelta>3){
                printf("\ninserimento non valido...");
            }
        }while(scelta<1 || scelta>3);
        if(scelta == 1){
            printf("\nil team di UNICEF ti ringrazia per la tua donazione e sicuramente dei bambini gioveranno del tuo bel gesto!");
        }else if(scelta == 2){
            printf("\nil team di TELETHON ti ringrazia per la tua donazione e sicuramente dei bambini gioveranno del tuo bel gesto!");
        }else if(scelta == 3){
            printf("\nil team di SAVE THE CHILDREN ti ringrazia per la tua donazione e sicuramente dei bambini gioveranno del tuo bel gesto!");
        }
    }else{
        printf("\n soldi sul contro insufficenti per effettuare la donazione");
    }
}

void cercaAcquisto(Cart* c, char* name){
    int flag = 0;   //flag = 0 vuol dire che non ha ancora trovato l'ordine
    while(c != NULL){
        if(strcmp(c->name, name) == 0){
            printf("\nordine trovato: acquisto su %s il %d/%d/%d al costo di %f", c->name, c->day, c->month, c->year, c->price);
            flag = 1;
        }
        c = c->next;
    }
    if(flag == 0){
        printf("\nordine inesistente");
    }
}

int main(){
    int scelta; 
    Cart* cart = NULL;
    Action* actionCart = NULL;
    float saldo = 0;
    float speseMensili = 0;
    int supermercato = 0;       //se 1 è attiva la funzione e blocca tutti gli acquisti
    float speseAzioni = 0; 
    int giorno = 1;
    int mese = 1;
    int anno = 2021;
    do{
        printf("\n---------------------------------------------------");
        printf("\nSALDO: %f", saldo);
        printf("\nTOTALE SPESE MENSILI: %f", visualizzaSpeseMensili(cart, mese));     
        printf("\nBILANCIO AZIONI:");
        if(speseAzioni == 0)   //se non hai ancora comprato azioni stampa 0
            printf("0");
        else 
            trend(actionCart, &speseAzioni);
        printf("\n---------------------------------------------------"); 
        printf("\n1.ACQUISTA");   
        printf("\n2.CARICA CARTA");     
        printf("\n3.ACQUISTA AZIONI");  
        printf("\n4.INVIA DENARO");      
        printf("\n5.VISUALIZZA ABBONAMENTI");   
        printf("\n6.INVITA UN TUO AMICO");  
        printf("\n7.ATTIVA FUNZIONE SUPERMERCATO");      
        printf("\n8.DONAZIONI");  
        printf("\n9.VISUALIZZA ACQUISTI");    
        printf("\n10.CERCA ACQUISTO");    
        printf("\n11.!HELP!");       
        printf("\n0.USCITA"); 

        printf("\ndove vuoi andare:");
        scanf("%d", &scelta);
        fflush(stdin);
        printf("---------------------------------------------------");
        if(scelta<0 || scelta>11){
            printf("\nfunzionalita' non disponibile... riprova!");
        }else{
            if(scelta == 1){
            char name[10];
            float price;
            int abbonamento;
            printf("\ninserisci il nome del sito su cui vuoi effettuare l'ordine: ");
            scanf("%s", &name);
            fflush(stdin);
            printf("inserisci il prezzo: ");
            scanf("%f", &price);
            fflush(stdin);
            printf("\nstai effettuando un abbonamento? digita 1 se la tua risposta e' 'si' se no digita 0...");
            scanf("%d", &abbonamento);
            fflush(stdin);
            cart = acquista(cart, name, price, giorno, mese, anno, abbonamento, &speseMensili, &saldo, supermercato);
            
            // cart = acquista(cart, "amazon", 7.99, 25, 1, 2021, 1, &speseMensili, &saldo, supermercato);  //acquisto di tipo abbonamento
            // cart = acquista(cart, "e-bay", 101.99, 4, 1, 2021, 0, &speseMensili, &saldo, supermercato);  //acquisto di tipo normale
            // cart = acquista(cart, "subito", 57.99, 9, 1, 2021, 0, &speseMensili, &saldo, supermercato);  //acquisto di tipo normale
            // cart = acquista(cart, "apple", 2.99, 12, 2, 2021, 1, &speseMensili, &saldo, supermercato);  //acquisto di tipo abbonamento
            // cart = acquista(cart, "e-price", 80.99, 2, 10, 2021, 0, &speseMensili, &saldo, supermercato);   //acquisto di tipo normale
            // cart = acquista(cart, "apple", 2.99, 12, 3, 2021, 1, &speseMensili, &saldo, supermercato);      //acquisto di tipo abbonamento
            // cart = acquista(cart, "amazon", 7.99, 25, 4, 2021, 1, &speseMensili, &saldo, supermercato);     //acquisto di tipo abbonamento

            }else if(scelta == 2){
                float importo;
                printf("\ninserisci quanti soldi vuoi caricare sulla tua MasterClass:");
                scanf("%f", &importo);
                fflush(stdin);
                ricarica(&saldo, importo);

                //ricarica(&saldo, 300);
            }else if(scelta == 3){
                int numeroAzioni;
                int nomeAzione;
                caricaListinoAzioni();
                scaricaListinoAzioni();
                printf("\ninserisci quali azioni vuoi comprare: ");
                scanf("%d", &nomeAzione);
                printf("\ninserisci quante azioni vuoi comprare: ");
                scanf("%d", &numeroAzioni);
                if(nomeAzione == 1){
                    actionCart = azioni(actionCart, "tesla", 25.00, numeroAzioni, &saldo, &speseAzioni, supermercato);
                }else if(nomeAzione == 2){
                    actionCart = azioni(actionCart, "ferrari", 30.00, numeroAzioni,  &saldo, &speseAzioni, supermercato);
                }else if(nomeAzione == 3){  
                    actionCart = azioni(actionCart, "bugatti", 20.00, numeroAzioni,  &saldo, &speseAzioni, supermercato);
                }else if(nomeAzione == 4){
                    actionCart = azioni(actionCart, "nasa", 35.00, numeroAzioni,  &saldo, &speseAzioni, supermercato);
                }else if(nomeAzione == 5){
                    actionCart = azioni(actionCart, "mediaset", 15.00, numeroAzioni,  &saldo, &speseAzioni, supermercato);
                }
            }else if(scelta == 4){
                float importo;
                printf("\ninserisci quando denaro vuoi inviare: ");
                scanf("%f",importo);
                fflush(stdin);
                inviaDenaro(importo, &saldo);
            }else if(scelta == 5){
                visualizzaAbbonamenti(cart);
            }else if(scelta == 6){
                char email[30];
                printf("\ninserisci l'email del tuo amico: ");
                scanf("%s", email);
                fflush(stdin);
                invitaAmico(email);
                invitaAmico(email);
            }else if(scelta == 7){
                if(supermercato == 0){
                    supermercato = 1;
                    printf("\nfunzione supermercato attivata");
                }else{
                    supermercato = 0;
                    printf("\nfunzione supermercato disattivata");
                }
            }else if(scelta == 8){
                float importo;
                printf("\ninserisci l'importo dela tua donazione: ");
                scanf("%f", importo);
                donazioni(importo, &saldo);
                donazioni(importo, &saldo);
            }else if(scelta == 9){
                printf("\nACQUISTI");
                visualizzaAcquisti(cart);
            }else if(scelta == 10){
                char name[10];
                printf("\ninserisci il sito su cui hai effettuato l'acquisto: ");
                scanf("%s", &name);
                fflush(stdin);
                cercaAcquisto(cart, name);
            }else if(scelta == 11){

                printf("\n1.ACQUISTA = effettua un acquisto di qualsiasi tipo!");   
                printf("\n2.CARICA CARTA = carica la tua MasterClass dove vuoi quando vuoi!");     
                printf("\n3.ACQUISTA AZIONI = non farti scappare le opportunita che il mercato ti offre, corri subito ad acquistare azioni e monitorarle con il tuo contro MasterClass!");  
                printf("\n4.INVIA = invia a un tuo amico un regalo! ");      
                printf("\n5.VISUALIZZA ABBONAMENTI = visualizza gli abbonamenti attivi per tenere sempre sotto controllo le tue finanze!");   
                printf("\n6.INVITA UN TUO AMICO = invia tramite email un invito ad unirsi a MasterClass!");      
                printf("\n8.ATTIVA FUNZIONE SUPERMERCATO = puoi congelare temporaneamente i soldi sul tuo contro MasterClass per non farteli rubare in luoghi pubblici!");      
                printf("\n9.DONAZIONI = ricorda che ci sono sempre persone che stanno peggio di noi, aiutale tramite una piccola donazione!");  
                printf("\n10.VISUALIZZA ACQUISTI = visualizza la cronologia di tutti gli acquisti fatti con MasterClass");    
            }
            giorno = giorno +5;     //metto +10 in modo da rendere piu veloce il programma
            if(giorno >= 31){
                mese = mese + 1;
                giorno = 1;
            }else if(mese >= 12){
                anno = anno + 1;
                giorno = 1;
                mese = 1;
            }
        }
    }while(scelta != 0);

}
