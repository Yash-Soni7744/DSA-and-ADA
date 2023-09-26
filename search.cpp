// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

struct node{
  int data;
  struct node*next;
};

struct node*head = NULL;

//displaying the list

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

int searchlist(int key){
    struct node*temp= head;
    while(temp!=NULL){
        if(temp->data == key){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    int k=0;
    insertatbegin(12);
    insertatbegin(22);
    insertatbegin(30);
    insertatbegin(44);
    insertatbegin(56);
    printlist();
    
    k=searchlist(44);
    if(k==1){
        cout<<"\n Element Found";
    }
    else{
        cout<<"\n Element not Found";       
    }

    return 0;
}
