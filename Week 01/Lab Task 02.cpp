#include <iostream>
using namespace std;

const int MAX = 100;

int arr[MAX];
int n = 0;

// 1. Insert at the end
void insertEnd(int value) {
    if (n == MAX) {
        cout << "List is full!\n";
        return;
    }

    arr[n] = value;
    n++;
}

// 2. Insert at the start
void insertStart(int value) {
    if (n == MAX) {
        cout << "List is full!\n";
        return;
    }

    for (int i = n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    arr[0] = value;
    n++;
}

// 3. Insert after a specific value
void insertAfter(int specific, int value) {
    if (n == MAX) {
        cout << "List is full!\n";
        return;
    }

    int pos = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == specific) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        cout << "Value not found!\n";
        return;
    }

    for (int i = n; i > pos + 1; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos + 1] = value;
    n++;
}

// 4. Insert before a specific value
void insertBefore(int specific, int value) {
    if (n == MAX) {
        cout << "List is full!\n";
        return;
    }

    int pos = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == specific) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        cout << "Value not found!\n";
        return;
    }

    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = value;
    n++;
}

// 5. Display the array
void display() {
    if (n == 0) {
        cout << "List is empty!\n";
        return;
    }

    cout << "Array List: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

// 6. Delete from the end
void deleteEnd() {
    if (n == 0) {
        cout << "List is empty!\n";
        return;
    }

    n--;
}

// 7. Delete from the start
void deleteStart() {
    if (n == 0) {
        cout << "List is empty!\n";
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;
}

// 8. Delete a specific value
void deleteSpecific(int value) {
    int pos = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        cout << "Value not found!\n";
        return;
    }

    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;
}

int main() {
    int choice, value, specific;

    do {
        cout << "\n===== ARRAY LIST MENU =====\n";
        cout << "1. Insert at end\n";
        cout << "2. Insert at start\n";
        cout << "3. Insert after specific value\n";
        cout << "4. Insert before specific value\n";
        cout << "5. Display array\n";
        cout << "6. Delete from end\n";
        cout << "7. Delete from start\n";
        cout << "8. Delete specific value\n";
        cout << "0. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertEnd(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertStart(value);
                break;

            case 3:
                cout << "Enter specific value: ";
                cin >> specific;
                cout << "Enter new value: ";
                cin >> value;
                insertAfter(specific, value);
                break;

            case 4:
                cout << "Enter specific value: ";
                cin >> specific;
                cout << "Enter new value: ";
                cin >> value;
                insertBefore(specific, value);
                break;

            case 5:
                display();
                break;

            case 6:
                deleteEnd();
                break;

            case 7:
                deleteStart();
                break;

            case 8:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteSpecific(value);
                break;

            case 0:
                cout << "Program ended.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}

