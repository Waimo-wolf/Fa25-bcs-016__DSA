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

void insert(Node*& head, int value)
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

void deleteEvenOdd(Node*& head, bool deleteEven)
{
    while (head != NULL &&
           ((deleteEven && head->data % 2 == 0) ||
            (!deleteEven && head->data % 2 != 0)))
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    Node* current = head;

    while (current != NULL && current->next != NULL)
    {
        if ((deleteEven && current->next->data % 2 == 0) ||
            (!deleteEven && current->next->data % 2 != 0))
        {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        else
        {
            current = current->next;
        }
    }
}

void display(Node* head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    Node* head = NULL;

    insert(head, 10);
    insert(head, 15);
    insert(head, 20);
    insert(head, 25);
    insert(head, 30);
    insert(head, 35);

    cout << "Original List: ";
    display(head);

    deleteEvenOdd(head, true);

    cout << "After deleting even values: ";
    display(head);

    return 0;
}
