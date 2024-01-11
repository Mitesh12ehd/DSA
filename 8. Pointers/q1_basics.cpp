#include<iostream>
using namespace std;

void changeSign(int*ptr){
    *ptr = *ptr * -1;
}

int main(){

    // int a = 5;
    // //pointer create
    // int* ptr = &a;
    // cout << "Address of a is = " << &a << endl;
    // cout << "ptr = "<< ptr << endl;
    // cout << "Value that ptr pointing to = " << *ptr <<endl;
    // cout << "Address of ptr is = " << &ptr;

    // int a = 5;
    // int* ptr1 = &a;
    // cout << sizeof(ptr1) << endl;
    // char ch = 'a';
    // char* ptr2 = &ch;
    // cout << sizeof(ptr2) << endl;
    // double d = 1.05;
    // double* ptr3 = &d;
    // cout << sizeof(ptr3) << endl;


    //-----int array-----
    // int arr[4] = {12,13,14,15};
    // cout << arr <<endl;
    // cout << arr[0] <<endl;
    // cout << &arr<<endl;
    // cout << &arr[0];


    //------char array------
    // char ch[10] = "MITESH";
    // char *c = ch;
    // cout << ch << endl;
    // cout << &ch << endl;
    // cout << ch[0] << endl;
    // cout << &c << endl;
    // cout << c << endl;
    // cout << *c << endl;

    // int a[] = {1,2,3,4};
    // int *p = a++;
    // cout << *p <<endl;


    int a=10;
    changeSign(&a);
    cout<<a;

    


    return 0;
}