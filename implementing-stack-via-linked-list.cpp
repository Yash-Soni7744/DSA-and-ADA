// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

struct node{
  int data;
  struct node*next;
};

struct node*top = NULL;

void push(int val){
    struct node*newnode = new struct node;
    newnode->data = val;
    top = newnode;
}

void pop(){
    if(top == NULL){
        cout<<"Stack Underflow";
    }
    else{
        cout<<"The popped element is: "<<top->data;
        top = top->next;
    }
}

void display(){
    struct node*ptr;
    if(top == NULL){
        cout<<"Stack is Empty";
    }
    else{
        ptr = top;
        cout<<"Start Elements";
        while (ptr!=NULL){
            cout<<ptr->data<<ptr = ptr->next;
        }
    }
}

int main() {
    int ch,val;
    cout<<"1.) push an element in stack";
    cout<<"2.) pop an element from stack";
    cout<<"3.) display stack";
    cout<<"4.) Exit";
}
