#include <iostream>
#include <string>
#define MAX 10

using namespace std;

int n, full = 0, empty_sm, mutex = 1, in = -1, out = -1;
string que[MAX];

int isq_empty()
{
    if (out == -1)
        return 1;
    return 0;
}

int is_full()
{
    if ((out == 0 && in == n - 1) || (out == in + 1))
        return 1;
    return 0;
}

void display()
{
    int i;
    for (i = 0; i < n; i++)
    {
        cout << "[" << que[i] << "] ";
    }
    // if (in >= out)
    // {
    //     for (i = out; i <= in; i++)
    //         cout << "[" << que[i] << "] ";
    // }

    // else
    // {
    //     for (i = out; i < n; i++)
    //         cout << "[" << que[i] << "] ";
    //     for (i = 0; i < in; i++)
    //         cout << "[" << que[i] << "] ";
    // }
}

void enque(string item)
{
    if (is_full())
        return;
    else
    {
        if (out == -1)
            out = out + 1;
        in = (in + 1) % n;
        que[in] = item;
    }
}

string deque()
{
    if (isq_empty())
        return NULL;
    else
    {
        string item = que[out];
        que[out] = ' ';
        if (out == in)
        {
            out = -1;
            in = -1;
        }
        else
        {
            out = (out + 1) % n;
        }

        return item;
    }

    return NULL;
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

void produce(string data)
{
    mutex = wait(mutex);
    full = signal(full);
    empty_sm = wait(empty_sm);
    enque(data);
    cout << "Producer produces item " << data << "in the buffer";
    mutex = signal(mutex);
}

string consume()
{
    string data;
    mutex = wait(mutex);
    full = wait(full);
    empty_sm = signal(empty_sm);
    data = deque();
    cout << "Consumer consumes item " << data << "from the buffer";
    mutex = signal(mutex);

    return data;
}

int main()
{

    cout << "Enter the size: ";
    cin >> n;
    int cont = 1, ch;
    string data;
    empty_sm = n;

    for (int i = 0; i < n; i++)
    {
        que[i] = ' ';
    }

    while (cont)
    {
        cout << "\n1-produce\n";
        cout << "2-consume\n";
        cout << "3-display\n";
        cout << "4-exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            if (mutex == 1 && empty_sm != 0)
            {
                cout << "Enter the item to produce - ";
                cin >> data;
                produce(data);
            }

            else
            {
                cout << "Buffer is full\n";
            }
            break;

        case 2:
            if (mutex == 1 && full != 0)
            {
                // cout<<"Enter the item to produce - ";
                // cin>>data;
                data = consume();
            }

            else
            {
                cout << "Buffer is empty\n";
            }
            break;

        case 3:
            display();
            break;

        case 4:
            cont = 0;
            break;

        default:
            cout << "Invalid choice\n";
            break;
        }
    }

    return 0;
}