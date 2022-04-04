#include<stdio.h>
#include<stdlib.h>
#include "snode.h"
typedef struct snode node_t;

node_t * setup() {

    node_t * head ;
  
    node_t * node1 = (node_t*)malloc(sizeof(node_t));
    node_t * node2 = (node_t*)malloc(sizeof(node_t));
    node_t * node3 = (node_t*)malloc(sizeof(node_t));

    strcpy(node1->str, "hello");
    strcpy(node2->str, "there");
    strcpy(node3->str, "prof");
    node1->length = 5;
    node2->length = 5;
    node3->length = 4;
    
    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    
    
   return head;
}

void teardown(node_t * head) {
    node_t * temp;
    while(head != NULL){
    	temp = head;
    	head = head->next;
    	free(temp);
    }
}

void add(node_t ** head, char * str, int length){
    node_t * temp = *head;
    node_t * node_new = (node_t *)malloc(sizeof(node_t));
    strcpy(node_new->str, str);
    node_new->length = length;
    node_new->next = temp;
    *head = node_new;
}

void dump_all(node_t*);

int main (int argc, char ** argv) {
    node_t * head = setup();
    add(&head, "hi", 2);
    dump_all(head);
    teardown(head);
    return 0;
}

void dump_all(node_t * head) {
    printf("head -> ");
    node_t * cur = head;
    while(cur != NULL) {
        printf("%s ", cur->str);
	cur = cur->next;
    }
    printf("\ndone\n ");
}
