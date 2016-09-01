#include "stdio.h"
#include "stdlib.h"

#ifndef _list_h

struct node;
typedef struct node *ptrToNode;
typedef ptrToNode list;
typedef ptrToNode position;

list MakeEmpty(list l);
int IsEmpty(list l);
int IsLast(position p, list l);
position Find(int x, list l);
void Delete(int x, list l);
position FindPrevious(int x, list l);
void Insert(int x, list l, position p);
void DeleteList(list l);
position Header(list l);
position First(list l);
position Advance(position p);
int Retrieve(position p);

#endif

struct node{
    int element;
    position next;
};

list MakeEmpty(list l){
    l->next = NULL;
    return l;
}

int IsEmpty(list l){
    return l->next == NULL;
}

int IsLast(position p, list l){
    return p->next == NULL;
}

position Find(int x, list l){
    position p;

    p = l->next;
    while (p != NULL && p->element != x ) {
        p = p->next;
    }

    return p;
}

position FindPrevious(int x, list l){
    position p;

    p = l;
    while (p->next != NULL && p->next->element != x) {
        p = p->next;
    }
    if (p->next == NULL) p = NULL;

    return p;
}

void Delete(int x, list l) {
    position p, tempCell;

    p = FindPrevious(x, l);
    if (p) {
        tempCell = p->next;
        p->next = tempCell->next;
        free(tempCell);
    }

}

void Insert(int x, list l, position p) {
    position tempCell;
    tempCell = malloc(sizeof(struct node));

    tempCell->element = x;
    tempCell->next = p->next;
    p->next = tempCell;
}

void DeleteList(list l){
    position temp, p;
    p = l->next;
    l->next = NULL;
    while (p) {
        temp = p->next;
        free(p);
        p = temp;
    }

}
