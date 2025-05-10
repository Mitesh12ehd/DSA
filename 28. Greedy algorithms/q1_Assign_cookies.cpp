#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Leetcode 455
//Assign cookies

//time = O(nlogn)
//space = O(1)
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(s.begin(),s.end());
    sort(g.begin(),g.end());

    int i=0,j=0;
    int count = 0;
    while(i < g.size() && j < s.size()){
        if(s[j] >= g[i]){
            count++;
            i++,j++;
        }
        else{
            j++;
        }
    }
    return count;
}

int main(){
    return 0;
}