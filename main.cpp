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
T* add_array(T* arr, T size, T switch_on)
{
   /* T* arr = new T[size];*/
    T* arrn = new T[size];
    if (switch_on == 2)
    {
        for (size_t i = 0, j = 0; i < size; i++)
        {
            if (arr[i] % 2 == 0)
            {
                // delete odds
                arrn[i] = arr[i];
                j++;
            }
        }
    }
    if (switch_on == 1)
    {
        for (size_t i = 0, j = 0; i < size; i++)
        {
            if (arr[i] % 2 != 0)
            {
                // delete evens
                arrn[i] = arr[i];
                j++;
            }
        }
    }
   
    return arrn;
}

int main()
{
    srand(time(0));
    int size, switch_on;
    cout << "Enter size: ";
    cin >> size;   
    int* arr1 = new int[size];
    cout << "Enter array:" << endl;
    for (size_t i = 0; i < size; i++)
    {
        cout << "->";
        cin >> arr1[i];
    }
    cout << "Enter [1] to delete even numbers || Enter [2] to delete odd numbers -> ";
    cin >> switch_on;
    if (switch_on < 1 || switch_on > 2)
    {
        cout << "Choice out of range! Try again" << endl;
        exit(0);
    }
    cout << "Originl Array:\t";
    for (size_t i = 0; i < size; i++)
    {
        cout << arr1[i] << "\t";
    }
    cout << endl;
    int* arr = add_array<int>(arr1, size, switch_on);
    cout << "Cleared Array:" << "\t";
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] != -842150451)
        {
            cout << arr[i] << "\t";
        }
    }
    return 0;
}