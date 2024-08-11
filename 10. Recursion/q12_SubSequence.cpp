#include<iostream>
using namespace std;

void printSubSequences(string str,string output,int i){
    //base case
    if(i >= str.length()){
        cout << output <<endl;
        return;
    }
    //exclude
    printSubSequences(str,output,i+1);
    //include
    output.push_back(str[i]);
    printSubSequences(str,output,i+1);
}

//backtracking simple
// void printSubSequences(string str,int i,string& output){
//     if(i >= str.size()){
//         cout << output << ",";
//         return;
//     }

//     //include
//     output.push_back(str[i]);
//     printSubSequences(str,i+1,output);
//     output.pop_back();

//     //exclude
//     printSubSequences(str,i+1,output);
// }
int main(){
    string str = "abc";
    string output = "";
    int i=0;

    printSubSequences(str,output,i);
    return 0;
}