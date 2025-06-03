#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node*next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~Node(){
        int value=this->data;
        //memeory frewe code
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory freed at node with value "<<value<<endl;
    }
};

void insertAtHead(Node* &head,int d){
    Node*temp=new Node(d);
    temp->next=head;
    head=temp;
}

void insertAtTail(Node*&tail,int d){
    Node*temp=new Node(d);
    tail->next=temp;
    tail=tail->next;
}

void insertAtPosition(Node* &tail,Node* &head,int d,int position){
   //insert at start
   if(position==1){
    insertAtHead(head,d);
    return;
   }

   Node*temp=head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    //insert at last position
    if(temp->next==NULL){
        insertAtTail(tail,d);
        return;
    }

    Node* nodeToInsert=new Node(d);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;
    
}

void print(Node*&head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void deleteNode(int position,Node* &head,Node* &tail){
     if(position==1){
        Node*temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
     }
     else{
        // middle or last node deletion 
        Node*curr=head;
        Node*prev=NULL;
        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++; 
        }
        if(curr->next==NULL){
            tail=prev;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;

    }

}

int main(){

    Node*node1=new Node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;
    Node* head=node1;
    Node* tail=node1;
    print(head);
    insertAtHead(head,12);
    print(head); 
    insertAtHead(head,15);
    print(head);
    insertAtTail(tail,9);
    print(head);
    insertAtTail(tail,8);
    print(head);
    insertAtPosition(tail,head,11,3);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    deleteNode(6,head,tail);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    deleteNode(5,head,tail);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    return 0;
}