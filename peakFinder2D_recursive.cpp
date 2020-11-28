/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int peakFinder(int, int, int**, int, int);
int findMax(int, int&, int**, int );

// the aim is to find one of the peak elements in a 2d array, not the biggest peak element. 

int main()
{   
    int row = 0;
    int column = 0;
    cout << "Enter number of rows in the array:\n";
    cin >> row;
    
    cout << "Enter number of columns in the array:\n";
    cin >> column;
    
    int* arr[row]; //created an 2d array
    for(int j = 0; j <= row - 1; j ++)
    {
        *(arr + j) = new int[column];
    }
    
    cout << "Enter the elements of the array:\n";
    for(int i = 0; i <= row - 1; i++)
    {
        for(int j = 0; j <= column - 1; j++)
        {
            cin >> *(*(arr + i) + j );
        }
        
    }
    
    int peak = peakFinder(row - 1, column - 1, arr, 0, column);
    cout << "One of the Peak elements: " << peak;

    return 0;
}

int peakFinder(int row, int column, int** arr, int start, int end)
{
    int imax = 0;
    int midcol = (end - start)/2 + start;
    cout << "midcol: " << midcol;
    
    int globalpeak = findMax(row, imax, arr, midcol);
    cout << "globalpeak: " << globalpeak;
    
    if(start == end)
    {
        return globalpeak;
    }
    
    if(globalpeak >= *(*(arr + imax) + midcol - 1) && globalpeak >= *(*(arr + imax) + midcol + 1))
    {
        return globalpeak;
    }
    
    if(globalpeak < *(*(arr + imax) + midcol - 1))
    {
        return peakFinder(row, column, arr, start, midcol - 1);
    }
    
    
    return peakFinder(row, column, arr, midcol + 1, end);
    
    
}

int findMax(int row, int& imax, int** arr, int midcol)
{
    int max = 0;
    for(int i = 0; i <= row; i ++)
    {
        if(*(*(arr + i) + midcol) > max)
        {
            max = *(*(arr + i) + midcol);
            imax = i;
        }
    }
    return max;
}

