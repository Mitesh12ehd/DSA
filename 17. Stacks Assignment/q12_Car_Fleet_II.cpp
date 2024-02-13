#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<double> getCollisionTimes(vector<vector<int>>& cars) {
    vector<double> ans(cars.size(),-1);
    stack<int> st;
    for(int i=cars.size()-1; i>=0; i--){
        while(!st.empty() && cars[st.top()][1] >= cars[i][1] ){
            //collision not possible
            st.pop();
        }
        while(!st.empty()){
            //collision possible
            double collTime = (double)(cars[st.top()][0]-cars[i][0]) / (double)(cars[i][1]-cars[st.top()][1]);
            if(ans[st.top()] == -1 || collTime <= ans[st.top()]){
                ans[i] = collTime;
                break;
            }
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

int main(){
    vector<vector<int>> cars = {
        {3,4},
        {5,4},
        {6,3},
        {9,1}
    };
    vector<double> ans = getCollisionTimes(cars);
    for(auto it:ans){
        cout << it << " ";
    }
    return 0;
}