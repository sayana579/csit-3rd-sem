#include<stdio.h>
#include<ctype.h>
int stack[50], top=-1;

void push(int x){ stack[++top]=x; }
int pop(){ return stack[top--]; }

int main(){
    char exp[50];
    int i,a,b;
    printf("Enter postfix: ");
    scanf("%s",exp);

    for(i=0;exp[i];i++){
        if(isdigit(exp[i]))
            push(exp[i]-'0');
        else{
            b=pop();
            a=pop();
            switch(exp[i]){
                case '+': push(a+b); break;
                case '-': push(a-b); break;
                case '*': push(a*b); break;
                case '/': push(a/b);
            }
        }
    }
    printf("Result: %d",pop());
}
