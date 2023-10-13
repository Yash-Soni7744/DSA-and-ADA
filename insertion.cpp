// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

struct node{
  int data;
  struct node*next;
};

struct node*head = NULL;

// displaying the list

void printlist(){
    struct node*p = head;
    cout<<"\n[ ";
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<"]";
}

//insertion at beginning

void insertatbegin(int data){
    struct node*newnode = new struct node;
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

//insertion at position
void insertafternode(struct node*list,int data){
    struct node*newnode= new struct node;
    newnode->data = data;
    newnode->next=list->next;
    list->next = newnode;
}
int main() {
    // Write C++ code here
    insertatbegin(2);
    insertatbegin(55);
    insertatbegin(33);
   
    cout<<"linked list:\n";
    printlist();
    return 0;
}

//insertion at end

void insertatend(int data){
    struct node*newnode= new struct node;
    newnode->data = data;
    struct node*linked=head;
    while(linked->next!=NULL){
        linked = linked->next;
    }
    linked->next = newnode;
}
int main() {
    // Write C++ code here
    insertatbegin(2);
    insertatbegin(55);
    insertatbegin(33);
    insertatend(12);
    insertatend(90);
    insertafternode(head->next,40);
    insertafternode(head->next,62);
    cout<<"linked list:\n";
    printlist();
    return 0;
}
