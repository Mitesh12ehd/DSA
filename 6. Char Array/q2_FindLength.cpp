#include<iostream>
#include<string.h>
using namespace std;

int findLength(char name[]){
    int length = 0;
    int i=0;
    while(name[i] != '\0'){
        length++;
        i++;
    }
    return length;
}
int main(){
    char name[100];
    cin>>name;
    cout<<"Length is = "<<findLength(name)<<endl;

    //predefined function
    cout<<"Length is = "<<strlen(name);

    return 0;
}