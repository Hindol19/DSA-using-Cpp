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
    void deleteBeg();
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
void LL::deleteBeg()
{
     if (head == NULL)
    {
        cout << "Stack Underflow" << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    free(temp);
    cout << "Item Deleted\n";
}

// Display:
void LL::Display()
{
    if (head == NULL)
    {
        cout << "Stack is Empty!" << endl;
        return;
    }
    cout << "The Stack is:" << endl;
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

class Stack
{
    LL li;

public:
    void Push(int);
    void Pop();
    void Display();
};
void Stack::Push(int item)
{
    li.insertBeg(item);
}
void Stack::Pop()
{
    li.deleteBeg();
}
void Stack::Display()
{
    li.Display();
}
int main()
{
    Stack q1;
    int ch, n, res;
    do
    {
        cout << "\n";
        cout << "Enter 0 to exit.\n";
        cout << "Enter 1 to Push.\n";
        cout << "Enter 2 to Pop.\n";
        cout << "Enter 3 to Display Items.\n";
        cout << "Enter Your Choice.\n\n";
        cin >> ch;
        switch (ch)
        {
        case 0:
            cout << "Exited";
            break;
        case 1:
            cout << "Enter item to be Pushed: ";
            cin >> n;
            cout << "\n";
            q1.Push(n);
            break;
        case 2:
            q1.Pop();
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