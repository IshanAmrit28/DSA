#include<iostream>
using namespace std;
class Queue{
    int * arr;
    int qfront;
    int rear;
    int size;

    public:

    Queue(){
        size=1000001;
        arr = new int[size];
        qfront = rear = 0;        
    }

    bool isEmpty(){
        if(qfront==rear){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int data){
        if(rear==size){
            cout<<"queue is full"<<endl;
        }
        else{
            arr[rear]=data;
            rear++;
        }
    }

    int dequeue(){
        if(qfront==rear){
            return-1;
        }
        else{
            int ans=arr[qfront];
            arr[qfront]=-1;
            qfront++;
            if(qfront==rear){
                qfront=rear=0;
            }
            return ans;
        }
    }

    int front(){
        if(qfront==rear){
            cout<<"queue is empty"<<endl;
            return-1;
        }
        else{
            return arr[qfront];
        }
    }


};
int main(){
    
    return 0;
}