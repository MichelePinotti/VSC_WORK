/*Es1.
Creare un algoritmo che ricevute due stringhe come parametri le concatena in una stringa unica e la stampa a video.*/

/*Es2.
Creare un algoritmo che ricevuta una stringa di due parole le divide in due stringhe e le stampa a video.*/


#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#define DIM1 10
#define DIM2 10
#define DIM3 20
void concatena(char*, char*);
void dividi(char*);
int lenght(char*);

int main(){
    /*char s1[DIM1];
    char s2[DIM2];
    printf("\ninserisci la stringa 1 ");
    scanf("%s", s1);
    printf("\ninserisci la stringa 2 ");
    scanf("%s", s2);

    concatena(s1, s2);*/

    char str[DIM3];
    printf("\ninserisci la stringa di due parole");
    gets(str);
    dividi(str);
}

void concatena(char* s1, char* s2){
    char s3[DIM1+DIM2];
    int cnt;

    for(int i=0; i<DIM1; i++){  //copia s1 in s3
        s3[i] = s1[i];
    }
    for(int i=0, cnt=0; i<DIM1; i++,cnt++){     //copia s2 in s3
        if(s3[i] == '\0'){
            for(int j=0; j<DIM2;j++){
                s3[i]=s2[j];
                i++;
            }
        }
    }
    printf("\nstringa unita: %s", s3);
}

void dividi(char* s){
    char* s1=(char*)malloc(DIM1*(sizeof( char)));   //ho messo malloc perchè cosi svuota le celle che non utilizzerai se non le usi tutte e 10
    char s2[DIM1];
    for(int i=0; i<lenght(s); i++){  //riempimento stringa 1

        printf("-%d-", i);
        s1[i]=s[i];
    }

    for(int i=lenght(s), j=0; j<DIM1; i++, j++){  //riempimento stringa 2
        s2[j] = s[i];
    }
    printf("\nstringa1 : %s", s1);
    printf("\nstringa2 : %s", s2);
}

int lenght(char* s){
    int spazio;
    for(int i=0; i<DIM3; i++){  
        if(s[i] == ' '){
            spazio=i+1;
        }
    }
    return spazio;
}