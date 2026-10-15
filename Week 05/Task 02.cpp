#include <iostream>
#include <string>
#include <cctype>
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

int priority(char op)
{
    if (op == '^')
        return 3;

    if (op == '*' || op == '/' || op == '%')
        return 2;

    if (op == '+' || op == '-')
        return 1;

    return 0;
}

string infixToPostfix(string infix)
{
    Stack s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        if (isalnum(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
            {
                postfix += s.pop();
            }

            if (!s.isEmpty())
                s.pop();
        }
        else
        {
            while (!s.isEmpty() &&
                   s.peek() != '(' &&
                   priority(s.peek()) >= priority(ch))
            {
                postfix += s.pop();
            }

            s.push(ch);
        }
    }

    while (!s.isEmpty())
    {
        postfix += s.pop();
    }

    return postfix;
}

int main()
{
    string infix;

    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
