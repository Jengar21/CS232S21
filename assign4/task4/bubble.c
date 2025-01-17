/* Example: bubble sort strings in array */

#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */


#define NUM 30   /* number of strings */
#define LEN 1200  /* max length of each string */

int main()
{
  char * Strings[NUM];

  printf("Please enter %d strings, one per line:\n", NUM);

  int i=0;
 for(int i=0; i<NUM ; i++){
       fgets(Strings,LEN,stdin);
   }
  
  
  /* Write a for loop here to read NUM strings.

     Use fgets(), with LEN as an argument to ensure that an input line that is too
     long does not exceed the bounds imposed by the string's length. However, each 
	 string stored in array Strings must not waste space. That is, only the buffer
	 used by fgets() to temporary store the string read from input stream needs to 
	 be LEN bytes long.  
	 Note that the newline and NULL characters will be included in LEN.
  */

  puts("\nHere are the strings in the order you entered:");
 
  for(i=0; i<NUM; i++){
    printf("[%d] %s\n",i+1,Strings[i]);
    }

  int j;

char temp[NUM];

for(i=0; i<NUM;i++){
  
  for(j=0;j<NUM-i-1;j++){
    
    if(strcmp(Strings[j],Strings[j+1])>0){
      
      strcpy(temp,Strings[j]);
      
      strcpy(Strings[j],Strings[j+1]);
      
      strcpy(Strings[j+1],temp);

      }

    }

}


  /* Bubble sort */
  /* Write code here to bubble sort the strings in ascending alphabetical order

     Your code must meet the following requirements:
        (i) The comparison of two strings must be done by checking them one
            character at a time, without using any C string library functions.
            That is, write your own while/for loop to do this.
       (ii) Implement a swap function to swap two strings by swapping pointers
	    without copying any chars.You are not allowed to use any C library 
	    functions in swap.
      (iii) You are allowed to use strlen() to calculate string lengths.
  */
  /* Output sorted list */
  
  puts("\nIn alphabetical order, the strings are:");
  for(int x=0;x<NUM;x++){
       printf("%s",Strings[x]);
   }
   
   return 0;
 
  for(i=0; i<NUM; i++){
    printf("[%d] %s\n",i+1,Strings[i]);
}
}


/* Write a for loop here to print all the strings. Feel free to use puts/printf
     etc. for printing each string.
  */


