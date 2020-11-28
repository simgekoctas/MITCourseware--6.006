/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int peakFinder(int, int, int* , int);

// the aim is to find one of the peak elements, not the biggest peak element. O(logn) complexity. 

int main()
{   
    int n = 0;
    cout << "Enter number of elements in the array:\n";
    cin >> n;
    
    int list[n];
    int* arr = list;
    
    cout << "Enter the elements of the array:\n";
    for(int i = 0; i <= n - 1; i++)
    {
        cin >> *(arr + i);
    }
    
    int peak = peakFinder(0, n - 1, arr, n);
    cout << "One of the Peak elements:" << peak;

    return 0;
}

int peakFinder(int start, int end, int* arr, int n)
{
    int mid = (end - start)/2 + start;
    
    //if((mid == 0 || *(arr + mid) > *(arr + mid + 1)) && (mid == n -1 || *(arr + mid) > *(arr + mid - 1)))
    //{
    //    return *(arr + mid);
    //}
    
    if(mid == 0 || mid == n - 1)
    {
        cout << "first if\n";
        return *(arr + mid);
        
    }
    
    if(*(arr + mid) >= *(arr + mid + 1) && *(arr + mid) >= *(arr + mid - 1))
    {
        cout << "second if\n";
        return *(arr + mid);
        
    }
    
    if(*(arr + mid) <= *(arr + mid - 1))
    {
        cout << "third if\n";
        peakFinder(start, mid - 1, arr, n);
        
    }
    else if(*(arr + mid) <= *(arr + mid + 1))
    {
        cout << "else if\n";
        peakFinder(mid + 1, end, arr, n);
        
    }
    
}
