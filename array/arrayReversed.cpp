#include <iostream>
#include <ctime>

using namespace std;


int  main(){
    srand(time(0));
    int n, i;
    int* a;

    cout << "Ingrese el tamaño: ";
    cin >> n;
    cout << endl;

    if(n <= 0){
        cout << "El tamaño debe ser mayor a 0.";
    }else{

    a =new(nothrow) int[n];

    if(a==nullptr){
        cout << "No se pudo asignar memoria." << endl;
        return 1;  // Salir del programa si no se asigna memoria
    }


    // Llenar el arreglo con números aleatorios
    for (i = 0; i < n; i++) {
        a[i] = rand() % n;  
        cout << a[i] << " ";  

    cout << endl;

    
    for (i = n - 1; i >= 0; i--) {
        cout << a[i] << " ";
    }

    cout << endl;

    // Liberar la memoria asignada
    delete[] a;

    }


    return 0;
}
