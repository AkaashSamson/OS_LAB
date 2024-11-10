#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;

int total_head_movement = 0, n, current_head;
int request[32]; // To account for extra boundary requests (0 and block)

void right_display()
{
    for (int i = 0; i <= n + 1; i++)
    {
        if (request[i] >= current_head)
            cout << request[i] << " ";
    }
    for (int i = n; i >= 0; i--)
    {
        if (request[i] <= current_head)
            cout << request[i] << " ";
    }
}

void left_display()
{
    for (int i = n; i >= 0; i--)
    {
        if (request[i] <= current_head)
            cout << request[i] << " ";
    }
    for (int i = 1; i <= n + 1; i++)
    {
        if (request[i] >= current_head)
            cout << request[i] << " ";
    }
}

int main()
{
    int block, direction;

    // Taking input for Block Size
    cout << "Enter the Block Size of the Disk: ";
    cin >> block;

    cout << "Enter the number of Disk Requests: ";
    cin >> n;

    // Set the first request as 0 (start) and last as block (end)
    request[0] = 0;
    request[n + 1] = block;

    cout << "Enter the Disk Requests to be Searched: ";
    for (int i = 1; i <= n; i++)
        cin >> request[i];

    // Sort the requests including 0 and block size
    sort(request, request + n + 2);

    cout << endl;
    cout << "Enter the Current Disk Head Position: ";
    cin >> current_head;

    cout << "Enter Direction [Left - 0; Right - 1]: ";
    cin >> direction;

    cout << "Track sequence: " << " ";

    // Calculating total disk head movement
    if (direction == 0)
    {
        total_head_movement += (current_head - request[0]); // Move left to 0
        total_head_movement += (request[n] - request[0]);   // Then move right to the end
        left_display();
    }
    else
    {
        total_head_movement += (request[n + 1] - current_head); // Move right to the end
        total_head_movement += (request[n + 1] - request[1]);   // Then move left to 0
        right_display();
    }

    cout << endl
         << "The Total Disk Head Movement is: " << total_head_movement;
}
