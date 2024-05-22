#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // vector<int> nums = {1,2,3,4,5,2,5,3,7,2,7,1,5,3,2,1,6,2};
    // vector<int>::iterator first = nums.begin();
    // auto last = nums.end() ;

    // cout << "first element is :" <<  first[1] <<endl;
    // cout << "second element is :" << first[2] <<endl;


    // cout << "last element is :" <<  *last <<endl;
    // cout << "before last element is :" << last[-2] <<endl;

    // advance(first,3); //5
    // cout << "iterator after adance :" <<  first[1] <<endl;

    // advance(first,-1); //4
    // cout << "iterator after adance :" <<  first[1] <<endl;

    // vector<int>::iterator it;
    // for(it = nums.begin() ; it < nums.end() ; ++it){
    //     cout << *it <<endl;
    // }

    // cout << "==================" <<endl;

    // int value = 2;
    // int counter = count(first , last , value);

    // cout <<counter << endl;
    // cout << "==================" <<endl;

    // for(auto &elm : nums){
    //     cout << elm <<endl;
    // }
    // cout << "==================" <<endl;

    // sort(first , last);

    // for(auto &elm : nums){
    //     cout << elm <<endl;
    // }


    vector<int> nums = {1,2,3,4,5,2,5,3,7,2,7,1,5,3,2,1,6,2};

    vector<int>::iterator ite ;

    for (ite = nums.begin(); ite != nums.end(); ite++)
    {
        cout << *ite << " ";
    }
    
    


};