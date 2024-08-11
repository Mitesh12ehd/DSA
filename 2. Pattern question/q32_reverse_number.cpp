#include<iostream>
using namespace std;

int main(){
    int n = 4;

    int total = 0;
    for(int i=0; i<n; i++){
        int temp = n-i;
        while(temp--){
            total++;
        }
    }

    for(int i=0; i<n; i++){
        int startCount = n-i-1;

        int start = startCount;
        for(int j=0; j<n-i; j++){
            cout << total;
            total--;
            
            int var = start;
            while(var--){
                cout << "*";
            }
            start--;
        }
        startCount--;
        cout << endl;
    }

    return 0;
}