#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int item)
    {
        this->data = item;
        this->next = NULL;
    }
};
class CLL
{
public:
    Node *last;
    CLL()
    {
        last = NULL;
    }
    void insertBeg(int);
    void insertEnd(int);
    void insertAfterNode(int, int);
    void deleteNode(int);
    void Display();
};

// Insertion Functions:
void CLL::insertBeg(int item)
{
    Node *curr = new Node(item);
    if (last == NULL)
    {
        last = curr;
        curr->next = last;
        return;
    }
    curr->next = last->next;
    last->next = curr;
}
void CLL::insertEnd(int item)
{
    Node *curr = new Node(item);
    if (last == NULL)
    {
        last = curr;
        curr->next = last;
        return;
    }
    curr->next = last->next;
    last->next = curr;
    last = curr;
}

void CLL::insertAfterNode(int item, int x)
{
    Node *curr = new Node(item);
    if (last == NULL)
    {
        last = curr;
        curr->next = last;
        return;
    }
    if (last->data == x)
    {
        insertEnd(item);
        return;
    }
    Node *temp1 = last;
    temp1 = temp1->next;
    Node *temp2 = last;
    do
    {
        if (temp1->data == x)
        {
            curr->next = temp1->next;
            temp1->next = curr;
            return;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    } while (temp2 != last);
    cout << "Element Not Found" << endl;
}
// Deletion Functions:
void CLL::deleteNode(int x)
{
    if (last == NULL)
    {
        cout << "List is Empty! Nothing to Delete!" << endl;
        return;
    }
    Node *temp1 = last;
    temp1 = temp1->next;
    Node *temp2 = last;
    do
    {
        if (temp1->data == x)
        {
            if (temp1 == last)
            {
                last = temp2;
            }
            temp2->next = temp1->next;
            free(temp1);
            cout << x << " is Deleted" << endl;
            return;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    } while (temp2 != last);
    cout << "Element Not Found" << endl;
}

// Display:
void CLL::Display()
{
    if (last == NULL)
    {
        cout << "List is Empty!" << endl;
        return;
    }
    cout << "The Linked List is:" << endl;
    Node *temp = last;
    temp = temp->next;
    while (temp != last)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << " ";
    cout << endl;
}
int main()
{
    CLL li;
    int ch, n, res, ind;
    do
    {
        cout << "\n";
        cout << "Enter 0 to exit.\n";
        cout << "Enter 1 to Insert At Beginning.\n";
        cout << "Enter 2 to Insert At End.\n";
        cout << "Enter 3 to Insert After Node.\n";
        cout << "Enter 4 to Delete Node.\n";
        cout << "Enter 5 to Display.\n";
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
            li.insertBeg(n);
            cout << "Item Inserted!\n";
            break;
        case 2:
            cout << "Enter item to be inserted: ";
            cin >> n;
            cout << "\n";
            li.insertEnd(n);
            cout << "Item Inserted!\n";
            break;
        case 3:
            cout << "Enter item to be inserted: ";
            cin >> n;
            cout << "Enter Node after which item is to be inserted: ";
            cin >> ind;
            cout << "\n";
            li.insertAfterNode(n, ind);
            cout << "Item Inserted!\n";
            break;
        case 4:
            cout << "Enter item to be deleted: ";
            cin >> n;
            cout << "\n";
            li.deleteNode(n);
            break;
        case 5:
            li.Display();
            break;
        default:
            cout << "WRONG INPUT!\n";
            break;
        }
    } while (ch != 0);
    return 0;
}