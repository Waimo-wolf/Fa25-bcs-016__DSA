#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Insert a node into BST
Node* insert(Node* root, int value)
{
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Print leaf nodes
void printLeafNodes(Node* root)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
        return;
    }

    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

// Count leaf nodes
int countLeafNodes(Node* root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeafNodes(root->left)
         + countLeafNodes(root->right);
}

int main()
{
    Node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Leaf nodes: ";
    printLeafNodes(root);

    cout << "\nTotal leaf nodes: ";
    cout << countLeafNodes(root);

    return 0;
}
