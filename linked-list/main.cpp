#include "nodeList.h"
#include <iostream>

using namespace std;

void showMenu() {
    cout << "\n----- Menu -----\n";
    cout << "1. Insert at start\n";
    cout << "2. Insert at end\n";
    cout << "3. Print list\n";
    cout << "4. Delete an element\n";
    cout << "5. Search data\n";
    cout << "6. Find middle node\n";
    cout << "7. List length\n";
    cout << "8. Print i-th node\n";
    cout << "9. Insert at i-th position\n";
    cout << "10. Delete i-th node\n";
    cout << "11. Reverse list\n";
    cout << "12. Sort using Merge Sort\n";
    cout << "13. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    List myList;
    int option, data, i, size;
    bool result;
    NodeList* middle = nullptr;

    do {
        showMenu();
        cin >> option;

        switch (option) {
            case 1:
                do {
                    cout << "Enter data to insert at start (-1 to stop): ";
                    cin >> data;
                    if (data != -1) {
                        result = myList.insertAtStart(data);
                        cout << (result ? "Inserted successfully.\n" : "Error inserting.\n");
                    }
                } while (data != -1);
                break;

            case 2:
                do {
                    cout << "Enter data to insert at end (-1 to stop): ";
                    cin >> data;
                    if (data != -1) {
                        result = myList.insertAtEnd(data);
                        cout << (result ? "Inserted successfully.\n" : "Error inserting.\n");
                    }
                } while (data != -1);
                break;

            case 3:
                cout << "List: ";
                myList.printList();
                break;

            case 4:
                cout << "Enter value to delete: ";
                cin >> data;
                result = myList.deleteElement(data);
                cout << (result ? "Deleted successfully.\n" : "Error: Not found or list empty.\n");
                break;

            case 5:
                cout << "Enter value to search: ";
                cin >> data;
                result = myList.searchData(data);
                cout << (result ? "Found.\n" : "Not found.\n");
                break;

            case 6:
                middle = myList.middleNode();
                cout << (middle ? "Middle node: " + to_string(middle->data) + "\n" : "List is empty.\n");
                break;

            case 7:
                size = myList.length();
                cout << "List size: " << size << endl;
                break;

            case 8:
                cout << "Enter index to print: ";
                cin >> i;
                myList.printIthNode(i);
                break;

            case 9:
                cout << "Enter index: ";
                cin >> i;
                cout << "Enter data: ";
                cin >> data;
                myList.insertAtIthPos(i, data);
                cout << "Inserted at position " << i << ".\n";
                break;

            case 10:
                cout << "Enter index to delete: ";
                cin >> i;
                myList.deleteIthNode(i);
                cout << "Deleted node at position " << i << ".\n";
                break;

            case 11:
                myList.reverseList();
                cout << "List reversed.\n";
                break;

            case 12:
                myList.sortWithMergeSort();
                cout << "List sorted using Merge Sort.\n";
                break;

            case 13:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid option. Please try again.\n";
        }
    } while (option != 13);

    return 0;
}
