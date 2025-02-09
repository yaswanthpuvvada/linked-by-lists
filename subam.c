#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node* next;
};
typedef struct node* list;
list create(){
    list h=(list)malloc(sizeof(sizeof(struct node)));
    h->data=-1;
    h->next=NULL;
    return h;
};
void insert(list h,int val,int ind){
    list new,temp=h;
    new=(list)malloc(sizeof(struct node));
    new->data=val;
    if(temp->next==NULL){
       new->next=NULL;
       h->next=new;
    }
    else{
    for(int i=0;i<ind;i++){
        temp=temp->next;
    }
    new->next=temp->next;
    temp->next=new;
    }
}
void print(list h){
    list t=h;
    printf("head :");
    t=t->next;
    while(t!=NULL){
        printf(" %d ",t->data);
        t=t->next;
    }
    printf(": End");
}
void delete(list h){
    
}
void main(){
    list h=create();
    insert(h,1,0);
    insert(h,2,1);
    insert(h,3,2);
    insert(h,4,3);
    print(h);


}

