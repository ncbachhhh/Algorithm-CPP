//
// Created by nguye on 10/17/2025.
//
// Queue

#include <iostream>
#include <vector>

using namespace std;

class Queue {
private:
    vector<int> elements;
public:
    bool isEmpty() {
        return elements.empty();
    }

    void enqueue(int element) {
        elements.push_back(element);
    }

    void dequeue() {
        if (!isEmpty()) {
            for ( int i = 0; i < elements.size() - 1; i++) {
                elements[i] = elements[i + 1];
            }
            elements.pop_back();
        }
        else {
            cout << "Queue is empty. Cannot dequeue element." << endl;
        }
    }

    int front() {
        return elements[0];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < elements.size(); i++) {
            cout << elements[i] << " ";
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
    int choice;
    bool active = true;

    do {
        displayMenu();
        cout << "Enter your choice: ";
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
                }
                else {
                    cout << "Queue is not empty." << endl;
                }
                break;
            case 5:
                queue.display();
                break;
            case 6:
                active = false;
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (active);
    return 0;
}