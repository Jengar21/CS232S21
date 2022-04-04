#include<stdio.h>
#include<stdlib.h>
//#include<string.h>
#include "snode.h"
typedef struct snode node_t;

node_t * setup() {
    node_t *head ;//head declared for you
    //Allocate three more pointers
    //head for the first Node, and temporary pointers node1, node2 and node3
    head = (node_t*) malloc(sizeof(node_t));
    node_t* node1 = (node_t*) malloc(sizeof(node_t));
    node_t* node2 = (node_t*) malloc(sizeof(node_t));
    node_t* node3 = (node_t*) malloc(sizeof(node_t));
    //Allocate three node pointees and store references to them in the three pointers
    //Dereference each pointer to store the appropriate number into the value field in its pointee.
    //Dereference each pointer to access the .next field in its pointee,
    //and use pointer assignment to set the .next field to point to the appropriate Node.
    strcpy(head->str,"" ); head->length = 0; head->next = node1;
    strcpy(node1->str, "hello"); node1->length = 5; node1->next = node2;
    strcpy(node2->str, "there"); node2->length = 5; node2->next = node3;
    strcpy(node3->str, "prof" ); node3->length = 4; node3->next = NULL;
    return head;
}

void teardown(node_t* head) {
    //TODO: free all dynamic memory you requested.
    //We will now get all the nodes, as created in setup()
    node_t* node1 = head->next;
    node_t* node2 = node1->next;
    node_t* node3 = node2->next;
    //And, we shall free() the memory from last node
    free(node3);    // Can also do free(head->next->next->next);
    free(node2);    // free(head->next->next);
    free(node1);    // free(head->next);
    free(head);
}

//You can ignore the following code for testing
void dump_all(node_t*);

int main (int argc, char ** argv) {
    node_t * head = setup();
    dump_all(head);
    teardown(head);
    return 0;
}

void dump_all(node_t * head) {
    printf("head ->");
    node_t * cur = head;
    while(cur != NULL) {
        printf("%s ", cur->str);
        cur = cur->next;
    }
    printf("\ndone\n ");
}
