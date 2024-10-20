#include <iostream>
#include <string>
#define MAX 10

using namespace std;
int mutex = 1, full = 0, empty_sm, n, in = -1, out = -1, x = 0;
string que[MAX], y;

// Implement a circular queue
int isempty()
{
    if (in == -1)
        return 1;
    return 0;
}

int isfull()
{
    if ((in == 0 && out == n - 1) || (in == out + 1))
        return 1;
    return 0;
}

void enque(string item)
{
    if (isfull())
    {
        cout << "Queue Overflow\n";
        return;
    }
    if (in == -1)
        in = 0;
    out = (out + 1) % n;
    que[out] = item;
}

string deque()
{
    string item;
    if (isempty())
    {
        cout << "Queue Underflow\n";
        return NULL;
    }
    item = que[in];
    que[in] = " ";
    if (in == out)
    {
        in = -1;
        out = -1;
    }
    else
    {
        in = (in + 1) % n;
    }
    return item;
}

void display_que()
{
    int i;
    for (i = 0; i < n; i++)
    {
        cout << "[" << que[i] << "] ";
    }

    cout << endl;
    cout << "In = " << out << " Out = " << in << " Size = " << n << endl;
}

int wait(int s)
{
    while (s < 0)
        ;
    return --s;
}

int signal(int s)
{
    return ++s;
}

void producer()
{
    string data;
    mutex = wait(mutex);
    full = signal(full);
    empty_sm = wait(empty_sm);
    // enque(++x);
    cout << "Enter the item to be produced: ";
    cin >> data;
    enque(data);
    cout << "Producer produces the item '" << data << "' \n";
    mutex = signal(mutex);
}

void consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty_sm = signal(empty_sm);
    y = deque();
    cout << "Consumer consumes the item '" << y << "' \n";
    mutex = signal(mutex);
}

int main()
{
    int ch;
    cout << "Enter the size of the buffer: ";
    cin >> n;
    empty_sm = n;
    while (1)
    {
        cout << "\n\n1. Produce an item\n2. Consume an item\n3. Display the queue\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        cout << endl;
        switch (ch)
        {
        case 1:
            if ((mutex == 1) && (empty_sm != 0))
            {
                producer();
            }
            else
                cout << "Buffer is full\n";
            break;
        case 2:
            if ((mutex == 1) && (full != 0))
                consumer();
            else
                cout << "Buffer is empty\n";
            break;
        case 3:
            display_que();
            break;
        case 4:
            return 0;
            break;
        }
    }

    return 0;
}
