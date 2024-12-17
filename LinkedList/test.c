#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head;

void insert(int x) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
        // temp->next=head;
    } else {
        struct node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
        temp->next=head;
    }
}

void printed() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("\nData: %d", temp->data);
        printf("\tNext: %p", (void*)temp->next);
        temp = temp->next;
    }
}

void delnode(int target) {
    struct node* temp = head;
    
    // Special case for deleting the head node
    if (head->data == target) {
        head = head->next;  // Update head to the next node
        free(temp);         // Free the old head node
        return;
    }

    // Traverse the list to find the target node
    struct node* prev = NULL;
    while (temp != NULL && temp->data != target) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with value %d not found.\n", target);
        return; // Node not found
    }

    // Delete the node
    prev->next = temp->next;
    free(temp);
}

void delete() {
    struct node* curr = head;
    while (curr != NULL) {
        struct node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    head = NULL;
}

int main() {
    head = NULL;
    int x;
    printf("Enter the data:\n");
    for (int i = 0; i < 6; i++) {
        scanf("%d", &x);
        insert(x);
    }

    // delnode(4);   // Deletes the node with value 4
    // delete();     // Deletes the entire list
    printed();    // Prints the list (should display "List is empty.")
    
    return 0;
}
