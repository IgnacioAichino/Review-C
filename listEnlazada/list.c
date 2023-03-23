#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Nodo
{
    int value;
    struct Nodo* sig;
}Nodo;


typedef struct List
{
    int size;
    Nodo* firstItem;
}List;


List* newList(){
    List* ll= (List*) malloc(sizeof(List));
    ll->size= 0;
    ll->firstItem= NULL;

    return ll;
}

Nodo* creatNode(int data){
    Nodo* nodo= (Nodo*) malloc(sizeof(Nodo));
    nodo->value= data;
    nodo->sig= NULL;

    return nodo;
}

void add(List* ll, Nodo* nodo){
    
    Nodo* temp= ll->firstItem;

    if(ll->firstItem == NULL){ //primer nodo
        ll->firstItem= nodo;
    }
    else{
        while(temp->sig){
            temp= temp->sig;
        }
        temp->sig= nodo;
    }

    ll->size++;
}

Nodo* read(List* ll, unsigned int index){
    
    if(ll->firstItem == NULL){
        return NULL;
    }
    else{
        Nodo* temp= ll->firstItem;        
        int i= 0;
        while(i<index && temp->sig){
            temp= temp->sig;
            i++;
        }

        if(i != index) return NULL;
        return temp;
    }
}


int contar(List* ll){
    return ll->size;
}

int main(){

    List* list= newList();

   /* Nodo* a= creatNode(1);
    Nodo* b= creatNode(2);
    Nodo* c=  creatNode(3);
    
    add(list, a);
    add(list, b);
    add(list, c);*/
    
    int option= 0;
    do{
        printf("\nMenu: \n"
                "[1] Añadir nodo a lista \n"
                "[2] Ver cantidad de elementos \n"
                "[3] Obtener nodo: \n"
                "[4] Exit \n");
        
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("\nIndique valot INT para nodo: ");
                int value= 0;
                scanf("%d", &value);
                add(list, creatNode(value));
                break;

            case 2:
                printf("\nElementos total: %d\n", contar(list));
                break;
       
            case 3:
                printf("Indique numero de nodo: ");
                int index= 0;
                scanf("%d", &index);
                printf("\nValor nodo: %d\n", read(list,index)->value);
                break;
            
            case 4:
                exit(0);             
            
            default:
                printf("\n OPCION INCORRECTA \n");
                break;
        }
    }while(option != 1 || option !=2 || option !=3 || option != 4);

    return 0;
}