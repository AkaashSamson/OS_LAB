#include <iostream>

#define MAX 10

using namespace std;

int m, n;
int alloc[MAX][MAX], maxr[MAX][MAX], need[MAX][MAX], wait[MAX], avail[MAX], total_resrc[MAX], work[MAX], req[MAX];
// bool finish[MAX];

void display_table()
{
    cout << "Process\t\tAllocation\tMax\t\tNeed\t\tAvailable\n";

    for (int i = 0; i < n; i++)
    {
        cout << "P" << i << "   \t\t";
        for (int j = 0; j < m; j++)
            cout << alloc[i][j] << " ";
        cout << "\t\t";
        for (int j = 0; j < m; j++)
            cout << maxr[i][j] << " ";
        cout << "\t\t";
        for (int j = 0; j < m; j++)
            cout << need[i][j] << " ";
        if (i == 0)
        {
            cout << "\t\t";
            for (int j = 0; j < m; j++)
                cout << avail[j] << " ";
        }
        cout << endl;
    }
}

bool safety()
{
    int i, j, safe[n], cnt = 0;
    bool finish[n] = {false}, found = false, safe_seq;
    for (int i = 0; i < n; i++)
    {
        work[i] = avail[i];
    }

    while (cnt < n)
    {
        safe_seq = false;
        for (i = 0; i < n; i++)
        {
            if (!finish[i])
            {
                found = true;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                        found = false;
                }
                if (found)
                {
                    safe_seq = true;
                    safe[cnt++] = i;
                    for (j = 0; j < m; j++)
                    {
                        work[j] += alloc[i][j];
                    }
                    finish[i] = true;
                }
            }
        }

        if (!safe_seq)
            break;
    }

    if (safe_seq)
    {
        cout << "Safe Sequence Exists\n";
        cout << "Safe seq: P" << safe[0];
        for (i = 1; i < n; i++)
            cout << " -> P" << safe[i];
        cout << "\n\n";
        display_table();
        cout << "\n";
        return true;
    }
    else
    {
        cout << "Safe Sequence doesn't exist\n";
        cout << "\n\n";
        display_table();
        cout << "\n";
        return false;
    }
}

void displaymat(int mat[MAX][MAX], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

bool request_resources(int process_number, int request[])
{
    for (int i = 0; i < m; i++)
    {
        if (request[i] > need[process_number][i])
        {
            cout << "Error: Process has exceeded its maximum claim.\n";
            return false;
        }
        if (request[i] > avail[i])
        {
            cout << "Error: Resources are not available.\n";
            return false;
        }
    }

    for (int i = 0; i < m; i++)
    {
        avail[i] -= request[i];
        alloc[process_number][i] += request[i];
        need[process_number][i] -= request[i];
    }

    if (safety())
    {
        cout << "Request can be granted.\n";
        return true;
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            avail[i] += request[i];
            alloc[process_number][i] -= request[i];
            need[process_number][i] += request[i];
        }
        cout << "Request cannot be granted.\n";
        return false;
    }
}

int main()
{
    int i, j, total_alloc = 0;
    char ch;
    cout << "Enter the number of Processes: ";
    cin >> n;
    cout << "Enter the number of Resources types: ";
    cin >> m;

    cout << "Enter the Total instances of each Resource: ";
    for (i = 0; i < m; i++)
    {
        cin >> total_resrc[i];
    }

    cout << "Enter the Allocation Matrix: \n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> alloc[i][j];
        }
    }

    cout << "Enter the Max Matrix: \n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> maxr[i][j];
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need[i][j] = maxr[i][j] - alloc[i][j];
        }
    }

    cout << "Need Matrix is: " << endl;
    displaymat(need, n, m);

    for (j = 0; j < m; j++)
    {
        total_alloc = 0;
        for (i = 0; i < n; i++)
        {
            total_alloc += alloc[i][j];
            // cout << "alloc[" << i << "][" << j << "]: " << alloc[i][j] << " ";
        }
        // cout << "Total Allocation of Resource " << j << ": " << total_alloc << endl;
        avail[j] = total_resrc[j] - total_alloc;
    }
    cout << "Available Resources: ";
    for (i = 0; i < m; i++)
    {
        cout << avail[i] << " ";
    }
    cout << endl;

    safety();

    while (true)
    {
        cout << "\nDo you want to request resources for a process? (y/n): ";
        cin >> ch;
        if (ch == 'n')
            break;
        cout << "Enter the process number: ";
        cin >> i;
        cout << "Enter the request array: ";
        for (j = 0; j < m; j++)
        {
            cin >> req[j];
        }

        request_resources(i, req);
    }

    return 0;
}
