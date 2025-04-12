#include <stdio.h>
#include <stdlib.h>

typedef struct node snode;
struct node {
    int data;
    struct node *next;
};

void display(snode *head);
snode* getNode(int value);
snode* createList(snode *head);
snode* insertNodeBegining(snode* head);
snode* insertNodeAtPosition(snode* head, int pos);
snode* insertNodeEnd(snode* head);
snode* deleteNodeBeginning(snode* head);
snode* deleteNodeEnd(snode* head);
snode* deleteNodeAtPosition(snode* head, int pos);
void findElement(snode *head, int element);

snode* getNode(int value) {
    snode *p = (snode*) malloc(sizeof(struct node));
    p->data = value;
    p->next = NULL;
    return p;
}

snode* createList(snode *head) {
    char s;
    snode *p, *q;
    int data;
    do {
        printf("Enter element: ");
        scanf("%d", &data);
        p = getNode(data);
        
        if (!head) {
            head = p;  
        } else {
            q = head;
            while (q->next) q = q->next;
            q->next = p;  
        }

        printf("Do you want to continue adding nodes? (y/n): ");
        scanf(" %c", &s);  
    } while (s == 'y' || s == 'Y');
    return head;
}

snode* insertNodeBegining(snode* head) {
    snode* newNode;
    int data;
    printf("Enter the data for the new node: ");
    scanf("%d", &data);
    newNode = getNode(data);
    newNode->next = head; 
    return newNode;
}

snode* insertNodeEnd(snode* head) {
    snode* newNode;
    snode* temp;
    int data;

    printf("Enter the data for the new node: ");
    scanf("%d", &data);
    newNode = getNode(data);

    if (!head) return newNode;  

    temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

snode* insertNodeAtPosition(snode* head, int pos) {
    snode *newNode, *temp;
    int data, i;

    printf("Enter the data for the new node: ");
    scanf("%d", &data);
    newNode = getNode(data);

    if (pos == 1) {
        newNode->next = head;
        return newNode;
    }

    temp = head;
    for (i = 1; i < pos - 1 && temp; i++) temp = temp->next;

    if (!temp) {
        printf("Invalid position!\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    
    return head;
}

snode* deleteNodeBeginning(snode* head) {
    if (!head) {
        printf("\nList is empty. Nothing to delete.\n");
        return head;
    }

    snode* temp = head;
    head = head->next;
    free(temp);
    
    printf("\nNode deleted from the beginning.\n");
    return head;
}

snode* deleteNodeEnd(snode* head) {
    if (!head) {
        printf("\nList is empty. Nothing to delete.\n");
        return head;
    }

    if (!head->next) {
        free(head);
        return NULL;
    }

    snode *temp = head, *prev = NULL;
    while (temp->next) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
    return head;
}

snode* deleteNodeAtPosition(snode* head, int pos) {
    if (!head) {
        printf("\nList is empty. Nothing to delete.\n");
        return head;
    }

    snode *temp = head;
    if (pos == 1) {
        head = head->next;
        free(temp);
        return head;
    }

    snode *prev = NULL;
    int i;
    for (i = 1; i < pos && temp; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) {
        printf("\nInvalid position! Node does not exist.\n");
        return head;
    }

    prev->next = temp->next;
    free(temp);
    return head;
}

void display(snode *head) {     
    snode *p;
    if (!head) {
        printf("\nList is empty\n");
    } else {
        p = head;
        printf("\nList of elements are: ");
        while (p) {
            printf("%5d", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

void findElement(snode *head, int element) {
    snode *p = head;
    while (p) {
        if (p->data == element) {
            printf("Element found\n");
            return;
        }
        p = p->next;
    }
    printf("Element not found\n");
}


int main() {
    int choice, pos, element;
    snode *head = NULL;
    
    do {
        printf("\nEnter a number between 1 and 10 to choose an option:\n");
        printf("1. Create linked list\n");
        printf("2. Insert node at the beginning\n");
        printf("3. Insert node at the end\n");
        printf("4. Insert node at the given position\n");
        printf("5. Delete node at the beginning\n");
        printf("6. Delete node at the end\n");
        printf("7. Delete node at the given position\n");
        printf("8. Find element\n");
        printf("9. Display\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = createList(head);  
                break;
            case 2:
                head = insertNodeBegining(head); 
                break;
            case 3:
                head = insertNodeEnd(head);
                break;
            case 4:
                printf("Enter the position: ");
                scanf("%d", &pos);
                head = insertNodeAtPosition(head, pos);
                break;
            case 5:
                head = deleteNodeBeginning(head);
                break;
            case 6:
                head = deleteNodeEnd(head);
                break;
            case 7:
                printf("Enter the position: ");
                scanf("%d", &pos);
                head = deleteNodeAtPosition(head, pos);
                break;
            case 8:
                printf("Enter the element to find: ");
                scanf("%d", &element);
                findElement(head, element);
                break;
            case 9:
                display(head);
                break;
            case 10:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please choose a number between 1 and 10.\n");
        }
    } while (choice != 10);
    
    return 0;   
}

