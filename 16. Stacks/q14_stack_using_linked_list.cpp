#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(){
        this->data = 0;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        //here we have to destructor
        int value = this->data;
        cout << "Node with value = "<< value << " is deleted" <<endl;
    }
}; 

class Stack{
    private:
        Node* top;
        int size;

    public:
        Stack(){
            top = NULL;
            size = 0;
        }

        //function
        void push(int data){
            Node* newNode = new Node(data);
            newNode->next = top;
            top = newNode;
            size++;
        }

        void pop(){
            if(top == NULL){
                cout << "stack underflow" << endl;
                return;
            }
            
            Node* temp = top;
            top = top->next;
            temp->next = NULL;
            delete temp;
            size--;
        }

        int getTop(){
            if(top == NULL){
                cout << "stack empty" << endl;
                return -1;
            }
            else{
                return top->data;
            }
        }

        //it return number of element present in stack
        int getSize(){
            return size;
        }
};

int main(){
    Stack st;
    
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    while(st.getSize() != 0){
        cout<< st.getTop() << " ";
        st.pop();
    }
    cout <<endl;

    cout << st.getSize();

    return 0;
}