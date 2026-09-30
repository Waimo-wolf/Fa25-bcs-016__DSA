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

class LinkedList
{
private:
    Node* head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void insert(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void display()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    // Find all occurrences of a value
    void findOccurrences(int value)
    {
        Node* temp = head;
        int position = 1;
        int count = 0;

        while (temp != NULL)
        {
            if (temp->data == value)
            {
                cout << value << " found at position "
                     << position << endl;

                count++;
            }

            temp = temp->next;
            position++;
        }

        if (count == 0)
        {
            cout << value << " was not found in the list." << endl;
        }
        else
        {
            cout << "Total occurrences = " << count << endl;
        }
    }
};

int main()
{
    LinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(20);
    list.insert(40);
    list.insert(20);
    list.insert(50);
    list.insert(20);

    cout << "Linked List: ";
    list.display();

    int value;

    cout << "Enter value to search: ";
    cin >> value;

    list.findOccurrences(value);

    return 0;
}
