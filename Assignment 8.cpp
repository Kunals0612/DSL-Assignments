#include <bits/stdc++.h>
using namespace std;
class Seat
{
public:
   int in_time;
   int end_time;
   Seat *next;
   Seat(int i, int e)
   {
      in_time = i;
      end_time = e;
      next = NULL;
   }
};
class Appointment
{
public:
   Seat *head;
   Appointment()
   {
      head = NULL;
   }
   void book(int i, int e)
   {
      Seat *new_book = new Seat(i, e);
      if (head == NULL)
      {
         head = new_book;
         return;
      }
      Seat *temp = head;
      while (temp->next != NULL)
      {
         temp = temp->next;
      }
      temp->next = new_book;
   }
   void cancel(int i, int e)
   {
      Seat* temp = head;
      if(head->next == NULL)
      {
         head = head->next;
         free(temp);
      }
      else
      {
         do{
         if(temp->next->in_time == i && temp->next->end_time==e)
         {
            Seat* del = temp->next;
            temp->next = del->next;
            free(del);
            return;
         }
         temp = temp->next;
      }while(temp!=NULL);

      }
     
   }
   void display()
   {
      if (head == NULL)
      {
         cout << "No appointment is booked yet" << endl;
      }
      Seat *temp = head;
      while (temp != NULL)
      {
         cout << temp->in_time << " - " << temp->end_time << "  is already booked" << endl;
         temp = temp->next;
      }
   }
};
int main()
{
   Appointment a;
   cout << "1. Display the appointment....." << endl;
   cout << "2. Add appointment......" << endl;
   cout << "3. Cancel appointment......" << endl;
   while (true)
   {
      int choice;
      cout << "Enter the choice : ";
      cin >> choice;
      if (choice == 1)
      {
         a.display();
      }
      else if (choice == 2)
      {
         int i;
         cout << "Enter the booking in_time : ";
         cin >> i;
         int e;
         cout << "Enter the booking end_time : ";
         cin >> e;
         a.book(i, e);
      }
      else if (choice == 3)
      {
         int i;
         cout << "Enter the cancelation in_time : ";
         cin >> i;
         int e;
         cout << "Enter the cancelation end_time : ";
         cin >> e;
         a.cancel(i, e);
      }
      else
      {
         cout << "Invalid Input" << endl;
      }
   }
   return 0;
}
