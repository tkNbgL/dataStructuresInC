//utku nebioğlu 13070001018

#include <stdio.h>
#include <stdlib.h>

typedef struct LINKED_QUEUE_NODE_s *LINKED_QUEUE_NODE;
typedef struct LINKED_QUEUE_NODE_s{
    LINKED_QUEUE_NODE next;
    void *data;
}LINKED_QUEUE_NODE_t[1];

typedef struct LINKED_QUEUE_s *LINKED_QUEUE;
typedef struct LINKED_QUEUE_s{
    LINKED_QUEUE_NODE head;
    LINKED_QUEUE_NODE tail;
    LINKED_QUEUE_NODE midtail;
    int count;
}LINKED_QUEUE_t[1];

LINKED_QUEUE linked_queue_init();
void linked_queue_free(LINKED_QUEUE queue);
int linked_queue_is_empty(LINKED_QUEUE queue);
int linked_queue_size(LINKED_QUEUE queue);
void linked_queue_enqueue(LINKED_QUEUE queue, void *data);
void *linked_queue_dequeue(LINKED_QUEUE queue);

int main()
{
    LINKED_QUEUE s;
    int counter;
    s=linked_queue_init();
    int a,b,c,e,*d,f,g,h,i,o,u,z,k,l,ab,ba,*p;
    a=1;
    b=2;
    c=3;
    e=4;
    f=5;
    g=6;
    h=7;
    i=8;
    o=9;
    u=10;
    z=11;
    k=100;
    l=15;
    ab=20;
    ba=21;
    linked_queue_enqueue(s,&a);
    linked_queue_enqueue(s,&b);
    linked_queue_enqueue(s,&c);
    linked_queue_enqueue(s,&e);
    linked_queue_enqueue(s,&f);
    linked_queue_enqueue(s,&g);
    linked_queue_enqueue(s,&h);
    linked_queue_enqueue(s,&i);
    linked_queue_enqueue(s,&o);
    linked_queue_enqueue(s,&u);
    linked_queue_enqueue(s,&z);
    linked_queue_enqueue(s,&l);
    linked_queue_enqueue(s,&l);
    linked_queue_enqueue(s,&l);
    linked_queue_enqueuemid(s,&k);
    d=findMiddle(s);
      printf("Middle Element is %d\n",*d);


    return 0;
}

int findMiddle(LINKED_QUEUE queue){
    return queue->midtail->data;
}

void linked_queue_enqueuemid(LINKED_QUEUE queue, void *data){
    LINKED_QUEUE_NODE node=(LINKED_QUEUE_NODE)malloc(sizeof(LINKED_QUEUE_NODE_t));
    if(node != NULL){
        node->data=data;
        node->next=NULL;
        queue->midtail->next=node;
        queue->midtail=node;

    }
}

LINKED_QUEUE linked_queue_init(){
    LINKED_QUEUE newhead;

    newhead=(LINKED_QUEUE)malloc(sizeof(LINKED_QUEUE_t));
    if(newhead != NULL){
        newhead->head=NULL;
        newhead->tail=NULL;
        newhead->midtail=NULL;
    }
    else{
        printf("eroor");
    }
    return newhead;
}

void linked_queue_enqueue(LINKED_QUEUE queue, void *data){
    LINKED_QUEUE_NODE node=(LINKED_QUEUE_NODE)malloc(sizeof(LINKED_QUEUE_NODE_t));
    if(node != NULL){
        node->data=data;
        node->next=NULL;
        if(queue->head==NULL){
            queue->head=node;
            queue->midtail=node;
        }
        else{
            queue->tail->next=node;
            //queue->midtail=queue->head->next;
        }
        queue->tail=node;
        queue->count+=1;
        if(queue->count ==1){
            queue->midtail=node;
        }
        else{
            queue->head->next=node;

            if(queue->count & 1){
                queue->midtail=queue->midtail->next;
            }
        }
    }
    else{
        printf("unable to allocate memory");
    }
}

void *linked_queue_dequeue(LINKED_QUEUE queue){
    LINKED_QUEUE_NODE node;
    void *res=NULL;
    node=queue->head;
    if(node != NULL){
        if(node == queue->tail){
            queue->head=NULL;
            queue->tail=NULL;
        }
        else{
            queue->head=node->next;
        }
        res=node->data;
        queue->count -= 1;

    if(!((queue->count)& 1)){
        queue->midtail=queue->midtail->next;
    }

        free(node);
    }
    else{
        printf("queue empty");
    }



    return res;
}
