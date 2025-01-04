#include<iostream>
#include<vector>

using namespace std;

//leetcode 1497
//check if array pairs are divisable by k

bool canArrange(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> freq(k,0);

    for(auto it:arr){
        int rem = it % k;
        if(rem < 0){
            rem = rem + k;
        }
            
        freq[rem]++;
    }

    if(freq[0] % 2 != 0){
        return false;
    }

    for(int i=1; i<=k/2; i++){
        if(freq[i] != freq[k-i]){
            return false;
        }
    }
    return true;
}

int main(){
    

    return 0;
}