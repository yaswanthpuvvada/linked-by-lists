#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};
typedef struct node* list;
list create(){
list h=(list)malloc(sizeof(struct node));
h->next=h;
h->data=-1;
return h;
}
void insert(list l,int data){
    list temp=l,k=l;
    if(temp==NULL)
    {
        printf("Error");
    }
    else{
        list new=(list)malloc(sizeof(struct node));
        new->data=data;
        temp=temp->next;
        while(temp->next!=l){
            temp=temp->next;
        }
        temp->next=new;
        new->next=l;
    }
}
//deletion take another list by data as it is circular no starating index
void delete(list l,int data){
list temp=l,curr;
while(temp->next!=l&&temp->data!=data){
    curr=temp;
    temp=temp->next;
}
if (temp != l && temp->data == data) {
        curr->next = temp->next;
        free(temp);
    } 
    else {
        printf("Node with value %d not found\n", data);
    }
}
void main(){
    list n=create();
    list k=n;
    insert(n,1);
    insert(n,22);
        insert(n,3);
            insert(n,4);
            delete(n,22);
            printf("%d  :",n->data);
            n=n->next;
        while(n!=k){
          printf("%d  :",n->data);
          n=n->next;
        }
}