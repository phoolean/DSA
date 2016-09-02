#include "stdlib.h"

#ifndef _queue_h

struct node;
typedef struct node *queue;

int IsEmpty(queue q);
int IsFull(queue q);
queue CreatQueue(int maxEleNum);
void DisposeQueue(queue q);
void MakeEmpty(queue q);
void Enqueue(int x, queue q);
int Dequeue(queue q);


#endif

struct node{
    int front;
    int rear;
    int size;
    int capacity;
    int *array;
};

int IsEmpty(queue q){
    return q->size == 0;
}

int IsFull(queue q){
    return q->size == q->capacity;
}

queue CreatQueue(int maxEleNum){
    queue q;
    q = malloc(sizeof(struct node));
    q->array = malloc(sizeof(int) * maxEleNum);
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    q->capacity = maxEleNum;
    return q;

}

void MakeEmpty(queue q){
    if (q->size != 0) {
        while(q->size){
            Dequeue(q);
        }
    }
}

void Enqueue(int x, queue q){
    if (!IsFull(q)) {
        q->rear = (q->rear+1)%q->capacity;
        q->array[q->rear] = x;
        q->size++;
    }
}

int Dequeue(queue q){
    int temp;
    if (!IsEmpty(q)) {
        temp = q->array[q->front];
        q->front = (q->front+1)%q->capacity;
        q->front++;
    }

    return temp;

}
