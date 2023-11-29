#include <bits/stdc++.h>
using namespace std;
class Queue{
    int front;
    int back;
    vector<char> v;
public:
    Queue()
    {
       this->back = 0;
       this->front = 0;
    }
    void enqueue(char data)
    {
        v.push_back(data);
        this->back++;
        cout<<"Job has been added successfully!!"<<endl;
    }
    void dequeue()
    {
        if(this->front == this->back)
        {
           this->front = 0;
           this->back = 0;
        }
        else
        {
           this->front++;
        }
        cout<<"Job has been deleted successfully!!"<<endl;
    }
    int getfront()
    {
        if(this->front == 0)
        {
            return -1;
        }
        return v[this->front];
    }
    bool isEmpty()
    {
        return this->front == 0;
    }
    void display()
    {
    for(int i = front;i < back; i++)
    {
    cout<<v[i]<<" ";
    }
    cout<<endl;
    cout<<"front->"<<front<<endl;
    cout<<"Rear->"<<back<<endl;
    }

};
int main()
{
    Queue q;
    cout<<"Enter 1 to add job"<<endl;
    cout<<"Enter 2 to delete job"<<endl;
    cout<<"Enter 3 to display job"<<endl;
    while(true)
    {
    int choice;
       cout<<"Enter the choice"<<": ";
       cin>>choice;
       if(choice == 1)
       {
        char s;
        cout<<"Enter the description of the task: "<<endl;
        cin>>s;
        q.enqueue(s);
       }
       else if(choice == 2)
       {
        q.dequeue();
       }
       else if(choice == 3)
       {
           q.display();
       }
       else
       {
        cout<<"Invalid Choice.."<<endl;
       }

    }

       return 0;
}
