#include<iostream>
using namespace std;

//1-intitution
//next array point
//if(arr[i] is filled) then point to next element after top in stack i.e.handle on insertion
//else point to next free space i.e handle on deletion

class NStack{
    int *a,*top,*next;
    int n; //number of stack
    int size;//size of main array
    int freespot;

    public:
    NStack(int _n,int s){
        n = _n;
        size = s;

        freespot = 0;
        a = new int[size];
        top = new int[n];
        next = new int[size];

        //intializtion
        for(int i=0; i<n; i++){
            top[i] = -1;
        }
        for(int i=0; i<size; i++){
            next[i] = i+1;
        }
        next[size-1] = -1;
    }

    // push X into mth stack
    bool push(int X,int m){
        if(freespot == -1){
            return false; //stack overflow
        }
        
        int index = freespot;
        freespot = next[index];
        a[index] = X;
        next[index] = top[m-1];
        top[m-1] = index;
        return true;
    }

    //pop from mth stack
    int pop(int m){
        if(top[m-1] == -1){
            return -1; //stack underflow 
        }

        int index = top[m-1];
        top[m-1] = next[index];
        next[index] = freespot;
        freespot = index;
        return a[index];
    }

    ~NStack(){
        delete []a;
        delete []top;
        delete []next;
    }
};

int main(){
    NStack st(3,6);
    cout << st.push(10,1) << endl;
    cout << st.push(10,1) << endl;
    cout << st.push(10,1) << endl;
    cout << st.push(10,1) << endl;
    cout << st.push(10,1) << endl;
    cout << st.push(10,1) << endl;
    cout << st.push(10,1) << endl;
    cout << st.pop(1) << endl;

    return 0;
}