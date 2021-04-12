/*lista di studenti con nome cognome e media*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student{
    char name[20];
    char sur[20];
    float media;
    struct student* next;
}Student;

typedef struct{
    int b;
    int h;
}Rettangolo;

typedef struct nodo{
    Rettangolo dati;
    struct nodo* next;
}Nodo;

void pushhead(Student** stu,char* name,char* sur,float media){
    Student* newhead = (Student*)malloc(sizeof(Student));
    Student* temp = newhead;
    newhead->next = (*stu);
    strcpy(newhead->name, name);
    strcpy(newhead->sur, sur);
    newhead->media = media;
    (*stu) = temp;
}

/*Student* popcoda(Student** stu,char* name,char* sur,float media){
    Student* copy = (*stu);
    
    if((*stu) == NULL){
        Student* newcoda = (Student*)malloc(sizeof(Student));
        (*stu)->next = newcoda;
        strcpy(newcoda->name, name);
        strcpy(newcoda->sur, sur);
        newcoda->media = media;
        newcoda->next = NULL;
        (*stu) = newcoda;
        return (*stu);
    }else{
        Student* tmp = (*stu);
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = (Student*)malloc(sizeof(Student));
        tmp = tmp->next;
        strcpy(tmp->name, name);
        strcpy(tmp->sur, sur);
        tmp->media = media;
        tmp->next = NULL;
        (*stu) = copy;
    }
    popcoda(&(*stu)->next,name,sur,media);
}*/

Student* pushcoda(Student* stu,char * name,char* sur, float media){
    //printf("ciao");
    if(stu == NULL){
        Student* newcoda = (Student*)malloc(sizeof(Student));   
        //printf("ciao");
        strcpy(newcoda->name, name);
        strcpy(newcoda->sur, sur);
        newcoda->media = media;
        newcoda->next = NULL;
        //printf("ciao");
        return newcoda;
    }else{
        Student* tmp = stu;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        Student* newcoda = (Student*)malloc(sizeof(Student));
        tmp->next = newcoda;
        strcpy(newcoda->name, name);
        strcpy(newcoda->sur, sur);
        newcoda->media = media;
        newcoda->next = NULL;
        return stu;
    }
    pushcoda(stu->next,name,sur,media);
}

void print(Student* stu){
    while(stu != NULL){
        printf("%s   %s   %f\n", stu->name, stu->sur, stu->media);
        stu = stu->next;
    }
}

Student* pophead(Student* stu){
    Student* tmp = stu;
    Student* newhead = stu->next;
    free(tmp);
    return newhead;
}

Student* popcoda(Student* stu){
    Student* tmp = stu;
    if(tmp != NULL){
        if(tmp->next == NULL){
            stu=NULL;
            free(tmp);
        }else{
            while(tmp->next->next != NULL){
                tmp = tmp->next;
            }
            free(tmp->next);
            tmp->next = NULL;
        }
    }
    return stu;
}

void addNodo(Nodo** list, int b, int h){
    Nodo* newr = (Nodo*)malloc(sizeof(Nodo));
    newr->dati.b = b;
    newr->dati.h = h;

    newr->next = (*list);
    (*list) = newr;
}

int main(){
    Student* stu = NULL;
    stu = pushcoda(stu, "michele", "pinotti", 6.892545);
    stu = pushcoda(stu, "bhsdgh", "pinjaduhaddotti", 7.288);
    stu = pushcoda(stu, "jadjdunxx", "djbbhb", 8.1555);

    stu = popcoda(stu);
    print(stu);

    Nodo* list = NULL;
    addNodo(&list, 4, 8);
    addNodo(&list, 5, 9);
    addNodo(&list, 2, 6);

    Nodo* tmp = list;
    while(tmp != NULL){
        int area = (list->dati.b) * (list->dati.h) / 2;
        printf("\nbase: %d   altezza: %d   area: %d", tmp->dati.b, tmp->dati.h, area);
        tmp = tmp->next;
    }
}