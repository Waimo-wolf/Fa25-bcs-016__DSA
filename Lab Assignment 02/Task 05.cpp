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
    ~LLStack() { while (!isEmpty()) pop(); }
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

// Sorts stack so popping values returns them in ascending order.
template <typename StackType>
void insertionSortStack(StackType& inputStack) {
    StackType tempStack;

    while (!inputStack.isEmpty()) {
        int current = inputStack.pop();

        // Move larger values back to inputStack until the correct place is found.
        while (!tempStack.isEmpty() && tempStack.peek() > current) {
            inputStack.push(tempStack.pop());
        }

        tempStack.push(current);
    }

    // Move sorted values back. The smallest value will be at the top.
    while (!tempStack.isEmpty()) {
        inputStack.push(tempStack.pop());
    }
}

int main() {
    try {
        cout << "Insertion sort using array-based stack (popped top to bottom):\n";
        ArrayStack arrayStack;
        int values1[] = {45, 7, 28, 81, 66, 19};
        for (int i = 0; i < 6; ++i) arrayStack.push(values1[i]);
        insertionSortStack(arrayStack);
        while (!arrayStack.isEmpty()) cout << arrayStack.pop() << " ";
        cout << "\n\n";

        cout << "Insertion sort using linked-list-based stack (popped top to bottom):\n";
        LLStack linkedStack;
        int values2[] = {54, 21, 76, 11, 32};
        for (int i = 0; i < 5; ++i) linkedStack.push(values2[i]);
        insertionSortStack(linkedStack);
        while (!linkedStack.isEmpty()) cout << linkedStack.pop() << " ";
        cout << '\n';
    } catch (const exception& ex) {
        cerr << "Error: " << ex.what() << '\n';
        return 1;
    }
    return 0;
}

