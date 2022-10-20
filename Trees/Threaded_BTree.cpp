#include <iostream>
using namespace std;

class ThBT
{
    int data;
    ThBT *left;
    ThBT *right;
    int rThread, lThread;

public:
    // Default Constructor
    ThBT()
    {
        this->data = 0;
        this->left = NULL;
        this->right = NULL;
        this->rThread = 1;
        this->lThread = 1;
    }
    // Parameterized Constructor
    ThBT(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
        this->rThread = 1;
        this->lThread = 1;
    }
    ThBT *Insert(ThBT *, int);
    ThBT *InorderSuccessor(ThBT *);
    void Inorder(ThBT *);
};
ThBT *ThBT::Insert(ThBT *root, int val)
{
    ThBT *temp = root;
    ThBT *par = NULL;

    while (temp != NULL)
    {

        if (temp->data == val)
        {
            cout << "Node already exists\n";
            return root;
        }
        par = temp;

        // Traverse Left:
        if (val < temp->data)
        {
            if (temp->lThread == 0)
                temp = temp->left;
            else
                break;
        }
        // Traverse Right:
        else
        {
            if (temp->rThread == 0)
                temp = temp->right;
            else
                break;
        }
    }
    ThBT *curr = new ThBT(val);
    if (par == NULL)
    {
        root = curr;
    }
    else if (val < par->data)
    {
        curr->left = par->left;
        curr->right = par;
        par->lThread = 0;
        par->left = curr;
    }
    else
    {
        curr->left = par;
        curr->right = par->right;
        par->rThread = 0;
        par->right = curr;
    }
    return root;
}

ThBT *ThBT::InorderSuccessor(ThBT *ptr)
{
    if (ptr == NULL)
        return NULL;
    if (ptr->rThread == 1)
        return ptr->right;
    // Else Return leftmost element of right Subtree:
    ptr = ptr->right;
    while (ptr->lThread == 0)
        ptr = ptr->left;
    return ptr;
}

void ThBT::Inorder(ThBT *root)
{
    if (root == NULL)
        return;
    while (root->lThread != 1)
        root = root->left;
    while (root != NULL)
    {
        cout << root->data << " ";
        root = InorderSuccessor(root);
    }
    cout << endl;
}
int main()
{
    ThBT tree1, *root1 = NULL;
    int ch, n;
    do
    {
        cout << "\n";
        cout << "Enter 0 to exit.\n";
        cout << "Enter 1 to Insert a Node.\n";
        cout << "Enter 2 to Display in INORDER Format.\n";
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
            cout << "INORDER FORMAT:\n";
            tree1.Inorder(root1);
            break;
        default:
            cout << "WRONG INPUT!\n";
            break;
        }
    } while (ch != 0);
    return 0;
}