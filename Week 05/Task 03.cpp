#include <iostream>
#include <string>
#include <cctype>
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

class Stack
{
private:
    Node* top;

public:
    Stack()
    {
        top = NULL;
    }

    void push(int value)
    {
        Node* newNode = new Node(value);

        newNode->next = top;
        top = newNode;
    }

    int pop()
    {
        if (top == NULL)
            return 0;

        Node* temp = top;
        int value = top->data;

        top = top->next;

        delete temp;

        return value;
    }

    bool isEmpty()
    {
        return top == NULL;
    }
};

int getValue(char variable)
{
    int value;

    cout << "Enter value of " << variable << ": ";
    cin >> value;

    return value;
}

int calculate(int first, int second, char op)
{
    if (op == '+')
        return first + second;

    if (op == '-')
        return first - second;

    if (op == '*')
        return first * second;

    if (op == '/')
        return first / second;

    if (op == '%')
        return first % second;

    return 0;
}

int evaluatePostfix(string postfix)
{
    Stack s;

    for (int i = 0; i < postfix.length(); i++)
    {
        char ch = postfix[i];

        if (isdigit(ch))
        {
            s.push(ch - '0');
        }
        else if (isalpha(ch))
        {
            int value = getValue(ch);
            s.push(value);
        }
        else
        {
            int second = s.pop();
            int first = s.pop();

            int result = calculate(first, second, ch);

            s.push(result);
        }
    }

    return s.pop();
}

int main()
{
    string postfix;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);

    cout << "Result = " << result << endl;

    return 0;
}
