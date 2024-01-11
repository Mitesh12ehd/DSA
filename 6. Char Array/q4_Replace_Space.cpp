#include<iostream>
using namespace std;

void Replace_Space(char arr[]){
    //Time O(n) , Space O(1)
    int i=0;
    while(arr[i] !='\0'){
        if(arr[i] == ' '){
            arr[i] = '@';
        }
        i++;
    }
}
int main(){
    char arr[100];
    cin.getline(arr,100);
    Replace_Space(arr);
    cout<<arr;

    return 0;
}