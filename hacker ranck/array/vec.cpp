#include <iostream>
#include <assert.h>

using namespace std;

class Vector
{

    private :

        int* arr = nullptr;

        int size = 0;

        int capacity ;

    public :

        Vector (int size) :

        size{size} {

        if (size < 0 ) size =1;
        capacity = size + 10;

        arr = new int[capacity];

        }



        ~Vector() {

        delete[] arr;

        arr = nullptr;

        }



        int get(int index) {

        assert(0 <= index && index >= size);

        return arr[index];

        }



        void set(int index , int value) {

        assert(0 <= index && index <= size);

        arr[index] = value;

        }



        void print () {

        for (int i = 0; i < size; i++)

        {

        cout << arr[i] << " ";

        }

        cout <<endl;

        }



        int find(int value) {

        for (int i = 0; i < size; i++)

        {

        if (arr[i] == value)

        {

        return i;

        }

        }

        return -1;

        }

        void append(int value) {
            if (size == capacity)  expand_capacity();
            
            arr[size++] = value;
            
        }

        void expand_capacity() {
            capacity *= 2;
            int* arr2 = new int[capacity];

            for (int i = 0; i < size; i++)
            {
                arr2[i] = arr[i];
            }

            swap(arr2 , arr);
            delete[] arr2;
            
        }

        void insert(int index , int value) {
            assert(0 <= index && index <= size);
            if (size == capacity) expand_capacity();

            for (int i = size - 1; i >= index; i--)
            {
                arr[i+1] = arr[i]; 
            }

            arr[index] = value;

            size ++;
            
        }

        void right_rotation() {
            int temp = arr[size-1];

            for (int i = size - 2; i >= 0; i--)
            {
                arr[i + 1] = arr[i];
            }

            arr[0] = temp;
            
        }

        void left_rotation() {
            int temp = arr[0];

            for (int i = 0; i < size; i++)
            {
                arr[i ] = arr[i + 1 ];
            }

            arr[size - 1] = temp;
            
        }

        void right_rotate(int times) {
            int ponus = times % size;
            for (int i = 0; i < ponus; i++)
            {
                right_rotation();
            }
            
        }

        

};


int main ()
{
    Vector v(10);

    for (int i = 0; i < 10; i++)
    {
        v.set(i,i);
    }

    v.print();

    v.append(10);
    v.print();

    v.right_rotation();
    v.print();

    v.left_rotation();
    v.print();

    v.right_rotate(2000);
    v.print();

    cout << "--------------";


     
}