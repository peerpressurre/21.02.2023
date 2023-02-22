#include <iostream>
#include <ctime>
using namespace std;

int* Positive(int* arr, int size)
{
    int* arr2 = new int[size];
    int i, j = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] > 0)
        {
            arr2[j] = arr[i];
            j++;
        }
    }
    arr2[j] = 0;
    return arr2;
}

int main()
{
    srand(time(0));
    int size;
    cout << "Enter size: ";
    cin >> size;
    int* arr = new int[size];
    cout << "Original Array:\t";
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand() % 21 - 10;
        cout << arr[i] << "\t";
    }  
    cout << endl;
    int *arr2 = Positive(arr, size);
    cout << "Changed Array:\t";
    for (size_t i = 0; i < size; i++)
    {
        if (arr2[i] != -842150451)
        {
            cout << arr2[i] << "\t";
        }
    }
    cout << "Sizeof: " << sizeof(arr2) << endl;
    delete[] arr; 
    delete[] arr2;
    return 0;
}
