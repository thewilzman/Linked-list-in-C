/******************************************************************************
Using the codes I gave you from the Linked List lecture, make a program that
takes user input, asking how many nodes should be in the linked list
- Afterwards, prompt the user to enter the data for each node.
- You can add nodes either to the head or to the tail, it is entirely up to you.
- Print out the entire linked list
- Remove 1 node from the head and print the updated linked list
- Finally remove 1 node from the tail and print the updated linked list


*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

//Function to define a Node structure for the doubly linked list
    struct Node{
        int data;
        struct Node* next;
        struct Node* prev;
    };
    
// Function to create a new node     
    struct Node* createNode (int data){
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;
        return newNode;
    }

//Function to add node at the head of the linked list
    void addingNodeHead(struct Node** head, int data){
        struct Node* newNode = createNode(data);
        newNode->prev = NULL;
        if (*head == NULL){
            *head = newNode;
            newNode->next = NULL;
            return;
        }
        
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
        
// Function to add node at the tail of the linked list
    void addingNodeTail(struct Node** head, int data){
        struct Node* newNode = createNode(data);
        newNode->next = NULL;
        if (*head == NULL){
            *head = newNode;
            newNode->prev = NULL;
            return;
         }
         
        struct Node* tail = *head;
        while (tail->next != NULL){
        tail = tail->next;
        }
        
        tail->next = newNode;
        newNode->prev = tail;
        
    }
    
    //Function to remove Head of the doubly linked list   
    void removeHead(struct Node** head){
        if (*head == NULL){
         return;
        }
        struct Node* temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }
    
    //Function to remove tail of the doubly linked list
    void removeTail(struct Node** head){
        if (*head == NULL){
         return;
        }
        //need a case for one node being in the list
        struct Node* temp = *head;
        while (temp->next->next != NULL){
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
    
    //Function to print the doubly linked list
    void printList(struct Node* head){
        struct Node* temp = head;
        while (temp != NULL) {
            printf("%d -> ", temp->data); 
            temp = temp->next;
        }
        printf("NULL\n");
    }

    int main() {
        
        
        struct Node* head = NULL;
        
        int nodeAdded; // var for the number of nodes to add at the head
        
        printf("Enter the number of nodes:\n");
        scanf("%d", &nodeAdded);
        
        // taking user input for node to be added into the linked list
        for(int i = 0 ; i < nodeAdded; i++){// for loop for adding numbers of nodes according to var nodeAdded
            int data;
            printf("Enter data for node %d: ", i+1);
            scanf("%d", &data);
            addingNodeHead(&head, data); // adding nodes to the head of the linked list 
        }
        
        


    
    printf("Doubly Linked list: ");

    // Printing the list
    printList(head);

    
    removeHead(&head);// removing head of the doubly Linked list
    //Printing the list after removing head
    printf("After removing head: ");
    printList(head);
    
    

    removeTail(&head);// remove tail of the doubly Linked list
    //Printing list after removing tail
    printf("After removing tail: ");
    printList(head);
    
    
    
    
    return 0;
    
}
    
   
