#include <iostream>

using namespace std;

int main(){
    int i, n, valor;
    int a[n];
    int suma = 0;

    cout << "Ingrese el tamaño del arreglo: " << endl; 
    cin >> n;

    for(i = 0; i < n; i++){
        cout << "Ingrese el valor: " << endl; 
        cin >> valor;
        a[i]= valor;

    }

    cout << "La suma de los valores es: " << suma;

    return 0;
}
