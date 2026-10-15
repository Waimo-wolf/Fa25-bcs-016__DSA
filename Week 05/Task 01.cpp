#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    char data;
    Node* next;

    Node(char value)
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

    void push(char value)
    {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    char pop()
    {
        if (top == NULL)
            return '\0';

        Node* temp = top;
        char value = top->data;

        top = top->next;

        delete temp;

        return value;
    }

    char peek()
    {
        if (top == NULL)
            return '\0';

        return top->data;
    }

    bool isEmpty()
    {
        return top == NULL;
    }
};

bool isMatching(char opening, char closing)
{
    if (opening == '(' && closing == ')')
        return true;

    if (opening == '[' && closing == ']')
        return true;

    if (opening == '{' && closing == '}')
        return true;

    return false;
}

bool isBalanced(string expression)
{
    Stack s;

    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];

        if (ch == '(' || ch == '[' || ch == '{')
        {
            s.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (s.isEmpty())
                return false;

            char opening = s.pop();

            if (!isMatching(opening, ch))
                return false;
        }
    }

    return s.isEmpty();
}

int main()
{
    string expression;

    cout << "Enter brackets: ";
    cin >> expression;

    if (isBalanced(expression))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;

    return 0;
}
