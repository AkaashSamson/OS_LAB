// #include <iostream>
// using namespace std;

// int main()
// {
//     int n, f, faults = 0;
//     cout << "Enter number of Frames: ";
//     cin >> f;
//     cout << "Enter number of Pages: ";
//     cin >> n;

//     int pages[n], frames[f], index = 0;
//     for (int i = 0; i < n; i++)
//         cin >> pages[i];

//     // Initialize frames with -1 (empty)
//     for (int i = 0; i < f; i++)
//         frames[i] = -1;

//     for (int i = 0; i < n; i++)
//     {
//         int page = pages[i];
//         bool page_hit = false;

//         // Check if page is already in frames
//         for (int j = 0; j < f; j++)
//         {
//             if (frames[j] == page)
//             {
//                 page_hit = true;
//                 break;
//             }
//         }

//         cout << "Page " << page << " : ";
//         if (!page_hit)
//         {
//             // Replace the oldest page (index tracks FIFO order)
//             frames[index] = page;
//             index = (index + 1) % f; // Circular replacement
//             faults++;

//             // Display frames
//             for (int j = 0; j < f; j++)
//             {
//                 if (frames[j] == -1)
//                     cout << "[ ] ";
//                 else
//                     cout << "[" << frames[j] << "] ";
//             }
//             cout << "Page fault\n";
//         }
//         else
//         {
//             // Display frames
//             for (int j = 0; j < f; j++)
//             {
//                 if (frames[j] == -1)
//                     cout << "[ ] ";
//                 else
//                     cout << "[" << frames[j] << "] ";
//             }
//             cout << "Page hit\n";
//         }
//     }

//     cout << "Number of page faults: " << faults << endl;
//     return 0;
// }

//

#include <iostream>

using namespace std;

int main()
{
    int f, n, faults = 0, index = 0, farthest, rep_index, next_pos;

    cout << "Enter no. of frames: ";
    cin >> f;
    cout << "Enter no. of pages: ";
    cin >> n;
    int pages[n], frame[f];

    cout << "Enter page reference: ";
    for (int i = 0; i < n; i++)
        cin >> pages[i];

    for (int j = 0; j < f; j++)
    {
        frame[j] = -1;
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
                break;
            }
        }

        if (!found)
        {
            farthest = i;

            for (int j = 0; j < f; j++)
            {

                if (frame[j] == -1)
                {
                    rep_index = j;
                    break;
                }

                next_pos = n;

                for (k = i + 1; k < n; k++)
                {
                    if (frame[j] == page[k])
                    {
                        next_pos = k;
                        break;
                    }

                    if (farthest < next_pos)
                    {
                        farthest = next_pos;
                        rep_index = j;
                    }
                }
            }

            frame[rep_index] = page;
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