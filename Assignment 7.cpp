#include <bits/stdc++.h>
using namespace std;
class Seat
{
public:
    int row;
    int seatnum;
    bool book;
    int data;
    Seat *next;
    Seat *prev;
    Seat(int r, int s)
    {
        row = r;
        seatnum = s;
        next = NULL;
        prev = NULL;
        book = false;
    }
};
class Row
{
public:
    Seat *head;
    Row()
    {
        head = NULL;
    }
};
class Cinemahall
{
public:
    // int matrix[10][7];
    Row *rows[10];
    Cinemahall()
    {
        for (int i = 0; i < 10; i++)
        {
            rows[i] = new Row();
            for (int j = 0; j < 7; j++)
            {
                Seat *new_seat = new Seat(i, j);
                if (rows[i]->head == NULL)
                {
                    rows[i]->head = new_seat;
                    new_seat->next = new_seat;
                    new_seat->prev = new_seat;
                }
                else
                {
                    Seat *ls = rows[i]->head->prev;
                    ls->next = new_seat;
                    new_seat->prev = ls;
                    new_seat->next = rows[i]->head;
                    rows[i]->head->prev = new_seat;
                }
            }
        }
    }
    // void available()
    // {
    //     //int matrix[10][7];
    //     for (int i = 0; i < 10; i++)
    //     {

    //         Seat *temp = rows[i]->head;
    //         do
    //         {

    //             if (temp->book == false)
    //             {

    //             }

    //             temp = temp->next;
    //         } while (temp != rows[i]->head);
    //     }
    // for (int i = 0; i < 10; i++)
    // {
    //     for (int j = 0; j < 7; j++)
    //     {
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // }
    void display()
    {

        for (int i = 0; i < 10; i++)
        {
            Seat *temp = rows[i]->head;
            for (int j = 0; j < 7; j++)
            {
                if(temp->book == true)
                {
                    cout<<"(B)";
                }
                else{
                    cout<<"(_)";
                }
                temp = temp->next;
            }
            cout << endl;
        }
    }
    void bookseat(int r, int s)
    {
        // int matrix[10][7];
        Seat *temp = rows[r]->head;

        do
        {
            if (temp->seatnum == s && temp->book == false)
            {
                temp->book = true;
                return;
            }
            temp = temp->next;

        } while (temp != rows[r]->head);
    }
    void cancel(int r, int s)
    {
        // int matrix[10][7];

        Seat *temp = rows[r]->head;
        do
        {
            if (temp->seatnum == s && temp->book == true)
            {
                temp->book = false;
                return;
            }

            temp = temp->next;

        } while (temp != rows[r]->head);
    }
};
int main()
{
    Cinemahall cn;
    cout << "1.Display Available seat......" << endl;
    cout << "2.Book seat ...." << endl;
    cout << "3.Cancel seat...." << endl;
    while (true)
    {
        int choice;
        cout<<endl;
        cout << "Enter the choice :   ";
        cin >> choice;
        if (choice == 1)
        {
            cn.display();
        }
        else if (choice == 2)
        {
            int r, s;
            cout << endl;
            cout << "Enter the row number to book the seat";
            cin >> r;
            cout << "Enter the seat number to book the seat";
            cin >> s;
            cn.bookseat(r, s);
        }
        else if (choice == 3)
        {
            int r, s;
            cout << endl;
            cout << "Enter the row number to cancel the seat";
            cin >> r;
            cout << "Enter the seat number to cancel the seat";
            cin >> s;
            cn.cancel(r, s);
        }
        else
        {
            cout << endl;
            cout << "Invalid Input" << endl;
        }
    }

    return 0;
}
