#include <iostream>
#include <ctime>
using namespace std;

template<typename T>
T* init_array(size_t size)
{
    T* arr = new T[size];
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = T(rand() % 10);
    }
    return arr;
}

template<typename T>
void print_array(T* arr, int size = -1)
{
    if (size == -1)
    {
        size = _msize(arr) / sizeof * arr;
    }
    for (size_t i = 0; i < size; i++)
    {
        cout << *(arr + i) << '\t';
    }
    cout << endl;
}

//template<typename T>
int summul(int* arr, int size, int* sum, int* mul)
{
    *sum = 0;
    *mul = 1;
    for (int i = 0; i < size; i++)
    {
        *sum += arr[i];
        *mul *= arr[i];
    }
    return *sum;
    return *mul;
}

int main()
{
    srand(time(0));
    int size, sum = 0, mul = 1;
    int* sumptr = &sum;
    int* mulptr = &mul;
    cout << "Enter size: ";
    cin >> size;
    int* arr = new int[size];
    cout << "Array:\t";
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand() % 10;
        cout << arr[i] << "\t";
    }  
    int* arrptr = arr;
    cout << endl;
    summul(arr, size, sumptr, mulptr);
    cout << "Sum: " << *sumptr << "\n" << "Mul: " << *mulptr;
    return 0;
}