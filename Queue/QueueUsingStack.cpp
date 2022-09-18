#include <iostream>
#define SIZE 5
using namespace std;
// Creating Stack
class Stack
{
private:
    int num[SIZE];
    int top;

public:
    Stack(); // This is the constructor
    int push(int);
    int peek();
    int pop();
    int isEmpty();
    int isFull();
    void displayItems();
};

// Constructor:
Stack::Stack()
{
    top = -1;
}
int Stack::isEmpty()
{
    if (top == -1) // Stack Underflow
        return 1;
    else
        return 0;
}
int Stack::isFull()
{
    if (top == (SIZE - 1)) // Stack Overflow
        return 1;
    else
        return 0;
}
int Stack::push(int x)
{
    if (isFull() == 1)
        return -9999;
    top++;
    num[top] = x;
    return x;
}
int Stack::pop()
{
    if (isEmpty() == 1)
        return -9999;
    int temp = num[top];
    top--;
    return temp;
}
int Stack::peek()
{
    return num[top];
}
void Stack::displayItems()
{
    // cout << "Stack is: ";
    for (int i = top; i >= 0; i--)
    {
        cout << num[i] << " ";
    }
    cout << "\n";
}

// Creating Queue
class Queue
{
private:
    Stack s1, s2;

public:
    int Enqueue(int);
    int Dequeue();
    void display();
};

int Queue::Enqueue(int x)
{
    if (s1.isFull() == 1)
        return -9999;
    while (!s1.isEmpty())
    {
        s2.push(s1.peek());
        s1.pop();
    }
    s1.push(x);
    while (!s2.isEmpty())
    {
        s1.push(s2.peek());
        s2.pop();
    }
    return x;
}
int Queue::Dequeue()
{
    if (s1.isEmpty() == 1)
        return -9999;
    int temp = s1.peek();
    s1.pop();
    return temp;
}
void Queue::display()
{
    if (s1.isEmpty())
    {
        cout << "Queue is Empty!\nNothing to Display.\n\n";
        return;
    }
    cout << "Queue is:\n";
    s1.displayItems();
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
            res = q1.Enqueue(n);
            if (res == -9999)
            {
                cout << "Queue Overflow!!\nCANNOT INSERT ITEM\n\n";
                break;
            }
            cout << res << " is Pushed.\n";
            break;

        case 2:
            res = q1.Dequeue();
            if (res == -9999)
            {
                cout << "Queue Underflow!!\nNO ITEMS TO DELETE\n\n";
                break;
            }
            cout << res << " is Deleted.\n";
            break;
        case 3:

            q1.display();
            break;

        default:
            cout << "WRONG INPUT!\n";
            break;
        }
    } while (ch != 0);
}
