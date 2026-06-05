#include<stdio.h>
#include<string.h>
#include<ctype.h>

char stack[50]; int top=-1;
void push(char c){ stack[++top]=c; }
char pop(){ return stack[top--]; }

int priority(char c){
    if(c=='+'||c=='-') return 1;
    if(c=='*'||c=='/') return 2;
    return 0;
}

int main(){
    char infix[50], prefix[50];
    int i,j=0;
    printf("Enter infix: ");
    scanf("%s",infix);
    strrev(infix);

    for(i=0;infix[i];i++){
        if(isalnum(infix[i]))
            prefix[j++]=infix[i];
        else if(infix[i]==')')
            push(infix[i]);
        else if(infix[i]=='('){
            while(stack[top]!=')')
                prefix[j++]=pop();
            pop();
        }
        else{
            while(priority(stack[top])>priority(infix[i]))
                prefix[j++]=pop();
            push(infix[i]);
        }
    }
    while(top!=-1)
        prefix[j++]=pop();

    prefix[j]='\0';
    strrev(prefix);
    printf("Prefix: %s",prefix);
}
