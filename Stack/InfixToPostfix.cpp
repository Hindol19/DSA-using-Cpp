#include <iostream>
#include <string>
#define SIZE 10
using namespace std;

class StackN
{
private:
    char num[SIZE];
    int top;

public:
    StackN();
    bool isEmpty();
    bool isFull();
    char Push(char);
    char Pop();
    char Peek();
    void Disp();
};

StackN::StackN()
{
    top = -1;
}
bool StackN::isEmpty()
{
    if (top == -1)
        return true;
    return false;
}
bool StackN::isFull()
{
    if (top == SIZE - 1)
        return true;
    return false;
}
char StackN::Push(char x)
{
    if (isFull() == true)
        return '0';
    top++;
    num[top] = x;
    return x;
}
char StackN::Pop()
{
    if (isEmpty() == true)
        return '0';
    char temp = num[top];
    top--;
    return temp;
}
char StackN::Peek()
{
    if (isEmpty() == true)
        return '0';
    return num[top];
}
void StackN::Disp()
{
    cout << "Stack is:\n";
    for (int i = 0; i <= top; i++)
    {
        cout << num[i] << " ";
    }
    cout << "\n";
}

int priority(char alpha)
{
    if (alpha == '+' || alpha == '-')
        return 1;

    if (alpha == '*' || alpha == '/')
        return 2;

    if (alpha == '^')
        return 3;

    return 0;
}
int main()
{
    StackN stk;
    // char in[100];
    string in = "(a+b)*c+(d-e)/f+g";
    string alp = "";
    int k = 0;
    for (int i = 0; i < in.length(); i++)
    {
        // cout << in[i] << "\n";
        if (isalpha(in[i]))
        {
            alp = alp + in[i];
        }
        else
        {
            if (stk.isEmpty() || stk.Peek() == '(' || in[i]=='(')
                stk.Push(in[i]);
            else
            {
                if (in[i] == ')')
                {
                    while (stk.Peek() != '(')
                    {
                       alp=alp + stk.Pop();
                    }
                    stk.Pop();
                }
                else if (priority(in[i]) <= priority(stk.Peek()))
                {
                    while (priority(in[i]) <= priority(stk.Peek()))
                    {
                        alp = alp + stk.Pop();
                    }
                    stk.Push(in[i]);
                }
                else
                {
                    stk.Push(in[i]);
                }
            }
        }
        // cout<<alp<<"\n";
    }
    while (!stk.isEmpty())
    {
        alp = alp + stk.Pop();
    }
    cout << alp;
}
