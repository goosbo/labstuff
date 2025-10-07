#include "stdio.h"
#include "string.h"
#include "stdlib.h"

typedef struct node{
    char c;
    struct node* next;
}node;

node* top = NULL;

typedef struct nodeint{
    int c;
    struct nodeint* next;
}nodeint;
nodeint* topint = NULL;
void pushint(char c){
    nodeint* newnode = (nodeint*)malloc(sizeof(nodeint));
    if(!newnode){
        printf("stack overflow\n");
        return;
    }
    newnode->c = c;
    newnode->next = topint;
    topint = newnode;
}

int popint(){
    if(topint == NULL){
        printf("stack underflow\n");
        return '\0';
    }
    int val = topint->c;
    nodeint* temp = topint;
    topint = topint->next;
    free(temp);
    return val;
}

void push(char c){
    node* newnode = (node*)malloc(sizeof(node));
    if(!newnode){
        printf("stack overflow\n");
        return;
    }
    newnode->c = c;
    newnode->next = top;
    top = newnode;
}

char pop(){
    if(top == NULL){
        printf("stack underflow\n");
        return '\0';
    }
    char val = top->c;
    node* temp = top;
    top = top->next;
    free(temp);
    return val;
}

int isop(char c){
    return c=='+'||c=='-'||c=='*'||c=='/'||c=='^'||c=='%';
}

int isoperand(char c){
    return (c>='A'&&c<='Z')||(c>='a'&&c<='z')||(c>='0'&&c<='9');
}

int precedence(char op){
    switch(op){
        case '+':
        case '-':
        return 1;
        case '*':
        case '/':
        return 2;
        case '^':
        return 3;
        default:
        return 0;
    }
}

int higher_or_eq_precedence(char op1,char op2){
    int p1 = precedence(op1);
    int p2 = precedence(op2);
    if(p1 == p2){
        if(op1 == '^')return 0;
        return 1;
    }
    return p1>p2;
}

void infix_2_postfix(char infix[],char postfix[]){
    push('(');
    strcat(infix,")");
    int i = 0,j = 0;
    char ch;
    while((ch = infix[i++])!='\0'){
        if(ch == ' ')continue;
        else if(ch == '(')push(ch);
        else if(isoperand(ch))postfix[j++] = ch;
        else if(isop(ch)){
            while(top != NULL && higher_or_eq_precedence(top->c,ch)) postfix[j++] = pop();
            push(ch);
        }
        else if(ch == ')'){
            while(top != NULL && top->c != '(')postfix[j++] = pop();
            pop();
            
        }
    }
    postfix[j] = '\0';
}

int evaluate(int n1,int n2,char op){
    switch(op){
        case '+':
        return n1+n2;
        case '-':
        return n1-n2;
        case '*':
        return n1*n2;
        case '/':
        return n1/n2;
        case '%':
        return n1%n2;
    }
}
int evaluate_postfix(char postfix[]){
    int i = 0;
    char ch;
    while((ch = postfix[i++])!='\0'){
        if(isoperand(ch))pushint(ch-'0');
        else if(isop(ch)){
            int n2 = popint(),n1 = popint();
            pushint(evaluate(n1,n2,ch));
        }
    }
    return topint->c;
}

int main(){
    int choice;
    char str[100],result[100];

    printf("Enter string:");
    scanf("%s",str);
    printf("Enter 1 for infix to postfix, 2 for postfix eval: ");
    scanf("%d",&choice);

    switch(choice){
        case 1:
        infix_2_postfix(str,result);
        printf("Result: %s\n",result);
        break;
        case 2:
        printf("Result: %d\n",evaluate_postfix(str));
        break;
        default:
        printf("invalid input\n");
    }
    return 0;
}
