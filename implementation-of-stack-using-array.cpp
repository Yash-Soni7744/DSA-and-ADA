// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#define Max 1000
class Stack{
    int top;
    
public:

int a[Max];
Stack(){
    top = -1;
}
bool push(int x);
int pop();
int peek();
bool isEmpty();
};

bool Stack::push(int x){
    if (top>=(Max-1)){
        cout<<"Stack Overflow";
        return false;
    }
    else{
        a[++top] = x;
        cout<<x<<" pushed into stack\n";
        return true;
    }
}

int Stack::pop(){
    if(top<0){
        cout<<"state under flow";
        return 0;
    }
    else{
        int x = a[top--];
        return x;
    }
}

int Stack::peek(){
    if(top<0){
        cout<<"stack is empty";
        return 0;
    }
    else{
        int x = a[top];
        return x;
    }
}
bool Stack::isEmpty(){
    return (top<0);
}
int main() {
    
    class Stack S;
    S.push(10);
    S.push(30);
    S.push(34);
    
    cout<<S.pop()<<" popped from stack \n";
    cout<<"Top element is: "<<S.pop();
    cout<<"\nElements of stack are: ";
    while(!S.isEmpty()){
        cout<<S.peek()<<" ";
        S.pop();
    }
    return 0;
}
