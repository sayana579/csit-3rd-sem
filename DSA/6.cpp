#include<stdio.h>
#include<ctype.h>
#include<string.h>
int stack[50], top=-1;
void push(int x){ stack[++top]=x; }
int pop(){ return stack[top--]; }

int main(){
    char exp[50];
    printf("Enter prefix: ");
    scanf("%s",exp);

    for(int i=strlen(exp)-1;i>=0;i--){
        if(isdigit(exp[i]))
            push(exp[i]-'0');
        else{
            int a=pop();
            int b=pop();
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
