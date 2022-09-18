#include <iostream>
#define SIZE 5
using namespace std;

class Queue
{
private:
    int num[SIZE];
    int front;
    int rear;

public:
    Queue(); // Constructor
    int isEmpty();
    int isFull();
    int Enqueue(int);
    int Dequeue();
    void displayItems();
};

Queue::Queue()
{
    front = -1;
    rear = -1;
}

int Queue::isEmpty()
{
    if (front == -1 || rear == -1)
        return 1;
    else
        return 0;
}
int Queue::isFull()
{
    if (rear == SIZE - 1)
        return 1;
    else
        return 0;
}
int Queue::Enqueue(int x)
{
    if (isFull() == 1)
        return -9999;
    rear++;
    num[rear] = x;

    if (front == -1)
        front = 0;
    return x;
}
int Queue::Dequeue()
{
    if (isEmpty() == 1)
        return -9999;
    int temp = num[front];
    for (int i = 0; i < rear; i++)
    {
        num[i] = num[i + 1];
    }
    rear--;
    // front++;
    return temp;
}
void Queue::displayItems()
{
    if (isEmpty() == 1)
    {
        cout << "Queue is Empty\n";
        return;
    }
    cout << "Queue is:\n";
    for (int i = front; i <= rear; i++)
    {
        cout << num[i] << " ";
    }
    cout << "\n";
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
            q1.displayItems();
            break;

        default:
            cout << "WRONG INPUT!\n";
            break;
        }
    } while (ch != 0);
}