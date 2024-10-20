// FIFO page replacement

#include <iostream>
#define MAX 50
using namespace std;
int pgs[MAX], n, f, que[MAX], in = -1, out = -1;

int isempty()
{
    if (in == -1)
        return 1;
    return 0;
}

int isfull()
{
    if ((in == 0 && out == f - 1) || (in == out + 1))
        return 1;
    return 0;
}

void enque(int item)
{
    if (isfull())
    {
        cout << "Queue Overflow\n";
        return;
    }
    if (in == -1)
        in = 0;
    out = (out + 1) % f;
    que[out] = item;
}

int deque()
{
    int item;
    if (isempty())
    {
        cout << "Queue Underflow\n";
        return 0;
    }
    item = que[in];
    que[in] = -1;
    if (in == out)
    {
        in = -1;
        out = -1;
    }
    else
    {
        in = (in + 1) % f;
    }
    return item;
}

int ispagehit(int pg)
{
    for (int i = 0; i < f; i++)
    {
        if (pg == que[i])
            return 1;
    }
    return 0;
}

void display_que()
{
    int i;
    for (i = 0; i < f; i++)
    {
        if (que[i] == -1)
            cout << "[ ] ";
        else
            cout << "[" << que[i] << "] ";
    }

    cout << " ";
}

int main()
{
    cout << "Enter number of Frames: ";
    cin >> f;
    cout << "Enter number of Pages: ";
    cin >> n;
    cout << "Enter page references: ";
    for (int i = 0; i < n; i++)
    {
        cin >> pgs[i];
    }
    for (int i = 0; i < f; i++)
    {
        que[i] = -1;
    }

    int faults = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "Page " << pgs[i] << " :";
        if (!ispagehit(pgs[i]))
        {
            if (isfull())
            {
                deque();
            }
            enque(pgs[i]);
            faults++;
            display_que();
            cout << "Page fault\n";
        }
        else
        {
            display_que();
            cout << "Page hit\n";
            // cout << "No page fault\n";
        }
    }

    cout << "Number of page faults: " << faults << endl;
    return 0;
}