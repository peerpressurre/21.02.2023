#include <iostream>
#include <ctime>
using namespace std;

int** DelCol(int** arr, int row, int col, int index)
{
    int** arr2 = new int* [row];
    for (int i = 0; i < row; i++)
    {
        arr2[i] = new int[col-1];
        for (int j = 0; j < col - 1; j++)
        {
            if (j < index)
            {
                arr2[i][j] = arr[i][j];
            }
            else if(j >= index)
            {
                arr2[i][j] = arr[i][j+1];
            }
        }
    }
    return arr2;
}

int main()
{
    srand(time(0));
    int row, col;
    cout << "Enter number of rows: ";
    cin >> row;
    cout << "Enter number of columns: ";
    cin >> col;
    int index;
    cout << "Enter index of column to delete: ";
    cin >> index;
    int** arr = new int* [row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = rand() % 10;
        }
    }
    cout << "Original array:\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
    int** arr2 = DelCol(arr, row, col + 1, index);
    cout << "New array:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col - 1; j++)
        {
            cout << arr2[i][j] << "  ";
        }
        cout << endl;
    }
    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
        delete[] arr2[i];
    }
    delete[] arr;
    delete[] arr2;
    return 0;
}