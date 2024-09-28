#include <iostream>

using namespace std;


int main ()
{
    int row = 3,column = 4;
//     cin >> row >> column;
    
//     int arr [row][column];

    int arr[3][4] {
        {8 , 16 ,9 ,52},
        {3 , 15 ,27,6 },
        {14 ,25 ,2 ,10}
    };

    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < column; j++)
    //     {
    //         cin >> arr[i][j];
    //     }
        
    // }

    cout << "----------------" <<endl;

    int l_sum;

    for (int i = 0; i < row; i++)
    {
        l_sum += arr[i][i];
    }
    
    cout << l_sum << endl;
  
    cout << "----------------" <<endl;

    int r_sum;
    for (int r = 0 , c = column - 1  ; r < row && c > 0; r++ , c--)
    {
        r_sum += arr[r][c];
    }
    
        cout << r_sum << endl;

    cout << "----------------" <<endl;
    
    int last_row= 0;
    for (int i = 0; i < column; i++)
    {
        last_row += arr[row - 1][i];
    }

    cout << last_row << endl;

    cout << "----------------" <<endl;
    
    int last_column= 0;
    for (int i = 0; i < row; i++)
    {
        last_column += arr[i][column - 1];
    }

    cout << last_column << endl;

    cout << "----------------" <<endl;

}