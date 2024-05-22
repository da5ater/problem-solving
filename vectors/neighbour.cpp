#include <iostream>
#include <vector>

using namespace std;


bool IsValid(int r , int c , int NColumns , int NRows){
    if (r < 0 || c < 0 || r > NRows - 1 || c > NColumns - 1) 
    {
        return 0;
    }

    return 1;
    
}

vector<int> GetAdjacent(vector <vector <int>> &arr ,int  r ,int  c)
{
    // to check for bounds 
    int NRows = arr.size();
    int NColumns  = arr[0].size();

    vector <int> NewArr;
    

    if (IsValid(r-1 , c-1 ,NColumns, NRows))
    {
        NewArr.push_back(arr[r-1][c-1]);
    }
    if (IsValid(r-1 , c ,NColumns, NRows))
    {
        NewArr.push_back(arr[r-1][c]);
    }
    if (IsValid(r-1 , c+1 ,NColumns, NRows))
    {
        NewArr.push_back(arr[r-1][c+1]);
    }
    if (IsValid(r , c-1 ,NColumns, NRows))
    {
        NewArr.push_back(arr[r][c-1]);
    }
    if (IsValid(r , c+1 ,NColumns, NRows))
    {
        NewArr.push_back(arr[r][c+1]);
    }
    if (IsValid(r+1 , c+1 ,NColumns, NRows))
    {
        NewArr.push_back(arr[r+1][c+1]);
    }
    if (IsValid(r+1 , c ,NColumns, NRows))
    {
        NewArr.push_back(arr[r+1][c]);
    }
    if (IsValid(r+1 , c-1 ,NColumns, NRows))
    {
        NewArr.push_back(arr[r+1][c-1]);
    }

        return NewArr;




}
int main ()
{
    vector<vector <int>> arr {
        {1 , 2 , 3},
        {4 , 5 , 6},
        {7 , 8 , 9},
    };

    // position of element we want to find it's neighbour 
    int r =2, c = 2;

    vector<int> neighbours= GetAdjacent(arr , r , c);

    for (auto &i : neighbours)
    {
        cout << i << " ";
    }
    
}