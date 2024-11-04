#include <iostream>
#define MAX 50

using namespace std;

int n, req_seq[MAX], current_head, traversal[MAX + 1];
char direction;

void sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int move_left(int left[], int left_size, int &current_head, int traversal[], int &index)
{
    int total_head_movement = 0;
    for (int i = left_size - 1; i >= 0; --i)
    {
        total_head_movement += abs(current_head - left[i]);
        current_head = left[i];
        traversal[index++] = current_head;
    }
    return total_head_movement;
}

int move_right(int right[], int right_size, int &current_head, int traversal[], int &index)
{
    int total_head_movement = 0;
    for (int i = 0; i < right_size; ++i)
    {
        total_head_movement += abs(current_head - right[i]);
        current_head = right[i];
        traversal[index++] = current_head;
    }
    return total_head_movement;
}

int look(const int req_seq[], int n, int current_head, char direction, int traversal[], int &index)
{
    int left[MAX], right[MAX];
    int left_size = 0, right_size = 0;
    int total_head_movement = 0;
    traversal[0] = current_head;

    // Separate requests into left and right of the current head
    for (int i = 0; i < n; ++i)
    {
        if (req_seq[i] < current_head)
            left[left_size++] = req_seq[i];
        else if (req_seq[i] > current_head)
            right[right_size++] = req_seq[i];
    }

    if (direction == 'L' || direction == 'l')
        right[right_size++] = current_head;
    else if (direction == 'R' || direction == 'r')
        left[left_size++] = current_head;

    // Sort the requests
    sort(left, left_size);
    sort(right, right_size);

    index = 1;

    if (direction == 'L' || direction == 'l')
    {
        total_head_movement += move_left(left, left_size, current_head, traversal, index);
        total_head_movement += move_right(right, right_size, current_head, traversal, index);
    }
    else if (direction == 'R' || direction == 'r')
    {
        total_head_movement += move_right(right, right_size, current_head, traversal, index);
        total_head_movement += move_left(left, left_size, current_head, traversal, index);
    }

    return total_head_movement;
}

int main()
{
    int index;
    cout << "Enter the number of requests: ";
    cin >> n;
    cout << "Enter the request sequence: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> req_seq[i];
    }

    cout << "Enter the initial head position: ";
    cin >> current_head;
    cout << "Enter the direction (L or R): ";
    cin >> direction;

    int total_head_movement = look(req_seq, n, current_head, direction, traversal, index);

    cout << "Total head movement: " << total_head_movement << endl;
    cout << "Traversal sequence: ";

    for (int i = 0; i < index - 1; ++i)
    {
        cout << traversal[i] << "->";
    }
    cout << traversal[index - 1] << endl;

    return 0;
}