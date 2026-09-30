#include <iostream>              // Includes the input/output library.
using namespace std;             // Allows us to use cout and cin without std::.

// This class represents one node of the doubly linked list.
class Node
{
public:
    int data;                    // Stores the value of the node.
    Node* next;                  // Points to the next node.
    Node* prev;                  // Points to the previous node.

    // Constructor of Node.
    Node(int value)
    {
        data = value;            // Stores the given value in data.
        next = NULL;             // Initially, next does not point to any node.
        prev = NULL;             // Initially, prev does not point to any node.
    }
};

// This class represents the complete doubly linked list.
class DoublyLinkedList
{
private:
    Node* head;                  // Head points to the first node of the list.

public:

    // Constructor of DoublyLinkedList.
    DoublyLinkedList()
    {
        head = NULL;             // Initially, the list is empty.
    }

    // This function inserts a new node at the end of the list.
    void insert(int value)
    {
        Node* newNode = new Node(value);
        // Creates a new node and stores the given value in it.

        if (head == NULL)
        {
            // Checks whether the list is empty.

            head = newNode;
            // Makes the new node the first node.

            return;
            // Stops the function here.
        }

        Node* temp = head;
        // Creates a temporary pointer starting from the first node.

        while (temp->next != NULL)
        {
            // Moves through the list until the last node is found.

            temp = temp->next;
            // Moves temp to the next node.
        }

        temp->next = newNode;
        // Makes the new node the next node of the last node.

        newNode->prev = temp;
        // Makes the previous pointer of the new node point to the old last node.
    }

    // This function displays the linked list.
    void display()
    {
        Node* temp = head;
        // Starts traversal from the first node.

        while (temp != NULL)
        {
            // Continues until the end of the list.

            cout << temp->data << " ";
            // Prints the data of the current node.

            temp = temp->next;
            // Moves to the next node.
        }

        cout << endl;
        // Moves the cursor to the next line.
    }

    // This function reverses the doubly linked list.
    void reverse()
    {
        Node* current = head;
        // current starts from the first node.

        Node* temp = NULL;
        // temp is used to temporarily store a pointer.

        while (current != NULL)
        {
            // Continues until all nodes have been processed.

            temp = current->prev;
            // Saves the previous pointer of the current node.

            current->prev = current->next;
            // Makes prev point to what was previously next.

            current->next = temp;
            // Makes next point to what was previously prev.

            current = current->prev;
            // Moves to the next node in the original direction.
        }

        if (temp != NULL)
        {
            // Checks that the list was not empty.

            head = temp->prev;
            // Updates head to the new first node.
        }
    }
};

// Main function starts program execution.
int main()
{
    DoublyLinkedList list;
    // Creates an object named list.

    list.insert(10);
    // Inserts 10 into the list.

    list.insert(20);
    // Inserts 20 into the list.

    list.insert(30);
    // Inserts 30 into the list.

    list.insert(40);
    // Inserts 40 into the list.

    list.insert(50);
    // Inserts 50 into the list.

    cout << "Original List: ";
    // Displays a message before the original list.

    list.display();
    // Displays the original list.

    list.reverse();
    // Calls the reverse function.

    cout << "Reversed List: ";
    // Displays a message before the reversed list.

    list.display();
    // Displays the reversed list.

    return 0;
    // Ends the program successfully.
}
