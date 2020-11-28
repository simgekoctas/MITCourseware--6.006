/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int peakFinder(int, int, int**);

// the aim is to find one of the peak elements in a 2d array, not the biggest peak element. less than O(nm) complexity

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
    
    int peak = peakFinder(row - 1, column - 1, arr);
    cout << "One of the Peak elements: " << peak;

    return 0;
}

int peakFinder(int row, int column, int** arr)
{
    int mid = *(*(arr + row/2) + column/2); // middle element of the 2d array
    int i = row/2;
    int j = column/2;
    
    int imax = i; // needed for storing the new max element's index
    int jmax = j;
    
    int max = mid;
    bool enter = false;
    
    do{
        enter = false;
        
        if(!enter){ // if enter is false, meaning that we are in the beginning of the do while loop so need to store new imax jmax indexes
            i = imax;
            j = jmax;
        }
        
        if(i != 0 && max < *(*(arr + i - 1) + j)) // if the current max value is smaller than the value on the above
        {
            max = *(*(arr + i - 1) + j);
            imax = i - 1;
            jmax = j;
            enter = true;
        }
        
        if(i != row && max < *(*(arr + i + 1) + j)) // if the current max value is smaller than the value on the below
        {
            max = *(*(arr + i + 1) + j);
            imax = i + 1;
            jmax = j;
            enter = true;
        }
        
        if(j != 0 && max < *(*(arr + i) + j - 1)) // if the current max value is smaller than the value on the left
        {
            max = *(*(arr + i) + j - 1);
            imax = i;
            jmax = j - 1;
            enter = true;
        }
        
        if(j != column && max < *(*(arr + i) + j + 1)) // if the current max value is smaller than the value on the right
        {
            max = *(*(arr + i) + j + 1);
            imax = i;
            jmax = j + 1;
            enter = true;
        }
        
    }while(enter);
    
    return *(*(arr + imax) + jmax); // after the do while loop, we will have the max element's indexes
    
}
