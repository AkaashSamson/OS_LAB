// #include <iostream>
// using namespace std;

// int main()
// {
//     int f, n, faults = 0;

//     cout << "Enter no. of frames: ";
//     cin >> f;
//     cout << "Enter no. of pages: ";
//     cin >> n;

//     int pages[n], frame[f];

//     cout << "Enter page reference: ";
//     for (int i = 0; i < n; i++)
//         cin >> pages[i];

//     for (int j = 0; j < f; j++)
//     {
//         frame[j] = -1;
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
//                 break;
//             }
//         }

//         if (!found)
//         {
//             int replace_index = -1, farthest = i;
//             for (int j = 0; j < f; j++)
//             {
//                 if (frame[j] == -1)
//                 {
//                     replace_index = j;
//                     break;
//                 }

//                 int next_use = n; // Default: not used again
//                 for (int k = i + 1; k < n; k++)
//                 {
//                     if (frame[j] == pages[k])
//                     {
//                         next_use = k;
//                         break;
//                     }
//                 }

//                 if (next_use > farthest)
//                 {
//                     farthest = next_use;
//                     replace_index = j;
//                 }
//             }

//             frame[replace_index] = page;
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

