#include <bits/stdc++.h>
using namespace std;
class Seat
{
public:
    int row;
    int seatnum;
    bool book;
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
    void available()
    {
        int matrix[10][7];
        for (int i = 0; i < 10; i++)
        {
            int j = 0;
            Seat *temp = rows[i]->head;
            do
            {

                if (temp->book == false)
                {
                    matrix[i][j] = 0;
                }
                j++;
                temp = temp->next;
            } while (temp != rows[i]->head);
        }
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    void bookseat(int r, int s)
    {
        int matrix[10][7];
        Seat *temp = rows[r]->head;
        int j = 0;
        do
        {
            if (temp->seatnum == s && temp->book == false)
            {
                temp->book = true;
                return;
            }
            if (temp->book == true)
            {
                matrix[r][s] = 1;
            }
            j++;
            temp = temp->next;

        } while (temp != rows[r]->head);
    }
    void cancel(int r, int s)
    {
        int matrix[10][7];
        int j = 0;
        Seat *temp = rows[r]->head;
        do
        {
            if (temp->seatnum == s && temp->book == true)
            {
                temp->book = false;
            }
            if (temp->book == false)
            {
                matrix[r][s] = 0;
            }
            temp = temp->next;
            j++;
        } while (temp != rows[r]->head);
    }
};
int main()
{
    Cinemahall cn;
    cn.bookseat(0, 0);
    cn.bookseat(0, 3);
    cout << "Available seats : " << endl;
    cn.available();

    return 0;
}
