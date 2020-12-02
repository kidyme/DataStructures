//
// Created by kidyme on 2020/11/23.
//

#ifndef PRAC_C_BINARYTREE_H
#define PRAC_C_BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>
#define OVERFLOW 1

typedef struct node {
    char data;
    struct node *left;
    struct node *right;
} Node, *NodePtr, *Tree;

Tree InitTree();
// 初始化树

Tree InsertTree(Tree tree, char pre_node, int isLeft);
// 插入

void Preorder(Node *node);
// 先序遍历


#endif//PRAC_C_BINARYTREE_H
