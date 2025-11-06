//
// Created by Sarthak Duvedi on 04/11/25.
//

#include<iostream>

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

    Node* insert(Node* root,int val) {

        if (root == NULL) {
            return new Node(val);
        }

        if (val < root->data) {
            root->left = insert(root->left, val);
        } else {
            root->right = insert(root->right, val);
        }

        return root;

    }

    // QUESTION 3
    friend bool findBSTElement(Node* root, int k);
    friend Node* findBSTElementNode(Node* root, int k);
    friend void traverseDepth(Node* root);
    friend int maxBSTElement(Node* root);
    friend int minBSTElement(Node* root);
    friend Node* inOrderSuccessor(Node* root);


    // QUESTION 4
    friend Node* insertElement(Node* root, int k);
    friend Node* deleteNode(Node* root, int k);
    friend int maxDepthBST(Node* root);
    friend int minDepthBST(Node* root);
    friend bool isBST(Node* root);


    // friend void traverseDepth(Node* root);
    // friend int heightOfTree(Node* root);
    // friend void traverseBreadth(Node* root);
    // friend bool isTreeSame(Node* root1, Node* root2);


};

void traverseDepth(Node* root) {

    if (root == NULL) {
        return;
    }

    std::cout << root->data << " ";
    traverseDepth(root->left);
    traverseDepth(root->right);

}


bool findBSTElement(Node* root, int k) {

    if (root == NULL) {

        return false;

    } else if (root->data > k) {

        return findBSTElement(root->left, k);

    } else if (root->data < k) {

        return findBSTElement(root->right, k);

    } else {
        return true;
    }

}


int maxBSTElement(Node* root) {

    if (root->right == NULL)
        return root->data;
    else
       return maxBSTElement(root->right);

}

int minBSTElement(Node* root) {

    if (root->left == NULL)
        return root->data;
    else
        return minBSTElement(root->left);

}

Node* findBSTElementNode(Node* root, int k) {

    if (root == NULL) {

        return NULL;

    } else if (root->data > k) {

        return findBSTElementNode(root->left, k);

    } else if (root->data < k) {

        return findBSTElementNode(root->right, k);

    } else {

        return root;

    }

}

Node* inOrderSuccessor(Node* root, int data) {

        static Node* prev = NULL;

    if (root != NULL && root->data == data) {

        if (root -> right) {
            return root->right;
        } else {
            if (prev != NULL) {
                return prev;
            } else {
                return NULL;
            }
        }
    }

    prev = root;

    if (root->data < data) {
        return inOrderSuccessor(root->right, data);
    } else {
       return inOrderSuccessor(root->left, data);
    }

}

Node* inOrderPredecessor(Node* root, int data) {

    static Node* prev = NULL;

    if (root != NULL && root->data == data) {

        if (root -> left) {
            return root->left;
        } else {
            if (prev != NULL) {
                return prev;
            } else {
                return NULL;
            }
        }
    }

    if (root->data < data) {
        prev = root;
        return inOrderSuccessor(root->right, data);
    } else {
        prev = root;
        return inOrderSuccessor(root->left, data);
    }


}


Node* insertElement(Node* root, int k) {

    if (root == NULL) {
        return new Node(k);
        // root = newNode;
        // return;
    }

    if (root->data < k) {
        root->right =  insertElement(root->right, k);
    } else {
       root->left = insertElement(root->left, k);
    }

    return root;

}

Node* deleteNode(Node* root, int k) {

    if (root == NULL) {
        return NULL;
    }

    if (root->data == k) {
        delete root;
    } else if (k < root->data) {
        return  deleteNode(root->left, k);
    } else {
        return deleteNode(root->right, k);
    }

    return root;

}

int maxDepthBST(Node* root) {

    if (root == NULL) {
        return 0;
    }

    int leftDepth = maxDepthBST(root->left);
    int rightDepth = maxDepthBST(root->right);

    return std::max(leftDepth + 1, rightDepth + 1);

}

int minDepthBST(Node* root) {

    if (root == NULL) {
        return 0;
    }

    int leftDepth = maxDepthBST(root->left);
    int rightDepth = maxDepthBST(root->right);

    return std::min(leftDepth + 1, rightDepth + 1);

}

bool isBST(Node* root) {

    if (root == NULL) {
        return true;
    }

    if (root->data < root->left->data || root->data > root->right->data)
        return false;



    bool isLeftSmall = isBST(root->left);
    bool isRightSmall = isBST(root->right);

    return isLeftSmall && isRightSmall;

}


int main() {



    Tree tree1;

    int a[] = {3, 2, 1, 5, 6, 4};

    for(int i = 0; i < 6; i++)
      tree1.root = tree1.insert(tree1.root, a[i]);

     // traverseDepth(tree1.root);

     tree1.root = insertElement(tree1.root, 7);
     traverseDepth(tree1.root);

    // Node* myNode = findBSTElement(tree1.root, 4);
    // std::cout << myNode->data << " ";

     // bool x = findBSTElement(tree1.root, 1);
     // std::cout << x << std::endl;


     //tree1.root = deleteNode(tree1.root, 1);
     //traverseDepth(tree1.root);

    // Node* myNode = inOrderSuccessor(tree1.root, 6);
    // Node* yourNode = inOrderPredecessor(tree1.root, 3);
    //
    // std::cout << myNode->data << " " << std::endl;
    // std::cout << yourNode->data << std::endl;


   bool x = isBST(tree1.root);
    std::cout   << x << std::endl;


   //traverseDepth(tree1.root);

    //traverseDepth(tree1.root);


    return 0;
}