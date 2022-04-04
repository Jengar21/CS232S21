#include<stdio.h>
#include<stdlib.h>
#include "snode.h"
typedef struct snode node_t;

node_t * setup() {
    node_t * head = (node_t*)malloc(sizeof(node_t));
    node_t * node1 = (node_t*)malloc(sizeof(node_t));
    node_t * node2 = (node_t*)malloc(sizeof(node_t));
    node_t * node3 = (node_t*)malloc(sizeof(node_t));
    strcpy(node1->str, "hello");
    node1->length = 5;
    strcpy(node2->str, "there");
    node2->length =5;
    strcpy(node3->str, "prof");
    node3->length = 4;
    head->next = node1;
    node1->next = node2;
    node2->next =node3;
    node3->next = NULL;
    return head;
}//TODO:copy setup func from previous task


void teardown(node_t* head) {
   //TODO: free all dynamic memory you requested.
    //We will now get all the nodes, as created in setup()
    node_t* node1 = head->next;
    node_t* node2 = node1->next;
    node_t* node3 = node2->next;
    //And, we shall free() the memory from last node
  // Can also do free(head->next->next->next);
    free(node3);
    free(node2);    // free(head->next->next);
    free(node1);    // free(head->next);
    free(head);
    //TODO: free all dynamic memory you requested.
    //Please complete the prototype of teardown.
    //You are not allowed to use globals
}

void add(node_t ** head, char * str, int length){
  node_t * nodeadd =(node_t*)malloc(sizeof(node_t));
strcpy(nodeadd->str, str);
nodeadd->length = length;
nodeadd->next = *head;
*head = nodeadd;
    //TODO: implement add to add a new node to front, pointed by head
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
