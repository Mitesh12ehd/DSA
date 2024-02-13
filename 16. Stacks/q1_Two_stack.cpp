#include<iostream>
using namespace std;

class Stack{
    private:
        int* arr;
        int size;
        int top1;
        int top2;

    public:
        Stack(int size){
            arr = new int[size];
            this->size = size;
            top1 = -1;
            top2 = size;
        }

        void push1(int data){
            if(top2-top1 == 1){
                cout << "stack overflow 1" << endl;
            }
            else{
                top1++;
                arr[top1] = data;
            }
        }
        void pop1(){
            if(top1 == -1){
                cout << "stack underflow 1" <<endl;
            }
            else{
                top1--;
            }
        }
        void push2(int data){
            if(top2-top1 == 1){
                cout << "stack overflow 2" << endl;
            }
            else{
                top2--;
                arr[top2] = data;
            }
        }
        void pop2(){
            if(top2 == size){
                cout << "stack underflow 2" <<endl;
            }
            else{
                top2++;
            }
        }
};

int main(){
    Stack st(10);

    st.push1(10);
    st.push1(20);
    st.push1(30);
    st.push1(40);
    st.push1(50);
    st.push1(60);

    st.pop1();
    st.pop1();
    st.pop1();
    st.pop1();
    st.pop1();
    st.pop1();
    st.pop1();

    st.push2(100);
    st.push2(90);
    st.push2(80);
    st.push2(60);
    st.push2(60);

    

    return 0;
}