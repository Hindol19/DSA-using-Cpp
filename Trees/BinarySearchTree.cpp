#include <iostream>
using namespace std;

class BST
{
    int data;
    BST *left;
    BST *right;

public:
    // Default Constructor
    BST()
    {
        this->data = 0;
        this->left = NULL;
        this->right = NULL;
    }
    // Parameterized Constructor
    BST(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
    BST *Insert(BST *, int);
    BST *Delete(BST *, int);
    BST *minValueNode(BST *);
    void Inorder(BST *);
    void Preorder(BST *);
    void Postorder(BST *);
    int Search(BST *, int);
};
BST *BST::Insert(BST *root, int val)
{
    if (root == NULL)
        return new BST(val);
    if (val > root->data)
        root->right = Insert(root->right, val);
    if (val < root->data)
        root->left = Insert(root->left, val);
    return root;
}
void BST::Inorder(BST *root)
{
    if (root == NULL)
        return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}
void BST::Preorder(BST *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}
void BST::Postorder(BST *root)
{
    if (root == NULL)
        return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}
int BST::Search(BST *root, int val)
{
    if (root == NULL)
    {
        return 0;
    }
    if (val == root->data)
    {
        return 1;
    }
    if (val < root->data)
        Search(root->left, val);
    if (val > root->data)
        Search(root->right, val);
}
BST *BST::minValueNode(BST *root)
{
    BST *curr = root;
    while (curr && curr->left != NULL)
        curr = curr->left;
    return curr;
}
BST *BST::Delete(BST *root, int val)
{
    if (root == NULL)
        return root;
    if (val < root->data)
        root->left = Delete(root->left, val);
    else if (val > root->data)
        root->right = Delete(root->right, val);
    else
    {
        if (root->right == NULL && root->left == NULL)
            return NULL;
        else if (root->left == NULL)
        {
            BST *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            BST *temp = root->left;
            free(root);
            return temp;
        }
        BST *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = Delete(root->right, root->data);
    }
    return root;
}
int main()
{
    BST tree1, *root1 = NULL;
    int ch, n;
    do
    {
        cout << "\n";
        cout << "Enter 0 to exit.\n";
        cout << "Enter 1 to Insert a Node.\n";
        cout << "Enter 2 to Delete a Node.\n";
        cout << "Enter 3 to Search For a Node.\n";
        cout << "Enter 4 to Display in INORDER Format.\n";
        cout << "Enter 5 to Display in PREORDER Format.\n";
        cout << "Enter 6 to Display in POSTORDER Format.\n";
        cout << "Enter Your Choice.\n\n";

        cin >> ch;
        switch (ch)
        {
        case 0:
            cout << "Exited";
            break;
        case 1:
            cout << "Enter item to be inserted: ";
            cin >> n;
            cout << "\n";
            root1 = tree1.Insert(root1, n);
            cout << "Item Inserted!\n";
            break;

        case 2:
            cout << "Enter item to be Deleted: ";
            cin >> n;
            cout << "\n";
            if (tree1.Search(root1, n) == 1)
            {
                tree1.Delete(root1, n);
                cout << "Item Deleted!\n";
            }
            else
                cout << "ITEM IS NOT PRESENT\n";
            break;
        case 3:
            cout << "Enter item to be Searched: ";
            cin >> n;
            cout << "\n";
            if (tree1.Search(root1, n) == 1)
                cout << "ITEM IS PRESENT\n";
            else
                cout << "ITEM IS NOT PRESENT\n";
            break;
        case 4:
            cout << "INORDER FORMAT:\n";
            tree1.Inorder(root1);
            break;
        case 5:
            cout << "PREORDER FORMAT:\n";
            tree1.Preorder(root1);
            break;
        case 6:
            cout << "POSTORDER FORMAT:\n";
            tree1.Postorder(root1);
            break;
        default:
            cout << "WRONG INPUT!\n";
            break;
        }
    } while (ch != 0);
    return 0;
}