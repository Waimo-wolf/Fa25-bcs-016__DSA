#include <iostream>              // Includes input/output library.
using namespace std;             // Allows cout and cin without std::.

// This class represents one node.
class Node
{
public:
    int data;                    // Stores the value.
    Node* next;                  // Points to the next node.
    Node* prev;                  // Points to the previous node.

    // Constructor for creating a node.
    Node(int value)
    {
        data = value;            // Stores the given value.
        next = NULL;             // Initially next is NULL.
        prev = NULL;             // Initially prev is NULL.
    }
};

// This class represents the doubly linked list.
class DoublyLinkedList
{
private:
    Node* head;                  // Points to the first node.

public:

    // Constructor of the linked list.
    DoublyLinkedList()
    {
        head = NULL;             // Starts with an empty list.
    }

    // Function to insert a node at the end.
    void insert(int value)
    {
        Node* newNode = new Node(value);
        // Creates a new node.

        if (head == NULL)
        {
            // Checks if the list is empty.

            head = newNode;
            // Makes newNode the first node.

            return;
            // Ends the function.
        }

        Node* temp = head;
        // Starts from the first node.

        while (temp->next != NULL)
        {
            // Finds the last node.

            temp = temp->next;
            // Moves to the next node.
        }

        temp->next = newNode;
        // Connects the last node with the new node.

        newNode->prev = temp;
        // Connects the new node back to the previous node.
    }

    // Function to display the list.
    void display()
    {
        Node* temp = head;
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
        // Moves to a new line.
    }

    // Function to search and swap two nodes.
    void swapNodes(int value1, int value2)
    {
        Node* node1 = NULL;
        // Will store the address of the first node.

        Node* node2 = NULL;
        // Will store the address of the second node.

        Node* temp = head;
        // Starts searching from the first node.

        while (temp != NULL)
        {
            // Traverses the complete list.

            if (temp->data == value1)
            {
                // Checks if current node contains value1.

                node1 = temp;
                // Stores the address of that node.
            }

            if (temp->data == value2)
            {
                // Checks if current node contains value2.

                node2 = temp;
                // Stores the address of that node.
            }

            temp = temp->next;
            // Moves to the next node.
        }

        if (node1 == NULL || node2 == NULL)
        {
            // Checks whether one or both values were not found.

            cout << "Both values were not found." << endl;
            // Displays an error message.

            return;
            // Stops the function.
        }

        if (node1 == node2)
        {
            // Checks whether both values belong to the same node.

            cout << "Both values are the same." << endl;
            // Displays a message.

            return;
            // Stops the function.
        }

        // Checks if node1 and node2 are next to each other.
        if (node1->next == node2)
        {
            Node* before = node1->prev;
            // Stores the node before node1.

            Node* after = node2->next;
            // Stores the node after node2.

            if (before != NULL)
            {
                // Checks whether node1 has a previous node.

                before->next = node2;
                // Connects the previous node to node2.
            }
            else
            {
                head = node2;
                // If node1 was first, node2 becomes the new head.
            }

            if (after != NULL)
            {
                // Checks whether node2 has a next node.

                after->prev = node1;
                // Connects the next node back to node1.
            }

            node2->prev = before;
            // Sets node2's previous pointer.

            node2->next = node1;
            // Makes node2 point to node1.

            node1->prev = node2;
            // Makes node1 point back to node2.

            node1->next = after;
            // Connects node1 to the node after node2.
        }

        // Checks if node2 is immediately before node1.
        else if (node2->next == node1)
        {
            Node* before = node2->prev;
            // Stores the node before node2.

            Node* after = node1->next;
            // Stores the node after node1.

            if (before != NULL)
            {
                // Checks whether node2 has a previous node.

                before->next = node1;
                // Connects previous node to node1.
            }
            else
            {
                head = node1;
                // Makes node1 the new head.
            }

            if (after != NULL)
            {
                // Checks whether node1 has a next node.

                after->prev = node2;
                // Connects the next node back to node2.
            }

            node1->prev = before;
            // Sets node1's previous pointer.

            node1->next = node2;
            // Makes node1 point to node2.

            node2->prev = node1;
            // Makes node2 point back to node1.

            node2->next = after;
            // Connects node2 to the next node.
        }

        // This block handles nodes that are not adjacent.
        else
        {
            Node* node1Prev = node1->prev;
            // Saves node1's previous node.

            Node* node1Next = node1->next;
            // Saves node1's next node.

            Node* node2Prev = node2->prev;
            // Saves node2's previous node.

            Node* node2Next = node2->next;
            // Saves node2's next node.

            if (node1Prev != NULL)
            {
                // Checks whether node1 has a previous node.

                node1Prev->next = node2;
                // Connects node1's previous node to node2.
            }
            else
            {
                head = node2;
                // If node1 was first, node2 becomes head.
            }

            if (node1Next != NULL)
            {
                // Checks whether node1 has a next node.

                node1Next->prev = node2;
                // Connects node1's next node back to node2.
            }

            if (node2Prev != NULL)
            {
                // Checks whether node2 has a previous node.

                node2Prev->next = node1;
                // Connects node2's previous node to node1.
            }
            else
            {
                head = node1;
                // If node2 was first, node1 becomes head.
            }

            if (node2Next != NULL)
            {
                // Checks whether node2 has a next node.

                node2Next->prev = node1;
                // Connects node2's next node back to node1.
            }

            node1->prev = node2Prev;
            // Gives node1 node2's old previous connection.

            node1->next = node2Next;
            // Gives node1 node2's old next connection.

            node2->prev = node1Prev;
            // Gives node2 node1's old previous connection.

            node2->next = node1Next;
            // Gives node2 node1's old next connection.
        }

        cout << "Nodes swapped successfully." << endl;
        // Displays successful swap message.
    }
};

// Main function.
int main()
{
    DoublyLinkedList list;
    // Creates a doubly linked list object.

    list.insert(10);
    // Inserts 10.

    list.insert(20);
    // Inserts 20.

    list.insert(30);
    // Inserts 30.

    list.insert(40);
    // Inserts 40.

    list.insert(50);
    // Inserts 50.

    cout << "Original List: ";
    // Displays message.

    list.display();
    // Displays original list.

    int value1, value2;
    // Creates two integer variables.

    cout << "Enter first value: ";
    // Asks user for first value.

    cin >> value1;
    // Takes first value from user.

    cout << "Enter second value: ";
    // Asks user for second value.

    cin >> value2;
    // Takes second value from user.

    list.swapNodes(value1, value2);
    // Searches and swaps the two nodes.

    cout << "List after swapping nodes: ";
    // Displays message.

    list.display();
    // Displays the modified list.

    return 0;
    // Ends the program.
}
