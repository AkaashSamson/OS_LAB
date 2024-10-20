// To implement LRU page replacement algorithm
#include <iostream>
#define MAX 50
using namespace std;
int pgs[MAX], n, f, in = -1, out = -1;

class frame
{
public:
    int data;
    int freq;

public:
    frame()
    {
        data = -1;
        freq = 0;
    }
    frame(int d)
    {
        data = d;
        freq = 1;
    }

    frame(const frame &f)
    {
        data = f.data;
        freq = f.freq;
    }
};

class frame que[MAX];

int isempty()
{
    if (in == -1)
        return 1;
    return 0;
}

int isfull()
{
    for (int i = 0; i < f; i++)
    {
        if (que[i].data == -1)
            return 0;
    }
    return 1;
}

int LRU()
{
    int min = 0, sec_min;
    for (int i = 0; i < f; i++)
    {
        if (que[i].freq < que[min].freq)
        {
            min = i;
            sec_min = min;
        }
        else if (que[i].freq < que[sec_min].freq)
        {
            sec_min = i;
        }
    }
    que[sec_min].freq--;
    return min;
}

void enque(frame item)
{
    // if (isfull())
    // {
    //     cout << "Queue Overflow\n";
    //     return;
    // }
    if (in == -1)
        in = 0;
    out = LRU();
    que[out] = item;
}

frame deque()
{
    frame item;
    // if (isempty())
    // {
    //     cout << "Queue Underflow\n";
    //     return 0;
    // }
    in = LRU();
    item = que[in];
    que[in] = frame();
    // if (in == out)
    // {
    //     in = -1;
    //     out = -1;
    // }
    // else
    // {
    //     in = (in + 1) % f;
    // }
    return item;
}

int ispagehit(int pg)
{
    for (int i = 0; i < f; i++)
    {
        if (pg == que[i].data)
            return i;
    }
    return -1;
}

void display_que()
{
    int i;
    for (i = 0; i < f; i++)
    {
        if (que[i].data == -1)
            cout << "[ ] ";
        else
            cout << "[" << que[i].data << "] ";
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
        que[i] = frame();
    }

    int faults = 0, ind;
    for (int i = 0; i < n; i++)
    {
        cout << "Page " << pgs[i] << " :";
        ind = ispagehit(pgs[i]);
        if (ind == -1)
        {
            if (isfull())
            {
                deque();
            }
            enque(frame(pgs[i]));
            faults++;
            display_que();
            cout << "Page fault\n";
        }
        else
        {
            que[ind].freq++;
            display_que();
            cout << "Page hit\n";
            // cout << "No page fault\n";
        }
    }

    cout << "Number of page faults: " << faults << endl;
    return 0;
}