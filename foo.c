#include <stdio.h>

#include <stdlib.h>

int *foo(int *a, int *b, int s);

int main () {

int *arr = NULL, x = 6, y = 7, i;

arr = foo(&x, &y, 5);

printf("x = %d y = %d\n", x, y);

if(arr != NULL) {

for(i=0; i < 5; i++) {

printf("arr[%d] = %d\n",

i, arr[i]);

}

}

free(arr);

return 0;

}

/************************************/

int *foo(int *a, int *b, int s) {

int *tmp, i;

tmp = malloc(sizeof(int)*s);

if(tmp != NULL) {

for(i=0; i < s; i++) {

tmp[i] = i + *b;

}

*a = tmp[2];

*b = 8;

 }
  }
