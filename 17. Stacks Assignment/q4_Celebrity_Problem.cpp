#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//method 1
// int celebrity(vector<vector<int> >& mat, int n) {
//     int n = mat.size();
        
//     for(int i=0; i<n; i++){
//         bool isCelebrity = true;
            
//         for(int j=0; j<n; j++){
//             if(mat[i][j] == 1){
//                 isCelebrity = false;
//             }
//         }
            
//         for(int j=0; j<n; j++){
//             if(mat[j][i] == 0 && j != i){
//                 isCelebrity = false;
//             }
//         }
            
//         if(isCelebrity){
//             return i;
//         }
//     }
//     return -1;
// }

//method 2
int celebrity(vector<vector<int> >& M, int n) {
    stack<int> st;

    //step 1.push all person in stack
    for(int i=0; i<n; i++){
        st.push(i);
    }

    //step 2
    while(st.size() != 1){
        int A = st.top();
        st.pop();
        int B = st.top();
        st.pop();
        if(M[A][B] == 1){
            //means A is not celebrity
            st.push(B);
        }
        else if(M[A][B] == 0){
            //means B is not celebrity
            st.push(A);
        }
    }

    //step 3.single person in stack might be celebrity. verify it
    int mightBeCelebrity = st.top();
    st.pop();

    for(int i=0; i<n; i++){
        if(M[mightBeCelebrity][i] != 0){
            return -1;
        }
    }
    for(int j=0; j<n; j++){
        if(M[j][mightBeCelebrity] != 1   &&   j != mightBeCelebrity){
            return -1;
        }
    }
    return mightBeCelebrity;
}

int main(){
    vector<vector<int>> M = {{0,1,0},
                             {0,0,0},
                             {0,1,0}};
    
    int n = 3;
    cout << celebrity(M,n);
    return 0;
}