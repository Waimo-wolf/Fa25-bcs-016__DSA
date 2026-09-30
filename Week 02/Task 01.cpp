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

    // Insert data at the end
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

    // Display list normally
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

    // Lab Task 1: Reverse display using loop
    void reverseUsingLoop()
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        // Find length of list
        int count = 0;
        Node* temp = head;

        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        // Print from last node to first
        for (int i = count - 1; i >= 0; i--)
        {
            temp = head;

            for (int j = 0; j < i; j++)
            {
                temp = temp->next;
            }

            cout << temp->data << " ";
        }

        cout << endl;
    }

    // Lab Task 1: Reverse display using recursion
    void reverseUsingRecursion(Node* temp)
    {
        if (temp == NULL)
            return;

        reverseUsingRecursion(temp->next);

        cout << temp->data << " ";
    }

    void displayReverseRecursive()
    {
        reverseUsingRecursion(head);
        cout << endl;
    }

    // Lab Task 2: Merge two lists into a third new list
    static LinkedList mergeLists(LinkedList& list1, LinkedList& list2)
    {
        LinkedList thirdList;

        Node* temp = list1.head;

        while (temp != NULL)
        {
            thirdList.insert(temp->data);
            temp = temp->next;
        }

        temp = list2.head;

        while (temp != NULL)
        {
            thirdList.insert(temp->data);
            temp = temp->next;
        }

        return thirdList;
    }

    // Lab Task 3: Find multiple occurrences
    void findOccurrences(int value)
    {
        Node* temp = head;
        int count = 0;
        int position = 1;

        while (temp != NULL)
        {
            if (temp->data == value)
            {
                cout << "Value " << value
                     << " found at position "
                     << position << endl;

                count++;
            }

            temp = temp->next;
            position++;
        }

        if (count == 0)
        {
            cout << "Value " << value << " not found." << endl;
        }
        else
        {
            cout << "Total occurrences: " << count << endl;
        }
    }
};

int main()
{
    // First Linked List
    LinkedList list1;

    list1.insert(10);
    list1.insert(20);
    list1.insert(30);
    list1.insert(20);
    list1.insert(40);
    list1.insert(20);

    cout << "List 1: ";
    list1.display();

    // Lab Task 1 - Reverse using loop
    cout << "\nReverse using loop: ";
    list1.reverseUsingLoop();

    // Lab Task 1 - Reverse using recursion
    cout << "Reverse using recursion: ";
    list1.displayReverseRecursive();

    // Lab Task 3 - Multiple occurrences
    cout << "\nSearching for 20:" << endl;
    list1.findOccurrences(20);

    // Second Linked List
    LinkedList list2;

    list2.insert(50);
    list2.insert(60);
    list2.insert(70);

    cout << "\nList 2: ";
    list2.display();

    // Lab Task 2 - Merge two lists
    LinkedList list3 = LinkedList::mergeLists(list1, list2);

    cout << "\nMerged List (List 3): ";
    list3.display();

    return 0;
}
