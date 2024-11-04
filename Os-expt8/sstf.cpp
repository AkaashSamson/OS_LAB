#include <iostream>
#include <cmath>
#define MAX 50

using namespace std;

int n, req_seq[MAX], current_head, traversal[MAX + 1];
bool visited[MAX];

int find_nearest_request(int current_head, const int req_seq[], bool visited[], int n)
{
    int min_distance = INT_MAX;
    int nearest_index = -1;

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            int distance = abs(req_seq[i] - current_head);
            if (distance < min_distance)
            {
                min_distance = distance;
                nearest_index = i;
            }
        }
    }

    return nearest_index;
}

int sstf(const int req_seq[], int n, int current_head, int traversal[])
{
    int total_head_movement = 0;
    traversal[0] = current_head;

    for (int i = 0; i < n; ++i)
    {
        int nearest_index = find_nearest_request(current_head, req_seq, visited, n);
        visited[nearest_index] = true;
        total_head_movement += abs(req_seq[nearest_index] - current_head);
        current_head = req_seq[nearest_index];
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
        visited[i] = false;
    }
    cout << "Enter current head position: ";
    cin >> current_head;

    int total_movement = sstf(req_seq, n, current_head, traversal);

    cout << "Total head movement: " << total_movement << endl;
    cout << "Traversal sequence: ";
    for (int i = 0; i < n; ++i)
    {
        cout << traversal[i] << "->";
    }
    cout << traversal[n] << endl;

    return 0;
}
