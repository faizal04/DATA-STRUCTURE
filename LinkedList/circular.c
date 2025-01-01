//kl sai pakka
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next; 
};
struct node* head;

void insert(int x){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data= x;
    temp->next=NULL;

    if(head==NULL){
        head=temp;
        temp->next=head;
    }
    else{
        struct node*current=head;
            while(current->next!=head){
                current = current->next; 
            };
            current->next=temp;
            temp->next=head;
    };
}


void printed(){
        printf("head:-> %p",head);
    struct node *temp=head;

do{
printf("\ndata \t  %d",temp->data);
printf("\tlink:- %p",temp->next);
temp=temp->next;
}while(temp!=head);
}

int main(){
    head=NULL;
    int x;
    printf("enter the data");
    for (int i=0;i<6;i++){
        scanf("%d",&x);
        insert(x);
    };
   
    printed();
}

// insert node 
