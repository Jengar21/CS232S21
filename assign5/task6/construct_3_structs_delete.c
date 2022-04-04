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

void delete_node_at(node_t ** head, int idx) {
	node_t * cur = *head;
	node_t * last = NULL;
    	int i = 0;
    	if(idx == 0){
    		*head = (*head)->next;
    		free(cur);
    		return;
    	}
	while(cur != NULL) {
		if(i == idx){
        		last->next = last->next->next;
        		free(cur);
        		return;
        	}
		last = cur;
		cur = cur->next;
		i++;
	}
    
} 
void delete_node_key(node_t **head, char * key) {
    	node_t * cur = *head;
    	node_t * last = NULL;
	while(cur != NULL) {
		if(strcmp(cur->str, key)==0 && cur != *head){
        		last->next = last->next->next;
        		free(cur);
        		return;
        	}
        	else if(strcmp(cur->str, key)==0 && cur == *head){
        		*head = cur->next;
        		free(cur);
        		return;
        	}
		last = cur;
		cur = cur->next;
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
    printf("head -> ");
    node_t * cur = head;
    while(cur != NULL) {
        printf("%s ", cur->str);
	cur = cur->next;
    }
    printf("\ndone\n ");
}
