#include<iostream>
using namespace std;

int main(){
char a;
cout<<"enter a ";
cin>>a;

if(a>='a' && a<='z'){
    cout<<"lower case"<<endl;
}
else if(a>='A' && a<='Z'){
    cout<<"upper case"<<endl;
}
else if(a>='0' && a<='9'){
    cout<<"digit"<<endl;
}
else{
    cout<<"special character"<<endl;
}
return 0;
}