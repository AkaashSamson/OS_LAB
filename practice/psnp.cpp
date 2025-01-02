// #include <iostream>
// using namespace std;

// struct fcfs
// {
//     int pid, at, bt, ct, wt, tat, pri;
// };

// struct fcfs a[10];

// void prisort(fcfs a[], int n, int start, int sum)
// {
//     for (int i = start; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (a[j].at <= sum && (a[i].pri > a[j].pri))
//             {
//                 swap(a[i], a[j]);
//             }
//         }
//     }
// }

// int main()
// {
//     int n;
//     cout << "ENter n:";
//     cin >> n;

//     cout << "ENter at and bt and pri\n";
//     for (int i = 0; i < n; i++)
//     {
//         a[i].pid = i + 1;
//         cin >> a[i].at;
//         cin >> a[i].bt;
//         cin >> a[i].pri;
//     }

//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (a[i].at > a[j].at || (a[i].at == a[j].at && a[i].pri > a[j].pri))
//             {
//                 swap(a[i], a[j]);
//             }
//         }
//     }

//     int sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (a[i].at <= sum)
//         {
//             a[i].ct = sum + a[i].bt;
//             sum += a[i].bt;
//             a[i].tat = a[i].ct - a[i].at;
//             a[i].wt = a[i].tat - a[i].bt;
//             prisort(a, n, i + 1, sum);
//         }
//         else
//         {
//             sum++;
//             i--;
//         }
//     }

//     float totalTAT = 0, totalWT = 0;

//     cout << "\nProcess\tAT\tBT\tTAT\tWT\n";
//     for (int i = 0; i < n; i++)
//     {
//         cout << "P" << a[i].pid << "\t" << a[i].at << "\t" << a[i].bt << "\t" << a[i].tat << "\t" << a[i].wt << endl;

//         totalTAT += a[i].tat;
//         totalWT += a[i].wt;
//     }
// }

#include <iostream>

using namespace std;

struct process
{
    int no, at, bt, ct, tat, wt, pr;
};

void sort_pr(process p[], int st, int n, int ct)
{
    for (int i = st; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (p[j].at <= ct && p[i].pr > p[j].pr)
                swap(p[i], p[j]);
        }
    }
}

void sortbyno(process p[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (p[j].no > p[j + 1].no)
            {
                process tmp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tmp;
            }
        }
    }
}

int main()
{

    int n, i, j;

    cout << "Enter the number of processes: ";
    cin >> n;

    process p[n];

    cout << "Enter at,bt and pr: \n";

    for (i = 0; i < n; i++)
    {
        cin >> p[i].at >> p[i].bt >> p[i].pr;
        p[i].no = i + 1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (p[i].at > p[j].at || ((p[i].at > p[j].at) && (p[i].pr = p[j].pr)))
                swap(p[i], p[j]);
        }
    }

    int ct = 0, tltat = 0, tlwt = 0, tstmp[100], idx = 0;

    cout << "Gantt Chart: \n |";
    tstmp[idx++] = 0;

    for (i = 0; i < n; i++)
    {
        if (p[i].at <= ct)
        {
            cout << "  P" << p[i].no << "  |";
            ct += p[i].bt;
            p[i].ct = ct;
            p[i].tat = ct - p[i].at;
            p[i].wt = p[i].tat - p[i].bt;
            tltat += p[i].tat;
            tlwt += p[i].wt;
            sort_pr(p, i + 1, n, ct);
        }

        else
        {
            cout << "  idle  |";
            ct = p[i--].at;
        }

        tstmp[idx++] = ct;
    }

    cout << "\n";
    for (i = 0; i < idx; i++)
    {
        cout << tstmp[i] << "      ";
    }

    sortbyno(p, n);

    cout << "\n\n";
    cout << "ID\t" << "AT\t" << "BT\t" << "PR\t" << "CT\t" << "TAT\t" << "WT\n";
    for (i = 0; i < n; i++)
    {
        cout << "P" << p[i].no << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].pr << "\t" << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << "\n";
    }
}
