#include <iostream>
#include <vector>


using namespace std;


int main () {

    vector<int> a = {1,2,3,4};

    vector <int> b(a.size()) ;

    int x = a.size();

    for (int i = 0; i < a.size(); i++)
    {
        b[i] = a[--x]; 
    }

    for(auto elm : b) {
        cout << elm <<endl;
    }
    
}