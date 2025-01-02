#include <iostream>
#define MAX 10

using namespace std;

int alloc[MAX][MAX], maxe[MAX][MAX], need[MAX][MAX], avail[MAX], totalrs[MAX], req[MAX];
int n, m;

void displaytable()
{
    int i, j;
    cout << "\nAvailable - ";
    for (j = 0; j < m; j++)
    {
        cout << avail[j] << " ";
    }

    cout << "\n\n";
    cout << "Allocation\t\t Max\t\t Need\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << alloc[i][j] << " ";
        }
        cout << "\t\t\t";

        for (j = 0; j < m; j++)
        {
            cout << maxe[i][j] << " ";
        }
        cout << "\t\t";

        for (j = 0; j < m; j++)
        {
            cout << need[i][j] << " ";
        }
        cout << "\n";
    }
}
void getmat(int mat[MAX][MAX])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
}

void showmat(int mat[MAX][MAX])
{
    int i, j, cnt = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}

bool safety()
{
    displaytable();
    int work[n], i, seq[n], idx = 0, cnt, j;
    bool finish[n], found = false, safe = false;

    for (i = 0; i < n; i++)
    {
        work[i] = avail[i];
        finish[i] = false;
    }

    for (cnt = 0; cnt < n; cnt++)
    {
        found = false;
        safe = true;

        for (i = 0; i < n; i++)
        {
            if (!finish[i])
            {
                found = true;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        found = false;
                        break;
                    }
                }

                if (found)
                    break;
            }
        }

        if (!found)
        {
            safe = false;
            break;
        }

        else
        {

            for (j = 0; j < m; j++)
            {
                work[j] += alloc[i][j];
            }
            seq[idx++] = i;
            finish[i] = true;
        }
    }

    if (safe)
    {
        cout << "Safe seq exists\n";
        cout << "Seq: ";
        for (i = 0; i < idx - 1; i++)
            cout << 'P' << seq[i] << "->";
        cout << 'P' << seq[i] << "\n";
        return true;
    }

    else
    {
        cout << "Safe seq doesnt exist\n";
        return false;
    }
}

void alloc_rsrc(int req[MAX], int p)
{
    for (int j = 0; j < m; j++)
    {
        avail[j] -= req[j];
        alloc[p][j] += req[j];
        need[p][j] -= req[j];
    }
}

void dealloc_rsrc(int req[MAX], int p)
{
    for (int j = 0; j < m; j++)
    {
        avail[j] += req[j];
        alloc[p][j] -= req[j];
        need[p][j] += req[j];
    }
}

bool request(int p, int req[MAX])
{

    cout << "Test\n";
    int i, j;
    for (j = 0; j < m; j++)
    {
        if (req[j] > avail[j])
        {
            cout << "Requesting for more than available\n";
            return false;
        }
    }

    for (j = 0; j < m; j++)
    {
        if (req[j] > need[p][j])
        {
            cout << "Requesting for more than needed\n";
            return false;
        }
    }

    alloc_rsrc(req, p);

    bool present = false;
    for (j = 0; j < m; j++)
    {
        if (avail[j] > 0)
        {
            present = true;
        }
    }
    if (!present)
    {
        cout << "Requesting for more than 50 percent of the resources\n";
        return false;
    }

    if (safety())
    {
        return true;
    }
    else
    {
        cout << "Not safe";
        dealloc_rsrc(req, p);
        return false;
    }
}

int main()
{
    char ch;
    int p;
    cout << "Enter the number of the processes: ";
    cin >> n;

    cout << "Enter the number of resources: ";
    cin >> m;

    // int alloc[n][m], max[n][m], need[n][m], avail[m], totalrs[m], i, j;
    int i, j;

    cout << "Enter the available resources: ";
    for (j = 0; j < m; j++)
    {
        cin >> avail[j];
    }

    cout << "Enter the allocation matrix: \n";
    getmat(alloc);

    cout << "Enter the Max matrix: \n";
    getmat(maxe);

    cout << "Need matrix: \n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need[i][j] = maxe[i][j] - alloc[i][j];
        }
    }

    showmat(need);

    int sum;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            sum += alloc[j][i];
        }
        totalrs[i] = sum + avail[i];
    }

    safety();

    while (true)
    {
        cout << "Do you want to continue (y/n): ";
        cin >> ch;
        if (ch == 'n')
            break;
        else
        {
            cout << "Enter the process requesting for resources: ";
            cin >> p;
            cout << "Enter the request array: \n";
            for (j = 0; j < m; j++)
            {
                cin >> req[j];
            }
            if (request(p, req))
                cout << "Request can be granted\n";
            else
                cout << "Request cannot be granted\n";
        }
    }
}
