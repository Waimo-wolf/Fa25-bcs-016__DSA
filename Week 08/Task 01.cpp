#include <iostream>
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

// Find the height of a node
int height(Node* root)
{
    if (root == NULL)
        return 0;

    return root->height;
}

// Find the maximum of two values
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

// Right rotation (LL case)
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

// Left rotation (RR case)
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

// Insert a node into AVL Tree
Node* insert(Node* root, int value)
{
    // Normal BST insertion
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);

    else if (value > root->data)
        root->right = insert(root->right, value);

    else
        return root;

    // Update height
    root->height = 1 + maxValue(height(root->left),
                                height(root->right));

    // Calculate balance factor
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

// Display tree using inorder traversal
void display(Node* root)
{
    if (root == NULL)
        return;

    display(root->left);
    cout << root->data << " ";
    display(root->right);
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

    cout << "\nAVL Tree (Inorder Traversal): ";
    display(root);

    return 0;
}
