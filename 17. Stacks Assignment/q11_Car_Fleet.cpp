#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

class Car{
    public:
    int pos,speed;
    Car(int p,int s){
        pos = p;
        speed = s;
    }
};

static bool myComparator(Car& a,Car& b){
    return a.pos < b.pos; //ascending
}

int carFleet(int target, vector<int>& position, vector<int>& speed) {
    //it is used to sort the position array and change corresponing speed array element
    vector<Car> cars;
    for(int i=0; i<position.size(); i++){
        Car car(position[i],speed[i]);
        cars.push_back(car);
    }
    sort(cars.begin(),cars.end(),myComparator);

    //solution
    stack<float> st;
    for(auto car:cars){
        float time = (target-car.pos) / ((float)car.speed);
        
        while(!st.empty() && time >= st.top()){
            st.pop();
        }
        st.push(time);

    }
    return st.size();
}

int main(){
    int target = 12;
    vector<int> position = {10,8,0,5,3};
    vector<int> speed = {2,4,1,1,3};
    cout << carFleet(target,position,speed);
    return 0;
}