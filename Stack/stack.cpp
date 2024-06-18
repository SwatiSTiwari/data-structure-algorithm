
#include <iostream>
using namespace std;
#include<stack>

class Stack{
    //property
    public:
    int *arr;
    int size;
    int top;
    
    
    
    
    //behaviour
    Stack(int s){
        this->size=s;
        arr=new int[size];
        top=-1;
    }
    
    void push(int element){
        if(size-top>1){
            top++;
            arr[top]=element;
            
        }
        else{
            cout<<"stack is overflow";
        }
    }
    void pop(int element){
        if(top>=0){
            top--;
            
        }
        else{
            cout<<"stack is underflow";
        }
    }
    int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
         cout<<"stack is empty";   
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

int main() {
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    
    st.pop(5);
    
    cout<<"top of the elemnt"<<st.peek()<<endl;
    st.pop(4);
    
    cout<<"top of the elemnt"<<st.peek()<<endl;
    st.pop(3);
    
    cout<<"top of the elemnt"<<st.peek()<<endl;
    

    

    return 0;
}