#include<stdio.h>
#include<stdlib.h>

//  using Global value

// struct LinkedlistNode
// {
//     int data;
//     struct LinkedlistNode*link;
// };


// struct  linkedlistNode * head;


// void insert(int x){
//    struct LinkedlistNode*temp= (struct LinkedlistNode*)malloc(sizeof(struct LinkedlistNode));
//    temp->data=x;
//    temp->link=NULL;
//    if(head==NULL){
//    head=temp;
//    }
//    else {
//         struct LinkedlistNode* current = head;
//         while (current->link != NULL) { 
//             current = current->link;
//         }
//         current->link = temp;
//     }
// }
// void print(){
//     struct LinkedlistNode*temp= head;
//     while(temp!=NULL){
//         printf("data: %d \n",temp->data);
//         printf("link: %d",temp->link);
//         temp=temp->link;
//     }

// }
// int main(){
//     head=NULL;
//     int x;
//     printf("enter the element you want to enter in the linked list");
//     for(int i=0;i<4;i++){
//     scanf("%d",&x);
//     insert(x);
//     }
//     print();
// }




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
    // while(temp!=NULL){
    //     printf("\n%d", temp->data);
    //     printf("\t %p",temp->next);
    //     temp=temp->next;
    // }
do{
printf("\ndata \t  %d",temp->data);
printf("\tlink:- %p",temp->next);
temp=temp->next;
}while(temp!=head);
}

void delnode(int target){
    struct node* temp= head;
    struct node*temp2=head->next;
    while(temp2->data!=target){
        temp=temp->next;
        temp2=temp2->next;
    }
    temp->next=temp2->next;
    free(temp2);
}


void delete (){
    struct node* curr= head;
while(curr!=NULL){
    struct node* temp = curr;
    curr=curr->next;
    free(temp);
}
// head=NULL;
}

int main(){
    head=NULL;
    int x;
    printf("enter the data");
    for (int i=0;i<6;i++){
        scanf("%d",&x);
        insert(x);
    };
    // delnode(4);
    // delete();
    printed();
}
