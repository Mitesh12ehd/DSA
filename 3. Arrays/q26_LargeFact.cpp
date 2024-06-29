#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//approach : 
    //we multiply each number one by one.
    //at each multiplication we store result in array
    //it performed by book multiplication that we perform on book without calculator
    // 12 * 6 =    1
    //             12
    //              6
    //           -------
    //             72

//only catch is, array ans created in reverse order
//dryrun on num = 7

vector<int> factorial(int N){
    vector<int> ans;
    ans.push_back(1);
    int carry = 0;

    for(int i=2; i<=N; i++){
        for(int j=0; j<ans.size(); j++){
            int x = ans[j]*i  +  carry;
            ans[j] = x % 10;
            carry = x / 10;
        }
        while(carry){
            ans.push_back(carry%10);
            carry = carry / 10;
        }
        carry = 0;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    vector<int> ans;
    ans = factorial(7);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i];
    }
    return 0;
}