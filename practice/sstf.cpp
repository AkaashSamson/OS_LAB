#include <iostream>

using namespace std;

int main()
{
    int n;

    cout << "Enter the number the requests: ";

    cin >> n;

    int seq[n], req[n], head, ub, i, cnt = 0, total = 0, idx = 0, j, pos;
    bool visited[n];

    cout << "Enter the upper bound on the block size: ";
    cin >> ub;

    cout << "Enter the current head position: ";
    cin >> head;

    cout << "Enter the request sequence: ";
    for (i = 0; i < n; i++)
    {
        cin >> req[i];
        visited[i] = false;
    }

    for (cnt = 0; cnt < n; cnt++)
    {
        int min = INT_MAX;
        for (j = 0; j < n; j++)
        {
            // cout << req[j] << " ";
            if (!visited[j] && abs(head - req[j]) < min)
            {
                min = abs(head - req[j]);
                pos = j;
            }
        }

        total += min;
        visited[pos] = true;
        // cout << req[pos] << " " << visited[pos] << "\n";
        seq[idx++] = head;
        head = req[pos];
    }

    seq[idx++] = head;

    cout << "Total head movement: ";
    cout << total << "\n";

    cout << "Sequence: ";
    if (seq[0] != seq[1])
        cout << seq[0] << "->";
    for (i = 1; i < idx - 1; i++)
    {
        cout << seq[i] << "->";
    }
    cout << seq[i] << "\n";
}
