#pragma once
#include <iostream>

class NodeList {
public:
    int data;
    NodeList* next;

    NodeList(int data);
};

class List {
private:
    NodeList* head;
    NodeList* split(NodeList* head);
    NodeList* merge(NodeList* left, NodeList* right);
    NodeList* mergeSort(NodeList* head);

public:
    List();
    ~List();

    bool insertAtStart(int data);
    bool insertAtEnd(int data);
    void printList() const;
    void clearList();
    bool deleteElement(int data);
    bool searchData(int data);
    int length() const;
    NodeList* middleNode() const;

    void printIthNode(int i) const;
    NodeList* insertAtIthPos(int i, int data);
    NodeList* deleteIthNode(int i);
    NodeList* reverseList();
    void sortWithMergeSort();
};

