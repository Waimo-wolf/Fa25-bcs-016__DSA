#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int CAPACITY = 20;

struct ArrayList
{
    int data[CAPACITY];
    int size = 0;
};

// Insert value at the end
bool insertEnd(ArrayList& list, int value)
{
    if (list.size == CAPACITY)
        return false;

    list.data[list.size] = value;
    list.size++;

    return true;
}

// Insert value at the beginning
bool insertAtBeginning(ArrayList& list, int value)
{
    if (list.size == CAPACITY)
        return false;

    int* ptr = list.data + list.size;

    while (ptr != list.data)
    {
        *ptr = *(ptr - 1);
        ptr--;
    }

    list.data[0] = value;
    list.size++;

    return true;
}

// Delete value at a specific position
bool deleteAtPosition(ArrayList& list, int position)
{
    if (position < 0 || position >= list.size)
        return false;

    int* ptr = list.data + position;

    while (ptr < list.data + list.size - 1)
    {
        *ptr = *(ptr + 1);
        ptr++;
    }

    list.size--;

    return true;
}

// Display the ArrayList
void displayList(const ArrayList& list)
{
    for (int i = 0; i < list.size; i++)
    {
        cout << list.data[i];

        if (i < list.size - 1)
            cout << ", ";
    }

    cout << endl;
}

int main()
{
    ArrayList list;
    int registrationLastTwo;

    cout << "Enter the last two digits of your registration number: ";
    cin >> registrationLastTwo;

    // Part A: Populate ArrayList using insertion operation
    insertEnd(list, 18);
    insertEnd(list, 7);
    insertEnd(list, 45);
    insertEnd(list, 11);
    insertEnd(list, 36);
    insertEnd(list, registrationLastTwo);
    insertEnd(list, 21);
    insertEnd(list, 13);
    insertEnd(list, 29);

    cout << "\nInitial ArrayList: ";
    displayList(list);

    // Part B: Calculate sum, minimum and maximum
    int* ptr = list.data;
    int* minPtr = list.data;
    int* maxPtr = list.data;
    int sum = 0;

    for (int i = 0; i < list.size; i++, ptr++)
    {
        sum += *ptr;

        if (*ptr < *minPtr)
            minPtr = ptr;

        if (*ptr > *maxPtr)
            maxPtr = ptr;
    }

    cout << "Minimum Value: " << *minPtr << endl;
    cout << "Maximum Value: " << *maxPtr << endl;
    cout << "Sum: " << sum << endl;

    // Part C: Copy elements and sort the copy
    int temporary[CAPACITY];

    for (int i = 0; i < list.size; i++)
    {
        temporary[i] = list.data[i];
    }

    // Sort in ascending order
    for (int i = 0; i < list.size - 1; i++)
    {
        for (int j = i + 1; j < list.size; j++)
        {
            if (temporary[j] < temporary[i])
            {
                int swapValue = temporary[i];
                temporary[i] = temporary[j];
                temporary[j] = swapValue;
            }
        }
    }

    // Find median
    int medianValue = temporary[list.size / 2];

    int* medianPtr = list.data;

    for (int i = 0; i < list.size; i++)
    {
        if (*medianPtr == medianValue)
            break;

        medianPtr++;
    }

    cout << "Median Value: " << *medianPtr << endl;

    // Part D: Calculate averages and closest value
    double generalAverage =
        static_cast<double>(sum) / list.size;

    double specialAverage =
        (*minPtr + *medianPtr + *maxPtr) / 3.0;

    double closestDistance =
        fabs(*list.data - specialAverage);

    int* closestPtr = list.data;

    for (ptr = list.data + 1;
         ptr < list.data + list.size;
         ptr++)
    {
        double distance =
            fabs(*ptr - specialAverage);

        if (distance < closestDistance)
        {
            closestDistance = distance;
            closestPtr = ptr;
        }
    }

    int closestPosition =
        static_cast<int>(closestPtr - list.data);

    cout << fixed << setprecision(2);

    cout << "General Average: "
         << generalAverage << endl;

    cout << "Special Average: "
         << specialAverage << endl;

    cout << "Closest Value: "
         << *closestPtr << endl;

    cout << "Position of Closest Value: "
         << closestPosition << endl;

    // Part E: Final calculations
    double averageDifference =
        fabs(generalAverage - specialAverage);

    double finalScore =
        fabs(*closestPtr - generalAverage)
        + fabs(*closestPtr - specialAverage)
        + averageDifference;

    cout << "Difference Between Averages: "
         << averageDifference << endl;

    cout << "Final Score: "
         << finalScore << endl;

    // Delete the closest value
    cout << "ArrayList After Deletion: ";

    deleteAtPosition(list, closestPosition);

    displayList(list);

    // Insert rounded special average at beginning
    int roundedSpecialAverage =
        static_cast<int>(round(specialAverage));

    insertAtBeginning(list, roundedSpecialAverage);

    cout << "Final ArrayList After Insertion: ";

    displayList(list);

    return 0;
}
