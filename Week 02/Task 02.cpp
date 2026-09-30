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

    // Merge two lists into a third new list
    LinkedList merge(LinkedList& list2)
    {
        LinkedList list3;

        Node* temp = head;

        while (temp != NULL)
        {
            list3.insert(temp->data);
            temp = temp->next;
        }

        temp = list2.head;

        while (temp != NULL)
        {
            list3.insert(temp->data);
            temp = temp->next;
        }

        return list3;
    }
};

int main()
{
    LinkedList list1;
    LinkedList list2;

    // First list
    list1.insert(10);
    list1.insert(20);
    list1.insert(30);

    // Second list
    list2.insert(40);
    list2.insert(50);
    list2.insert(60);

    cout << "First Linked List: ";
    list1.display();

    cout << "Second Linked List: ";
    list2.display();

    // Create third list
    LinkedList list3 = list1.merge(list2);

    cout << "Third Linked List after Merging: ";
    list3.display();

    return 0;
}
