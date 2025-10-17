//
// Created by nguye on 10/17/2025.
//
// Queue LinkedList

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

class Queue {
private:
    Node* head;
    Node* tail;
public:
    Queue() {
        head = nullptr;
        tail = nullptr;
    }

    bool isEmpty() {
        if (head == nullptr) {
            return true;
        }
        return false;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue element." << endl;
            return;
        }
        else {
            Node* temp = head;
            head = head -> next;
            delete temp;

            if (head == nullptr) {
                tail = nullptr;
            }
        }
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue is empty. No front element." << endl;
            return -1;
        }
        return head->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* current = head;
        cout << "Queue elements: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

void displayMenu() {
    cout << "========== MENU QUEUE ==========" << endl;
    cout << "1. Push element onto queue" << endl;
    cout << "2. Pop element from queue" << endl;
    cout << "3. View top element of queue" << endl;
    cout << "4. Check if queue is empty" << endl;
    cout << "5. Display queue elements" << endl;
    cout << "6. Exit" << endl;
}

int main() {
    Queue queue;
    bool active = true;
    int choice;
    do {
        displayMenu();
        cout << endl << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                int element;
                cout << "Enter element to enqueue: ";
                cin >> element;
                queue.enqueue(element);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                if (!queue.isEmpty()) {
                    cout << "Front element: " << queue.front() << endl;
                }
                else {
                    cout << "Queue is empty. No front element." << endl;
                }
                break;
            case 4:
                if (queue.isEmpty()) {
                    cout << "Queue is empty." << endl;
                } else {
                    cout << "Queue is not empty." << endl;
                }
                break;
            case 5:
                queue.display();
                break;
            case 6:
                cout << "Exiting program." << endl;
                active = false;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (active == true);
    return 0;
}