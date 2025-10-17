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

int main() {
    cout << "Created Stack." << endl;
    Stack stack;
    cout << "Stack check is empty: " << (stack.isEmpty() ? "Yes" : "No") << endl;
    cout << "Pushing elements 1, 2, 3 onto stack." << endl;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.display();
    cout << "Stack check is empty: " << (stack.isEmpty() ? "Yes" : "No") << endl;
    cout << "Top element: " << stack.top() << endl;
    cout << "Popping top element." << endl;
    stack.pop();
    stack.display();

    return 0;
}