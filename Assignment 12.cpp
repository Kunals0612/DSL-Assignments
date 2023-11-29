#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct item {
    int value;
    int priority;
};
item pr[100000];

void enqueue(int value, int priority,int &size)
{
    size++;
    pr[size].value = value;
    pr[size].priority = priority;
}
int peek(int& size)
{
    int hp=-1;int val;int index;
    for(int i=0;i<=size;i++)
    {
        if(hp<pr[i].priority)
        {
            hp=pr[i].priority;
            val=pr[i].value;
            index=i;
        }
    }
    // cout<<val<<endl;
    return index;
}
void dequeue(int &size)
{
    int ind = peek(size);
    for (int i = ind; i < size; i++)
    {
        pr[i] = pr[i + 1];
    }
    size--;
}
 

int main() {
    int size=0;
    enqueue(10,2,size);
    enqueue(12,3,size);
    enqueue(14,4,size);
    enqueue(16,5,size);
    int i=peek(size);
    cout<<pr[i].value<<endl;
    dequeue(size);
    i=peek(size);
    cout<<pr[i].value<<endl;
    return 0;
}
