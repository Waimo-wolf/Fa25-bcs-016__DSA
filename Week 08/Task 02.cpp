#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

// Find height
int height(Node* root)
{
    if (root == NULL)
        return 0;

    return root->height;
}

// Find maximum value
int maxValue(int a, int b)
{
    if (a > b)
        return a;

    return b;
}

// Calculate balance factor
int getBalance(Node* root)
{
    if (root == NULL)
        return 0;

    return height(root->left) - height(root->right);
}

// Right rotation
Node* rightRotate(Node* y)
{
    Node* x = y->left;
    Node* temp = x->right;

    x->right = y;
    y->left = temp;

    y->height = 1 + maxValue(height(y->left),
                             height(y->right));

    x->height = 1 + maxValue(height(x->left),
                             height(x->right));

    return x;
}

// Left rotation
Node* leftRotate(Node* x)
{
    Node* y = x->right;
    Node* temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = 1 + maxValue(height(x->left),
                             height(x->right));

    y->height = 1 + maxValue(height(y->left),
                             height(y->right));

    return y;
}

// Insert into AVL tree
Node* insert(Node* root, int value)
{
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);

    else if (value > root->data)
        root->right = insert(root->right, value);

    else
        return root;

    root->height = 1 + maxValue(height(root->left),
                                height(root->right));

    int balance = getBalance(root);

    // LL Case
    if (balance > 1 && value < root->left->data)
        return rightRotate(root);

    // RR Case
    if (balance < -1 && value > root->right->data)
        return leftRotate(root);

    // LR Case
    if (balance > 1 && value > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL Case
    if (balance < -1 && value < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Level order traversal
void levelOrder(Node* root)
{
    if (root == NULL)
        return;

    queue<Node*> q;

    q.push(root);

    while (!q.empty())
    {
        Node* current = q.front();

        q.pop();

        cout << current->data << " ";

        if (current->left != NULL)
            q.push(current->left);

        if (current->right != NULL)
            q.push(current->right);
    }
}

int main()
{
    Node* root = NULL;

    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> value;

        root = insert(root, value);
    }

    cout << "\nLevel Order Traversal: ";
    levelOrder(root);

    return 0;
}
