#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int number;
    struct node *next;
} node_t;

void push(node_t *queue, int num){
    node_t *cur = queue;
    //go to the last item in line
    while(cur->next != NULL){
        cur= cur->next;
    }
    //set the end of the line to the new node
    cur->next = (node_t*)malloc(sizeof(node_t));
    //set the number
    cur->next->number = num;
    //set the next item to come into the end of the line to be NULL
    cur->next->next = NULL;
}

int pop(node_t *queue){
    //check if queue is empty
    if(queue->next == NULL){
        return -1;
    }
    //grab the first item in line
    int popped = queue->next->number; //cur
    node_t *temp = queue->next; //cur
    free(temp);
    //since first item gone, the next item points at the item next to that
    queue->next= queue->next->next;
    return popped;
}

int main(){
    node_t *queue = malloc(sizeof(node_t));
    queue->next = NULL;
    printf("%s\n", "HI");
    push(queue, 2);
    push(queue, 3);
    push(queue, 1);
    printf("%s\n", "HI");
	while(queue->next != NULL){
		if(queue->next->number == 3){
			printf("%d\n",pop(queue));
    	}
		queue =queue->next;
	}
    
    return 0;
}
