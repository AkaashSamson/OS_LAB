#include <iostream>
using namespace std;

void sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int xch = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                int tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
                xch++;
            }
        }
        if (xch == 0)
            break;
    }
}

// int abs(int i)
// {
//     return (i < 0) ? -i : i;
// }

int main()
{
    int ubound, n, total = 0, i, head, prev_head, pos;
    bool lw = false, hg = false, R;

    cout << "Enter the number of requests to be scheduled: ";
    cin >> n;

    int req[n + 2], seq[n + 2], idx = 0;

    cout << "Enter the upper bound for the block: ";
    cin >> ubound;

    cout << "Enter the current head position: ";
    cin >> head;

    cout << "Enter the previous head position: ";
    cin >> prev_head;

    cout << "Enter the request sequence: ";
    for (i = 0; i < n; i++)
    {
        cin >> req[i];
        if (!lw && req[i] == 0)
            lw = true;
        if (!hg && req[i] == ubound)
            hg = true;
    }

    if (!lw)
        req[n++] = 0;
    if (!hg)
        req[n++] = ubound;

    sort(req, n);

    R = (prev_head < head);
    i = 0;

    while (req[i] != head)
        i++;
    pos = i;

    seq[idx++] = head;

    if (R)
    {

        total += (req[n - 1] - head) + (req[n - 1] - req[0]) + (head - req[0]);

        for (i = pos + 1; i < n; i++)
        {
            seq[idx++] = req[i];
        }

        for (i = 0; i <= pos; i++)
        {
            seq[idx++] = req[i];
        }
    }

    else
    {
        total += (req[n - 1] - head) + (req[n - 1] - req[0]) + (head - req[0]);

        for (i = pos + 1; i < n; i++)
        {
            seq[idx++] = req[i];
        }

        for (i = 0; i <= pos; i++)
        {
            seq[idx++] = req[i];
        }
    }

    cout << "Total head movement: " << total << "\n";
    cout << "Sequence: ";
    for (i = 0; i < idx - 1; i++)
        cout << seq[i] << "->";
    cout << seq[i] << "\n";

    return 0;
}