#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//leetcode 1975
//maximum matrix sum

//here after performing operation,at max only 1 element remain nagative,
//                                  or it can be 0 element remain nagative

//if total number of nagative element is even,
//      then after performing operation, there is 0 nagative element

//if total number of nagative element is odd,
//      then after performing operation, there is 1 nagative element

//here in odd case
//to maximize sum, we allocagte nagative sign to who is who has minimum absolute value


//1.first count the sum of all element by considering all as positive
//2.then if there is even nagative element, then no need to change the sum
//3.then if there is odd nagative element, then remove 2*minimum elment
//                                          (because we added it in sum by considering positive)

long long maxMatrixSum(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    int nagativeCount = 0;
    long long ans = 0;
    int mini = INT_MAX;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            //find minimum element
            mini = min(mini,abs(matrix[i][j]));
            //find sum by considering all elements as positive
            ans = ans + abs(matrix[i][j]);
            //find count of nagative number
            if(matrix[i][j] < 0){
                nagativeCount++;
            }
        }
    }

    if(nagativeCount % 2 == 0){
        return ans;
    }
    else{
        ans = ans - (2*mini);
        return ans;
    }
}

int main(){
    return 0;
}