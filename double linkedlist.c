#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *pvs;
    int data;
    struct node *next;
};
typedef struct node snode;

int menu() {
    int k;
    printf("\n------ Double Linked List Operations ------");
    printf("\n1. Create linked list");
    printf("\n2. Insert node at beginning");
    printf("\n3. Insert node at end");
    printf("\n4. Insert at given position");
    printf("\n5. Delete node at beginning");
    printf("\n6. Delete node at end");
    printf("\n7. Delete at given position");
    printf("\n8. Find element");
    printf("\n9. Display");
    printf("\n10. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &k);
    return k;
}

snode* getNode() {
    snode *p;
    int val;
    printf("\nEnter value: ");
    scanf("%d", &val);
    p = (snode*)malloc(sizeof(snode));
    p->data = val;
    p->next = NULL;
    p->pvs = NULL;
    return p;
}

snode* createList(snode* head) {
    snode *p, *q;
    char ch;
    do {
        p = getNode();
        if (!head)
            head = p;
        else {
            q = head;
            while (q->next != NULL)
                q = q->next;
            q->next = p;
            p->pvs = q;
        }
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
    return head;
}

void display(snode* head) {
    snode *p = head;
    if (!head) {
        printf("DLL is empty\n");
    } else {
        while (p) {
            printf("%5d", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

snode* insertAtBegin(snode* head) {
    snode *p = getNode();
    if (head) {
        p->next = head;
        head->pvs = p;
    }
    return p;
}

snode* insertAtEnd(snode* head) {
    snode *p = getNode();
    if (!head)
        return p;
    snode *q = head;
    while (q->next)
        q = q->next;
    q->next = p;
    p->pvs = q;
    return head;
}

snode* insertAtPos(snode* head, int pos) {
    if (pos == 1)
        return insertAtBegin(head);
    snode *p = getNode();
    snode *q = head;
    for (int i = 1; i < pos - 1 && q != NULL; i++)
        q = q->next;
    if (!q) {
        printf("Position out of bounds\n");
        return head;
    }
    p->next = q->next;
    if (q->next)
        q->next->pvs = p;
    q->next = p;
    p->pvs = q;
    return head;
}

snode* delbeg(snode* head) {
    if (!head) {
        printf("List is empty\n");
        return NULL;
    }
    snode *temp = head;
    head = head->next;
    if (head)
        head->pvs = NULL;
    free(temp);
    return head;
}

snode* delend(snode* head) {
    if (!head) {
        printf("List is empty\n");
        return NULL;
    }
    if (!head->next) {
        free(head);
        return NULL;
    }
    snode *p = head;
    while (p->next)
        p = p->next;
    p->pvs->next = NULL;
    free(p);
    return head;
}

snode* delpos(snode* head, int pos) {
    if (!head) {
        printf("List is empty\n");
        return NULL;
    }
    if (pos == 1)
        return delbeg(head);
    snode *p = head;
    for (int i = 1; i < pos && p != NULL; i++)
        p = p->next;
    if (!p) {
        printf("Position out of bounds\n");
        return head;
    }
    if (p->pvs)
        p->pvs->next = p->next;
    if (p->next)
        p->next->pvs = p->pvs;
    free(p);
    return head;
}

void findele(snode* head, int ele) {
    snode *p = head;
    int found = 0;
    while (p) {
        if (p->data == ele) {
            printf("Element %d found.\n", ele);
            found = 1;
            break;
        }
        p = p->next;
    }
    if (!found)
        printf("Element not found.\n");
}

int main() {
    snode *head = NULL;
    int ch, pos, ele;

    do {
        ch = menu();
        switch (ch) {
            case 1:
                head = createList(head);
                break;
            case 2:
                head = insertAtBegin(head);
                break;
            case 3:
                head = insertAtEnd(head);
                break;
            case 4:
                printf("Enter position to insert: ");
                scanf("%d", &pos);
                head = insertAtPos(head, pos);
                break;
            case 5:
                head = delbeg(head);
                break;
            case 6:
                head = delend(head);
                break;
            case 7:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                head = delpos(head, pos);
                break;
            case 8:
                printf("Enter element to find: ");
                scanf("%d", &ele);
                findele(head, ele);
                break;
            case 9:
                display(head);
                break;
            case 10:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (ch != 10);

    return 0;
}

