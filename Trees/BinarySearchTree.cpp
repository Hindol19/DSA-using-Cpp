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
    int countNodes(BST *);
    int countIntNodes(BST *);
    int countExtNodes(BST *);
    int height(BST *);
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
int BST::countNodes(BST *root) {
    if(root==NULL)
        return 0;
    else
        return(countNodes(root->left)+countNodes(root->right)+1);
}
int BST::countIntNodes(BST *root) {
    if(root==NULL)
        return 0;
    else if(root->left==NULL && root->right==NULL)
        return 0;
    else
        return(countIntNodes(root->left)+countIntNodes(root->right)+1);
}
int BST::countExtNodes(BST *root) {
    if(root==NULL)
        return 0;
    else if(root->left==NULL && root->right==NULL)
        return 1;
    else
        return(countExtNodes(root->left)+countExtNodes(root->right));
}
int BST::height(BST *root) {
    if(root==NULL)
        return 0;
    else
        return(max(height(root->left),height(root->right))+1);
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
        cout << "Enter 7 to count number of nodes.\n";
        cout << "Enter 8 to count number of internal nodes.\n";
        cout << "Enter 9 to count number of external nodes.\n";
        cout << "Enter 10 to calculate height of tree.\n";
        cout << "Enter Your Choice = ";

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
            cout<<endl;
            break;
        case 5:
            cout << "PREORDER FORMAT:\n";
            tree1.Preorder(root1);
            cout<<endl;
            break;
        case 6:
            cout << "POSTORDER FORMAT:\n";
            tree1.Postorder(root1);
            cout<<endl;
            break;
        case 7:
            cout << "No. of Nodes = "<<tree1.countNodes(root1)<<endl;
            break;
        case 8:
            cout << "No. of Internal Nodes = "<<tree1.countIntNodes(root1)<<endl;
            break;
        case 9:
            cout << "No. of External Nodes = "<<tree1.countExtNodes(root1)<<endl;
            break;
        case 10:
            cout << "Height of tree = "<<tree1.height(root1)<<endl;
            break;
        default:
            cout << "WRONG INPUT!\n";
            break;
        }
    } while (ch != 0);
    return 0;
}