#include "stdio.h"

int str_length(char* s){
    int l = 0;
    while(s[l] != '\0') l++;
    return l;
}

void str_concat(char* s1, char* s2, char* result){
    int i = 0,j = 0;
    while(s1[i] != '\0'){
        result[i] = s1[i];
        i++;
    }
    while(s2[j] != '\0') result[i++] = s2[j++];
    result[i] = '\0';
}

int str_cmp(char* s1, char* s2){
    int i = 0;
    while(s1[i] != '\0' && s2[i] != '\0'){
        if(s1[i] != s2[i]) return 0;
        i++;
    }
    if(s1[i] == '\0' && s2[i] == '\0') return 1;
    return 0;
}

void insert_substr(char* s, char* sub, int pos){
    int sub_len = str_length(sub);
    int s_len = str_length(s);
    for(int i = s_len; i >= pos-1;i--)s[i+sub_len] = s[i];
    for(int i = 0; i < sub_len; i++)s[i+pos-1] = sub[i];
}

void del_substr(char* s, char* sub){
    int sub_len = str_length(sub);
    int s_len = str_length(s);
    if(sub_len > s_len) return;
    for(int i = 0; i <= s_len-sub_len; i++){
        int j = 0,t = i;
        while(j < sub_len && s[i] == sub[j]){
            j++;i++;
        }
        if(j != sub_len){
            i = t;
            continue;
        }
        for(;i <= s_len;i++)s[i-sub_len] = s[i];
        s_len -= sub_len;
        i = t;
    }
}

int main(){
    int choice,pos;
    char s1[100], s2[100],r[100];
    printf("Enter your choice:\nLength of string - 1\nString Concatenation - 2\nString Comparison - 3\nInsert substring - 4\nDelete substring - 5\n");
    scanf("%d",&choice);
    scanf("%*c");
    switch(choice){
    case 1:
        printf("enter string: ");
        fgets(s1,100,stdin);
        s1[str_length(s1)-1] = '\0'; // removing new line
        printf("length: %d\n",str_length(s1));
        break;
    case 2:
        printf("enter string 1: ");
        fgets(s1,100,stdin);
        s1[str_length(s1)-1] = '\0'; // removing new line
        printf("enter string 2: ");
        fgets(s2,100,stdin);
        s2[str_length(s2)-1] = '\0'; // removing new line
        str_concat(s1,s2,r);
        printf("Concatenated String: %s\n",r);
        break;
    case 3:
        printf("enter string 1: ");
        fgets(s1,100,stdin);
        printf("enter string 2: ");
        fgets(s2,100,stdin);
        if(str_cmp(s1,s2)) printf("The strings are equal!\n");
        else printf("The strings are not equal!\n");
        break;
    case 4:
        printf("enter string: ");
        fgets(s1,100,stdin);
        s1[str_length(s1)-1] = '\0'; // removing new line
        printf("enter substring: ");
        fgets(s2,100,stdin);
        s2[str_length(s2)-1] = '\0'; // removing new line
        printf("enter position: ");
        scanf("%d",&pos);
        insert_substr(s1,s2,pos);
        printf("Result: %s\n",s1);
        break;
    case 5:
        printf("enter string: ");
        fgets(s1,100,stdin);
        s1[str_length(s1)-1] = '\0'; // removing new line
        printf("enter substring: ");
        fgets(s2,100,stdin);
        s2[str_length(s2)-1] = '\0'; // removing new line
        del_substr(s1,s2);
        printf("Result: %s\n",s1);
        break;
    default:
        printf("invalid input");
    }

}
