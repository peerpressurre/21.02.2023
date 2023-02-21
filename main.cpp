#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include<stdio.h>
#include<ctime>

using namespace std;


int* findSubset(int* A, int* B, int sizeA, int sizeB) {
    int i, j;

    // Iterate through A to find the first element that matches B[0]
    for (i = 0; i <= sizeA - sizeB; i++) {
        if (A[i] == B[0]) {
            // If the first element matches, check the remaining elements
            for (j = 1; j < sizeB; j++) {
                if (A[i + j] != B[j]) {
                    break; // Not a match, move on to next element in A
                }
            }
            if (j == sizeB) {
                return &A[i]; // Found a match, return pointer to start of subset
            }
        }
    }
    return 0; // Subset not found, return null pointer
}


int main()
{
    //int size;
    //cout << "Enter size: ";
    //cin >> size;
    //int* A = new int[size];
    //int* B = new int[size];
    //int sizeA = sizeof(A) / sizeof(A[0]);
    //int sizeB = sizeof(B) / sizeof(B[0]);
    //for (size_t i = 0; i < size; i++)
    //{
    //    A[i] = rand() % 10; 
    //    cout << A[i] << "\t";
    //}
    //cout << endl;
    //for (size_t i = 0; i < size; i++)
    //{
    //    B[i] = rand() % 10;
    //    cout << B[i] << "\t";
    //}
    //cout << endl;
    int A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int B[] = { 6, 7, 8 };
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
    int* subset = findSubset(A, B, sizeA, sizeB);
    if (subset) {
        cout << "Subset found starting at index " << subset - A << endl;
    }
    else {
        cout << "Subset not found" << endl;
    }

    return 0;
}