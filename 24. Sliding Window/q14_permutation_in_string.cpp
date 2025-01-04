#include<iostream>
using namespace std;

//leetcode 567
//permutation in string

bool helper(int hash[]){
    for(int i=0; i<26; i++){
        if(hash[i] != 0){
            return false;;
        }
    }
    return true;
}
bool checkInclusion(string s1, string s2) {
    int n1=s1.size();
    int n2=s2.size();
    if(n1 > n2){
        return 0;
    }

    int hash[26] = {0};
    for(auto it:s1){
        hash[it-'a']++;
    }
    int left=0;
    int right=0;
    while(right < n2){
        hash[s2[right]-'a']--;

        if(right-left+1 > n1){
            hash[s2[left]-'a']++;
            left++;
        }

        //check if whole s1  is included
        if(helper(hash)){
            return true;
        }
        right++;
    }
    return false;
}

int main(){
    return 0;
}