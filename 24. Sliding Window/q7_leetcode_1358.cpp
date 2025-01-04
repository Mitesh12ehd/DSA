#include<iostream>
using namespace std;

//number of substring containing all three character

//brute force n^2
// int numberOfSubstrings(string s) {
//     int n = s.length();
//     int ans = 0;

//     for(int i=0; i<n; i++){
//         int a=0,b=0,c=0;
//         for(int j=i; j<n; j++){
//             if(s[j] == 'a') a++;
//             else if(s[j] == 'b') b++;
//             else c++;

//             if(a && b && c){
//                 ans++;
//             }
//         }
//     }
//     return ans;
// }

//little bit optimization
// int numberOfSubstrings(string s) {
//     int n = s.length();
//     int ans = 0;

//     for(int i=0; i<n; i++){
//         int a=0,b=0,c=0;
//         for(int j=i; j<n; j++){
//             if(s[j] == 'a') a++;
//             else if(s[j] == 'b') b++;
//             else c++;

//             if(a && b && c){
//                 ans = ans + (n - j);
//                 break;
//             }
//         }
//     }
//     return ans;
// }

int numberOfSubstrings(string s) {
    int n = s.length();
    int ans = 0;
        
    int lastseen[3] = {-1,-1,-1};
    for(int i=0; i<n; i++){
        lastseen[s[i] - 'a'] = i;

        if(lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1){
            ans = ans + (1 + min(lastseen[0],min(lastseen[1],lastseen[2])));
        }
    }
    return ans;
}

int main(){
    string s = "abcabc";
    cout << numberOfSubstrings(s);

    return 0;
}