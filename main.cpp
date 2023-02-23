#include <iostream>
#include <ctime>
using namespace std;

int* AddBlock(int* arr, int size, int index)
{  
    int* arr2 = new int[size-1];
    for (size_t i = 0; i < size-1; i++)
    {
        if (i < index)
        {
            arr2[i] = arr[i];
        }
        else if (i >= index)
        {
            arr2[i] = arr[i + 1];
        }
    }
    return arr2;
}

int main()
{
    srand(time(0));
    int size, index;
    cout << "Enter size of an array: ";
    cin >> size;
    cout << "Enter index: ";
    cin >> index;
    int* arr = new int[size];
    cout << "Original Array:\t";
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand() % 10;
        cout << arr[i] << "\t";
    }
    cout << endl;
    int* arr2 = AddBlock(arr, size, index);
    cout << "Updated array:\t";
    for (size_t i = 0; i < size - 1; i++)
    {
        cout << arr2[i] << "\t";
    }
    delete[] arr;
    delete[] arr2;
    return 0;
}