#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// Note, the bits are counted from right to left. 
// Return the bit states of x within range of [start, end], in which both are inclusive.
// Assume 0 <= start & end <= 31
unsigned * get_bits(unsigned x,
                 unsigned start,
                 unsigned end) {



unsigned * arr = (unsigned *) malloc(sizeof(unsigned) * (end - start + 1));
    int len = end - start + 1;
    for (int i = 0; i <= len; ++i)
        
        arr[i] = (x & ( 1 << ( start + i)))?1:0;


    return arr;
    // YOUR CODE HERE
    // Returning NULL is a placeholder
    // get_bits dynamically allocates an array a and set a[i] = 1 when (i+start)-th bit
    // of x is 1, otherwise set a[i] = 0;
    // At last, get_bits returns the address of the array.
}



