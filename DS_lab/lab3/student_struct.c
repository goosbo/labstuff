#include "stdio.h"

struct student{
    char name[100],grade;
    int rollno;
};

void read_students(struct student st[],int n){
    for(int i = 0; i < n; i++){
        printf("Enter student %i details:\n",i+1);
        printf("Name: ");
        scanf("%*c%s",st[i].name);
        printf("Roll no: ");
        scanf("%d",&st[i].rollno);
        printf("Grade: ");
        scanf("%*c%c",&st[i].grade);
    }
}

void display_students(struct student st[],int n){
    for(int i = 0; i < n; i++){
        printf("Name: %s\n",st[i].name);
        printf("Roll no: %d\n",st[i].rollno);
        printf("Grade: %c\n",st[i].grade);
        printf("\n");
    }
}

void sort_students(struct student st[],int n){
    for(int i = 1; i < n; i++){
        int j = i-1;
        struct student curr = st[i];
        while(j >= 0 && st[j].rollno > curr.rollno){
            st[j+1] = st[j];
            j--;
        }
        st[j+1] = curr;
    }
}

int main(){
    int n;
    struct student st[10];
    printf("Enter number of students: ");
    scanf("%d",&n);
    read_students(st,n);
    sort_students(st,n);
    printf("Students after sorting: \n");
    display_students(st,n);
    return 0;
}
