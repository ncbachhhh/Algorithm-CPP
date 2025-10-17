//
// Created by nguye on 10/17/2025.
//
// Stack using Linked List

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;
public:
    Stack()  {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop element." << endl;
            return;
        } else {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    int peek() {
        if (isEmpty()) {
            return -1;
        }
        return top->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        Node* current = top;
        cout << "Stack elements: ";
        while (current != nullptr) {
            cout << current -> data << " ";
            current = current -> next;
        }
        cout << endl;
    }

    // Cleanup
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

void displayMenu() {
    cout << "========== MENU STACK ==========" << endl;
    cout << "1. Push element onto stack" << endl;
    cout << "2. Pop element from stack" << endl;
    cout << "3. View top element of stack" << endl;
    cout << "4. Check if stack is empty" << endl;
    cout << "5. Display stack elements" << endl;
    cout << "6. Exit" << endl;
}

int main() {
    Stack stack;
    int choice;
    bool active = true;
    do {
        displayMenu();
        cout << endl << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                int element;
                cout << "Enter element to push: ";
                cin >> element;
                stack.push(element);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                cout << "Top element: " << stack.peek() << endl;
                break;
            case 4:
                if (stack.isEmpty()) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Stack is not empty." << endl;
                }
                break;
            case 5:
                stack.display();
                break;
            case 6:
                cout << "Exiting program." << endl;
                active = false;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (active);

    return 0;
}