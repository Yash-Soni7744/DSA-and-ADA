#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int data){
    struct node *newnode = new struct node;
    newnode->data = data;
    newnode->next = NULL;
    
    if (front ==NULL && rear == NULL){
        front = rear = newnode;
    }
    else{
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue(){
    struct node *temp;
    temp = front;
    
    if(front == NULL && rear == NULL){
        cout<<"queue is empty\n";
    }
    else{
        cout<<"deleted element is "<<front->data<<endl;
        front = front->next;
        free(temp);
    }
}

void display(){
    struct node *temp = front;
    
    if(front == NULL && rear == NULL){
        cout<<"queue is empty\n";
    }
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    enqueue(23);
    enqueue(22);
    enqueue(255);
    enqueue(5);
    enqueue(3);
    enqueue(69);
    dequeue();
    dequeue();
    display();
}




