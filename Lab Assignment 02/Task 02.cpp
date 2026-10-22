#include <iostream>
#include <stdexcept>
using namespace std;

// Array-based circular queue
class ArrayQueue {
private:
    int* arr;
    int capacity;
    int frontIndex;
    int rearIndex;
    int count;

public:
    ArrayQueue(int cap = 100)
        : capacity(cap), frontIndex(0), rearIndex(-1), count(0) {
        if (capacity <= 0) throw invalid_argument("Queue capacity must be positive");
        arr = new int[capacity];
    }

    ~ArrayQueue() { delete[] arr; }

    ArrayQueue(const ArrayQueue&);
    ArrayQueue& operator=(const ArrayQueue&);

    void enqueue(int value) {
        if (count == capacity) throw overflow_error("Queue overflow");
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = value;
        ++count;
    }

    int dequeue() {
        if (isEmpty()) throw underflow_error("Queue underflow");
        int value = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        --count;
        return value;
    }

    int front() const {
        if (isEmpty()) throw underflow_error("Queue is empty");
        return arr[frontIndex];
    }

    bool isEmpty() const { return count == 0; }
    int size() const { return count; }
};

// Linked-list-based queue
class LLQueue {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) { data = value; next = NULL; }
    };
    Node* frontNode;
    Node* rearNode;
    int count;

public:
    LLQueue() : frontNode(NULL), rearNode(NULL), count(0) {}

    ~LLQueue() {
        while (!isEmpty()) dequeue();
    }

    LLQueue(const LLQueue&);
    LLQueue& operator=(const LLQueue&);

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rearNode == NULL) {
            frontNode = rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
        ++count;
    }

    int dequeue() {
        if (isEmpty()) throw underflow_error("Queue underflow");
        Node* temp = frontNode;
        int value = temp->data;
        frontNode = frontNode->next;
        if (frontNode == NULL) rearNode = NULL;
        delete temp;
        --count;
        return value;
    }

    int front() const {
        if (isEmpty()) throw underflow_error("Queue is empty");
        return frontNode->data;
    }

    bool isEmpty() const { return frontNode == NULL; }
    int size() const { return count; }
};

// Stack implemented using two queues.
// q1 always keeps the newest item at its front.
template <typename QueueType>
class StackUsingTwoQueues {
private:
    QueueType q1;
    QueueType q2;

public:
    void push(int value) {
        q2.enqueue(value);

        while (!q1.isEmpty()) {
            q2.enqueue(q1.dequeue());
        }

        while (!q2.isEmpty()) {
            q1.enqueue(q2.dequeue());
        }
    }

    int pop() {
        if (q1.isEmpty()) throw underflow_error("Stack underflow");
        return q1.dequeue();
    }

    int top() const {
        if (q1.isEmpty()) throw underflow_error("Stack is empty");
        return q1.front();
    }

    bool isEmpty() const { return q1.isEmpty(); }
};

int main() {
    try {
        cout << "Stack using array-based queues:\n";
        StackUsingTwoQueues<ArrayQueue> arrayStack;
        arrayStack.push(12);
        arrayStack.push(24);
        arrayStack.push(36);
        cout << "Popped: " << arrayStack.pop() << " (Expected: 36)\n";
        cout << "Top: " << arrayStack.top() << " (Expected: 24)\n\n";

        cout << "Stack using linked-list-based queues:\n";
        StackUsingTwoQueues<LLQueue> linkedStack;
        linkedStack.push(120);
        linkedStack.push(240);
        linkedStack.push(360);
        cout << "Popped: " << linkedStack.pop() << " (Expected: 360)\n";
        cout << "Top: " << linkedStack.top() << " (Expected: 240)\n";
    } catch (const exception& ex) {
        cerr << "Error: " << ex.what() << '\n';
        return 1;
    }
    return 0;
}

