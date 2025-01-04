#include<iostream>
#include<vector>
using namespace std;

//leetcode 1861


vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
    int m = box.size();
    int n = box[0].size();

    //step 1:first put stone to its correct position when it fall due to gravity
    for(int i=0; i<m; i++){
        int left = n-1;
        int right = n-1;

        while(left >= 0){
            //if obstacle arrive then put both pointer before obstacle
            if(box[i][left] == '*'){
                left--;
                right = left;
            }
            else if(box[i][left] == '.'){
                left--;
            }
            else{
                swap(box[i][left],box[i][right]);
                right--;
                left--;
            }
        }
    }

    //step2:now rotate matrix to 90 degree clockwise
    vector<vector<char>> ans(n,vector<char>(m,'a'));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            ans[i][j] = box[j][i];
        }
    }
    for(int i=0; i<n; i++){
        int start =0; 
        int end=m-1;
        while(start<end){
            swap(ans[i][start],ans[i][end]);
            start++,end--;
        }
    }
    return ans;
}

int main(){
    return 0;
}