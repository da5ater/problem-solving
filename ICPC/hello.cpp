#include <iostream>
#include <string>

using namespace std;

int main()
{
    string x = "bob";

    cout << std::string(x.rbegin(), x.rend());
}