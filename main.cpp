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

template<typename T>
T* add_array(size_t size, int size_a, int size_b)
{
    T* arr = new T[size];
    T* arr_a = init_array<int>(size_a);;
    T* arr_b = init_array<int>(size_b);
    cout << "Array A:" << "\t";
    print_array<int>(arr_a);
    cout << "Array B:" << "\t";
    print_array<int>(arr_b);

    for (size_t i = 0; i < size_a; i++)
    {
        arr[i] = arr_a[i];

    }
    for (size_t i = size_a, j = 0; i < size; i++, j++)
    {
        arr[i] = arr_b[j];
    }
    return arr;
}

int main()
{
    srand(time(0));
    cout << "Enter size a: ";
    int size_a;
    cin >> size_a;

    cout << "Enter size b: ";
    int size_b;
    cin >> size_b;

    int size = size_a + size_b;
    int* arr_3 = add_array<int>(size, size_a, size_b);
    cout << "Final Array:" << "\t";
    print_array<int>(arr_3);

    return 0;
}