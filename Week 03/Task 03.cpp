#include <iostream>              // Includes input/output library.
using namespace std;             // Allows cout and cin without std::.

// This class represents a node of the singly linked list.
class SNode
{
public:
    int data;                    // Stores the node's data.
    SNode* next;                 // Points to the next node.

    // Constructor of SNode.
    SNode(int value)
    {
        data = value;            // Stores the given value.
        next = NULL;             // Initially next is NULL.
    }
};

// This class represents the singly linked list.
class SinglyLinkedList
{
public:
    SNode* head;                 // Points to the first node.

    // Constructor of singly linked list.
    SinglyLinkedList()
    {
        head = NULL;             // Starts with an empty list.
    }

    // Function to insert data at the end.
    void insert(int value)
    {
        SNode* newNode = new SNode(value);
        // Creates a new singly linked list node.

        if (head == NULL)
        {
            // Checks if the list is empty.

            head = newNode;
            // Makes newNode the first node.

            return;
            // Stops the function.
        }

        SNode* temp = head;
        // Starts traversal from the first node.

        while (temp->next != NULL)
        {
            // Finds the last node.

            temp = temp->next;
            // Moves to the next node.
        }

        temp->next = newNode;
        // Connects the last node to the new node.
    }

    // Function to display singly linked list.
    void display()
    {
        SNode* temp = head;
        // Starts from the first node.

        while (temp != NULL)
        {
            // Continues until the end.

            cout << temp->data << " ";
            // Prints current node's data.

            temp = temp->next;
            // Moves to the next node.
        }

        cout << endl;
        // Moves to a new line.
    }
};

// This class represents a node of the doubly linked list.
class DNode
{
public:
    int data;                    // Stores the node's data.
    DNode* next;                 // Points to the next node.
    DNode* prev;                 // Points to the previous node.

    // Constructor of DNode.
    DNode(int value)
    {
        data = value;            // Stores the given value.
        next = NULL;             // Initially next is NULL.
        prev = NULL;             // Initially prev is NULL.
    }
};

// This class represents the doubly linked list.
class DoublyLinkedList
{
public:
    DNode* head;                 // Points to the first node.

    // Constructor of doubly linked list.
    DoublyLinkedList()
    {
        head = NULL;             // Starts with an empty list.
    }

    // Function to insert data at the end.
    void insert(int value)
    {
        DNode* newNode = new DNode(value);
        // Creates a new doubly linked list node.

        if (head == NULL)
        {
            // Checks if the list is empty.

            head = newNode;
            // Makes newNode the first node.

            return;
            // Stops the function.
        }

        DNode* temp = head;
        // Starts from the first node.

        while (temp->next != NULL)
        {
            // Finds the last node.

            temp = temp->next;
            // Moves to the next node.
        }

        temp->next = newNode;
        // Connects the old last node to newNode.

        newNode->prev = temp;
        // Connects newNode back to the old last node.
    }

    // Function to display the doubly linked list.
    void display()
    {
        DNode* temp = head;
        // Starts from the first node.

        while (temp != NULL)
        {
            // Continues until NULL.

            cout << temp->data << " ";
            // Prints the current node's data.

            temp = temp->next;
            // Moves to the next node.
        }

        cout << endl;
        // Moves to the next line.
    }
};

// This function converts a singly linked list into a doubly linked list.
DoublyLinkedList convertToDoubly(SinglyLinkedList& singlyList)
{
    DoublyLinkedList doublyList;
    // Creates a new empty doubly linked list.

    SNode* temp = singlyList.head;
    // Starts from the first node of the singly linked list.

    while (temp != NULL)
    {
        // Continues until all singly linked list nodes are processed.

        doublyList.insert(temp->data);
        // Copies the current data into the new doubly linked list.

        temp = temp->next;
        // Moves to the next singly linked list node.
    }

    return doublyList;
    // Returns the newly created doubly linked list.
}

// Main function.
int main()
{
    SinglyLinkedList singlyList;
    // Creates a singly linked list object.

    singlyList.insert(10);
    // Inserts 10 into the singly list.

    singlyList.insert(20);
    // Inserts 20 into the singly list.

    singlyList.insert(30);
    // Inserts 30 into the singly list.

    singlyList.insert(40);
    // Inserts 40 into the singly list.

    singlyList.insert(50);
    // Inserts 50 into the singly list.

    cout << "Singly Linked List: ";
    // Displays message.

    singlyList.display();
    // Displays the singly linked list.

    DoublyLinkedList doublyList =
        convertToDoubly(singlyList);
    // Converts the singly list into a new doubly list.

    cout << "Doubly Linked List: ";
    // Displays message.

    doublyList.display();
    // Displays the new doubly linked list.

    return 0;
    // Ends the program successfully.
}
