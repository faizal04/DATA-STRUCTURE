    // insert at beginning of linked list
    #include<stdio.h>
    #include<stdlib.h>
    struct node{
        int data;
        struct node* next; 
    };

    void insert(int x, struct node** head) {
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->data = x;
        temp->next = NULL;

        if (*head == NULL) { 
            *head = temp;    
        } else {
            struct node* current = *head;
            while (current->next != NULL) { 
                current = current->next;
            }
            current->next = temp; 
        }
    }

    void printed(struct node *head){
        while(head!=NULL){
            printf("\n%d", head->data);
            head=head->next;
        }
    }
    void insertAtBeginning(int data,struct node**head){
            struct node*temp= (struct node*)malloc(sizeof(struct node));
            temp->data=data;
            temp->next=*head;
            *head=temp;
    };

    int main(){
    struct node* head=NULL;
        int x;
        printf("enter the data");
        for (int i=0;i<4;i++){
            scanf("%d",&x);
            insert(x,&head);
        };
            insertAtBeginning(3,&head);
        printed(head);
    }
