#include<iostream>
using namespace std;

struct node{
    int data;
    struct node*next;
};

struct node*top = NULL;

void push(int data){
    struct node *newnode = new struct node;
    newnode->data = data;
    newnode->next = top;
    top = newnode;
    cout<<" "<<data<<"is pushed into the stack\n";
}

void pop(){
    if(top == NULL){
        cout<<"Stack Underflow";
    }
    cout<<"The popped element is: "<<top->data<<endl;
    top = top->next;
}
void peek(){
    if (top == NULL){
        cout<<"Stack Underflow"<<endl;
    }
    cout<<"The element at top is: "<<top->data<<endl;
}

void display(){
    struct node *ptr;
    if (top == NULL){
        cout<<"Stack Underflow"<<endl;
    }
    ptr = top;
    cout<<"[";
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<"]";
}
int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    
    pop();
    pop();
    peek();
    display();
}





