#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//gfg
//merge two binary max heap

void heapify(vector<int>& arr,int n,int i){
    int largest = i;
    int leftChild = 2*i+1;
    int rightChild = 2*i+2;
    
    if(leftChild < n && arr[largest] < arr[leftChild]){
        largest = leftChild;
    }
    if(rightChild < n && arr[largest] < arr[rightChild]){
        largest = rightChild;
    }
    
    //check if largest is updated or not
    if(largest != i){
        swap(arr[largest],arr[i]);
        //put largest to its correct posistion again
        heapify(arr,n,largest);
    }
}
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
    vector<int> ans;
    for(auto it:a){
        ans.push_back(it);
    }
    for(auto it:b){
        ans.push_back(it);
    }
        
    int size = ans.size();
    //create heap
    for(int i=(size/2)-1; i>=0; i--){
        heapify(ans,size,i);
    }
    return ans;
}

int main(){
    return 0;
}