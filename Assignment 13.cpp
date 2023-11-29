#include <iostream>
using namespace std;
#define MAX 100
class Deque
{
    int arr[MAX];
    int front;
    int rear;
    int size;

public:
    Deque(int size)
    {
        front = -1;
        rear = 0;
        this->size = size;
    }

    // Operations on Deque:

    // Checks whether Deque is full or not.
    bool isFull()
    {
        return ((front == 0 && rear == size - 1) || front == rear + 1);
    }

    // Checks whether Deque is empty or not.
    bool isEmpty() { return (front == -1); }

    // Inserts an element at front
    void insertfront(int key)
    {
        // check whether Deque if  full or not
        if (isFull())
        {
            cout << "Overflow\n"
                 << endl;
            return;
        }

        // If queue is initially empty
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }

        // front is at first position of queue
        else if (front == 0)
            front = size - 1;

        else // decrement front end by '1'
            front = front - 1;

        // insert current element into Deque
        arr[front] = key;
    }

    // function to inset element at rear end
    // of Deque.
    void insertrear(int key)
    {
        if (isFull())
        {
            cout << " Overflow\n " << endl;
            return;
        }

        // If queue is initially empty
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }

        // rear is at last position of queue
        else if (rear == size - 1)
            rear = 0;

        // increment rear end by '1'
        else
            rear = rear + 1;

        // insert current element into Deque
        arr[rear] = key;
    }

    // Deletes element at front end of Deque
    void deletefront()
    {
        // check whether Deque is empty or not
        if (isEmpty())
        {
            cout << "Queue Underflow\n"
                 << endl;
            return;
        }

        // Deque has only one element
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
            // back to initial position
            if (front == size - 1)
                front = 0;

            else // increment front by '1' to remove current
                // front value from Deque
                front = front + 1;
    }

    // Delete element at rear end of Deque
    void deleterear()
    {
        if (isEmpty())
        {
            cout << " Underflow\n"
                 << endl;
            return;
        }

        // Deque has only one element
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (rear == 0)
            rear = size - 1;
        else
            rear = rear - 1;
    }

    // Returns front element of Deque
    int getFront()
    {
        // check whether Deque is empty or not
        if (isEmpty())
        {
            cout << " Underflow\n"
                 << endl;
            return -1;
        }
        return arr[front];
    }

    // function return rear element of Deque
    int getRear()
    {
        // check whether Deque is empty or not
        if (isEmpty() || rear < 0)
        {
            cout << " Underflow\n"
                 << endl;
            return -1;
        }
        return arr[rear];
    }
   
};
int main()
{
    int size;
    cout << "Enter the size of the deque: " << endl;
    cin >> size;
    Deque q(size);
    cout << "Enter 1 for add at front \n Enter 2 for add at end \n Enter 3 for delete at front \n Enter 4 for delete at end \n Enter 5 to display" << endl;
    while (true)
    {
        int choice;
        cout << "Enter the choice: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            int data;
            cout << "Enter the number to add : " << endl;
            cin >> data;
            q.insertfront(data);
            break;
        case 2:
            int data1;
            cout << "Enter the number to add : " << endl;
            cin >> data1;
            q.insertrear(data1);
            break;
        case 3:
            q.deletefront();
            break;
        case 4:
            q.deleterear();
            break;
        case 5:
            cout<<"Front of the deque is: "<<q.getFront()<<endl;
            cout<<"Rear of the deque is: "<<q.getRear()<<endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}