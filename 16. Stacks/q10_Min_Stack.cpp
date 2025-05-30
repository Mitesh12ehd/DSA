#include<stdio.h>
#include<vector>
using namespace std;

//Leetcode 155 
//Min stack

//space = O(2n)
class MinStack {
public:
    vector< pair<int,int> > st;
    
    MinStack() {
         
    }
    
    void push(int val) {
        if(st.empty()){
            pair<int,int> p;
            p.first = val;
            p.second = val;
            st.push_back(p);
        }
        else{
            pair<int,int> p;
            p.first = val;
            p.second = min(val , st.back().second);
            st.push_back(p);
        }
    }

    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return st.back().second;
    }
};

//there is one more non-intutive approch that use mathematical formula