#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#define queue stack // dual use purpose
#define enqueue push // we can call push through inqueue

typedef struct node{
    int data;
    struct node *pre; // point the previous pointer
    struct node *next; // point the next pointer
}node;

typedef struct linkedlist{
    int count;
    struct node *front; // trace the front node 
    struct node *end; // trace the end node
}stack;

bool isempty(stack* head){
    if(head->count == 0)
        return true;
    else
        return false;

}

void create(stack* head){
    head->count = 0;
    head->front = NULL;
    head->end = NULL;
}

bool push(stack *head, int n){
    /*
    * Add an element(int) doubly likedlist
    * Time complexity: O(1)
    * Space complexity: O(1)
    * return True- if successful else False
    */
    node *ptr;
    ptr = (node*)malloc(sizeof(node));
    if (!ptr)
        return false; // if memory not allocated then return false
    ptr->data = n;
    ptr->pre = NULL;
    ptr->next = NULL;
    if (head->front == NULL){
        head->front = ptr;
        head->end = ptr;
    }
    else{
        head->front->pre = ptr;
        ptr->next = head->front;
        head->front = ptr;
    }
    head->count++;
    return true;
}

bool pop(stack* head, int* n){
    /*
    * Remove the front element(int) from the linkedlist
    * Time complexity: O(1)
    * Space Complexity: O(1)
    * return: true if Successful else false 
    */
    node *ptr;
    if(isempty(head) == true){
        return false;
    }
    else if(head->front == head->end){ // if one element is present
        *n = head->front->data;
        head->front = NULL;
        head->end = NULL;
        head->count--;
        return true;
    }
    else{
        *n = head->front->data;
        ptr = head->front;
        head->front->next->pre = NULL;
        head->front = head->front->next;
        free(ptr);
        head->count--;
        return true;
    }
}

bool top(stack* head, int* n){
    /*
    * display the front element
    * Time Complexity: O(1)
    * Space Complexity: O(1)
    * return: true if Successful else false 
    */
    if (isempty(head) == true)
        return false;
    else
        *n = head->front->data;
    return true;
}

/* QUEUE ADT*/

bool dequeue(queue* head, int* n){
    /*
    * remove the last element(int) from the element
    * Time Complexity: O(1)
    * Space Complexity: O(1)
    * return: true if successful else false
    */
    node *ptr;
    if (isempty(head) == true)
        return false;
    else if(head->front == head->end){
        *n = head->front->data;
        head->front = NULL;
        head->end = NULL;
        head->count--;
    }
    else{
        *n = head->front->data;
        ptr = head->end;
        head->end->pre->next = NULL;
        head->end = head->end->pre;
        
        free(ptr);
        head->count--;
    }
    return true;
}

bool peek(queue* head, int* n){
    /*
    * display the end element
    * Time Complexity: O(1)
    * Space Complexity: O(1)
    * return: true if Successful else false 
    */
    if (isempty(head) == true)
        return false;
    else
        *n = head->end->data;
    return true;
}

void display(stack* head){
    node *ptr;
    ptr = head->front;
    while (ptr != NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
}

void delete(stack* head){
    node *ptr, *preptr;
    ptr = head->front;
    while (ptr != NULL)
    {
        preptr = ptr;
        free(ptr);
        ptr = ptr->next;
    }
    
}

int main(int argc, char const *argv[])
{
    int n, m = 0, k;
    bool l;
    stack head;
    create(&head);

    do
    {
        printf("\n\n****stack and queue****");
        printf("\n1. push/ enqueue");
        printf("\n2. pop");
        printf("\n3. Top");
        printf("\n4. Dequeue");
        printf("\n5. Peek");
        printf("\n6. Display");
        printf("\n7. EXIT");
        printf("\nEnter your choice: ");
        scanf("%d",&n);
        switch (n){

            case 1:
                printf("\nEnter the element: ");
                scanf("%d",&k);
                l = push(&head, k);
                if (l == true)
                    printf("\nsuccessful entry");
                else
                    printf("\nNot successful entry");
                break;
            case 2:
                l = pop(&head, &m);
                if (l == false)
                    printf("\nError");
                else
                    printf("\nPop element is: %d",m);
                break;
            case 3: 
                    l = pop(&head, &m);
                    if (l == false)
                        printf("\nError");
                    else
                        printf("\nTop element is: %d",m);
                break;

            case 4:
                l = dequeue(&head, &m);
                if (l == false)
                    printf("\nElement is not dequeue");
                else
                    printf("\ndequeue element is: %d",m);
                break;

            case 5:
                l = dequeue(&head, &m);
                if (l == false)
                    printf("\nElement is not dequeue");
                else
                    printf("\npeek element is: %d",m);
                break;
            case 6:
                    display(&head);
                break;
            case 7:
                    delete(&head);
                break;

            default:
                printf("\nEnter valid input");
                break;
        }
    } while (n != 7);
    return 0;
}
 