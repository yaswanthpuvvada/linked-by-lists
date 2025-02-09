#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node* next;
};
typedef struct node* list;
list create(){
   list h=(list)malloc(sizeof(struct node));
    h->data = -1;
    h->next = NULL;
return h;
}
void insert(list h,int d,int ind){
    list temp=h,new;
   for(int i=0;i<ind;i++)
    {
        temp=temp->next;
    
    }
    new=(list)malloc(sizeof(struct node));
     new->data=d;
     new->next = temp->next;
     temp->next=new;
}
void delete(list h,int ind){
    list temp=h,k;
    for(int i=0;i<ind;i++)
    {
        temp=temp->next;
    }
    k=temp->next;
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
delete(n,0);
insert(n,48,0);
while(n !=NULL){
    printf("%d : ",n->data);
    n=n->next;
}
}