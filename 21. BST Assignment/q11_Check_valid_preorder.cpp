#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

class Node{
    public:

    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void build(int& i,int min,int max,vector<int>& A){
    if(i >= A.size()){
        return;
    }

    if(A[i] > min && A[i] < max){
        int rootData = A[i];
        i++;
        build(i,min,rootData,A);
        build(i,rootData,max,A);
    }
}

int solve(vector<int> &A) {
    int min = INT_MIN;
    int max = INT_MAX;
    int i=0;
    build(i,min,max,A);
    if(i == A.size()){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    return 0;
}