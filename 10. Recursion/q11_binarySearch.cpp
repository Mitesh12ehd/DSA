#include<iostream>
#include<vector>
using namespace std;

int binary_Search(vector<int>& v,int start,int end,int& key){
    if(start > end){
        return -1;
    }
    int mid = (start + end) / 2;
    if(v[mid] == key){
        return mid;
    }
     
    if(v[mid] < key){
        return binary_Search(v,mid+1,end,key);
    }
    else{
        return binary_Search(v,start,mid-1,key);
    }
}

int main(){
    vector<int> v{10,20,30,40,50,60};
    int n = 6;
    int key = 50;

    int start = 0; 
    int end = n-1;
    int m = binary_Search(v,start,end,key);

    cout << "ans is" << m;

    return 0;
}