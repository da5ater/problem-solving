#include <iostream>

using namespace std;


int main ()
{
    int row = 3,column = 4;

    int arr[row][column] {
        {8 , 16 ,9 ,52},
        {3 , 15 ,27,6 },
        {14 ,25 ,2 ,10}
    };

for (int r = 0; r < row; r++)
{
    for (int c = 0; c < column; c++)
    {
        cout << arr[r][c] << " ";
    }
    cout << endl;
}

    cout << "----------------------"<< endl;;
    
    int c1 =0; 
    int c2 =3; 

    for (int i  = 0; i < row; i++)
    {
        swap(arr[i][c1] , arr[i][c2]);
    }

    cout << "----------------------"<< endl;;

for (int r = 0; r < row; r++)
{
    for (int c = 0; c < column; c++)
    {
        cout << arr[r][c] << " ";
    }
    cout << endl;
}

}