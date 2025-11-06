//
// Created by Sarthak Duvedi on 28/10/25.
//
// Code to build a binary tree, with given preOrder Sequence

#include<iostream>
#include<queue>

class Queue;

class Node {

public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        this->data = val;
        left = NULL;
        right = NULL;
    }

};

class Tree {
public:
    Node* root;

    Tree() {
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


    friend bool findElement(Node* root, int k);
    friend void traverseDepth(Node* root);
    friend int heightOfTree(Node* root);
    friend void traverseBreadth(Node* root);
    friend bool isTreeSame(Node* root1, Node* root2);



};

     void traverseDepth(Node* root) {

        if (root == NULL) {
            return;
        }

        std::cout << root->data << " ";
        traverseDepth(root->left);
        traverseDepth(root->right);

    }

     bool findElement(Node* root, int k) {

         if (root == NULL) {
             return false;
         }

          if (root->data == k) {
             return true;
          }


     bool inLeft = findElement(root->left, k) ;
     bool inRight = findElement(root->right, k);


    return (inLeft || inRight);

 }

    int heightOfTree(Node* root) {

         if (root == NULL) {
             return 0;
         }

         int lh = heightOfTree(root->left);
         int rh = heightOfTree(root->right);

         return std::max(lh, rh) + 1;

     }

    std::queue <Node*> Q;

    void traverseBreadth(Node* root) {

        if (root == NULL) {
            return;
        }

         Q.push(root);

        if (root->left || root->right) {
            Q.push(NULL);
            traverseBreadth(root->left);
            traverseBreadth(root->right);
        }

        // Q.push(root->left);
        // Q.push(root->right);

        //if (root->left)
            //Q.push(root->left);
        //if (root->right)
           // Q.push(root->right);

        while (Q.size() > 0) {
            if (Q.front() == NULL) {
                std::cout << std::endl;
                Q.pop();
            } else {
                std::cout << Q.front()->data << " ";
                Q.pop();
            }
        }

        // if (root->right) {
        //     Q.push(root->right);
        // }
        // std::cout << Q.front()->data << " ";
        // Q.pop();

     }

    bool isTreeSame(Node* r1, Node* r2) {

        if (r1 == NULL && r2 == NULL) {
            return true;
        }

        if (r1 == NULL || r2 == NULL) {
            return false;
        }

        bool isLeft = isTreeSame(r1->left, r2->left);
        bool isRight = isTreeSame(r1->right, r2->right);

        return (isLeft && isRight && r1->data == r2->data);

    }



int main() {


    int preOrder1[] = {1, 2, -1, -1, 3, 4, -1, 6, 5, -1, -1};
        int preOrder2[] = {1, 2, -1, -1, 3, 4, -1, 6, 5, -1, -1};
        int BSTPreOrder[] = {3, 2, -1, -1, 4, 1, -1, -1, 5, -1, -1};

    Tree tree1;
    Tree tree2;
        Tree tree3;


    tree1.root = tree1.buildTree(preOrder1, 11);
    tree2.root = tree2.buildTree(preOrder2, 11);

     // traverseTree(tree1.root);

       // bool x = findElement(tree1.root, 5);
         // std::cout << x << std::endl;

         // int y = heightOfTree(tree1.root);
         // std::cout << y << std::endl;

        traverseBreadth(tree1.root);




    return 0;
}