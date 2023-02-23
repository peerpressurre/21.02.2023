#include <iostream>
#include <ctime>
using namespace std;

int* AddBlock(int* arr, int* block, int size_arr, int size_block, int index)
{
    int size = size_arr + size_block;
    int* arr2 = new int[size];
    for (size_t i = 0, j = 0, k = 0; i < size; i++)
    {
        if (i < index)
        {
            arr2[i] = arr[k];
            k++;
        }
        else if (i >= index && i < size_block + index)
        {
            arr2[i] = block[j];
            j++;
        }
        else
        {
            arr2[i] = arr[k];
            k++;
        }
    }
    return arr2;
}

int main()
{
    srand(time(0));
    int size_arr, size_block, index;
    cout << "Enter size of an array: ";
    cin >> size_arr;
    cout << "Enter size of block: ";
    cin >> size_block;
    cout << "Enter index: ";
    cin >> index;
    int* arr = new int[size_arr];
    int* block = new int[size_block];
    cout << "Original Array:\t";
    for (size_t i = 0; i < size_arr; i++)
    {
        arr[i] = rand() % 10;
        cout << arr[i] << "\t";
    }
    cout << endl;
    cout << "Block:\t\t";
    for (size_t i = 0; i < size_block; i++)
    {
        block[i] = rand() % 10;
        cout << block[i] << "\t";
    }
    cout << endl;
    int* arr2 = AddBlock(arr, block, size_arr, size_block, index);
    cout << "Updated array:\t";
    for (size_t i = 0; i < size_arr + size_block; i++)
    {
        cout << arr2[i] << "\t";
    }
    delete[] arr;
    delete[] arr2;
    delete[] block;
    return 0;
}