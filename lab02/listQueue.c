// a queue fixed by oliver tan
// fixed the size, and putQueue functions

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Queue.h"

typedef struct queueNode * link;

struct queueNode { 
    Item item; 
    link next; 
};

struct queueImp { 
    link head; 
    link tail;
    int size; 
};

static link createNode(Item item){ 
    link n = malloc (sizeof(*n));
    assert(n != NULL);
    n->item = item; 
    n->next = NULL;     
    return n;                         
}

// Creates an empty Queue
Queue createQueue (void){ 
    Queue q = malloc (sizeof (*q));
    assert(q != NULL); 
    q->head = NULL; 
    q->tail = NULL;
    q->size = 0; 
    return q;
}

void destroyQueue(Queue queue){
    link curr;
    link next;
    assert(queue != NULL);
    curr = queue->head;
    while(curr!=NULL){
        next = curr->next;
        free(curr);
        curr = next;
    }
    free(queue);

}

int queueSize (Queue q){ 
    assert(q != NULL);
    return q->size; 
}


void putQueue (Queue q, Item item){ 
    assert(q != NULL); 
    link n = createNode(item);
    
    if (q->head == NULL) {
        q->head = n;
        q->tail = n;
    } else {
        q->tail->next = n;
        q->tail = n;
    }
    
    q->size++;
}

Item getQueue (Queue q){ 
    assert(q != NULL);
    if(q->size != 0){
        Item item = q->head->item;
        link delNode = q->head;
        q->head = q->head->next;  
        q->size--;    
        free(delNode);
        return item;
    } else {
        fprintf(stderr,"queue underflow\n");
        abort();          
    }

}
