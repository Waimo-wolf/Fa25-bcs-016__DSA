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
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Find the smallest node in a subtree
Node* findMin(Node* root)
{
    while (root != NULL && root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

// Delete a node from BST
Node* deleteNode(Node* root, int value)
{
    if (root == NULL)
        return NULL;

    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        // Case 1: Node has no children
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // Case 2: Node has only a right child
        else if (root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 2: Node has only a left child
        else if (root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Node has both children
        else
        {
            Node* temp = findMin(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

// Display BST using inorder traversal
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

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Original BST: ";
    display(root);

    int value;

    cout << "\nEnter value to delete: ";
    cin >> value;

    root = deleteNode(root, value);

    cout << "BST after deletion: ";
    display(root);

    return 0;
}
