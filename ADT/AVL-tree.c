#include "stdlib.h"

#ifndef _avltree_h

struct treeNode;
typedef struct treeNode* avltree;
typedef struct treeNode* position;

avltree MakeEmpty(avltree t);
int Height(avltree t);
int Max(int a, int b);
position Find(int x, avltree t);
position FindMin(avltree t);
position FindMax(avltree t);
avltree Insert(int x, avltree t);
avltree Delete(int x, avltree t);
avltree LL(avltree t);
avltree RR(avltree t);
avltree LR(avltree t);
avltree RL(avltree t);

#endif

struct treeNode{
    int element;
    position left;
    position right;
    int height;
};

avltree MakeEmpty(avltree t){
    if (t != NULL) {
        MakeEmpty(t->left);
        MakeEmpty(t->right);
        free(t);
    }
    return t;
}

int Height(avltree t){
    if(t == NULL) return -1;
    else return t->height;
}

int Max(int a, int b){
    return (a > b)? a : b;
}

position Find(int x, avltree t){
    while (t) {
        if (t->element > x) t = t->left;
        else
        if (t->element < x) t = t->right;
        else break;
    }

    return t;

}

position FindMin(avltree t){
    position temp = t;
    while (t) {
        temp = t;
        t = t->left;
    }
    return temp;
}

position FindMax(avltree t){
    position temp = t;
    while (t) {
        temp = t;
        t = t->right;
    }
    return temp;
}

avltree Insert(int x, avltree t){
    if (t == NULL) {
        t = malloc(sizeof(struct treeNode));
        t->element = x;
        t->left = t->right = NULL;
        t->height = 0;
    }
    else
    if (x < t->element) {
        t->left = Insert(x, t->left);
        if (Height(t->left) - Height(t->right) > 1) {
            if (x < t->left->element) t = LL(t);
            else t = LR(t);
        }
    }
    else
    if (x > t->element) {
        t->right = Insert(x, t->right);
        if (Height(t->right) - Height(t->left) > 1) {
            if (x > t->right->element) t = RR(t);
            else t = RL(t);
        }
    }

    t->height = Max(Height(t->left), Height(t->right)) + 1;
    return t;
}

avltree Delete(int x, avltree t){
    position temp;

    if (t == NULL) return NULL;
    if (x < t->element){
        t->left = Delete(x, t->left);
    }
    else
    if (x > t->element){
        t->right = Delete(x, t->right);
    }
    else
    if (t->left && t->right) {
        temp = FindMin(t->right);
        t->element = temp->element;
        t->right = Delete(t->element, t->right);
    }
    else{
        temp = t;
        if (t->left == NULL) t = t->right;
        else
        if (t->right == NULL) t = t->left;
        free(temp);
    }

    if (t){
        if (Height(t->left) - Height(t->right) == 2) {
            if (Height(t->left->left) >= Height(t->left->right)) t = LL(t);
            else t = LR(t);
        }
        if (Height(t->right) - Height(t->left) == 2) {
            if (Height(t->right->right) >= Height(t->right->left)) t = RR(t);
            else t = RL(t);
        }
        t->height = Max(Height(t->left), Height(t->right)) + 1;
    }

    return t;

}

avltree LL(avltree t){
    position tempCell;

    tempCell = t->left;
    t->left = tempCell->right;
    tempCell->right = t;

    t->height = Max(Height(t->left), Height(t->right)) + 1;
    tempCell->height = Max(Height(tempCell->left), t->height) + 1;

    return tempCell;
}

avltree RR(avltree t){
    position tempCell;

    tempCell = t->right;
    t->right = tempCell->left;
    tempCell->left = t;

    t->height = Max(Height(t->left), Height(t->right)) + 1;
    tempCell->height = Max(t->height, Height(tempCell->right)) + 1;

    return tempCell;
}

avltree LR(avltree t){
    t->left = RR(t->left);
    return LL(t);
}

avltree RL(avltree t){
    t->right = LL(t->right);
    return RR(t);
}
