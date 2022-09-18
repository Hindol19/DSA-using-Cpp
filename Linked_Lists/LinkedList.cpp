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
class LL
{
public:
    Node *head;
    LL()
    {
        head = NULL;
    }
    void insertBeg(int);
    void insertEnd(int);
    void insertAtIndex(int, int);
    void deleteBeg();
    void deleteEnd();
    void deleteAtIndex(int);
    void Display();
    void DisplayRev(Node *);
};

// Insertion Functions:
void LL::insertBeg(int item)
{
    Node *curr = new Node(item);
    if (head == NULL)
    {
        head = curr;
        return;
    }
    curr->next = head;
    head = curr;
}
void LL::insertEnd(int item)
{
    Node *curr = new Node(item);
    if (head == NULL)
    {
        head = curr;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = curr;
}
void LL::insertAtIndex(int item, int ind)
{
    Node *curr = new Node(item);
    int size = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        size++;
    }
    if (ind == 0)
    {
        insertBeg(item);
        return;
    }
    if (ind == size - 1)
    {
        insertEnd(item);
        return;
    }
    if (head == NULL || ind >= size)
    {
        cout << "Index Not Present" << endl;
        return;
    }
    Node *temp1 = head;
    int i = 0;
    while (i < ind - 1)
    {
        temp1 = temp1->next;
        i++;
    }
    Node *temp2 = temp1->next;
    temp1->next = curr;
    curr->next = temp2;
    cout << "Item Inserted!\n";
}
// Deletion Functions:
void LL::deleteBeg()
{
    if (head == NULL)
    {
        cout << "List is Empty! Nothing to Delete!" << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    free(temp);
    cout << "Item Deleted\n";
}
void LL::deleteEnd()
{
    if (head == NULL)
    {
        cout << "List is Empty! Nothing to Delete!" << endl;
        return;
    }
    if (head->next == NULL)
    {
        cout << "Item Deleted\n";
        head = NULL;
        // free(head);
        return;
    }
    Node *temp = head, *temp2;
    while (temp->next != NULL)
    {
        temp2 = temp;
        temp = temp->next;
    }
    temp2->next = NULL;
    free(temp);
    cout << "Item Deleted\n";
}

void LL::deleteAtIndex(int ind)
{
    int size = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        size++;
    }
    if (ind == 0)
    {
        deleteBeg();
        return;
    }
    if (ind == size - 1)
    {
        deleteEnd();
        return;
    }
    if (head == NULL || ind >= size)
    {
        cout << "Index Not Present" << endl;
        return;
    }
    Node *temp1 = head;
    int i = 0;
    while (i < ind - 1)
    {
        temp1 = temp1->next;
        i++;
    }
    Node *temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}

// Display:
void LL::Display()
{
    if (head == NULL)
    {
        cout << "List is Empty!" << endl;
        return;
    }
    cout << "The Linked List is:" << endl;
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void LL::DisplayRev(Node *head)
{
    if (head == NULL)
        return;
    DisplayRev(head->next);
    cout << head->data << " ";
}
int main()
{
    LL li;
    int ch, n, res, ind;
    do
    {
        cout << "\n";
        cout << "Enter 0 to exit.\n";
        cout << "Enter 1 to Insert At Beginning.\n";
        cout << "Enter 2 to Insert At End.\n";
        cout << "Enter 3 to Insert At Index.\n";
        cout << "Enter 4 to Delete At Beginning.\n";
        cout << "Enter 5 to Delete At End.\n";
        cout << "Enter 6 to Delete At Index.\n";
        cout << "Enter 7 to Display.\n";
        cout << "Enter 8 to Display In Reverse (Normal Method).\n";
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
            cout << "\n";
            cout << "Enter index : ";
            cin >> ind;
            cout << "\n";
            li.insertAtIndex(n, ind);
            break;
        case 4:
            li.deleteBeg();
            break;
        case 5:
            li.deleteEnd();
            break;
        case 6:
            cout << "Enter index : ";
            cin >> ind;
            li.deleteAtIndex(ind);
            break;
        case 7:
            li.Display();
            break;
        case 8:
            cout << "The Reversed Linked List is:" << endl;
            li.DisplayRev(li.head);
            break;
        default:
            cout << "WRONG INPUT!\n";
            break;
        }
    } while (ch != 0);
    return 0;
}