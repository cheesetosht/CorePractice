#include <stdio.h>
#include <string.h>

#define SIZE 50
struct Stacv1{
    char st[SIZE];
    int top;
};

int priority(char ch){
    switch(ch){
        case '$':
               return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 3;
    }
}
int curr_priority(char ch){
    switch(ch){
        case '(':
            return 9;
        case ')':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 3;
        case '^':
            return 6;
        default:
            return 7;
    }
}
int st_priority(char ch){
    switch(ch){
        case '(':
            return 0;
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 4;
        case '^':
            return 5;
        default:
            return 8;
    }
}
void push(struct Stacv1* s1,char x){
    if(s1->top>=SIZE-1)
    {
        printf("Overflow\n");
        return;
    }
    s1->st[++s1->top]=x;
}
char peep(struct Stacv1 s1,int offset){
    if(s1.top-offset < 0)
    {
        printf("Underflow\n");
        return -1;
    }
    return s1.st[s1.top-offset];
}
char pop(struct Stacv1* s1){
    if(s1->top==-1)
    {
        printf("Underflow\n");
        return -1;
    }
    return s1->st[s1->top--];
}


void change(struct Stacv1* s1,int value,int offset){
    if(s1->top-offset < 0)
    {
        printf("Underflow\n");
        return;
    }
    s1->st[s1->top-offset]=value;
}
#define _IN2POSTv1_
#ifdef _IN2POSTv1_
int main(){
    struct Stacv1 s1;
    s1.top=-1;
    char current;
    int indx=0,outindx=0;
    char input[50],output[50];
    scanf("%s",input);
    strcat(input,"$");
    push(&s1,'$');
    current=input[indx];
    while(current!='$'){
        while(priority(current)<=priority(s1.st[s1.top])){
                output[outindx]=pop(&s1);
                outindx++;
        }
        push(&s1,current);
        current=input[++indx];
    }
    while(s1.st[s1.top]!='$'){
                output[outindx]=pop(&s1);
                outindx++;
    }
    output[outindx]='\0';
    printf("Output:%s\n",output);
    return 0;
}
#endif
#ifdef _IN2POSTv2_
int main()
{
    struct Stacv1 s1;
    char current;
    int indx=0,outindx=0;
    char input[50],output[50];
    s1.top=-1;
    scanf("%s",input);
    strcat(input,")");
    push(&s1,'(');
    current=input[indx];
    while(current!='\0'){
        while(curr_priority(current)<st_priority(s1.st[s1.top])){
                output[outindx]=pop(&s1);
                outindx++;
        }
        if(curr_priority(current)==st_priority(s1.st[s1.top]))
            pop(&s1);
        else
            push(&s1,current);
        current=input[++indx];
    }
    output[outindx]='\0';
    printf("Output:%s\n",output);
    return 0;
}
#endif
