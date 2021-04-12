
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>

#define DIM 16

int insert(char*);
int occourrence(char*, char);
void anagram(char*);
int suddividi(char*,char* ,char*);


int main(){
    char str[DIM];
    int scelta;

    do{
        printf("\n1.Inserimento stringa\n2.Conteggio occorrenze\n3.Generazione anagrammi\n4.suddividi\n5.Anagrammi\n0.USCITA");
        scanf("%d", &scelta);
        fflush(stdin);

        if(scelta==1){
            printf("\ninserisci una tringa di minimo 2 caratteri e massimo 15 caratteri: ");
            int flag = insert(str);
            if(flag){
                printf("\nstringa inserita con successo");
            }else{
                printf("\nstringa inserita non valida... ");
            }
        }
        if(scelta==2){
            char l;
            printf("\nscrivi che lettera vuoi cercare: ");
            scanf("%c", &l);
            int occ = occourrence(str, l);
            printf("\nla lettera da te scelta si presenta %d volte nella stringa", occ);
        }
        if(scelta==3){
            anagram(str);
        }
        if(scelta==4){
            char* s1=(char*)malloc(DIM*(sizeof( char)));   
            char s2[DIM];
            int riuscita = suddividi(str, s1, s2);
            if(riuscita){
                printf("\nstringa 1: %s",s1);
                printf("\nstringa 2: %s",s2);
            }else{
                printf("\nla stringa non e' composta da due parole");
            }
        }
    }while(scelta!=0 || scelta<0 || scelta>5);
}

int insert(char* s){
    gets(s);
    if(strlen(s)>15 || strlen(s)<2){
        return 0;
    }else{
        return 1;
    }
}

int occourrence(char* s, char l){
    int occ=0;
    for(int i=0; i<DIM; i++){
        if(*(s+i) == l)
            occ= occ+1;
    }
    return occ;
}

void anagram(char* s){
    printf("sto generando 5 anagrammi della stringa %s",s );
    char s1[DIM];
    char s2[DIM];
    char s3[DIM];
    char s4[DIM];
    char s5[DIM];

    for(int i=0; i<DIM; i++){

    }
}

int suddividi(char* s, char* s1, char* s2){
    int flag=0;
    int cnt=0;
    for(int i=0; i<DIM; i++){
        if(s[i] == ' ')
            flag=1;
    }
    if(flag){
        for(int i=0; s[i] != '\0'; i++){ 
            s1[i]=s[i];
            cnt=i;
        }

        for(int i=cnt, j=0; j<DIM; i++, j++){ 
            s2[j] = s[i];
        }
        return 1;
    }else{
        return 0;
    }
}