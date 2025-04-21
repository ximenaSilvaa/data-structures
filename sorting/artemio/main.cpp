#include <iostream>
#include "sortTest.h"

using namespace std;


int main() {
    unsigned int size = 0;
    SortTest myTest;

    srand(time(0));

    do {
        cout << "Size? ";
        cin >> size;
        if(myTest.setDataSize(size) == false) {
            cout << "No hubo memoria\n";
            return 0;
        }
    } while(size == 0);

    // Bubble Sort
    myTest.generateRandomNumbers();
    cout << "El arreglo original es:" << endl;
    myTest.printData();

    myTest.bubbleSort();
    cout << "El arreglo ordenado por Bubble Sort es:" << endl;
    myTest.printData();

    // Insertion Sort
    myTest.generateRandomNumbers();
    cout << "\nEl arreglo original es:" << endl;
    myTest.printData();

    myTest.insertionSort();
    cout << "El arreglo ordenado por Insertion Sort es:" << endl;
    myTest.printData();

    // Selection Sort
    myTest.generateRandomNumbers();
    cout << "\nEl arreglo original es:" << endl;
    myTest.printData();

    myTest.selectionSort();
    cout << "El arreglo ordenado por Selection Sort es:" << endl;
    myTest.printData();

    // Merge Sort
    myTest.generateRandomNumbers();
    cout << "\nEl arreglo original es:" << endl;
    myTest.printData();

    if(!myTest.mergeSort())
        cout << "No se pudo hacer el mergeSort\n";
    else
        cout << "El arreglo ordenado por Merge Sort es:" << endl;
    myTest.printData();

    // Quick Sort 
    myTest.generateRandomNumbers();
    cout << "\nEl arreglo original es:" << endl;
    myTest.printData();

    myTest.quickSort(0, size - 1);
    cout << "El arreglo ordenado por Quick Sort es:" << endl;
    myTest.printData();

    // Linear Search
    int value;
    cout << "\nIngrese un valor para buscar (Búsqueda Lineal): ";
    cin >> value;
    int linearIndex = myTest.linearSearch(value);
    if(linearIndex != -1)
        cout << "Valor encontrado en la posición " << linearIndex << " usando Búsqueda Lineal." << endl;
    else
        cout << "Valor no encontrado usando Búsqueda Lineal." << endl;

    // Binary Search
    cout << "\nIngrese un valor para buscar (Búsqueda Binaria): ";
    cin >> value;
    int binaryIndex = myTest.binarySearch(value);
    if(binaryIndex != -1)
        cout << "Valor encontrado en la posición " << binaryIndex << " usando Búsqueda Binaria." << endl;
    else
        cout << "Valor no encontrado usando Búsqueda Binaria." << endl;

    return 0;
}
