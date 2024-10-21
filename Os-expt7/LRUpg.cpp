#include <iostream>
#define MAX 50

using namespace std;

int pgs[MAX], n, f;

class Frame
{
public:
    int data;
    int freq;

    Frame() : data(-1), freq(0) {}
    Frame(int d, int fr) : data(d), freq(fr) {}
};

Frame que[MAX];

int isFull()
{
    for (int i = 0; i < f; i++)
    {
        if (que[i].data == -1)
            return 0;
    }
    return 1;
}

int findLRU()
{
    int min = 0;
    for (int i = 1; i < f; i++)
    {
        if (que[i].freq < que[min].freq)
        {
            min = i;
        }
    }
    return min;
}

void updateLRUOrder(int ind)
{
    for (int i = 0; i < f; i++)
    {
        if (i != ind)
        {
            que[i].freq--;
        }
        else
        {
            que[i].freq = f;
        }
    }
}

void enqueue(Frame item)
{
    int pos = findLRU();
    que[pos] = item;
}

int isPageHit(int pg)
{
    for (int i = 0; i < f; i++)
    {
        if (pg == que[i].data)
            return i;
    }
    return -1;
}

void displayQueue()
{
    for (int i = 0; i < f; i++)
    {
        if (que[i].data == -1)
            cout << "[ ] ";
        else
            cout << "[" << que[i].data << "] ";
    }
    cout << endl;
}

void processPages()
{
    int faults = 0, ind;
    for (int i = 0; i < n; i++)
    {
        cout << "Page " << pgs[i] << " :";
        ind = isPageHit(pgs[i]);
        if (ind == -1)
        {
            if (isFull())
            {
                int lruIndex = findLRU();
                que[lruIndex].data = -1;
            }
            enqueue(Frame(pgs[i], f));
            faults++;
        }
        else
        {
            updateLRUOrder(ind);
        }
        displayQueue();
    }
    cout << "Number of page faults: " << faults << endl;
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
        que[i] = Frame(-1, i);
    }

    processPages();

    return 0;
}