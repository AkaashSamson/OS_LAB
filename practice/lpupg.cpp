// #include <iostream>
// using namespace std;

// int main()
// {
//     int f, n, faults = 0;

//     cout << "Enter no. of frames: ";
//     cin >> f;
//     cout << "Enter no. of pages: ";
//     cin >> n;

//     int pages[n], frame[f], recent[f];

//     cout << "Enter page reference: ";
//     for (int i = 0; i < n; i++)
//         cin >> pages[i];

//     for (int j = 0; j < f; j++)
//     {
//         frame[j] = -1;
//         recent[j] = -1;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         int page = pages[i];
//         bool found = false;

//         for (int j = 0; j < f; j++)
//         {
//             if (page == frame[j])
//             {
//                 found = true;
//                 recent[j] = i; // Update recent use
//                 break;
//             }
//         }

//         if (!found)
//         {
//             int lru_index = 0;
//             for (int j = 1; j < f; j++)
//             {
//                 if (recent[j] < recent[lru_index])
//                     lru_index = j;
//             }

//             frame[lru_index] = page;
//             recent[lru_index] = i;
//             faults++;
//         }

//         cout << "Page " << page << " : ";
//         for (int j = 0; j < f; j++)
//         {
//             if (frame[j] == -1)
//                 cout << "[ ] ";
//             else
//                 cout << "[" << frame[j] << "] ";
//         }

//         cout << "Page ";
//         if (!found)
//             cout << "fault\n";
//         else
//             cout << "hit\n";
//     }

//     cout << "Total page faults: " << faults << "\n";
// }

#include <iostream>

using namespace std;

int main()
{
    int f, n, faults = 0, index = 0;

    cout << "Enter no. of frames: ";
    cin >> f;
    cout << "Enter no. of pages: ";
    cin >> n;

    int pages[n], frame[f], recent[f];

    cout << "Enter page reference: ";
    for (int i = 0; i < n; i++)
        cin >> pages[i];

    for (int j = 0; j < f; j++)
    {
        frame[j] = -1;
        recent[j] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        int page = pages[i];
        bool found = false;

        for (int j = 0; j < f; j++)
        {
            if (page == frame[j])
            {
                found = true;
                recent[j] = i;
                break;
            }
        }

        if (!found)
        {
            int lruindex = 0;
            for (int j = 0; j < f; j++)
            {
                if (recent[j] < recent[lruindex])
                    lruindex = j;
            }

            frame[lruindex] = page;
            recent[lruindex] = i;
            faults++;
        }

        cout << "Page " << page << " : ";
        for (int j = 0; j < f; j++)
        {
            if (frame[j] == -1)
                cout << "[ ] ";
            else
                cout << "[" << frame[j] << "] ";
        }

        cout << "Page ";
        if (!found)
            cout << "fault\n";
        else
            cout << "hit\n";
    }

    cout << "Total page faults: " << faults << "\n";
}