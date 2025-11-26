//
// Created by Sarthak Duvedi on 12/11/25.
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

    Node* getDifferentTree(int n);


};

Node* getDifferentTree(int n) {

    int newArray[n];

    for (int i = 1; i <= n; i++) {
        newArray[i - 1] = i;
    }

    for (int i = 0; i < n; i++) {
        Node* root = new Node(newArray[i]);
        for (int j = 0; j < n; j++) {
            if (j == i) {
                continue;
            } else {
                if (j < i) {
                    root->left = new Node(newArray[j]);
                } else {
                    root->right = new Node(newArray[i]);
                }
            }
        }

        return root;

    }

}

int main() {

    int n = 3;

    Node* roots[];

    for (int i = 0; i < n; i++) {
        roots[i] = getDifferentTree(i);
    }



    return 0;
}