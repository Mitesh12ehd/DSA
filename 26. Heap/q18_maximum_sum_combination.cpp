#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;

//interviewbit
//maximum sum combinations

//brute force  time = O(n^2) space = O(n^2)
// vector<int> solve(vector<int> &A, vector<int> &B, int C) {
//     vector<int> v;
//     int n = A.size();
    
//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             v.push_back(A[i]+B[i]);
//         }
//     }
//     sort(v.begin(),v.end());
//     vector<int> ans;
//     for(int i=v.size()-1; i>=0; i--){
//         C--;
        
//         ans.push_back(v[i]);
//         if(C == 0){
//             break;
//         }
//     }
//     return ans;
// }

//better  time = O(n^2) space = O(C)
// vector<int> solve(vector<int> &A, vector<int> &B, int C) {
//     int n = A.size();

//     priority_queue<int,vector<int>,greater<int>> pq;

//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             if(C){
//                 pq.push(A[i]+B[j]);
//                 C--;
//             }
//             else{
//                 if(pq.top() < (A[i]+B[j])){
//                     pq.pop();
//                     pq.push(A[i]+B[j]);
//                 }
//             }
//         }
//     }

//     vector<int> ans;
//     while(!pq.empty()){
//         ans.push_back(pq.top());
//         pq.pop();
//     }
//     reverse(ans.begin(),ans.end());
//     return ans;
// }

//optimal  time = O(nlogn) space = O(C)
vector<int> solve(vector<int> &A, vector<int> &B, int C) { 
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int n = A.size();

    vector<int> ans;
    
    priority_queue<pair<int,pair<int,int>>> pq;
    set<pair<int, int> > st;
    pq.push({A[n-1]+B[n-1] , {n-1,n-1}});
    st.insert({n-1,n-1});

    for(int count=0; count<C; count++){
        int sum = pq.top().first;
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        pq.pop();
        
        ans.push_back(sum);
        
        if(i-1 >= 0){
            int sum = A[i-1] + B[j];
            if(st.find({i-1,j}) == st.end()){
                pq.push({sum,{i-1,j}});
                st.insert({i-1,j});
            }
        }
        
        if(j-1 >= 0){
            int sum = A[i] + B[j-1];
            if(st.find({i,j-1}) == st.end()){
                pq.push({sum,{i,j-1}});
                st.insert({i,j-1});
            }
        }
    }
    return ans;
}

//dryrun on both case to understand
//A = {100,200,300,400,500,600,700,800,900};
//B = {1,2,3,4,5,6,7,8,9};
//C = 5

int main(){
    vector<int> A =  { 59, 63, 65, 6, 46, 82, 28, 62, 92, 96, 43, 28, 37, 92, 5, 3, 54, 93, 83};
    vector<int> B = {59, 63, 65, 6, 46, 82, 28, 62, 92, 96, 43, 28, 37, 92, 5, 3, 54, 93, 83};
    vector<int> ans = solve(A,B,10);

    for(auto it: ans){
        cout << it << " ";
    }

    return 0;
}