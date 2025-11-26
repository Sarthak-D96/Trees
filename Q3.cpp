//
// Created by Sarthak Duvedi on 18/11/25.
//

// i understood what the question is asking,
// but i didnt get what input format is required

#include<iostream>

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree {
    Node* root;
    public:
    BinaryTree() {
        root = NULL;
    }

    Node* BuildTree(int preOrder[], int size) {
        static int i = -1;
        Node* root = new Node(preOrder[i++]);


        if(preOrder[i] == -1) {
            return NULL;
        }

        root->left = BuildTree(preOrder, size);
        root->right = BuildTree(preOrder, size);

        return root;

    }

};
