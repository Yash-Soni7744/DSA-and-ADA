#include<iostream>
using namespace std;
#define SIZE 5

class Queue {
private:
    int items[SIZE], front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        if (front == 0 && rear == SIZE - 1) {
            cout << "Queue overflows\n";
            return true;
        }
        if (front == (rear + 1) % SIZE) {
            cout << "Queue overflows\n";
            return true;
        }
        else {
            return false;
        }
    }

    bool isEmpty() {
        if (front == -1) {
            return true;
        }
        else {
            return false;
        }
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue overflows\n";
        }
        else {
            if (front == -1) {
                front = 0;
            }
            rear = (rear + 1) % SIZE;
            items[rear] = val;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue underflows\n";
            return -1;
        }
        else {
            int element = items[front];
            if (front == rear) {
                front = -1;
                rear = -1;
            }
            else {
                front = (front + 1) % SIZE;
            }
            return element;
        }
    }

    void display() {
        for (int i = front; i != (rear + 1) % SIZE; i = (i + 1) % SIZE) {
            cout << items[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(3);
    q.enqueue(32);
    q.enqueue(31);
    q.enqueue(37);
    q.enqueue(33);
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
}
