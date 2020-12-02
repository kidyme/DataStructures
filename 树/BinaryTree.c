//
// Created by kidyme on 2020/11/23.
//

#include "BinaryTree.h"

Tree InitTree() {
    Tree tree = NULL;

    return tree;
}

Tree InsertTree(Tree tree, char pre_node, int isLeft) {
    char value;

    if (pre_node == ' ') {
        printf("输入根节点值:  ");
    }
    else {
        printf("输入节点%c的", pre_node);
        if (isLeft) {
            printf("左孩子值:  ");
        }
        else {
            printf("右孩子值:  ");
        }
    }

    scanf("%c", &value);
    fflush(stdin); // 清除缓冲区的换行符

    // 输入为空则退出
    if (value == ' ') {
        return tree;
    }

    NodePtr new_node = (NodePtr) malloc(sizeof(Node));
    if (!new_node) {
        exit(OVERFLOW);
    }

    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    tree = new_node;

    tree->left = InsertTree(tree->left, tree->data, 1);
    tree->right = InsertTree(tree->right, tree->data, 0);

    return tree;
}

void Preorder(Node *node) {
    if (node) {
        printf("%c ", node->data);
        Preorder(node->left);
        Preorder(node->right);
    }
}