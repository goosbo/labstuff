#include "stdio.h"

struct student{
    char name[50];
    int roll_no;
    float marks;
};

void read_students(struct student st[],int n){
    struct student *ptr = st;
    for(int i = 0; i < n; i++){
        printf("Enter student %i details:\n",i+1);
        printf("Name: ");
        scanf("%*c%s",ptr->name);
        printf("Roll no: ");
        scanf("%d",&ptr->roll_no);
        printf("Marks: ");
        scanf("%f",&ptr->marks);
        ptr++;
    }
}

void display_students(struct student st[],int n){
    printf("Student Details\n");
    struct student *ptr = st;
    for(int i = 0; i < n; i++){
        printf("Name: %s\n",ptr->name);
        printf("Roll no: %d\n",ptr->roll_no);
        printf("Marks: %f\n",ptr->marks);
        printf("\n");
        ptr++;
    }
}

void max_marks(struct student st[],int n){
    struct student *ptr = st;
    struct student *maxptr = ptr;
    for(int i = 0; i < n; i++){
        if(ptr->marks > maxptr->marks) {
            maxptr = ptr;
        }
        ptr++;
    }
    printf("Student with maximum marks\n");
    printf("Name: %s\n",maxptr->name);
    printf("Roll no: %d\n",maxptr->roll_no);
    printf("Marks: %f\n",maxptr->marks);
    printf("\n");
}


int main(){
    int n;
    struct student st[10];
    printf("Enter number of students: ");
    scanf("%d",&n);
    read_students(st,n);
    display_students(st,n);
    max_marks(st,n);
    return 0;
}
