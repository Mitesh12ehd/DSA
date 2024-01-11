#include<iostream>
#include<string.h>
using namespace std;

bool checkPalindrome(char arr[]){
    int i = 0;
    int j = strlen(arr) - 1;
    while(i<=j){
        if(arr[i] == arr[j]){
            i++;
            j--;
        }
        else{
            return false;
        }
    }
    return true;
}
int main(){
    char arr[100];
    cin>>arr;
    bool ans = checkPalindrome(arr);
    cout<<ans;

    return 0;
}