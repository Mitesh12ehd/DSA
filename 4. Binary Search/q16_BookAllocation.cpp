#include<iostream>
using namespace std;

bool isPossibleSolution(int A[],int N,int M,int sol){
    int pageSum = 0;
    int count = 1;
    for(int i=0; i<N; i++){
        if(A[i] > sol){
            return false;
        }
        if(pageSum + A[i] > sol){
            count++;
            pageSum = 0;
            pageSum = pageSum + A[i];
            if(count > M){
                return false;
            }
        }
        else{
            pageSum = pageSum + A[i];
        }
    }
    return true;
}
int findPages(int A[], int N, int M) {
    if(M > N){
        return -1;
    }
    
    int start =0;
    int end = 0;
    for(int i=0; i<N; i++){
        end = end + A[i];
    }
    int ans = -1;
    
    while(start <= end){
        int mid = start + (end-start) / 2;
        if(isPossibleSolution(A,N,M,mid)){
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}
int main(){
    int A[] = {12,34,67,90};
    int N = 4;
    int M = 2;
    int minimum_Pages = findPages(A,N,M);
    cout<<minimum_Pages;

    return 0;
}