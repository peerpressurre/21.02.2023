#include <iostream>
#include <ctime>
using namespace std;

int summul(int* arr, int size, int* pos, int* neg, int* zero)
{
    *neg = 0;
    *pos = 0;
    *zero = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            (*neg)++;
        } if (arr[i] > 0)
        {
            (*pos)++;
        }
        if (arr[i] == 0)
        {
            (*zero)++;
        }
    }
    return 0;
}

int main()
{
    srand(time(0));
    int size, neg = 0, pos = 0, zero = 0;
    cout << "Enter size: ";
    cin >> size;
    int* arr = new int[size];
    cout << "Array:\t";
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand() % 31 - 10;
        cout << arr[i] << "\t";
    }
    int* arrptr = arr;
    cout << endl;
    summul(arr, size, &pos, &neg, &zero);
    cout << "Number of positive numbers: " << pos << endl;
    cout << "Number of negative numbers: " << neg << endl;
    cout << "Number of numbers equal to 0: " << zero << endl;

    return 0;
}