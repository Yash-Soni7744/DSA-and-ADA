#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* next;
};

struct node* top = NULL;

void push(int val) {
    struct node* newnode = new struct node;
    newnode->data = val;
    newnode->next = top;
    top = newnode;
}

void pop() {
    if (top == NULL) {
        cout << "Stack Underflow" << endl;
    }
    else {
        cout << "The popped element is: " << top->data << endl;
        top = top->next;
    }
}

void display() {
    struct node* ptr;
    if (top == NULL) {
        cout << "Stack is Empty" << endl;
    }
    else {
        ptr = top;
        cout << "Stack Elements: [";
        while (ptr != NULL) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout <<"]"<<endl;
    }
}

int main() {
    int ch, val;
    while (true) {
        cout << "1.) Push an element in stack" << endl;
        cout << "2.) Pop an element from stack" << endl;
        cout << "3.) Display stack" << endl;
        cout << "4.) Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter value to push: ";
            cin >> val;
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice! Please enter a valid option." << endl;
        }
    }
    return 0;
}
