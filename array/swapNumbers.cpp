#include <iostream>

using namespace std;

int main(){
    int a= 5;
    int b= 8;
    int c= 3;
    int d= 4;
    int tmp;

    cout << a << " " << b << endl;
    cout << c << " " << d << endl;

    //swap
    tmp = a;
    a = b;
    b = tmp;

    //swap fuction
    swap(c,d);
    

    cout << a << " " << b << endl;
    cout << c << " " << d << endl;

    return 0;
}