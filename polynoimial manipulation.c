#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coef;
    int exp;
    struct Node* next;
};

typedef struct Node Node;

void insert(Node** poly, int coef, int exp) {
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->coef = coef;
    temp->exp = exp;
    temp->next = NULL;
    
    if (*poly == NULL) {
        *poly = temp;
        return;
    }
    
    Node* current = *poly;
    
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = temp;
}

void print(Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    
    Node* current = poly;
    
    while (current != NULL) {
        printf("%dx^%d", current->coef, current->exp);
        if (current->next != NULL) {
            printf(" + ");
        }
        current = current->next;
    }
    
    printf("\n");
}

Node* add(Node* poly1, Node* poly2) {
    Node* result = NULL;
    
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp == poly2->exp) {
            insert(&result, poly1->coef + poly2->coef, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->exp > poly2->exp) {
            insert(&result, poly1->coef, poly1->exp);
            poly1 = poly1->next;
        } else {
            insert(&result, poly2->coef, poly2->exp);
            poly2 = poly2->next;
        }
    }
    
    while (poly1 != NULL) {
        insert(&result, poly1->coef, poly1->exp);
        poly1 = poly1->next;
    }
    
    while (poly2 != NULL) {
        insert(&result, poly2->coef, poly2->exp);
        poly2 = poly2->next;
    }
    
    return result;
}

int main() {
    Node* poly1 = NULL;
    insert(&poly1, 5, 4);
    insert(&poly1, 3, 2);
    insert(&poly1, 1, 0);
    Node* poly2 = NULL;
    insert(&poly2, 4, 4);
    insert(&poly2, 2, 2);
    insert(&poly2, 1, 1);
    printf("First polynomial: ");
    print(poly1);
    printf("Second polynomial: ");
    print(poly2);
    Node* result = add(poly1, poly2);
    printf("Result: ");
    print(result);
  return 0;
}
