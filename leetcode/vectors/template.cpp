#include <iostream>
#include <string>

using namespace std;

template<typename T>
void print(T out){
    cout << out << endl;
}
template<typename type,int size>
class Array
{
    private :
        type  arr[size];
    public :
        int GetSize() {return size;};
};

int main ()
{
    print(123);
    print("mohamed");
    print('m');

    Array<int,5> array;
    cout << array.GetSize() << endl;

}