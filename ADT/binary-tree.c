#include "stdlib.h"
#include "stdio.h"

#ifndef _binarytree_h

struct treeNode;
typedef struct treeNode *binaryTree;
typedef struct treeNode *position;

binaryTree MakeEmpty(binaryTree t);
position Find(int x, binaryTree t);
position FindMin(binaryTree t);
position FindMax(binaryTree t);
binaryTree Insert(int x, binaryTree t);
binaryTree Delete(int x, binaryTree t);
//Next three interation traversal routines
void preOrderTraversal(binaryTree t);
void inOrderTraversal(binaryTree t);
void pastOrderTraversal(binaryTree t);

#endif

struct treeNode{
    int element;
    position left;
    position right;
};

binaryTree MakeEmpty(binaryTree t){
    if (t != NULL) {
        MakeEmpty(t->left);
        MakeEmpty(t->right);
        free(t);
    }
    return t;
}

position Find(int x, binaryTree t){
    if(t == NULL) return NULL;
    if(t->element > x) return Find(x, t->left);
    else if(t->element < x) return Find(x, t->right);
    else return t;
}

position FindMin(binaryTree t){
    if (t != NULL) {
        while (t->left != NULL) {
            t = t->left;
        }
    }
    return t;
}

position FindMax(binaryTree t){
    if (t != NULL) {
        while (t->right != NULL) {
            t = t->right;
        }
    }
    return t;
}

binaryTree Insert(int x, binaryTree t){
    if (t == NULL) {
        t = malloc(sizeof(struct treeNode));
        t->element = x;
        t->left = NULL;
        t->right = NULL;
    }
    else if (t->element > x) t->left = Insert(x, t->left);
    else if (t->element < x) t->right = Insert(x, t->right);
    //此过程中，仅插入的叶节点被挂载在子树位置，原树结构未改变
    return t;
}

binaryTree Delete(int x, binaryTree t){
    position temp;

    if (t == NULL) return NULL;
    if (t->element > x) t->left = Delete(x, t->left);
    else
    if (t->element < x) t->right = Delete(x, t->right);
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

    return t;
}
