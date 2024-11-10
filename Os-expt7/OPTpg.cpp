#include <iostream>
#define MAX 50
#define INTMAX = 10000

using namespace std;

int pgs[MAX], n, f;

class Frame
{
public:
    int data;
    int nxt_ocr;

    Frame() : data(-1), nxt_ocr(INT_MAX) {}
    Frame(int d, int qr) : data(d), nxt_ocr(qr) {}
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

int findOptimal()
{
    int max = 0;
    for (int i = 1; i < f; i++)
    {
        if (que[i].nxt_ocr > que[max].nxt_ocr)
        {
            max = i;
        }
    }
    return max;
}

int get_nxt_ocr(int ind)
{
    for (int i = ind + 1; i < n; i++)
    {
        if (pgs[i] == pgs[ind])
        {
            return i - ind;
        }
    }

    return INT_MAX;
}

void enqueue(Frame item)
{
    int pos = findOptimal();
    que[pos] = item;
    if (que[pos].nxt_ocr > n)
        que[pos].nxt_ocr--;
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
            enqueue(Frame(pgs[i], get_nxt_ocr(i)));
            faults++;
            displayQueue();
            cout << "Page Fault\n";
        }
        else
        {
            que[ind].nxt_ocr = get_nxt_ocr(i);
            displayQueue();
            cout << "Page Hit\n";
        }
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
        que[i] = Frame();
    }

    processPages();

    return 0;
}