#include "stdio.h"
#include "stdlib.h"

typedef struct term{
    int coeff, exp;
    struct term* next;
    struct term* prev;
} term;

term* create_term(int coeff, int exp){
    term* new_term = (term*)malloc(sizeof(term));
    new_term->coeff = coeff;
    new_term->exp = exp;
    new_term->next = NULL;
    new_term->prev = NULL;
    return new_term;
}

void display(term *poly){
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    term *temp = poly;
    while(temp != NULL){
        printf("%dx^%d", temp->coeff, temp->exp);
        if(temp->next != NULL) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}


void insert(term **poly, int coeff, int exp){
    if (coeff == 0) return; 

    term* new_term = create_term(coeff, exp);
    if (*poly == NULL){
        *poly = new_term;
        return;
    }
    
    term* curr = *poly;
    term* prev = NULL;

    while(curr != NULL && curr->exp > new_term->exp) {
        prev = curr;
        curr = curr->next;
    }

    if(curr != NULL && curr->exp == new_term->exp){
        curr->coeff += new_term->coeff;

        if(curr->coeff == 0){
            if(curr == *poly){ 
                *poly = curr->next;
                if (*poly != NULL) {
                    (*poly)->prev = NULL;
                }
            } 
            else { 
                prev->next = curr->next;
                if(curr->next != NULL){
                    curr->next->prev = prev;
                }
            }
        }
    } 
    else {
        if(curr == *poly){ 
            new_term->next = *poly;
            (*poly)->prev = new_term;
            *poly = new_term;
        } 
        else if (curr == NULL) { 
            prev->next = new_term;
            new_term->prev = prev;
        } 
        else { 
            new_term->next = curr;
            new_term->prev = prev;
            prev->next = new_term;
            curr->prev = new_term;
        }
    }
}

term* add(term *poly1, term* poly2){
    term* result = NULL;
    while(poly1 != NULL || poly2 != NULL){
        if(poly1 == NULL) {
            insert(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } 
        else if(poly2 == NULL) {
            insert(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } 
        else if(poly1->exp > poly2->exp) {
            insert(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } 
        else if(poly2->exp > poly1->exp) { 
            insert(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } 
        else {
            int sum_coeff = poly1->coeff + poly2->coeff;
            if(sum_coeff != 0) {
                insert(&result, sum_coeff, poly1->exp);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    return result;
}

int main(){
    int n1, n2;
    term *poly1 = NULL, *poly2 = NULL, *result = NULL;

    printf("Enter no. of terms for poly 1: ");
    scanf("%d", &n1);
    printf("Enter coeffs and exps\n");
    for(int i = 0; i < n1; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        insert(&poly1, x, y);
    }
    
    printf("Enter no. of terms for poly 2: ");
    scanf("%d", &n2);
    printf("Enter coeffs and exps\n");
    for(int i = 0; i < n2; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        insert(&poly2, x, y);
    }

    printf("Polynomial 1: ");
    display(poly1);
    printf("Polynomial 2: ");
    display(poly2);

    result = add(poly1, poly2);
    printf("Resultant Polynomial: ");
    display(result);

    return 0;
}