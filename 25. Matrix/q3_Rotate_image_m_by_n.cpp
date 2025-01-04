#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> rotate(vector<vector<int>> matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> ans(n,vector<int>(m));

    //store transpose
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            ans[i][j] = matrix[j][i];
        }
    }
    //reveres each row
    for(int i=0; i<n; i++){
        int start=0;
        int end=m-1;
        while(start<end){
            swap(ans[i][start],ans[i][end]);
            start++,end--;
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> matrix = {{1,2,3,4},
                                  {5,6,7,8},
                                  {9,10,11,12}};
    vector<vector<int>> ans = rotate(matrix);
    for(auto it:ans){
        for(auto i:it){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}