#include<iostream>
#include<vector>
#include<set>
using namespace std;

//leetcode 846
//Hand of Straights

//time = O(nlogn) space = O(n)
bool isNStraightHand(vector<int>& hand, int groupSize) {
    multiset<int> st;
    for(auto it:hand){
        st.insert(it);
    }

    int count = 0;
    int ele;
    while(!st.empty()){
        if(count == 0){
            ele = *(st.begin());
            count++;
            st.erase(st.begin());
        }
        else if(count == groupSize){
            count = 0;
        }
        else{
            if(st.find(ele+1) == st.end()){
                return false;
            }

            auto it = st.find(ele+1);
            ele = *(it);
            st.erase(it);
            count++;
        }
    }

    return count==groupSize;
}

//it can be solved using minheap
//explore leetcode solution

int main(){
    return 0;
}