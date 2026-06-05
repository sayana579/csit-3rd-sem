#include<stdio.h>
#include<ctype.h>
char stack[50]; int top=-1;

void push(char x){ stack[++top]=x; }
char pop(){ return stack[top--]; }

int priority(char x){
    if(x=='+'||x=='-') return 1;
    if(x=='*'||x=='/') return 2;
    return 0;
}

int main(){
    char exp[50], *e, x;
    printf("Enter infix: ");
    scanf("%s",exp);
    e=exp;

    while(*e){
        if(isalnum(*e))
            printf("%c",*e);
        else if(*e=='(')
            push(*e);
        else if(*e==')'){
            while((x=pop())!='(')
                printf("%c",x);
        }
        else{
            while(priority(stack[top])>=priority(*e))
                printf("%c",pop());
            push(*e);
        }
        e++;
    }
    while(top!=-1)
        printf("%c",pop());
}
