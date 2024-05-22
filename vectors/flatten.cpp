#include <iostream>
#include <vector>
 
template<typename T>
std::vector<T> flatten(std::vector<std::vector<T>> const &vec)
{
    std::vector<T> flattened;
    for (auto const &v: vec) {
        flattened.insert(flattened.end(), v.begin(), v.end());
    }
    return flattened;
}
 
int main()
{
    std::vector<std::vector<int>> vec {
        { 1, 2, 3 }, { 4, 5 }, { 6, 7, 8, 9 }
    };
 
    std::vector<int> flattened = flatten(vec);
    for (int &i: flattened) {
        std::cout << i << ' ';
    }
 
    return 0;
}