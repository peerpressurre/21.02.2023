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
T* no_rep(T* arr_a, T* arr_b, T size, T size_a, T size_b)
{
    T* arr = new T[size];
    int counter = 0;
    for (size_t i = 0; i < size_a; i++)
    {
       
        for (size_t n = i + 1; n < size_a; n++)
        {
            if (arr_a[i] == arr_a[n])
            {
                counter++;
            }
        }
        if (counter == 0)
        {
            arr[i] = arr_a[i];
        }
        counter = 0;
    }
    for (size_t i = 0, k = size_a; i < size_b; i++)
    {
        for (size_t j = 0; j < size_a; j++)
        {
            if (arr_b[i] == arr_a[j])
            {
                counter++;                        
            }
        }
        for (size_t n = i + 1; n < size_b; n++)
        {
            if (arr_b[i] == arr_b[n])
            {
                counter++;
            }
        }
        if (counter == 0)
        {
            arr[k] = arr_b[i];
            k++;  
        }
        counter = 0;
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
    
    int* arr_a = init_array<int>(size_a);
    int* arr_b = init_array<int>(size_b);
    cout << "Array A:" << "\t";
    print_array<int>(arr_a);
    cout << "Array B:" << "\t";
    print_array<int>(arr_b);
    int* arr_3 = no_rep<int>(arr_a, arr_b, size, size_a, size_b);
    cout << "Final Array:" << "\t";
    for (size_t i = 0; i < size; i++)
    {
        if (arr_3[i] != -842150451)
        {
            cout << arr_3[i] << "\t";

        }
    }
    delete[] arr_a;
    delete[] arr_b;
    delete[] arr_3;
    return 0;
}