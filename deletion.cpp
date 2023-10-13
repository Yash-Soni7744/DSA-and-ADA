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
    cout<<"]\n";
}
void insertatbegin(int data){
    struct node*newnode = new struct node;
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

//deletion at beginning

void deletebegin(){
    if (head != NULL) {
        struct node*temp = head;
        head = head->next;
        delete temp;
    }
}

//deletion at end
void deleteatend(){
    if (head == NULL || head->next == NULL) {
        // If the list is empty or has only one node, do nothing
        return;
    }
    struct node* linkedlist = head;
    while (linkedlist->next->next != NULL) {
        linkedlist = linkedlist->next;
    }
    delete linkedlist->next;
    linkedlist->next = NULL;
}

// delete the node
void deletenode(int key) {
    struct node* temp = head;
    struct node* prev = NULL;

    // If the node to be deleted is the head node
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        delete temp;
        return;
    }

    // Search for the node to be deleted, keep track of the previous node
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the node with the key is not present in the list
    if (temp == NULL) {
        cout << "Node with key " << key << " not found in the list." << endl;
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    delete temp;
}

//programme start
int main(){
  
    insertatbegin(12);
    insertatbegin(22);
    insertatbegin(32);
    insertatbegin(42);
    insertatbegin(52);
    cout<<"linked list \n";
    printlist();
    deletebegin();
    deleteatend();
    cout<<"linked list after deletion \n";
    printlist();
}
