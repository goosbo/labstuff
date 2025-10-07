#include "stdio.h"
#define MAX 100

typedef struct STACK{
    char s[MAX];
    int top;
}STACK;

void push(STACK *stack,char c){
    if(stack->top == MAX){
        printf("stack overflow\n");
        return;
    }
    stack->s[++stack->top] = c;
}

char pop(STACK *stack){
    if(stack->top == -1){
        printf("stack underflow\n");
        return '\0';
    }
    return stack->s[stack->top--];
}

int is_palindrome(char str[]){
    STACK stack;
    stack.top = -1;
    char* ch = str;
    while(*ch != '\0'){
        push(&stack,*ch);
        ch++;
    }
    ch = str;
    while(*ch != '\0'){
        if(*ch != pop(&stack)) return 0;
        ch++;
    }
    return 1;
}

int check_brackets(char str[]){
    STACK stack;
    stack.top = -1;
    char* ch = str,brac;
    while(*ch != '\0'){
        if(*ch == '(' || *ch == '{' || *ch == '[')push(&stack,*ch);
        else if(*ch == ')' || *ch == '}' || *ch == ']'){
            brac = pop(&stack);
            if(*ch == ')' && brac!='(')return 0;
            else if(*ch == '}' && brac!='{')return 0;
            else if(*ch == ']' && brac!='[')return 0;
        }
        ch++;
    }
    if(stack.top != -1)return 0;
    return 1;
}

int main(){
    int choice;
    char str[MAX];
    
    printf("Enter a string: ");
    scanf("%s",str);
    printf("Enter 1 for check palindrome, 2 for matching parenthesis\n");
    scanf("%d",&choice);

    switch(choice){
        case 1:
        if(is_palindrome(str))printf("it is a palindrome\n");
        else printf("it is not a palindrome\n");
        break;

        case 2:
        if(check_brackets(str))printf("matching parenthesis\n");
        else printf("parenthesis do not match\n");
        break;

        default:
        printf("invalid input\n");
    }
    return 0;
}