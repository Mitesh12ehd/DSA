#include<iostream>
#include<algorithm>
using namespace std;

int find_Length(char name[]){
    //Time = O(n) , space = O(1)
    int length = 0;
    int i=0;
    while(name[i] != '\0'){
        length++;
        i++;
    }
    return length;
}
void reverse_String(char arr[]){
    //Time = O(n) , space = O(1)
    int i=0;
    int j=find_Length(arr) - 1;

    while(i<=j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}
int main(){
    char arr[100];
    cin >> arr;
    reverse_String(arr);
    cout << arr;

    return 0;
}