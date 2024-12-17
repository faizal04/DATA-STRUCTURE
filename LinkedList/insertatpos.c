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
    }
    else{
        struct node*current=head;
            while(current->next!=NULL){
                current = current->next; 
            };
            current->next=temp;
    };
}

void insertatpos(int data,int pos){
    struct node * temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    struct node*current= head;
    for (int i=1;i<pos-1;i++){
        current=current->next;      //yaha per hamarai currnt mai jo position hai us sai phelai wala hoga
    }
    temp->next= current->next;
    current->next=temp;
}


void printed(){
    struct node *temp=head;
    while(temp!=NULL){
        printf("\n%d", temp->data);
        printf("\t %d",temp->next);
        temp=temp->next;
    }

}
int main(){
    head=NULL;
    int x;
    printf("enter the data");
    for (int i=0;i<4;i++){
        scanf("%d",&x);
        insert(x);
    };
    insertatpos(7,3);
    printed();
}
