#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node*next;
    node*prev;

    //constructor
    node(int d){
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }
    ~node(){
        int val=this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
    }
};

void insertAtHead(node* &head,node* &tail,int d){
    if(head==NULL){
        node* temp=new node(d);
        head=temp;
        tail=temp;
    }
    else{
    node*temp=new node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
    }
}

void insertAtTail(node* &tail,node*&head,int d){
    if(tail==NULL){
        node* temp=new node(d);
        tail=temp;
        head=temp;
    }
    else{

    node*temp=new node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
    }
}

void insertAtPosition(node* &head,node* &tail,int position,int d){
    if(position==1){
        insertAtHead(head,tail,d);
        return;
    }
    node*temp=head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertAtTail(tail,head,d);
        return;
    }

    node*newNode=new node(d);
    newNode->next=temp->next;
    temp->next->prev=newNode;
    newNode->prev=temp;
    temp->next=newNode;
}

void print(node* &head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int getLength( node* &head ){
    int count = 0;
    node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void deleteNode(int position,node* &head,node* &tail){
     if(position==1){
        node*temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
     }
     else{
        // middle or last node deletion 
        node*curr=head;
        node*prev=NULL;
        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++; 
        }
        if(curr->next==NULL){
            tail=prev;
        }
        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;

    }

}


int main(){
    node*node1=new node(10);
    node*head=node1;
    node*tail=node1;
    print(head);
    cout<<getLength(head)<<endl;
    insertAtHead(head,tail,11);
    print(head);
    insertAtHead(head,tail,12);
    print(head);
    insertAtHead(head,tail,13);
    print(head);
    insertAtHead(head,tail,14);
    print(head);
    insertAtHead(head,tail,15);
    print(head);
    insertAtHead(head,tail,16);
    print(head);
    insertAtTail(tail,head,9);
    print(head);
    cout<<tail->data<<endl;
    insertAtTail(tail,head,8);
    print(head);
    cout<<tail->data<<endl;
    return 0;
}