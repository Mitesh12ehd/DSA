#include<iostream>
#include<vector>
using namespace std;

//missing and repeating 
//gfg

//brute force, time = n^2, space = 1
vector<int> findTwoElement(vector<int>& arr) {
    int n = arr.size();
    int missing;
    int repeating;
    for(int i=1; i<=n; i++){
        int count = 0;
        for(int j=0; j<n; j++){
            if(arr[j] == i){
                count++;
            }
        }
        if(count == 0){
            missing = i;
        }
        if(count == 2){
            repeating = i;
        }
    }
    return {missing,repeating};
}

//better approach, time = 2n, space = n
vector<int> findTwoElement(vector<int>& arr) {
    int n=arr.size();
    vector<int> v(n+1,0);

    for(auto it:arr){
        v[it]++;
    }
    int missing;
    int repeating;
    for(int i=1; i<=n; i++){
        if(v[i] == 0){
            missing = i;
        }
        if(v[i] == 2){
            missing = i;
        }
    }
    return {repeating,missing};
}

//mathamatic approach time = O(n) space = O(1)
vector<int> findTwoElement(vector<int>& arr) {
    long long n = arr.size();
    
    //S - Sn = x-y
    long long Sn = (n*(n+1))/2;
    long long S=0;
    for(int i=0; i<n; i++){
        S += arr[i];
    }
    
    //S2 - S2n = x^2 - y^2
    long long S2n = (n * (n+1) * ((2*n)+1)) / 6;
    long long S2 = 0;
    for(int i=0; i<n; i++){
        S2 += (long long)arr[i] * (long long)arr[i];
    }

    long long val1 = S - Sn; // x-y
    long long val2 = S2 - S2n;
    val2 = val2 / val1; //x+y

    int x = (val1 + val2) / 2;
    int y = x - val1;
    return {x,y};
}

//fourth approach will be using bitwise xor 
//refer bit manipulation to explore

int main(){
    return 0;
}