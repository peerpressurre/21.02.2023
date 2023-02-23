#include <iostream>
#include <ctime>
using namespace std;

int* AddBlock(int* arr, int* block, int size1, int size2)
{
    int size = size1 + size2;
    int* arr2 = new int[size];
    for (size_t i = 0, j = 0; i < size; i++)
    {
        if (i < size1)
        {
            arr2[i] = arr[i];
        }
        else
        {
            arr2[i] = block[j];
            j++;
        }
    }
    return arr2;
}

int main()
{
    srand(time(0));
    int size1, size2;
    cout << "Enter size of an array: ";
    cin >> size1;
    cout << "Enter size of block to add: ";
    cin >> size2;
    int* arr = new int[size1];
    int* block = new int[size2];
    cout << "Original Array:\t";
    for (size_t i = 0; i < size1; i++)
    {
        arr[i] = rand() % 10;
        cout << arr[i] << "\t";
    }
    cout << endl;
    cout << "Block:\t\t";
    for (size_t i = 0; i < size2; i++)
    {
        block[i] = rand() % 10;
        cout << block[i] << "\t";
    }
    cout << endl;
    int* arr2 = AddBlock(arr, block, size1, size2);
    cout << "Updated array:\t";
    for (size_t i = 0; i < size1 + size2; i++)
    {
        cout << arr2[i] << "\t";
    }
    return 0;
}