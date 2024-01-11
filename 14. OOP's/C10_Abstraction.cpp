#include<iostream>
#include "C10_bird.h"
using namespace std;

void bird_Does_Something(Bird*& bird){
    bird->eat();
    bird->fly();
}

int main(){
    Bird *bird = new Sparrow();
    bird_Does_Something(bird);

    Bird *bird1 = new Eagle();
    bird_Does_Something(bird1);

    return 0;
}