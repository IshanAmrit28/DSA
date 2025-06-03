#include<iostream>
// #include<stack>
using namespace std;

class stack{
    //properties
    public:
    int *arr;
    int top;
    int size;

    //functions
    stack(int size){
        this->size=size;
        arr=new int(size);
        top=-1;
    }

    void push(int element){
        if(size-top>1){
            top++;
            arr[top]=element;
        }
        else{
            cout<<"stack overflow"<<endl;
        }
    }
    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"stack underflow"<<endl;
        }

    }
    int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout<<"stack is empty"<<endl;
            return-1;
        }
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }

};

int main(){

    stack st(5);
    st.push(22);
    st.push(23);
    st.push(24);
    st.push(25);
    st.push(26);
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    // stack<int> s;
    // s.push(2);
    // s.push(3);
    // s.push(3);
    // s.pop();
    // cout<<"ptinting top element "<<s.top()<<endl;
    // if(s.empty()){
    //     cout<<"stack is empty"<<endl;
    // }
    // else{
    //     cout<<"stack is not empty"<<endl;
    // }

    // cout<<"size of stack is "<<s.size()<<endl;
    return 0;
}