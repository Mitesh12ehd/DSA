#include<iostream>
#include<algorithm>
using namespace std;

//easy iterative approach time(max(m,n)) space = (max(m,n))
// string addStrings(string num1, string num2) {
//     int p1 = num1.length() - 1;
//     int p2 = num2.length() - 1;
//     int carry = 0;
//     string ans = "";

//     while(p1 <num1.length() && p2 <num2.length()){
//         int digit1 = num1[p1] - '0';
//         int digit2 = num2[p2] - '0';

//         int sum = digit1 + digit2 + carry;
//         int digit = sum % 10;
//         carry = sum / 10;
//         ans.push_back(digit + '0');
//         p1--,p2--;
//     }

//     while(p1 < num1.length()){
//         int digit1 = num1[p1] - '0';
//         int sum = digit1 + carry;
//         int digit = sum % 10;
//         carry = sum / 10;
//         ans.push_back(digit + '0');
//         p1--;
//     }

//     while(p2 < num2.length()){
//         int digit2 = num2[p2] - '0';
//         int sum = digit2 + carry;
//         int digit = sum % 10;
//         carry = sum / 10;
//         ans.push_back(digit + '0');
//         p2--;
//     }

//     while(carry){
//         int digit = carry % 10;
//         carry = carry / 10;
//         ans.push_back(digit + '0');
//     }

//     reverse(ans.begin(),ans.end());
//     return ans;
// }

//Time O(max(num1,num2))
//space O(max(num1,num2))
void addRE(string& num1,int p1,string& num2,int p2,int carry,string& ans){
    //base case
    if(p1<0 && p2<0){
        if(carry != 0){
            ans.push_back(carry + '0');
        }
        return;
    }
    //solve one case
    int n1 = ( p1>=0 ? num1[p1] : '0' ) - '0'; //subtract 0 bescause of ascci value
    int n2 = ( p2>=0 ? num2[p2] : '0' ) - '0';
    int sum = n1 + n2 + carry;
    int digit = sum % 10;
    carry = sum / 10;
    ans.push_back(digit + '0');

    //recursive approach
    addRE(num1, p1-1, num2, p2-1, carry, ans);
}
string addStrings(string& num1, string& num2) {
    int p1 = num1.length() - 1;
    int p2 = num2.length() - 1;
    int carry = 0;
    string ans = "";
    addRE(num1,p1,num2,p2,carry,ans);
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    //leetcode 415
    string s1 = "11";
    string s2 = "123";
    string ans = addStrings(s1,s2);
    cout << ans;
    return 0;
}