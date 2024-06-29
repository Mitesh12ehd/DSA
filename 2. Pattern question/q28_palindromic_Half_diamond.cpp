#include<iostream>
using namespace std;

int main(){
    int n = 5;

    for(int i=0; i<n; i++){
        //space
        for(int j=0; j<n-i-1; j++){
            cout << "  ";
        }

        //astrict
        int var = i+1;
        for(int j=0; j<i+1; j++){
            cout << var << " ";
            var--;
        }

        for(int j=0; j<i; j++){
            cout << j+2 << " ";
        }
        cout << endl;
    }

    return 0;
}