#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector <int> findCommon (vector<int> A, vector<int> B, vector<int> C, int n1, int n2, int n3){

    //Time O(n1+n2+n3)
    //space O(n1)

    vector<int> ans;
    set<int> st;
    int i,j,k;
    i=j=k=0;
    while( i<n1 && j<n2 && k<n3){
        if(A[i] == B[j] && B[j] == C[k]){
            // ans.push_back(A[i]);
            st.insert(A[i]);
            i++,j++,k++;
        }
        else if(A[i]<B[j]){
            i++;
        }
        else if(B[j]<C[k]){
            j++;
        }
        else{
            k++;
        }
    }
    for(auto i:st){
        ans.push_back(i);
    }
    return ans;
}

int main(){
    vector<int> arr1{1, 5, 10, 20, 40, 80};
    vector<int> arr2{6, 7, 20, 80, 100};
    vector<int> arr3{3, 4, 15, 20, 30, 70, 80, 120};

    int n1 = 6;
    int n2 = 5;
    int n3 = 8;

    vector<int> ans;
    ans = findCommon(arr1,arr2,arr3,n1,n2,n3);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}