#include <stdio.h>
#include <stdlib.h>
typedef struct LINKED_LIST_NODE_s *LINKED_LIST_NODE;
typedef struct LINKED_LIST_NODE_s{
    LINKED_LIST_NODE next;
    void *data;
}LINKED_LIST_NODE_t[1];

typedef struct LINKED_LIST_s *LINKED_LIST;
typedef struct LINKED_LIST_s{
    LINKED_LIST_NODE head;
}LINKED_LIST_t[1];

LINKED_LIST linked_list_init(){
    LINKED_LIST yeni;
    yeni=(LINKED_LIST)malloc(sizeof(LINKED_LIST_t));
    yeni->head=NULL;

}

void linked_list_insert(LINKED_LIST list, void *data, int idx){
    int i;
    LINKED_LIST_NODE node=(LINKED_LIST_NODE)malloc(sizeof(LINKED_LIST_NODE_t));
    LINKED_LIST_NODE temp=(LINKED_LIST_NODE)list;
    node->data=data;
    node->next=NULL;
    for(i=0; i<idx; i++){
        temp=temp->next;
    }
    node->next=temp->next;
    temp->next=node;

}
void *linked_list_remove(LINKED_LIST list , int idx){
    int i;
    LINKED_LIST_NODE node;
    LINKED_LIST_NODE temp=(LINKED_LIST_NODE)list;
    void *res;
    for(i=0; i<idx; i++){
        temp=temp->next;
    }
    node=temp->next;
    temp->next=node->next;
    res=node->data;
    free(node);
}

void linked_list_prepend(LINKED_LIST list, void *data){
    LINKED_LIST_NODE node=(LINKED_LIST_NODE)malloc(sizeof(LINKED_LIST_NODE_t));
    node->data=data;
    node->next=NULL;

    node->next=list->head;
    list->head=node;
}

void *linked_list_append(LINKED_LIST list, void *data){
    LINKED_LIST_NODE node=(LINKED_LIST_NODE)malloc(sizeof(LINKED_LIST_NODE_t));
    LINKED_LIST_NODE temp=(LINKED_LIST_NODE)list;
    node->data=data;
    while(temp!=NULL){
        temp=temp->next;
    }
    node->next=temp->next;
    temp->next=node;
}

void linked_list_set(LINKED_LIST list, void *data, int idx){
    LINKED_LIST_NODE temp=(LINKED_LIST_NODE)list;
    int i;

    for(i=0; i<idx; i++){
        temp=temp->next;
    }
    temp->data=data;

}

void *linked_list_get(LINKED_LIST list, int idx){
    LINKED_LIST_NODE temp=(LINKED_LIST_NODE)list;
    int i;

    for(i=0; i<idx; i++){
        temp=temp->next;
    }

    return temp->data;
}

void linked_list_removeall(LINKED_LIST list){
    LINKED_LIST_NODE node;
    while(list->head != NULL){
        node=list->head;
        list->head=node->next;
        free(node);
    }
    free(list);
}

void linked_list_concatenate(LINKED_LIST list, LINKED_LIST list2){
    LINKED_LIST_NODE temp;
    temp=(LINKED_LIST_NODE)list;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=list->head;
    free(list->head);

}

int main()
{
    LINKED_LIST s;
    s=linked_list_init();


}
