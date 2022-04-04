#include<stdio.h>
#include<stdlib.h>
#include "snode.h"
typedef struct snode node_t;

node_t * setup() {
    //TODO:copy setup func from previous task
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
}

void teardown(node_t * head) {
    //TODO: free all dynamic memory you requested.
    //Please complete the prototype of teardown.
    //You are not allowed to use globals
   node_t *t = head;
    while(head != NULL){
        t = head->next;
        free(head);
        head = t;
    }
}

void add(node_t ** head, char * str, int length){
    //TODO: copy add func from task2
   node_t * nodeadd =(node_t*)malloc(sizeof(node_t));
strcpy(nodeadd->str, str);
nodeadd->length = length;
nodeadd->next = *head;
*head = nodeadd;
}
void delete_node_at(node_t ** head, int idx) {
    //TODO: implement delete a node based on index
	//deletes a node at index idx, which ranges from zero to the length of the list - 1.
  node_t *h = *head;
   node_t *t = *head;
   if(idx == 0){ //index is 0 , therefore we need to update head....
        if(h){
            *head = (h->next);
            free(h);
        }
        else printf("Index does not exist \n");
    

   }
   else{
        int i;
        for(i=0;h && i<idx;i++){
            t = h;
            h = h->next;
        }
        if(i == idx){
            t->next = h->next;
            free(h);
        }
        else printf("Index does not exits \n");
   }
} 
void delete_node_key(node_t **head, char * key) {
    //TODO: implement delete a node based on key
	//given a certain key, find and delete. 
  node_t *h = *head;
   node_t *t = h;
   while(h){
        //printf("match - %d ",strcmp(h->str,key));
        if(strcmp(h->str,key)==0){
          
            if(t == h){ // key is found at head....
                *head = (h->next);
                free(h);          
            }
            else{
                t->next = h->next;
                free(h);
            }
        }
        t = h;
        h = h->next;
      
   }
}
void dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * head = setup();
    add(&head, "hi", 2);
    delete_node_key(&head, "prof");
    delete_node_at(&head, 0);
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
