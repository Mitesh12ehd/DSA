#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int m = matrix.size();
    int n = matrix[0].size();
    int total = m * n;

    int starting_raw = 0;
    int ending_col = n-1;
    int ending_raw = m-1;
    int starting_col = 0;

    int count = 0;

    while(count < total){
        //print Starting raw
        for(int i=starting_col; i<=ending_col && count<total; i++){
            ans.push_back(matrix[starting_raw][i]);
            count++;
        }
        starting_raw++;

        //print ending column
        for(int i=starting_raw; i<=ending_raw && count<total; i++){
            ans.push_back(matrix[i][ending_col]);
            count++;
        }
        ending_col--;

        //print ending raw
        for(int i=ending_col; i>=starting_col && count<total; i--){
            ans.push_back(matrix[ending_raw][i]);
            count++;
        }
        ending_raw--;

        //print Starting column
        for(int i=ending_raw; i>=starting_raw  && count<total; i--){
            ans.push_back(matrix[i][starting_col]);
            count++;
        }
        starting_col++;
    }
    return ans;
}

int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    vector<int> ans;
    ans = spiralOrder(matrix);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}