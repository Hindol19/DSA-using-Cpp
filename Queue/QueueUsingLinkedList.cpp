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
    void deleteEnd();
    void Display();
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
void LL::deleteEnd()
{
    if (head == NULL)
    {
        cout << "Queue is Empty! Nothing to Delete!" << endl;
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

// Display:
void LL::Display()
{
    if (head == NULL)
    {
        cout << "Queue is Empty!" << endl;
        return;
    }
    cout << "The Queue is:" << endl;
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

class Queue
{
    LL li;

public:
    void Enqueue(int);
    void Dequeue();
    void Display();
};
void Queue::Enqueue(int item)
{
    li.insertBeg(item);
}
void Queue::Dequeue()
{
    li.deleteEnd();
}
void Queue::Display()
{
    li.Display();
}
int main()
{
    Queue q1;
    int ch, n, res;
    do
    {
        cout << "\n";
        cout << "Enter 0 to exit.\n";
        cout << "Enter 1 to Enqueue.\n";
        cout << "Enter 2 to Dequeue.\n";
        cout << "Enter 3 to Display Items.\n";
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
            q1.Enqueue(n);
            break;

        case 2:
            q1.Dequeue();
            break;
        case 3:
            q1.Display();
            break;
        default:
            cout << "WRONG INPUT!\n";
            break;
        }
    } while (ch != 0);
}