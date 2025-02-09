#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct  node *next;
struct  node *prev;
};
typedef struct node* list;
list create(){
    list h=(list)malloc(sizeof(struct node));
    h->data = -1;
    h->next = NULL;
    h->prev = NULL;
    return h;
}
void insert(list l,int d,int ind){
    list temp=l,new_node;
    for(int i=0;i<ind-1;i++){
        temp=temp->next;
    }
     new_node = (list)malloc(sizeof(struct node));
    new_node->data = d;
    new_node->next = temp->next;
    
    if (temp->next != NULL) {
        temp->next->prev = new_node;
    }

    temp->next = new_node;
    new_node->prev = temp;
}
void delete(list l,int ind){
    list temp=l;
    for(int i=0;i<ind-1;i++){
        temp=temp->next;
    }
    list k=temp->next;
    k->next->prev=temp;
    temp->next=k->next;
    free(k);
}
void main(){
list n=create();
insert(n,1,0);
insert(n,2,1);
insert(n,3,2);
insert(n,4,3);
insert(n,5,4);
delete(n,2);
insert(n,3,2);

while(n!=NULL){
printf("%d :",n->data);
    n=n->next;
}
/*
while(n->next !=NULL){
    
    n=n->next;
}
while(n!=NULL){
    printf("%d :",n->data);
    n=n->prev;
}*/

}