//
// Created by Sarthak Duvedi on 11/11/25.
//

#include<iostream>


class Node {

    public:
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = NULL;
    }


    Node* buildTree(int preOrder[], int size) {

        static int i = -1;
        i++;

        if (preOrder[i] == -1 || i >= size) {
            return NULL;
        }

        Node* root = new Node(preOrder[i]);

        root->left = buildTree(preOrder, size);
        root->right = buildTree(preOrder, size);

        return root;

    }

    int leftLeaveSum(Node* root) {
        static int sum = 0;

        if (root == NULL) {
            return 0;
        }

        if (root->left) {
            sum += root->left->data;
        }else {
            return 0;
        }

        int leftSum = leftLeaveSum(root->left);
        int rightSum = leftLeaveSum(root->right);

        return  sum;

    }


};

int main() {

    BinaryTree BT;

    int preOrder[] = {3, 9, -1, -1, 20, 15, 1, -1, 7, -1, -1};
    BT.root = BT.buildTree(preOrder, 11);

    int x = BT.leftLeaveSum(BT.root);

    std::cout << x << std::endl;


    return 0;
}