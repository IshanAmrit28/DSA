#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node*next;
   

    //constructor
    node(int d){
        this->data=d;
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

void insertNode(node* &tail,int element,int d){
    //assuming that the element is present in list
    if(tail==NULL){
        node* newNode=new node(d);
        tail=newNode;
        newNode->next=newNode;
    }

    else{
        node* curr=tail;
        while(curr->data!=element){
            curr=curr->next;
        }
        node*temp=new node(d);
        temp->next=curr->next;
        curr->next=temp;
    }
}

void print(node* &tail){
    node*temp=tail;
    if(tail==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    do
    {
        cout<<tail->data<<" ";
        tail=tail->next;
    } while (tail!=temp);
    cout<<endl;
    
}

void deleteNode(node* &tail,int value){

    if(tail==NULL){
        cout<<"the list is empty"<<endl;
        return;
    }
    else{
        node*prev=tail;
        node*curr=tail->next;
        while(curr->data!=value){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        if(curr==prev){
            tail=NULL;
        }

        if(tail==curr){
            tail=prev;
        }
        curr->next=NULL;
        delete curr;
    }
}

int main(){
    node*tail=NULL;
    insertNode(tail,5,3);
    print(tail);
    insertNode(tail,3,5);
    print(tail);
    insertNode(tail,5,7);
    print(tail);
    insertNode(tail,7,9);
    print(tail);
    insertNode(tail,7,8);
    print(tail);
    insertNode(tail,5,6);
    print(tail);
    insertNode(tail,3,4);
    print(tail);
    return 0;
}