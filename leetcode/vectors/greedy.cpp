#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int maze[3][3] = {
        {10 , 15 ,10},
        {5 , 10 ,25 },
        {10 ,5  ,10}
    };

    int collection = 0;
    int column = 0;
    int row = 0;

        while(row + 1 <= 3 && column + 1 <=3)
        {
            
                
            int a = maze[row][column + 1];
            int b = maze[row + 1][column + 1];
            int c = maze[row + 1][column];

            int mx = max(a , max(b , c));

            if (mx == a)
            {
                collection += a;
                column++; 
            }else if (mx == b){
                collection += b;
                column++;
                row++;
            }else{
                collection += b;
                row++;
                
            }
            
        }

        cout << collection ;
        
            
            
            



}