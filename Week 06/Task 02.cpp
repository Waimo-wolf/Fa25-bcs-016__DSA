#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;

    Node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

class Deque
{
private:
    Node* front;
    Node* rear;

public:
    // Constructor
    Deque()
    {
        front = NULL;
        rear = NULL;
    }

    // Check whether deque is empty
    bool isEmpty()
    {
        return front == NULL;
    }

    // Insert element at front
    void insertFront(int value)
    {
        Node* newNode = new Node(value);

        if (isEmpty())
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }

        cout << value << " inserted at front." << endl;
    }

    // Insert element at rear
    void insertRear(int value)
    {
        Node* newNode = new Node(value);

        if (isEmpty())
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }

        cout << value << " inserted at rear." << endl;
    }

    // Delete element from front
    void deleteFront()
    {
        if (isEmpty())
        {
            cout << "Deque is empty!" << endl;
            return;
        }

        Node* temp = front;

        cout << "Deleted from front: " << temp->data << endl;

        front = front->next;

        if (front == NULL)
        {
            rear = NULL;
        }
        else
        {
            front->prev = NULL;
        }

        delete temp;
    }

    // Delete element from rear
    void deleteRear()
    {
        if (isEmpty())
        {
            cout << "Deque is empty!" << endl;
            return;
        }

        Node* temp = rear;

        cout << "Deleted from rear: " << temp->data << endl;

        rear = rear->prev;

        if (rear == NULL)
        {
            front = NULL;
        }
        else
        {
            rear->next = NULL;
        }

        delete temp;
    }

    // Display front element
    void getFront()
    {
        if (isEmpty())
        {
            cout << "Deque is empty!" << endl;
            return;
        }

        cout << "Front element: " << front->data << endl;
    }

    // Display rear element
    void getRear()
    {
        if (isEmpty())
        {
            cout << "Deque is empty!" << endl;
            return;
        }

        cout << "Rear element: " << rear->data << endl;
    }

    // Display all elements
    void display()
    {
        if (isEmpty())
        {
            cout << "Deque is empty!" << endl;
            return;
        }

        Node* temp = front;

        cout << "Deque: ";

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    // Destructor
    ~Deque()
    {
        while (!isEmpty())
        {
            Node* temp = front;
            front = front->next;
            delete temp;
        }

        rear = NULL;
    }
};

int main()
{
    Deque d;

    d.insertFront(20);
    d.insertFront(10);
    d.insertRear(30);
    d.insertRear(40);

    d.display();

    d.getFront();
    d.getRear();

    d.deleteFront();
    d.display();

    d.deleteRear();
    d.display();

    return 0;
}
