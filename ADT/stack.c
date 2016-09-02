#include "stdlib.h"

#ifndef _stack_h

struct node;
typedef struct node *ptrToNode;
typedef ptrToNode stack;

int IsEmpty(stack s);
stack CreatStack();
void DisposeStack(stack s);
void MakeEmpty(stack s);
void Push(int x, stack s);
int Pop(stack s);
int Top(stack s);

#endif

struct node{
    int element;
    ptrToNode next;
};

int IsEmpty(stack s){
    return s->next == NULL;
}

stack CreatStack(){
    stack s;

    s = malloc(sizeof(struct node));
    s->next = NULL;
    return s;

}

void MakeEmpty(stack s){
    if(s != NULL){
        while (!IsEmpty(s)) {
            Pop(s);
        }
    }
}

void Push(int x, stack s){
    ptrToNode tempCell;
    tempCell->element = x;
    tempCell->next = s->next;
    s->next = tempCell;

}

int Pop(stack s){
    int tempValue;
    ptrToNode tempCell;
    tempCell = s->next;
    s->next = s->next->next;
    tempValue = tempCell->element;
    free(tempCell);
    return(tempValue);
}
