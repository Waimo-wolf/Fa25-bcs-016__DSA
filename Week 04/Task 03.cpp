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

void deleteEvenPositions(Node*& head)
{
    Node* current = head;

    while (current != NULL && current->next != NULL)
    {
        Node* temp = current->next;

        current->next = temp->next;

        delete temp;

        current = current->next;
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
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);
    insert(head, 50);
    insert(head, 60);

    cout << "Original List: ";
    display(head);

    deleteEvenPositions(head);

    cout << "After deleting even positioned nodes: ";
    display(head);

    return 0;
}
