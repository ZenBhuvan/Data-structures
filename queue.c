#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
typedef struct node snode;
snode* getNode(int);
snode* enqueue(snode* head);
snode* dequeue(snode* head);
void display(snode*);
int menu() 
{
    int k;
    printf("2. enqueue\n");
    printf("5. dequeue\n");
    printf("9. Display\n");
    printf("\nEnter your choice: ");
    scanf("%d", &k);
    return k;
}
int main() {
    int ch;
    snode* head = NULL;
    printf("LINKED LIST  OPERATIONS\n");
    do {
        ch = menu();
        switch (ch) {
            case 1:
                printf("---Creating a linked list:---\n");
                break;
            case 2:
                printf("---Inserting node at beginning:---\n");
                head = enqueue(head);
                break;
            case 3:
                printf("---Inserting node at end:---\n");
                break;
            case 4:
                printf("---Inserting at given position:---\n");
                break;
            case 5:
                printf("---Deleting node at beginning:---\n");
               head = dequeue(head);
                break;
            case 6:
                printf("---Deleting node at end:---\n");
                break;
            case 7:
                printf("---Deleting node at given position:---\n");
                break;
            case 8:
                printf("---Finding element:---\n");
                break;
            case 9:
                printf("---Displaying list:---\n");
                display(head);
                break;
            case 10:
                exit(0);
            default:
                printf("Wrong choice, try again!\n");
        }
    } while (ch < 10);

    return 0;
}
snode* getNode(int value) {
    snode* p;
    p = (snode*)malloc(sizeof(snode));
    p->data = value;
    p->next = NULL;
    return p;
}
snode* enqueue(snode* head)
{
    int val;
    snode *p;
    printf("\nEnter the node value: ");
    scanf("%d", &val);
    p = getNode(val);
    if (!head)
        head = p;
    else 
    {
        p->next = head;
        head = p;
    }
    return head;
}
snode* dequeue(snode* head)
{
    snode *temp;
    temp = head;
    head = temp->next;
    free(temp);
    return head;
}
void display(snode* head) 
{
    snode* p;
    if (!head)
        printf("\nList is empty.");
    else
    {
        p = head;
        printf("\nList of elements: ");
        while (p)
        {
            printf("%5d", p->data);
            p = p->next;
        }
        printf("\n");
    }
}
