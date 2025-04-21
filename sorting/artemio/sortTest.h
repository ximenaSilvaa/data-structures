#pragma once

#include <ctime>

class SortTest {
public:
    SortTest();
    ~SortTest();
    
    // Funciones para la generación y manejo de datos
    bool setDataSize(unsigned int newSize);
    void generateRandomNumbers();
    void printData();

    // Algoritmos de ordenamiento
    void bubbleSort();
    void insertionSort();
    void selectionSort();
    bool mergeSort();
    void quickSort(int start, int end);

    // Funciones de búsqueda
    int linearSearch(int value);    // Búsqueda lineal
    int binarySearch(int value);    // Búsqueda binaria

private:
    // Funciones auxiliares para Merge Sort y Quick Sort
    void deleteArray();
    bool mergeSortExecute(unsigned int left, unsigned int right); 
    bool merge(unsigned int left, unsigned int middle, unsigned int right);
    int partition(int start, int end);

    unsigned int *data;  // Puntero al arreglo dinámico
    unsigned int size;   // Tamaño del arreglo
};
