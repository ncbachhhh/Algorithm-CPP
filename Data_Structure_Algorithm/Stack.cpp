//
// Created by nguye on 10/17/2025.
//
// Stack

#include <iostream>
#include <vector>

using namespace std;

class Stack {
private:
    vector<int> elements;
public:
    bool isEmpty() {
        return elements.empty();
    }

    void push(int element) {
        elements.push_back(element);
    }

    void pop() {
        if (!isEmpty()) {
            elements.pop_back();
        }
        else {
            cout << "Stack is empty. Cannot pop element." << endl;
        }
    }

    int top() {
        if (!isEmpty()) {
            return elements.back();
        }
        else {
            cout << "Stack is empty. No top element." << endl;
            return -1; // Trả lỗi
        }
    }

    void display() {
        cout << "Stack elements: ";
        for (int i = elements.size() - 1; i >= 0; i--) {
            cout << elements[i] << " ";
        }
        cout << endl;
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
                cout << "Top element: " << stack.top() << endl;
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