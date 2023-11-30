#include <bits/stdc++.h>
using namespace std;
class Stack{
    public:
       int topele;
       int size;
       char *arr;
       Stack(int s)
       {
         size = s;
         topele = -1;
         arr = new char[s];
       }
       void push(char data)
       {
          topele++;
          arr[topele] = data;
       }
       void pop()
       {
        topele--;
       }
       int empty()
       {
          if(topele == -1)
          {
             return 1;
          }
          else
          {
            return 0;
          } 
       }
       bool full()
       {
        if(topele == size)
          {
             return 1;
          }
          else
          {
            return 0;
          } 
       }
       bool top()
       {
          return arr[topele];
       }

};
int prec(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
string infixtoPostfix(string s)
{
    stack<char> st;
    string res;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            res += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && prec(st.top()) > prec(s[i]))
            {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    return res;
}

int main()
{
    cout << infixtoPostfix("(a-b/c)*(a/k-l)")<<endl;
    return 0;
}
