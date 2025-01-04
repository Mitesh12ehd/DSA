#include<iostream>
#include<vector>
using namespace std;

//method 1
bool isPowerOfFour(int n) {
    vector<int> v;
        
    v.push_back(1);
        
    int var = 1; //4^0
    while(var <= n/4){
        v.push_back(var);
        var = var*4;
    }

    if(v[v.size()-1] == n){
        return true;
    }
    return false;
}

//method 2
bool isPowerOfFour(int n) {
    if(n<=0){
        return false;
    }

    while(n != 1){
        if(n % 4 != 0){
            return false;
        }

        n = n/4;
    }
    return true;
}

int main(){
    return 0;
}