#include <stdio.h>
#include "snode.h"
#include "slist.h"
#include <string.h>
#include <stdlib.h>


struct slist *slist_create() 
{
    struct slist * newList = (struct slist *)malloc(sizeof(struct slist));
    newList->front = NULL;
    newList->back = NULL;
    return newList;
}

struct snode* slist_add_back(struct slist *l, char *str)
{
    if(l->front == NULL)
    {
        l->front = snode_create(str);
        l->back = l->front;
        
        return l->back;
    }

    l->back->next = snode_create(str);
    l->back = l->back->next;
    
    return l->back;
}

struct snode* slist_add_front(struct slist *l, char *str)
{
    if(l->front == NULL)
    {
        l->front = snode_create(str);
        l->back = l->front;
        
        return l->front;
    }
    
    struct snode * newFront = snode_create(str);
    newFront->next = l->front;
    l->front = newFront;

    return l->front;
}

struct snode* slist_find(struct slist *l, char *str)
{
    struct snode * temp = l->front;

    while(temp != NULL)
    {
        if(strcmp(temp->str,str) == 0)
        {
            break;
        }
        
        temp = temp->next;

    }

    if(temp != NULL)
    {
        return temp;
    }

    return NULL;

}

void slist_destroy(struct slist *l)
{
    struct snode * temp;
    while(l->front != NULL)
    {
        temp = l->front;
        l->front = l->front->next;
        snode_destroy(temp);
    }// might have to free back

    free(l);
}

void slist_traverse(struct slist *l)
{
    printf("front -> ");
    struct snode * cur = l->front;
    while(cur != NULL) {
        printf("%s ", cur->str);
	cur = cur->next;
    }
    printf("\ndone\n ");
}

uint32_t slist_length(struct slist *l)
{
    int count = 0;
    struct snode * temp = l->front;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return (uint32_t)count;
}

void slist_delete(struct slist *l, char *str)
{
    struct snode * temp = l->front;

    if(strcmp(temp->str,str) == 0)
    {
        l->front = temp->next;
        snode_destroy(temp);
        return;
    }

    while(strcmp(temp->next->str,str) != 0 && temp != NULL)
    {
        temp = temp->next;
    }

    if(temp != NULL)
    {
        struct snode * temp2 = temp->next;
        temp->next = temp->next->next;
        snode_destroy(temp2);
    }
}
 
