#include <iostream>
using namespace std;

int main() {
    int arr[100];
    int n, searchValue;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter array elements:\n";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter value to search: ";
    cin >> searchValue;

    int i = 0;
    bool found = false;

    while (i < n) {
        if (arr[i] == searchValue) {
            cout << "Value found at index " << i << endl;
            found = true;
            break;
        }

        i++;
    }

    if (!found) {
        cout << "Value not found!" << endl;
    }

    return 0;
}

