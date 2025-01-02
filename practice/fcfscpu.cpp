// //
// #include <iostream>
// using namespace std;

// struct Process {
//     int no, at, bt, ct, tat, wt;
// };

// void sortByArrival(Process p[], int n) {
//     for (int i = 0; i < n - 1; i++) {
//         for (int j = 0; j < n - i - 1; j++) {
//             if (p[j].at > p[j + 1].at) {
//                 Process temp = p[j];
//                 p[j] = p[j + 1];
//                 p[j + 1] = temp;
//             }
//         }
//     }
// }

// int main() {
//     int n;
//     cout << "Enter the number of processes: ";
//     cin >> n;

//     Process p[n];
//     cout << "Enter the burst times and arrival times of processes (bt at):\n";
//     for (int i = 0; i < n; i++) {
//         cin >> p[i].bt >> p[i].at;
//         p[i].no = i + 1;
//     }

//     sortByArrival(p, n);

//     int t = 0, totalTAT = 0, totalWT = 0;
//     cout << "Gantt Chart\n |";
//     for (int i = 0; i < n; i++) {
//         if (t < p[i].at) {
//             t = p[i].at;
//             cout << " idle |";
//         }
//         cout << "  P" << p[i].no << "  |";
//         p[i].ct = t + p[i].bt;
//         p[i].tat = p[i].ct - p[i].at;
//         p[i].wt = p[i].tat - p[i].bt;
//         t = p[i].ct;
//         totalTAT += p[i].tat;
//         totalWT += p[i].wt;
//     }

//     cout << "\n ";
//     t = 0;
//     if (p[0].at > 0) cout << p[0].at;
//     for (int i = 0; i < n; i++) {
//         if (i == 0 && p[0].at > 0) t = p[0].at;
//         cout << "      " << (t += p[i].bt);
//     }
//     cout << "\n";

//     cout << "Process \tArrival Time \tBurst Time \tCompletion Time \tTAT \tWT\n";
//     for (int i = 0; i < n; i++) {
//         cout << " P" << p[i].no << "\t\t" << p[i].at << "\t\t" << p[i].bt
//              << "\t\t" << p[i].ct << "\t\t" << p[i].tat << "\t" << p[i].wt << "\n";
//     }

//     cout << "Average Turnaround Time: " << (float)totalTAT / n << "\n";
//     cout << "Average Waiting Time: " << (float)totalWT / n << "\n";

//     return 0;
// }

#include <iostream>

using namespace std;

struct process
{
    int no, at, bt, ct, tat, wt;
};

void sortbyarr(process p[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (p[j].at > p[j + 1].at)
            {
                process tmp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tmp;
            }
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
    int n;

    cout << "Enter the no.of processes: ";
    cin >> n;

    process p[n];

    cout << "Enter the arrival and burst time: \n";
    int i, j;
    for (i = 0; i < n; i++)
    {
        cin >> p[i].at >> p[i].bt;
        p[i].no = i + 1;
    }

    sortbyarr(p, n);

    cout << "Gantt Chart: \n";
    cout << "|";
    int t = 0, totaltat = 0, totalwt = 0;

    for (i = 0; i < n; i++)
    {
        if (p[i].at > t)
        {
            t = p[i].at;
            cout << "  idle  |";
        }

        cout << "  P" << p[i].no << "  |";
        t = t + p[i].bt;
        p[i].ct = t;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        totaltat += p[i].tat;
        totalwt += p[i].wt;
    }

    cout << "\n";
    t = 0;
    if (p[0].at > 0)
        cout << p[0].at;
    else
        cout << 0;

    for (i = 0; i < n; i++)
    {
        cout << "      " << p[i].ct;
    }

    sortbyno(p, n);

    cout << "\n\n";
    cout << "ID\t" << "AT\t" << "BT\t" << "CT\t" << "TAT\t" << "WT\n";
    for (i = 0; i < n; i++)
    {
        cout << "P" << p[i].no << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << "\n";
    }
}