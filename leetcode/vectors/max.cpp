#include <iostream>

using namespace std;


int main ()
{
    int row ,column;
    cin >> row >> column;
    
    int arr [row][column];

    int max = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] > max) max = arr[i][j];
        }
        
    }

    cout << max;


    
}