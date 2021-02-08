/*Es1.
Creare un algoritmo che ricevute due stringhe come parametri le concatena in una stringa unica e la stampa a video.
ciao fabio ---> ciaofabio

Es2.
Creare un programma che richiede in input una stringa di più parole, suddivide la stringa in singole parole e le comunica a video*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void concatena(char*, char*);
int lenght(char*, char*);
void suddividi();
void print(int );

int main(int argc, char** argv){
    concatena(*(argv+1), *(argv+2));
    suddividi();
    return 0;
}

void concatena(char* s1,char* s2){
    const int DIM = lenght(s1, s2) + 1;
    char s3[DIM];
    s3[DIM - 1] = '\0';
    for (int i = 0, j = 0, z=0; i<DIM-1; i++){
        if(*(s1 + z) != '\0'){
            *(s3 + i) = *(s1 + z);
            z++;
        }
        else{
            *(s3 + i) = *(s2 + j);
            j++;
        }
    }
    printf("%s", s3);
}

int lenght(char* a, char* b){           //dimensione finale che avrà la stringa concatenata
    if(*a != '\0' && *b != '\0')
        return 2 + lenght((a + 1), (b + 1));
    else if(*a == '\0' && *b != '\0')
        return 1 + lenght(a, (b + 1));
    else if(*a != '\0' && *b == '\0')
        return 1 + lenght((a + 1), b);
    else
        return 0;
}

void suddividi(){
    char str[30];
    char s1[10];
    char s2[10];

    printf("inserisci la stringa\n");
    gets(str);
    int j;
    int k = 1;
    for(int i=0; str[i]!=0 && k!=0;i++){
        if(str[i]!=' '){
            s1[i]=str[i];
        }
        else{
            for(i;str[i]!='\0';i++){
                s2[i]=str[i];
                k=0;
            }
        }
    }
    printf("stringa 1: %s\n", s1);
    printf("stringa 2: %s", s2);
   
}

