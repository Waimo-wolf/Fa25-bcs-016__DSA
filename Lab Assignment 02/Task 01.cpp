#include <iostream>
#include <stdexcept>
using namespace std;

// Array-based stack
class ArrayStack {
private:
    int* arr;
    int capacity;
    int topIndex;

public:
    ArrayStack(int cap = 100) : capacity(cap), topIndex(-1) {
        if (capacity <= 0) throw invalid_argument("Stack capacity must be positive");
        arr = new int[capacity];
    }

    ~ArrayStack() { delete[] arr; }

    // Prevent accidental shallow copies of the dynamic array
    ArrayStack(const ArrayStack&);
    ArrayStack& operator=(const ArrayStack&);

    void push(int value) {
        if (topIndex == capacity - 1) throw overflow_error("Stack overflow");
        arr[++topIndex] = value;
    }

    int pop() {
        if (isEmpty()) throw underflow_error("Stack underflow");
        return arr[topIndex--];
    }

    int peek() const {
        if (isEmpty()) throw underflow_error("Stack is empty");
        return arr[topIndex];
    }

    bool isEmpty() const { return topIndex == -1; }
};

// Linked-list-based stack
class LLStack {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) { data = value; next = NULL; }
    };
    Node* topNode;

public:
    LLStack() : topNode(NULL) {}

    ~LLStack() {
        while (!isEmpty()) pop();
    }

    LLStack(const LLStack&);
    LLStack& operator=(const LLStack&);

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
    }

    int pop() {
        if (isEmpty()) throw underflow_error("Stack underflow");
        Node* temp = topNode;
        int value = temp->data;
        topNode = topNode->next;
        delete temp;
        return value;
    }

    int peek() const {
        if (isEmpty()) throw underflow_error("Stack is empty");
        return topNode->data;
    }

    bool isEmpty() const { return topNode == NULL; }
};

// Queue implemented using two stacks
template <typename StackType>
class QueueUsingTwoStacks {
private:
    StackType inStack;
    StackType outStack;

    void shiftStacks() {
        if (outStack.isEmpty()) {
            while (!inStack.isEmpty()) {
                outStack.push(inStack.pop());
            }
        }
    }

public:
    void enqueue(int value) { inStack.push(value); }

    int dequeue() {
        shiftStacks();
        if (outStack.isEmpty()) throw underflow_error("Queue underflow");
        return outStack.pop();
    }

    int front() {
        shiftStacks();
        if (outStack.isEmpty()) throw underflow_error("Queue is empty");
        return outStack.peek();
    }

    bool isEmpty() const {
        return inStack.isEmpty() && outStack.isEmpty();
    }
};

int main() {
    try {
        cout << "Queue using array-based stacks:\n";
        QueueUsingTwoStacks<ArrayStack> arrayQueue;
        arrayQueue.enqueue(15);
        arrayQueue.enqueue(25);
        arrayQueue.enqueue(35);
        cout << "Dequeued: " << arrayQueue.dequeue() << " (Expected: 15)\n";
        cout << "Front: " << arrayQueue.front() << " (Expected: 25)\n\n";

        cout << "Queue using linked-list-based stacks:\n";
        QueueUsingTwoStacks<LLStack> linkedQueue;
        linkedQueue.enqueue(110);
        linkedQueue.enqueue(220);
        linkedQueue.enqueue(330);
        cout << "Dequeued: " << linkedQueue.dequeue() << " (Expected: 110)\n";
        cout << "Front: " << linkedQueue.front() << " (Expected: 220)\n";
    } catch (const exception& ex) {
        cerr << "Error: " << ex.what() << '\n';
        return 1;
    }
    return 0;
}

