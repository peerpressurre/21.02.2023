#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include<stdio.h>
#include<ctime>

using namespace std;

int Subset(int* arra, int* arrb, int sizea, int sizeb)
{
    int counter = 0;
    int i, j, temp = 0;
    for (size_t i = 0; i < sizeb; i++)
    {
        for (size_t j = temp; j < sizea; j++)
        {
            if (arrb[i] == arra[j])
            {
                counter++;
                temp = j + 1;
                if (counter == 2 && counter > 0)
                {
                    return j - 1;
                    break;
                }    
                break;
            }
            else
            {
                counter = 0;
            }
        }
    }
    if (counter < 2 && counter < 0)
    {
        return 0;
    }
}

int main()
{
    int A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int B[] = {3, 6, 7, 8 };
    int sizeA = sizeof(A) / sizeof(A[0]);
    int sizeB = sizeof(B) / sizeof(B[0]);
    cout << "Array 1:\t";
    for (size_t i = 0; i < sizeA; i++)
    {
        cout << A[i] << "\t";
    }
    cout << endl;
    cout << "Array 2:\t";
    for (size_t i = 0; i < sizeB; i++)
    {
        cout << B[i] << "\t";
    }
    cout << endl;
    int subset = Subset(A, B, sizeA, sizeB);
    if (subset)
    {
        cout << "Subset found starting at index " << subset << endl;
    }
    else {
        cout << "Subset not found" << endl;
    }
    delete[] A;
    delete[] B;
    return 0;
}