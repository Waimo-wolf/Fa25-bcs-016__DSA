#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

int josephus(int n, int k)
{
    Node* head = NULL;
    Node* last = NULL;

    // Create circular linked list
    for (int i = 1; i <= n; i++)
    {
        Node* newNode = new Node(i);

        if (head == NULL)
        {
            head = newNode;
            last = newNode;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }
    }

    // Make the list circular
    last->next = head;

    Node* current = head;

    while (current->next != current)
    {
        // Move k-1 positions
        for (int i = 1; i < k; i++)
        {
            current = current->next;
        }

        // Find previous node
        Node* previous = current;

        while (previous->next != current)
        {
            previous = previous->next;
        }

        // Delete current node
        previous->next = current->next;

        Node* temp = current;
        current = current->next;

        delete temp;
    }

    int survivor = current->data;

    delete current;

    return survivor;
}

int main()
{
    int n, k;

    cout << "Enter number of people: ";
    cin >> n;

    cout << "Enter counting number: ";
    cin >> k;

    int survivor = josephus(n, k);

    cout << "Survivor is: " << survivor << endl;

    return 0;
}
