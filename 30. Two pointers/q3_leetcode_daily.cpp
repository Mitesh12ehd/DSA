#include<iostream>
using namespace std;

//leetcode 2337
//move pieces to obtain a string

bool canChange(string start, string target) {
    int i=0;
    int j=0;
    int n = start.length();
	
    while(i < n || j < n){
        //skip spaces in start string
        while(i < n && start[i] == '_'){
            i++;
        }
        //skip spaces in target string
        while(j < n && target[j] == '_'){
            j++;
        }

        //now we stand st point where both pointer point either L or R 

        if(i == n || j == n){
            break;
        }
        //if charcter don't match transformation not possible
        if(start[i] != target[j]){
            return false;
        }

        //L can only move in left
        if(start[i] == 'L'){
            if(i < j){
                return false;
            }
        }
        //R can only mpve in right 
        if(start[i] == 'R'){
            if(i > j){
                return false;
            }
        }  
        i++;
        j++;
    }
    return i == n && j == n;
}

int main(){
    

    return 0;
}