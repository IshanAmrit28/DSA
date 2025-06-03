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

int main(){
    
    return 0;
}