#include<iostream>
#include<vector>
using namespace std;

//gfg
//floyd warshall algorithm

void shortestDistance(vector<vector<int>>& mat) {
    int n = mat.size();
        
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j] == -1){
                mat[i][j] = 1e9;
            }
        }
    }
        
    //algorithm
    for(int via=0; via<n; via++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                mat[i][j] = min(mat[i][j], mat[i][via] + mat[via][j]);
            }
        }
    }

    //if interviewer ask to detect nagative cycle
    // for(int i=0; i<n; i++){
    //     if(mat[i][i] < 0){
    //         cout << "there is nagative cycle";
    //     }
    // }
        
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j] == 1e9){
                mat[i][j] = -1;
            }
        }
    }
}

int main(){
    return 0;
}