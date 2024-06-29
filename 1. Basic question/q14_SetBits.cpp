#include<iostream>
using namespace std;

int setBits(int n){
    int count = 0;
    while(n != 0){
        int bit = n % 2;
        n = n /2;

        if(bit == 1){
            count++;
        }
    }
    return count;
}

int main(){
    int n;
    cout << "enter number = ";
    cin >> n;
    cout << setBits(n);
    return 0;
}