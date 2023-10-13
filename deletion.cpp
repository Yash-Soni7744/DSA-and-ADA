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
void insertatbegin(int data){
    struct node*newnode = new struct node;
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}
//deletion at end

void deleteatend(){
    struct node*linkedlist=head;
    while(linkedlist->next->next!=NULL){
        linkedlist=linkedlist->next;
    }
    linkedlist->next = NULL;
}
// delete the node
void deletenode(int key){
    struct node*temp = head,*prev;
    if(temp! = NULL && temp->data == key){
        head = temp->next;
    }
    return;
}
// Find key to be deleted
while (temp!=NULL && temp -> data!=key){
    prev = temp;
    temp = temp->next;
}
if (temp == NULL){
    prev->next = temp->next;
}

//programme start
int main(){
    insertatbegin(12);
    insertatbegin(12);
    insertatbegin(12);
    insertatbegin(12);
    insertatbegin(12);
    cout<<"linked list \n";
    printlist();
    deleteatend();
    cout<<"linked list after deletion \n"
    printlist();
}
