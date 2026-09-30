#include <iostream>
using namespace std;

int main() {
    int start, stop;
    int sum = 0;

    cout << "Enter starting value: ";
    cin >> start;

    cout << "Enter stopping value: ";
    cin >> stop;

    for (int x = start; x <= stop; x++) {
        sum = sum + (x * x);
    }

    cout << "Sum of squares = " << sum << endl;

    return 0;
}

