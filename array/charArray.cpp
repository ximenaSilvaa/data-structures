#include<iostream>
using namespace std;
int length(char input[]){
    int count = 0;
    for(int i=0; input[i] != '\0'; i++){
        count++;
    }
    return count;

}

int main() {
    char name[100];
    cout << "Enter your name: ";
    cin >> name;

    /*
    Era para entender que cuando se encuentra un null se deja de imprimir.
    name[1]= '\0';
    name[3] = 'd';
    name[4] = 'x';
    */
   
    cout << "Your name is " << name << endl;
    cout << "Length: " << length(name);

    return 0;
}