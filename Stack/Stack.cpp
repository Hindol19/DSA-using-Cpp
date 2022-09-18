#include <iostream>
#define SIZE 100
using namespace std;
class Stack
{
private:
    int num[SIZE];
    int top;

public:
    Stack(); // This is the constructor
    int push(int);
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
void Stack::displayItems()
{
    cout << "Stack is: ";
    for (int i = top; i >= 0; i--)
    {
        cout << num[i] << " ";
    }
    cout << "\n";
}
int main()
{
    Stack stk;
    int ch, n, res;
    do
    {
        cout << "\n";
        cout << "Enter 0 to exit.\n";
        cout << "Enter 1 to Push Item.\n";
        cout << "Enter 2 to Pop Item.\n";
        cout << "Enter 3 to Display Items.\n";
        cout << "Enter Your Choice.\n";

        cin >> ch;
        switch (ch)
        {
        case 0:
            cout << "Exited";
            break;
        case 1:
            cout << "Enter item to be inserted: ";
            cin >> n;
            res = stk.push(n);
            if (res == -9999)
            {
                cout << "Stack Overflow!!";
                break;
            }
            cout << res << " is Pushed.\n";
            break;

        case 2:
            res = stk.pop();
            if (res == -9999)
            {
                cout << "Stack Underflow!!";
                break;
            }
            cout << res << " is Deleted.\n";
            break;
        case 3:
            stk.displayItems();
            break;

        default:
            cout << "WRONG INPUT!\n";
            break;
        }
    } while (ch != 0);
}
