#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//method 1
// vector<int> solveProblem(vector<int> arr){
//     vector<int> ans(arr.size());

//     int n = arr.size();
//     for(int i=arr.size()-1; i>=0; i--){
//         int ansElement = -1;
//         for(int j=i-1; j>=0; j--){
//             if(arr[j] < arr[i]){
//                 ansElement = arr[j];
//                 break;
//             }
//         }
//         ans[i] = ansElement;
//     }
//     return ans;
// }

//method 2
vector<int> solveProblem(vector<int> arr){
    vector<int> ans(arr.size());
    stack<int> st;
    st.push(-1);

    for(int i=0; i<arr.size(); i++){
        int curr = arr[i];
        //pop element until we got smaller element than curr at st.top()
        while(st.top() >= curr){
            st.pop();
        }
        // we got smaller element than current in st.top()
        ans[i] = st.top();
        st.push(curr);
    }
    return ans;
}

int main(){
    vector<int> arr = {2,1,5,6,2,3};
    vector<int> ans = solveProblem(arr);

    for(auto it:ans){
        cout << it << " ";
    }
    return 0;
}