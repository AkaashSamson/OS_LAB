#include <iostream>

using namespace std;

struct process
{
    int no, at, bt, ct, tat, wt, rt;
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
                if ((p[i].rt < highpri) || (p[i].rt == highpri && p[i].at < p[hi].at))
                {
                    highpri = p[i].rt;
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
        cin >> p[i].at >> p[i].bt;
        p[i].no = i + 1;
        p[i].rt = p[i].bt;
    }

    psap(p, n);

    cout << "\n\n";
    cout << "ID\t" << "AT\t" << "BT\t" << "CT\t" << "TAT\t" << "WT\n";
    for (i = 0; i < n; i++)
    {
        cout << "P" << p[i].no << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << "\n";
    }
}
