#include <iostream>

using namespace std;

void InsertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int current = arr[i];
        int IndexOfPrev = i - 1;

        while (IndexOfPrev > -1 && current < arr[IndexOfPrev])
        {
            swap(arr[IndexOfPrev + 1], arr[IndexOfPrev]);
            IndexOfPrev--;
        }
    }
}

void SelectionSort(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        int MinIndex = i;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[MinIndex])
            {
                MinIndex = j;
            }
        }

        if (MinIndex != i)
        {
            swap(arr[i], arr[MinIndex]);
        }
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    SelectionSort(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
