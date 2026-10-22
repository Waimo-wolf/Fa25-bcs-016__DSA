#include <iostream>
#include <stdexcept>
using namespace std;

// Array-based circular queue
class ArrayQueue {
private:
    int* arr;
    int capacity, frontIndex, rearIndex, count;

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
    ~LLQueue() { while (!isEmpty()) dequeue(); }
    LLQueue(const LLQueue&);
    LLQueue& operator=(const LLQueue&);

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rearNode == NULL) frontNode = rearNode = newNode;
        else {
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

    bool isEmpty() const { return frontNode == NULL; }
    int size() const { return count; }
};

// Bubble sort using queue operations. Each pass bubbles the largest
// value in the unsorted prefix to the end of that prefix.
template <typename QueueType>
void bubbleSortQueue(QueueType& q) {
    int n = q.size();

    for (int pass = 0; pass < n - 1; ++pass) {
        int unsortedCount = n - pass;
        QueueType temp;

        // Move all elements to a temporary queue without changing their order.
        for (int i = 0; i < n; ++i) {
            temp.enqueue(q.dequeue());
        }

        // Bubble through only the unsorted prefix.
        int current = temp.dequeue();
        for (int j = 0; j < unsortedCount - 1; ++j) {
            int nextValue = temp.dequeue();

            if (current > nextValue) {
                q.enqueue(nextValue);
            } else {
                q.enqueue(current);
                current = nextValue;
            }
        }

        // The largest value in this pass goes to the end of the unsorted prefix.
        q.enqueue(current);

        // Append the already-sorted suffix.
        while (!temp.isEmpty()) {
            q.enqueue(temp.dequeue());
        }
    }
}

int main() {
    try {
        cout << "Bubble sort using array-based queue:\n";
        ArrayQueue arrayQueue;
        int values1[] = {71, 43, 18, 29, 6};
        for (int i = 0; i < 5; ++i) arrayQueue.enqueue(values1[i]);
        bubbleSortQueue(arrayQueue);
        while (!arrayQueue.isEmpty()) cout << arrayQueue.dequeue() << " ";
        cout << "\n\n";

        cout << "Bubble sort using linked-list-based queue:\n";
        LLQueue linkedQueue;
        int values2[] = {9, 3, 7, 1, 6};
        for (int i = 0; i < 5; ++i) linkedQueue.enqueue(values2[i]);
        bubbleSortQueue(linkedQueue);
        while (!linkedQueue.isEmpty()) cout << linkedQueue.dequeue() << " ";
        cout << '\n';
    } catch (const exception& ex) {
        cerr << "Error: " << ex.what() << '\n';
        return 1;
    }
    return 0;
}

