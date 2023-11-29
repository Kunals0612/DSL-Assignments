#include <bits/stdc++.h>
using namespace std;
class Stack
{
public:
    int top;
    int size;
    char *arr;
    Stack(int s)
    {
        size = s;
        top = -1;
        arr = new char[s];
    }
    void push(char data)
    {
        top++;
        arr[top] = data;
    }
    void pop()
    {
        top--; 
    }
    int isfull()
    {
        if (top == size)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int empty()
    {
        if (top == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << endl;
        }
    }
    char gettop()
    {
        return arr[top];
        
    }
};
int main()
{
    string str;
    cout << "Enter the string : " << endl;
    cin >> str;
    Stack s1(str.size());
    int c = str.size();
    for (int i = 0; i < c; i++)
    {
        char ch = str[i];
        if (ch == '[' or ch == '{' or ch == '(')
        {
            s1.push(ch);
        }
        else
        {
            if (ch == ')' and !s1.empty() and s1.gettop() == '(')
            {
                s1.pop();
            }
            else if (ch == ']' and !s1.empty() and s1.gettop() == '[')
            {
                s1.pop();
            }
            else if (ch == '}' and !s1.empty() and s1.gettop() == '{')
            {
                s1.pop();
            }
        }
    }
    if(s1.empty())
    {
        cout<<"Yess"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}