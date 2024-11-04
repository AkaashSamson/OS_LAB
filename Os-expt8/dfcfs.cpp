#include <iostream>
#include <cmath>
#define MAX 50

using namespace std;

int n, req_seq[MAX], current_head, traversal[MAX + 1];

int fcfs(const int req_seq[], int n, int current_head, int traversal[])
{
    int total_head_movement = 0;
    traversal[0] = current_head;

    for (int i = 0; i < n; ++i)
    {
        total_head_movement += abs(req_seq[i] - current_head);
        current_head = req_seq[i];
        traversal[i + 1] = current_head;
    }

    return total_head_movement;
}

int main()
{
    cout << "Enter number of requests: ";
    cin >> n;
    cout << "Enter request sequence: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> req_seq[i];
    }
    cout << "Enter current head position: ";
    cin >> current_head;

    int total_movement = fcfs(req_seq, n, current_head, traversal);

    cout << "Total head movement: " << total_movement << endl;
    cout << "Traversal sequence: ";
    for (int i = 0; i < n; ++i)
    {
        cout << traversal[i] << "->";
    }
    cout << traversal[n] << endl;

    return 0;
}