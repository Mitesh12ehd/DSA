#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string calc_Sum(int a[],int n,int b[],int m){
    int carry = 0;
    string ans;
    
    int i = n-1;
    int j = m-1;
    
    while(i>=0 && j>=0){
        int x = a[i] + b[j] + carry;
        int digit = x % 10;
        ans.push_back(digit + '0');
        carry = x / 10;
        i--,j--;
    }
    
    while(i>=0){
        int x = a[i] + 0 + carry;
        int digit = x % 10;
        ans.push_back(digit + '0');
        carry = x / 10;
        i--;
    }
    
    while(j>=0){
        int x = 0 + b[j] + carry;
        int digit = x % 10;
        ans.push_back(digit + '0');
        carry = x / 10;
        j--;
    }
    
    if(carry){
        ans.push_back(carry + '0');
    }
    while(ans[ans.size()-1] == '0'){
        ans.pop_back();
    }
    reverse(ans.begin() , ans.end());
    return ans;
}
int main(){
    int a[] = {1,2,3};
    int b[] = {4,5,6};

    string ans = calc_Sum(a,3,b,3);
    cout<<ans;

    return 0;
}