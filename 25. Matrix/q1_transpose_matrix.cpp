#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> ans(n,vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            ans[i][j] = matrix[j][i];
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> matrix = {{1,2,3},
                                  {4,5,6}};

    vector<vector<int>> ans = transpose(matrix);
    for(auto it:ans){
        for(auto i:it){
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}