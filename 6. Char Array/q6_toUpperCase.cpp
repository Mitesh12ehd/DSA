#include<iostream>
using namespace std;

void toUpperCase(char arr[]){
    int i=0;
    while(arr[i] != '\0'){
        if( arr[i] >= 'a' && arr[i] <= 'z'){
            arr[i] = arr[i] - 'a' + 'A';
        }
        i++;
    }
}
int main(){
    char arr[100];
    cin.getline(arr,100);
    toUpperCase(arr);
    cout<<arr;

    return 0;
}