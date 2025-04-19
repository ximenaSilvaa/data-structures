#include <iostream>
#include <ctime>
#include <climits> //este es para lo de largest


using namespace std;

int main(){
    //Inicializo el tiempo en 0
    srand(time(0));

    int n, i;
    int *a;
    int largest = INT_MIN;

    //Tamaño
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> n;

    //Creo el arreglo 
    a = new(nothrow) int[n];

    //LLeno random
    for(i= 0; i <n; i++){
        a[i] = rand() % n;
        cout << a[i] << " ";
        if(a[i]> largest){
            largest = a[i];
        }
    }

    cout << "El número más grande es: " << largest;

    delete[] a;


    return 0;
}