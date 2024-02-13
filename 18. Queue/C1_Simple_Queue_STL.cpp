#include<iostream>
#include<queue>
using namespace std;

int main(){
    //creation
    queue<int> q;

    //insertion
    q.push(5);
    q.push(10);
    q.push(15);
    q.push(20);

    //size
    cout << q.size() <<endl;

    //deletion
    q.pop();
    q.pop();
    q.pop();
    q.pop();

    //check empty
    cout << q.empty() << endl;

    //find front element
    cout << q.front();

    return 0;
}