#include<iostream>
using namespace std;

void printAllPermutations(string& str,int i){
    //base case
    if(i >= str.length()){
        cout << str << " ";
        return;
    }

    for(int j=i; j<str.length(); j++){
        //swap
        swap(str[i],str[j]);
        //recursive call
        printAllPermutations(str,i+1);
        //backtracking
        swap(str[i],str[j]);
    }
}
int main(){
    string str = "abc";
    int i = 0;
    printAllPermutations(str,i);
    return 0;
}