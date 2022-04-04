/* Include the system headers we need */
#include <stdlib.h>
#include <stdio.h>

/* Include our header */
#include "mystring.h"

/* Define what our struct is */
struct mystring_t {
	size_t size;
	char *data;
};

/* Utility function to handle allocation failures. In this
   case we print a message and exit. */
static void allocation_failed() {
    fprintf(stderr, "Out of memory.\n");
    exit(1);
}

mystring_t *mystring_new() {
//////////YOUR CODE HERE///////////////////////////////////////////////////////////
	mystring_t *retval = (mystring_t*) malloc(sizeof(mystring_t));
	// whats this?->	s.data = (char*) malloc((s.size+1)*sizeof(char));
	if(retval == NULL){
		allocation_failed();
	}
	retval->size = 1;
	retval->data = (char *) malloc(sizeof(char));
	if(retval->data == NULL){
		allocation_failed();
	}
	retval->data[0]=' ';
//////////YOUR CODE HERE///////////////////////////////////////////////////////////
	return retval;
}

/* Return the value at the specified location/component "loc" of the mystring */
char mystring_get(mystring_t *s, size_t loc) {
//////////YOUR CODE HERE///////////////////////////////////////////////////////////
	if(loc < s->size && loc >= 0){
		return s->data[loc];
	}
//////////YOUR CODE HERE///////////////////////////////////////////////////////////
		return ' ';
}

void mystring_delete(mystring_t *s) {
//////////YOUR CODE HERE///////////////////////////////////////////////////////////
	free(s->data);
	free(s);
//////////YOUR CODE HERE///////////////////////////////////////////////////////////
}

int mystring_get_len(mystring_t *s) {
//////////YOUR CODE HERE///////////////////////////////////////////////////////////
	return s->size;
//////////YOUR CODE HERE///////////////////////////////////////////////////////////
}

char* mystring_get_data(mystring_t *s) {
//////////YOUR CODE HERE///////////////////////////////////////////////////////////
//////////YOUR CODE HERE///////////////////////////////////////////////////////////
	return s->data;
}
void mystring_cat(mystring_t *s, char *s2) {
//////////YOUR CODE HERE///////////////////////////////////////////////////////////
	size_t j;
	int t = 0;
	for(j=0;*(s2+j)!='\0';j++)
	j++;
	s->data = (char *)realloc(s->data, sizeof(char)*(s->size + j));
		for(int i = s->size; i < (s->size + j); i++){
			s->data[i] = *(s2+t);
			t++;
		}
		s->size = s->size + j;
//////////YOUR CODE HERE///////////////////////////////////////////////////////////
}

/* Set a value in the mystring. If the extra memory allocation fails, call
   allocation_failed(). Unset space should be value of space */
void mystring_set(mystring_t *s, size_t loc, char value) {
//////////YOUR CODE HERE///////////////////////////////////////////////////////////
	if(loc < s->size && loc >= 0){
	s->data[loc] = value;
	}
	else{
		s->data = (char *)realloc(s->data, sizeof(char)*(loc+1));
		
		for(int i = s->size; i < loc+1; i++){
			s->data[i] = ' ';
		}
		s->data[loc] = value;
		s->size = loc+1;
	}
//////////YOUR CODE HERE///////////////////////////////////////////////////////////
	return;
}
