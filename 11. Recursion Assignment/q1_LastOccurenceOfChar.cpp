#include<iostream>
using namespace std;

//iterative time = O(n) , space = O(1)
// int LastOccurenceOfChar(string str,char ch){
//     for(int i=str.length()-1; i>=0; i--){
//         if(str[i] == ch){
//             return i;
//         }
//     }
//     return -1;
// }

//recursive time = O(n) , space = O(n)
void LastOccurenceOfChar(string& str,char& ch,int i,int& ans){
    if( i < 0){
        return;
    }

    if(str[i] == ch){
        ans = i;
        return;
    }
    LastOccurenceOfChar(str,ch,i-1,ans);
}

int main(){
    string str = "abcddedg";
    char ch = 'd';
    int i = str.length() - 1;
    int ans = -1;
    LastOccurenceOfChar(str,ch,i,ans);
    cout << ans;
    return 0;
}