#include "nodeList.h"
#include <iostream>
using namespace std;

NodeList::NodeList(int data) {
    this->data = data;
    this->next = nullptr;
}

List::List() {
    head = nullptr;
}

List::~List() {
    clearList();
}

bool List::insertAtStart(int data) {
    NodeList* newNode = new(std::nothrow) NodeList(data);
    if (newNode == nullptr) return false;

    newNode->next = head;
    head = newNode;
    return true;
}

bool List::insertAtEnd(int data) {
    NodeList* newNode = new(std::nothrow) NodeList(data);
    if (newNode == nullptr) return false;

    if (head == nullptr) {
        head = newNode;
    } else {
        NodeList* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return true;
}

void List::printList() const {
    NodeList* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

void List::clearList() {
    NodeList* current = head;
    NodeList* nextNode;
    while (current) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}

bool List::deleteElement(int data) {
    NodeList* temp = head;
    NodeList* prev = nullptr;
    if (head == nullptr) return false;

    if (head->data == data) {
        NodeList* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    while (temp != nullptr && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) return false;

    prev->next = temp->next;
    delete temp;
    return true;
}

bool List::searchData(int data) {
    NodeList* temp = head;
    while (temp != nullptr) {
        if (temp->data == data) return true;
        temp = temp->next;
    }
    return false;
}

NodeList* List::middleNode() const {
    if (head == nullptr) return nullptr;
    NodeList* slow = head;
    NodeList* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int List::length() const {
    NodeList* temp = head;
    int count = 0;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void List::printIthNode(int i) const {
    if (i < 0) {
        cout << "-1" << endl;
        return;
    }
    NodeList* temp = head;
    int count = 0;
    while (count < i && temp != nullptr) {
        temp = temp->next;
        count++;
    }
    if (temp != nullptr) {
        cout << temp->data << endl;
    } else {
        cout << "-1" << endl;
    }
}

NodeList* List::insertAtIthPos(int i, int data) {
    if (i < 0) return head;

    if (i == 0) {
        NodeList* n = new NodeList(data);
        n->next = head;
        head = n;
        return head;
    }

    NodeList* temp = head;
    int count = 1;
    while (count <= i - 1 && temp != nullptr) {
        temp = temp->next;
        count++;
    }

    if (temp != nullptr) {
        NodeList* n = new NodeList(data);
        n->next = temp->next;
        temp->next = n;
    }

    return head;
}

NodeList* List::deleteIthNode(int i) {
    if (i < 0) return head;

    if (i == 0 && head != nullptr) {
        NodeList* newHead = head->next;
        delete head;
        return newHead;
    }

    NodeList* curr = head;
    int count = 1;
    while (count <= i - 1 && curr != nullptr) {
        curr = curr->next;
        count++;
    }

    if (curr != nullptr && curr->next != nullptr) {
        NodeList* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
    }

    return head;
}

NodeList* List::reverseList() {
    NodeList* current = head;
    NodeList* prev = nullptr;
    NodeList* next = nullptr;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    return head;
}

NodeList* List::split(NodeList* head) {
    if (head == nullptr || head->next == nullptr) return nullptr;

    NodeList* slow = head;
    NodeList* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    NodeList* secondHalf = slow->next;
    slow->next = nullptr;

    return secondHalf;
}

NodeList* List::merge(NodeList* left, NodeList* right) {
    if (left == nullptr) return right;
    if (right == nullptr) return left;

    NodeList* result = nullptr;

    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

NodeList* List::mergeSort(NodeList* head) {
    if (head == nullptr || head->next == nullptr) return head;

    NodeList* secondHalf = split(head);
    NodeList* left = mergeSort(head);
    NodeList* right = mergeSort(secondHalf);

    return merge(left, right);
}

void List::sortWithMergeSort() {
    head = mergeSort(head);
}
