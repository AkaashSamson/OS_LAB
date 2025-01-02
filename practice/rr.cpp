#include <iostream>
using namespace std;

struct process
{
    int no, at, bt, ct, tat, wt, rt;
};

int que[100], front = -1, rear = -1;

int is_emp()
{
    return (front == -1);
}

void insert(int item)
{

    que[++rear] = item;
    if (front == -1)
        front = rear;
}

int pop()
{
    if (!is_emp())
    {
        int item = que[front];
        if (front == rear)
            front = -1;
        else
            front++;
        return item;
    }
    return -1;
}

void sort_by_at(process p[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j + 1].at < p[j].at)
            {
                swap(p[j], p[j + 1]);
            }
        }
    }
}

void display_que()
{
    cout << "RQ: ";
    for (int i = front; i <= rear; i++)
    {
        cout << "P" << que[i] + 1 << " ";
    }
    cout << endl;
}

void rr(process p[], int n, int ts)
{
    int ct = 0, curr, complete = 0, idx = 0, pass = 0;

    while (complete < n)
    {
        if (!is_emp())
        {
            display_que();
            curr = pop();

            if (p[curr].rt > ts)
            {
                ct += ts;
                p[curr].rt -= ts;
            }
            else
            {
                ct += p[curr].rt;
                p[curr].rt = 0;
                p[curr].ct = ct;
                p[curr].tat = ct - p[curr].at;
                p[curr].wt = p[curr].tat - p[curr].bt;
                complete++;
            }

            while (idx < n && p[idx].at <= ct)
            {
                insert(idx++);
            }

            if (p[curr].rt > 0)
            {
                insert(curr);
            }
        }
        else
        {
            if (idx < n)
            {
                ct = p[idx].at;
                insert(idx++);
            }
        }
    }
}

int main()
{
    int n, ts;
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the Time slice: ";
    cin >> ts;

    process p[n];
    cout << "Enter the arrival and burst times: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].at >> p[i].bt;
        p[i].no = i;
        p[i].rt = p[i].bt;
    }

    sort_by_at(p, n);
    rr(p, n, ts);

    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << p[i].no + 1 << "\t" << p[i].at << "\t" << p[i].bt << "\t"
             << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << "\n";
    }

    return 0;
}
