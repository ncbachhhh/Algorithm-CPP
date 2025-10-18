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
        if (isEmpty()) {
            cout << "Loi: Cay rong!" << endl;
            return -1; // Hoặc ném ra ngoại lệ
        }
        Node* temp = root;
        while (temp->right != nullptr) { // Đi sang PHẢI để tìm max
            temp = temp->right;
        }
        return temp->data;
    }

    int getMin() {
        if (isEmpty()) {
            cout << "Loi: Cay rong!" << endl;
            return -1;
        }
        Node* temp = root;
        while (temp->left != nullptr) { // Đi sang TRÁI (đã đúng)
            temp = temp->left;
        }
        return temp->data;
    }

    Node* getRoot() {
        return root;
    }

    int getValue(Node* node) {
        return node->data;
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

        // Find node
        Node* current = root;
        Node* parent = nullptr;
        while (current != nullptr && current -> data != value) {
            parent = current;
            if (value < current -> data) {
                current = current -> left;
            }
            else {
                current = current -> right;
            }
        }
        if (current == nullptr) {
            return;
        }

        // Delete node
        // Case 1: Node has no children
        if (current -> left == nullptr && current -> right == nullptr) {
            if (current == root) {
                root = nullptr;
            }
            else if (parent -> left == current) {
                parent -> left = nullptr;
            }
            else {
                parent -> right = nullptr;
            }
            delete current;
            cout << "Node deleted successfully." << endl;
        }

        // Case 2: Node has one child
        // 2a. Right child only
        else if (current -> left == nullptr ) {
            if (current == root) {
                root = current -> right;
            }
            else if (current == parent -> left) {
                parent -> left = current -> right;
            }
            else {
                parent -> right = current -> right;
            }
            delete current;
            cout << "Node deleted successfully." << endl;
        }

        // 2b. Left child only
        else if (current -> right == nullptr) {
            if (current == root) {
                root = current -> left;
            }
            else if (current == parent -> left) {
                parent -> left = current -> left;
            }
            else {
                parent -> right = current -> left;
            }
            delete current;
            cout << "Node deleted successfully." << endl;
        }

        // Case 3: Node has two children
        else {
            Node* nextGenParent = current;
            Node* nextGen = current -> right;

            while (nextGen -> left != nullptr) {
                nextGenParent = nextGen;
                nextGen = nextGen -> left;
            }

            current -> data = nextGen -> data;

            if (nextGen == nextGenParent -> left) {
                nextGenParent -> left = nextGen -> right;
            }
            else {
                nextGenParent -> right = nextGen -> right;
            }

            delete nextGen;
            cout << "Node deleted successfully." << endl;
        }
    }

    void inOrder(Node* root) {
        if (root == nullptr) {
            return;
        }

        else {
            inOrder(root -> left);

            cout << root -> data << " ";

            inOrder(root -> right);
        }
    }

    void preOrder(Node* root) {
        if (root == nullptr) {
            return;
        }

        else {
            cout << root -> data << " ";
            preOrder(root -> left);
            preOrder(root -> right);
        }
    }

    void postOrder(Node* root) {
        if (root == nullptr) {
            return;
        }

        else {
            postOrder (root -> left);
            postOrder (root -> right);
            cout << root -> data << " ";
        }
    }

    ~BinaryTree() {

    }
};

int main() {
    BinaryTree tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    //            50
    //        /       \
    //       /         \
    //      30          70
    //     /  \        /  \
    //    20   40     60   80

    cout << tree.getValue(tree.getRoot() -> left -> right) << endl; // Correct

    cout << "InOrder: ";
    tree.inOrder(tree.getRoot());
    cout << endl;

    cout << "PreOrder: ";
    tree.preOrder(tree.getRoot());
    cout << endl;

    cout << "PostOrder: ";
    tree.postOrder(tree.getRoot());
}
