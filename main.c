#include <stdio.h>
#include <stdlib.h>
#define capacity 10

typedef struct{
    int v[capacity]; //vector cu pozitii capacitate
    int size; //cate elemente ai in vector
    int head, tail //first, last
}queue;

//1)
void enqueue( queue *coada, int givenkey){
    if(coada->size == capacity) //verificam daca coada este plina
    {
        printf("Coada plina");
        return;
    }
    coada->v[coada->tail] =givenkey;
    coada->tail++;

    if(coada->tail == capacity) coada->tail=0;

    coada->size++;
}

//2)
int dequeue(queue *coada){
    if(coada->size == 0)
    {
         printf("Coada goala");
        return 0;
    }

    int val = coada->v[coada->head];
    coada->head++;
    if(coada->head==capacity) coada->head=0;

    coada->size--;
    return val;
}

//3
void afisare(queue* coada)
{
    if(coada->size ==0) printf("Coada este goala");
    else{

        if(coada->head <= coada->tail){
            for(int i=coada->head; i <coada->tail; i++)
                printf("%d", coada->v[i]);
            printf("\n");
        }
        else{
            for(int i=coada->head; i<capacity; i++)
                printf("%d", coada->v[i]);
            for(int i=0; i<coada->tail; i++)
                printf("%d", coada->v[i]);

            printf("\n");
        }
    }
}

int main()
{
    queue coada;
    coada.size = 0;
    coada.head=0;
    coada.tail=0;

    enqueue(&coada,3);
    enqueue(&coada,6);
    enqueue(&coada,2);
    enqueue(&coada,1);
    afisare(&coada);

    dequeue(&coada);
    dequeue(&coada);
    afisare(&coada);

    return 0;
}
