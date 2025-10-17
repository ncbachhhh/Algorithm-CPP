//
// Created by nguye on 10/17/2025.
//
// Binary Tree

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
private:
    Node* root;
public:
    BinaryTree() {
        root = nullptr;
    }

    bool isEmpty() {
        return root == nullptr;
    }

    int getMax() {
        return root -> data;
    }

    int getMin() {
        Node* temp = root;
        while (temp -> left != nullptr) {
            temp = temp -> left;
        }
        return temp -> data;
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            root = newNode;
        }
        else {
            Node* current = root;
            while (true) {
                if (value == current -> data) {
                    delete newNode;
                    return;
                }
                else if (value < current -> data) {
                    if (current -> left == nullptr) {
                        current -> left = newNode;
                        return;
                    }
                    else {
                        current = current -> left;
                    }
                }
                else if (value > current -> data) {
                    if (current -> right == nullptr) {
                        current -> right = newNode;
                        return;
                    }
                    else {
                        current = current -> right;
                    }
                }
            }
        }
    }

    void deleteNode(int value) {
        if (isEmpty()) {
            cout << "Tree is empty. Cannot delete node." << endl;
            return;
        }
        Node* current = root;
        while (value == getMax()) {
            
        }
    }

    ~BinaryTree() {
        // Cleanup
    }
};

