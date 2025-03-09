#include<iostream>
using namespace std;

int fastExpontiation(int x,int n){
    //Time = O(log(n))
    int ans = 1;
    while(n > 0){
        if(n % 2 == 1){
            //n is odd
            ans = ans * x;
            n--;
        }
        x = x * x;
        n = n / 2;
    }
    return ans;
}

//brute force time = O(m * logn base 2) 
//dryrun to understand
int nthRoot(int n, int m) {
    for(int i=1; i<=m; i++){
        int var = fastExpontiation(i,n);
        if(var == m){
            return i;
        }
        else if(var > m){
            return -1;
        }
    }
    return -1;
}

//optimal
int nthRoot(int n, int m) {
    int start = 1;
    int end = m;
    
    while(start <= end){
        int mid = start + (end-start) / 2;
        int var = fastExpontiation(mid,n);

        if(var == m){
            return mid;
        }
        else if(var > m){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return -1;
}

//handle edge cases like n=10, m = 10^9
int expontiation(int mid,int n,int m){
    //this function
    //return 1 if == m
    //return 0 if < m
    //return 2 if > m
    long long ans = 1;
    for(int i=1; i<=n; i++){
        ans = ans * mid;
        if(ans > m){
            return 2;
        }
    }
    if(ans == m){
        return 1;
    }
    return 0;
}
int nthRoot(int n, int m) {
    int start = 1;
    int end = m;
    
    while(start <= end){
        int mid = start + (end-start) / 2;
        int var = expontiation(mid,n,m);

        if(var == 1){
            return mid;
        }
        else if(var == 0){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return -1;
}

int main(){
    cout << nthRoot(27,3);
    return 0;
}