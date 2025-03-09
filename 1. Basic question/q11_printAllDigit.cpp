#include<iostream>
#include<cmath>
using namespace std;

int countDigit(int n){
    int ans = 0;
    while(n != 0){
        ans++;
        n = n /10;
    }
    return ans;
}

void reverseArray(int arr[],int n){
    int start = 0;
    int end = n-1;
    while(start <= end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

void printAlldigit(int num){
    int totalDigit = countDigit(num);
    int arr[totalDigit];
    int i = 0;
    while(num != 0){
        int digit = num % 10;
        num = num / 10;
        arr[i] = digit;
        i++;
    }

    reverseArray(arr,totalDigit);
    for(auto it:arr){
        cout << it << ",";
    }
}

int main(){
    int n;
    cout << "enter n = ";
    cin >> n;
    printAlldigit(n);
    return 0;
}