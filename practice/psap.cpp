// #include <iostream>
// using namespace std;

// struct pri
// {
//     int pid, at, bt, ct, tat, wt, pri, rem;
// };

// struct pri a[100];

// void premp(pri a[], int n)
// {
//     int complete = 0, sum = 0, highestpri = 100;
//     int hi = -1, prev = -1;
//     bool check = false;
//     cout << "| ";

//     while (complete != n)
//     {
//         highestpri = 100;
//         check = false;

//         for (int i = 0; i < n; i++)
//         {
//             if (a[i].at <= sum && a[i].rem > 0)
//             {
//                 if (a[i].pri < highestpri || (a[i].pri == highestpri && a[i].at < a[hi].at))
//                 {
//                     highestpri = a[i].pri;
//                     hi = i;
//                     check = true;
//                 }
//             }
//         }

//         if (!check)
//         {
//             sum++;
//             continue;
//         }

//         a[hi].rem--;
//         if (a[hi].rem == 0)
//         {
//             complete++;
//             a[hi].ct = sum + 1;
//             a[hi].tat = a[hi].ct - a[hi].at;
//             a[hi].wt = a[hi].tat - a[hi].bt;
//         }
//         sum++;
//     }

//     cout << "\nProcess\tAT\tBT\tTAT\tWT\n";
//     for (int i = 0; i < n; i++)
//     {
//         cout << "P" << a[i].pid << "\t" << a[i].at << "\t" << a[i].bt << "\t" << a[i].tat << "\t" << a[i].wt << endl;
//     }
// }

// int main()
// {
//     int n;
//     cout << "Enter number of processes: ";
//     cin >> n;

//     cout << "Enter the arrival time and burst time\n";
//     for (int i = 0; i < n; i++)
//     {
//         cout << "P" << i << ": ";
//         a[i].pid = i + 1;
//         cin >> a[i].at >> a[i].bt >> a[i].pri;
//         a[i].rem = a[i].bt;
//     }

//     premp(a, n);
// }

#include <iostream>

using namespace std;

struct process
{
    int no, at, bt, pr, ct, tat, wt, rt;
};

void psap(process p[], int n)
{
    int i, sum = 0, highpri = 100, hi = -1, complete = 0, idx = 0;
    bool check = false;

    while (complete != n)
    {
        highpri = 100;
        check = false;
        // cout << sum << " ";

        for (i = 0; i < n; i++)
        {
            if (p[i].at <= sum && p[i].rt > 0)
            {
                if ((p[i].pr < highpri) || (p[i].pr == highpri && p[i].at < p[hi].at))
                {
                    highpri = p[i].pr;
                    hi = i;
                    check = true;
                }
            }
        }

        if (!check)
        {
            sum++;
            continue;
        }

        p[hi].rt--;
        sum++;

                if (p[hi].rt == 0)
        {
            p[hi].ct = sum;
            p[hi].tat = p[hi].ct - p[hi].at;
            p[hi].wt = p[hi].tat - p[hi].bt;
            complete++;
            cout << sum << "\n";
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    process p[n];
    int i;

    cout << "Enter the arrival burst and priorities: \n";
    for (i = 0; i < n; i++)
    {
        cin >> p[i].at >> p[i].bt >> p[i].pr;
        p[i].no = i + 1;
        p[i].rt = p[i].bt;
    }

    for (i = 0; i < n; i++)
    {
        cout << p[i].pr << " ";
    }

    psap(p, n);

    for (i = 0; i < n; i++)
    {
        cout << p[i].pr << " ";
    }
    cout << "\n";

    cout << "\n\n";
    cout << "ID\t" << "AT\t" << "BT\t" << "PR\t" << "CT\t" << "TAT\t" << "WT\n";
    for (i = 0; i < n; i++)
    {
        cout << "P" << p[i].no << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].pr << "\t" << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << "\n";
    }
}
