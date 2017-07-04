//
//  Sorter.cpp
//  Indexer
//
//  Created by Mykyta on 10.05.17.
//  Copyright © 2017 Mykyta Khomenko. All rights reserved.
//

#include "Sorter.h"

void exchange(Record array[], long long a, long long b) {
    Record temp = array[a];
    
    array[a] = array[b];
    array[b] = temp;
}

void partition(Record array[], long long start, long long end) {
    long long marker = start;
    long long pivot = (start + end) / 2;
    
    if ( end - start < 1 ) {
        return;
    }
    
    exchange(array, pivot, end);                                            //moving pivot element to the last position
    pivot = end;                                                            //changing indexes according to the above
    for ( ; marker < end && array[marker].isLess(array[pivot]); marker++ ); //looking for element greater than pivot and storing its index in 'marker'
    for ( long long i = marker + 1; i < pivot; i++ ) {                      //going further from greater to the pivot
        if ( array[i].isLess(array[pivot]) ) {                              //looking for smaller than pivot
            exchange(array, i, marker);                                     //exchange less that pivot with greater one
            marker += 1;
        }
    }
    exchange(array, pivot, marker);
    partition(array, start, marker - 1);
    partition(array, marker + 1, end);
}

void quickSort(Record array[], long long size) {
    long long start = 0;
    long long end = size - 1;
    
    partition(array, start, end);
}

void arrayDump(Record array[], long long size) {
    size -= 1;
    for ( long long i = 0; i < size; i++ ) {
        std::cout << array[i];
    }
    std::cout << array[size];
}

//void sort(Record records[], long long size) {
    //quickSort(records, size);
    //radixSort(records, size);
//}
//***RADIX SORT IMPLEMENTATION**
//
// A utility function to get maximum value in arr[]
unsigned long long getMax(Record arr[], long long n)
{
    unsigned long long mx = arr[0].V;
    for (long long i = 1; i < n; i++)
        if (arr[i].V > mx)
            mx = arr[i].V;
    return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(Record arr[], long long n, unsigned long long exp)
{
    Record* output = new Record[n]; // output array
    long long i;
    int count[10] = {0};
    
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (arr[i].V/exp)%10 ]++;
    
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    
    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i].V/exp)%10 ] - 1] = arr[i];
        count[ (arr[i].V/exp)%10 ]--;
    }
    
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
    delete[] output;
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixSort(Record arr[], long long n)
{
    // Find the maximum number to know number of digits
    unsigned long long m = getMax(arr, n);
    
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (unsigned long long exp = 1; exp != 0 && m/exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}




