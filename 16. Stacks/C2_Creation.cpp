#include<iostream>
using namespace std;

class Stack{
    private:
        int* arr;
        int top; //indicate index (0 based)
        int size;

    public:
        Stack(int size){
            arr = new int[size];
            this->size = size;
            top = -1;
        }

        //function
        void push(int data){
            if(top < size-1){
                top++;
                arr[top] = data;
            }
            else{
                cout << "stack overflow" << endl;
            }
        }

        void pop(){
            if(top == -1){
                cout << "stack underflow" << endl;
            }
            else{
                top--;
            }
        }

        int getTop(){
            if(top == -1){
                cout << "stack empty" << endl;
            }
            else{
                return arr[top];
            }
        }

        //it return number of element present in stack
        int getSize(){
            return top+1;
        }

        bool isEmpty(){
            if(top == -1){
                return true;
            }
            return false;
        }
};

int main(){
    Stack st(5);
    
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    while(!st.isEmpty()){
        cout<< st.getTop() << " ";
        st.pop();
    }
    cout <<endl;

    cout << st.getSize();

    return 0;
}