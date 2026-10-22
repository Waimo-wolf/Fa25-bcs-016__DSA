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

// Preorder: Node, Right, Left (NRL)
void preOrder(Node* root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->right);
    preOrder(root->left);
}

// Postorder: Right, Left, Node (RLN)
void postOrder(Node* root)
{
    if (root == NULL)
        return;

    postOrder(root->right);
    postOrder(root->left);
    cout << root->data << " ";
}

// Inorder: Right, Node, Left (RNL)
void inOrder(Node* root)
{
    if (root == NULL)
        return;

    inOrder(root->right);
    cout << root->data << " ";
    inOrder(root->left);
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

    cout << "Preorder (NRL): ";
    preOrder(root);

    cout << "\nPostorder (RLN): ";
    postOrder(root);

    cout << "\nInorder (RNL): ";
    inOrder(root);

    return 0;
}
