#include <stdio.h>
#include <stdlib.h>

// Set the bits of x within range of [start, end], in which both are inclusive
// Assume 0 <= start & end <= 31
void set_bits(unsigned * x,
             unsigned start,
             unsigned end,
             unsigned *v) {
               int len = end - start + 1; 
               
               for (int i = 0; i < len; ++i)
               
               if(v[i] == 1) (*x) = (*x) | (1 << (start + i ));
               
               else  
               (*x) = (*x) & ( ~ ( 1<< (start + i)));
    
  
   }// YOUR CODE HERE
    // No return value
    // v points to an array of at least (end-start+1) unsigned integers.
    // if v[i] == 0, then set (i+start)-th bit of x zero, otherwise, set (i+start)-th bit of x one.



