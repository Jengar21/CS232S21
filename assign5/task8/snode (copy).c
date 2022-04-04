#include <stdio.h>
#include "snode.h"
#include <string.h>
#include <stdlib.h>



struct snode *snode_create(void *s) 
{
 //TODO: implement snode_create, change the prototype to
 //match with header file
 //return node;
    struct snode * newNode = (struct snode*)malloc(sizeof(struct snode));
    newNode->str = (void*)malloc(strlen((char*)(s))+1);
    strcpy((char*)(newNode->str),s);
    newNode->next = NULL;

    return newNode;
}
void snode_destroy(struct snode * s) 
{
    free(s->str);
    free(s);
 //TODO: implement snode_destroy
 
}
 