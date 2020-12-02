#include "BinaryTree.h"

int main() {
        printf("Start\n");
        Tree tree = InitTree();
        tree = InsertTree(tree, ' ', -1);// 插入根节点时，第三个参数可取任意值

        Preorder(tree);
        printf("\n");
        Preorder(tree);
    return 0;
}
