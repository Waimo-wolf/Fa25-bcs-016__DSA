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

    int front() const {
        if (isEmpty()) throw underflow_error("Queue is empty");
        return frontNode->data;
    }

    bool isEmpty() const { return frontNode == NULL; }
    int size() const { return count; }
};

// Selection sort using queue operations. On each pass, find the maximum
// in the unsorted prefix and place it immediately before the sorted suffix.
template <typename QueueType>
void selectionSortQueue(QueueType& q) {
    int n = q.size();

    for (int pass = 0; pass < n - 1; ++pass) {
        int unsortedCount = n - pass;
        QueueType temp;
        int maxValue = 0;

        // Copy the queue into temp, preserving its order.
        for (int i = 0; i < n; ++i) {
            int value = q.dequeue();
            if (i == 0 || (i < unsortedCount && value > maxValue)) {
                maxValue = value;
            }
            temp.enqueue(value);
        }

        // Rebuild the unsorted prefix, skipping the first maximum.
        bool removed = false;
        for (int i = 0; i < unsortedCount; ++i) {
            int value = temp.dequeue();
            if (value == maxValue && !removed) {
                removed = true;
            } else {
                q.enqueue(value);
            }
        }

        // Place the maximum after the remaining unsorted values.
        q.enqueue(maxValue);

        // Keep the previously sorted suffix after this pass's maximum.
        while (!temp.isEmpty()) {
            q.enqueue(temp.dequeue());
        }
    }
}

int main() {
    try {
        cout << "Selection sort using array-based queue:\n";
        ArrayQueue arrayQueue;
        int values1[] = {42, 16, 27, 8, 19};
        for (int i = 0; i < 5; ++i) arrayQueue.enqueue(values1[i]);
        selectionSortQueue(arrayQueue);
        while (!arrayQueue.isEmpty()) cout << arrayQueue.dequeue() << " ";
        cout << "\n\n";

        cout << "Selection sort using linked-list-based queue:\n";
        LLQueue linkedQueue;
        int values2[] = {63, 5, 31, 14, 22};
        for (int i = 0; i < 5; ++i) linkedQueue.enqueue(values2[i]);
        selectionSortQueue(linkedQueue);
        while (!linkedQueue.isEmpty()) cout << linkedQueue.dequeue() << " ";
        cout << '\n';
    } catch (const exception& ex) {
        cerr << "Error: " << ex.what() << '\n';
        return 1;
    }
    return 0;
}

