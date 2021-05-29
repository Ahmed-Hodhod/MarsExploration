#include<iostream>
#include"PriQ.h"
using namespace std;
int main()
{
    int c, i, p;
    LinkedQueue<int> pq;
    do
    {
        cout << "1.Insert\n";
        cout << "2.Delete\n";
        cout << "3.Display\n";
        cout << "4.Exit\n";
        cout << "Enter your choice : ";
        cin >> c;
        switch (c)
        {
        case 1:
            cout << "Input the item value to be added in the queue : ";
            cin >> i;
            cout << "Enter its priority : ";
            cin >> p;
            pq.enqueue(i, p);
            break;
        case 2:
            pq.dequeue(i);
            break;
        case 3:
            pq.print();
            break;
        case 4:
            break;
        default:
            cout << "Wrong choice\n";
        }
    } while (c != 4);

    return 0;
}